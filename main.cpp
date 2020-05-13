#include <iostream>
#include<cmath>
using namespace std;

class Numar_complex
{
 double real,imag;

 public:

Numar_complex();

Numar_complex(double Real,double Imag);

Numar_complex (Numar_complex& x);

~Numar_complex();

friend istream& operator>> (istream &f, Numar_complex &x);
friend ostream& operator>> (ostream &g, Numar_complex &x);

friend Numar_complex operator+ (const Numar_complex &x,const Numar_complex &y);

friend Numar_complex operator- (const Numar_complex &x,const Numar_complex &y);

friend Numar_complex operator- (const Numar_complex &x);

friend Numar_complex operator* (const Numar_complex &x,const Numar_complex &y);

friend Numar_complex operator* (const Numar_complex &x,const double &y);

friend Numar_complex operator/ (const Numar_complex &x,const Numar_complex &y);

friend Numar_complex operator+= (Numar_complex &x,const Numar_complex &y);

friend Numar_complex operator-= (Numar_complex &x,const Numar_complex &y);

friend Numar_complex operator*= (Numar_complex &x,const Numar_complex &y);

friend Numar_complex operator^ (const Numar_complex &x,const double &y);

friend bool operator== (Numar_complex &x,Numar_complex &y);

friend bool operator!= (Numar_complex &x,Numar_complex &y);

friend double Abs(Numar_complex &x);

friend Numar_complex Sqrt(Numar_complex &x);



void setReal(double Real=0)
{
    real=Real;
}

void setImag(double Imag=0)
{
    imag=Imag;
}

double getReal()
{
    return real;
}

double getImag()
{
    return imag;
}

void afisare()
{
    if (real==0) cout<<imag<<"i"<<endl;
    else if (imag==0) cout<<real<<endl;
    else if (real>0&&imag>0)cout<<real<<"+"<<imag<<"i"<<endl;
    else if(imag<0)cout<<real<<imag<<"i"<<endl;
    else cout<<real<<"+"<<imag<<"i"<<endl;
}

void citire()
{
    double x,y;
    cout<<"Numarul complex este :\nreal=";
    cin>>x;
    real=x;
    cout<<"imag=";
    cin>>y;
    imag=y;
}

friend istream& operator>> (istream &f, Numar_complex &x)
{
cout<<"Numarul este";
    return(f>>x.real>>x.imag);
}


};

Numar_complex::Numar_complex()
{
    real=0;
    imag=0;
}

Numar_complex::Numar_complex(double Real,double Imag)
{
    real=Real;
    imag=Imag;
}

Numar_complex::Numar_complex (Numar_complex& x)
{
     real=x.real;
     imag=x.imag;
}

 Numar_complex:: ~Numar_complex()
{

}

Numar_complex operator+ (const Numar_complex &x,const Numar_complex &y)
{
    Numar_complex z;
    z.real=x.real+y.real;
    z.imag=x.imag+y.imag;
    return z;
}

 Numar_complex operator- (const Numar_complex &x,const Numar_complex &y)
{
    Numar_complex z;
    z.real=x.real-y.real;
    z.imag=x.imag-y.imag;
    return z;
}
Numar_complex operator- (const Numar_complex &x)
{
    Numar_complex z;
    z.real=-1*x.real;
    z.imag=-1*x.imag;
    return z;
}

Numar_complex operator* (const Numar_complex &x,const Numar_complex &y)
{
    Numar_complex z;
    z.real=x.real*y.real;
    z.imag=x.imag*y.imag;
    return z;
}

Numar_complex operator* (const Numar_complex &x,const double &y)
{
    Numar_complex z;
    z.real=x.real*y;
    z.imag=x.imag*y;
    return z;
}

Numar_complex operator/ (const Numar_complex &x,const Numar_complex &y)
{
    Numar_complex z;
    if(y.real!=0)
    z.real=x.real/y.real;
    if(y.imag!=0)
    z.imag=x.imag/y.imag;
    return z;
}

Numar_complex operator+= (Numar_complex &x,const Numar_complex &y)
{
    Numar_complex z;
    z.real=x.real+y.real;
    z.imag=x.imag+y.imag;
    return z;
}
Numar_complex operator-= (Numar_complex &x,const Numar_complex &y)
{
    Numar_complex z;
    z.real=x.real-y.real;
    z.imag=x.imag-y.imag;
    return (x=z);
}


Numar_complex operator*= (Numar_complex &x,const Numar_complex &y)
{
    Numar_complex z;
    z.real=x.real*y.real;
    z.imag=x.imag*y.imag;
    return (x=z);
}


Numar_complex operator^ (const Numar_complex &x,const double &y)
{
    Numar_complex z;
    z.real=x.real;
    z.imag=x.imag;
    double ys=y-1;
    while(ys)
    {z.real=z.real*x.real;
    z.imag=z.imag*x.imag;
    ys--;}

    return z;
}

bool operator== (Numar_complex &x,Numar_complex &y)
{
if(x.real==y.real&&x.imag==y.imag) return true;
else return false;
}

bool operator!= (Numar_complex &x,Numar_complex &y)
{
if(x.real==y.real&&x.imag==y.imag) return false;
else return true;
}

double Abs(Numar_complex &x)
{
    return sqrt(x.real*x.real+x.imag*x.imag);
}

Numar_complex Sqrt(Numar_complex &x)
{

double p1,p2,sn;

p1=sqrt((x.real+Abs(x))/2);


    if(x.imag<0) sn= -1;
    else if(x.imag==0) sn=0;
    else  sn=1;

p2=sn*sqrt((-x.real+Abs(x))/2);
Numar_complex r1(p1,p2);

return r1;

}




int main()
{Numar_complex a,b,c,x1,x2,delta;

    cin>>a>>b>>c;



delta=b*2-a*c*4;
x1=(-b+Sqrt(delta))/a*2;
x2=(-b-Sqrt(delta))/a*2;


x1.afisare();
x2.afisare();

}


