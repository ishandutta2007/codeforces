#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    double z,vx,vy,vz,a,b,m,t,dt;
    long long tmp;
    cin >> a >> b >> m >> vx >> vy >> vz;
    t = m/fabs(vy);
    
    cout << setprecision(10);
    
    if (vx==0.0)
       cout << a/2.0;
    else
    {
        dt = a/2.0/fabs(vx);
        tmp = (long long)(t/dt);
        dt = t-tmp*dt;
        tmp %= 4;
        if (tmp==0)
           cout << a/2.0 + dt*vx;
        else
        if (tmp==2)
           cout << a/2.0 - dt*vx;
        else
        if (tmp==1 && vx>0.0 || tmp==3 && vx<0.0)
           cout << a - dt*fabs(vx);
        else
            cout << dt*fabs(vx);
    }
    
    if (vz==0.0)
       z = 0.0;
    else
    {
        dt = b/vz;
        tmp = (long long)(t/dt);
        z = vz*(t-tmp*dt);    
        if (tmp%2==1)
           z = b-z;
    } 
    cout << " " << z;
    return 0;
}