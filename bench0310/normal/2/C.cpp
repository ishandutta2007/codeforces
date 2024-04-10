#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double x[3],y[3],r[3],t[3];

double close(double dx,double dy)
{
    for(int i=0;i<3;i++) t[i]=sqrt((x[i]-dx)*(x[i]-dx)+(y[i]-dy)*(y[i]-dy))/r[i];
    double o=0;
    for(int i=0;i<3;i++) o+=(t[i]-t[(i+1)%3])*(t[i]-t[(i+1)%3]);
    return o;
}

int main()
{
    for(int i=0;i<3;i++) cin >> x[i] >> y[i] >> r[i];
    double dx=(x[0]+x[1]+x[2])/3.0;
    double dy=(y[0]+y[1]+y[2])/3.0;
    double s;
    for(s=1;s>1e-6;)
    {
        if(close(dx,dy)>close(dx+s,dy)) dx+=s;
        else if(close(dx,dy)>close(dx-s,dy)) dx-=s;
        else if(close(dx,dy)>close(dx,dy+s)) dy+=s;
        else if(close(dx,dy)>close(dx,dy-s)) dy-=s;
        else s*=0.5;
    }
    if(close(dx,dy)<1e-5) cout << fixed << setprecision(5) << dx << " " << dy << endl;
    return 0;
}