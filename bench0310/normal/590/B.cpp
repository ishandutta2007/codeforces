#include <bits/stdc++.h>

using namespace std;

long double dist(array<long double,2> a,array<long double,2> b)
{
    return sqrt((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    array<long double,2> a,b;
    cin >> a[0] >> a[1] >> b[0] >> b[1];
    long double vmax,t;
    cin >> vmax >> t;
    array<long double,2> v,w;
    cin >> v[0] >> v[1] >> w[0] >> w[1];
    cout << fixed << setprecision(18);
    long double l=0,r=1e18;
    for(int i=0;i<500;i++)
    {
        long double m=(l+r)/2;
        array<long double,2> x=a;
        if(m<=t) x={a[0]+m*v[0],a[1]+m*v[1]};
        else x={a[0]+t*v[0]+(m-t)*w[0],a[1]+t*v[1]+(m-t)*w[1]};
        if(dist(x,b)<=m*vmax) r=m;
        else l=m;
    }
    cout << r << endl;
    return 0;
}