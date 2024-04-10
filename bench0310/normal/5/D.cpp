#include <bits/stdc++.h>

using namespace std;

double a,v,l,d,w,res;

double dist(double speed,double time)
{
    return speed*time+a*time*time/2;
}

double travelTime(double distance,double speed)
{
    double tAll,tMax;
    tAll=(sqrt(2*a*distance+speed*speed)-speed)/a;
    tMax=(v-speed)/a;
    if(tMax>=tAll) return tAll;
    else return tMax+(distance-dist(speed,tMax))/v;
}

int main()
{
    cin >> a >> v >> l >> d >> w;
    if(v<=w) res=travelTime(l,0);
    else
    {
        double tw=w/a;
        double dw=dist(0,tw);
        if(dw>=d) res=travelTime(l,0);
        else res=tw+2*travelTime(0.5*(d-dw),w)+travelTime(l-d,w);
    }
    cout << fixed << setprecision(12) << res << endl;
    return 0;
}