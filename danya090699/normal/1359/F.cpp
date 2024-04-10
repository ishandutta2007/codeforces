#include <bits/stdc++.h>
//#define double long double
using namespace std;
const double eps=1e-10;
struct seg
{
    double xl, yl, xr, yr;

    double y(double x) const
    {
        if(abs(xr-xl)<eps) return yl;
        else return yl+(x-xl)*(yr-yl)/(xr-xl);
    }

    bool operator < (const seg &s) const
    {
        double x=max(xl, s.xl);
        return y(x)<s.y(x);
    }
};
bool intersect(const seg &s1, const seg &s2)
{
    double xl=max(s1.xl, s2.xl), xr=min(s1.xr, s2.xr);
    double yl1=s1.y(xl), yl2=s2.y(xl), yr1=s1.y(xr), yr2=s2.y(xr);

    if(yl1>yl2) swap(yl1, yl2), swap(yr1, yr2);

    return (yl2-yl1<eps or yr2-yr1<eps);
}
struct event
{
    double x;
    int ty, nu;

    bool operator < (event &ev)
    {
        return x<ev.x;
    }
};
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int x[n], y[n];
    double vx[n], vy[n];
    for(int a=0; a<n; a++)
    {
        int dx, dy, s;
        scanf("%d%d%d%d%d", &x[a], &y[a], &dx, &dy, &s);
        double k=s/sqrt(dx*dx+dy*dy);
        vx[a]=dx*k, vy[a]=dy*k;
    }
    double l=0, r=1e10;
    bool fo=0;
    for(int i=0; i<60; i++)
    {
        double mid=(l+r)/2;
        event sp[n*2];
        seg ar[n];
        set <seg> se;
        set <seg>::iterator ptr[n];
        for(int a=0; a<n; a++)
        {
            ar[a]={x[a], y[a], x[a]+vx[a]*mid, y[a]+vy[a]*mid};
            if(ar[a].xl>ar[a].xr)
            {
                swap(ar[a].xl, ar[a].xr);
                swap(ar[a].yl, ar[a].yr);
            }
            sp[a]={ar[a].xl, 1, a}, sp[a+n]={ar[a].xr, -1, a};
        }
        sort(sp, sp+n*2);
        bool ok=0;
        for(int a=0; a<n*2; a++)
        {
            if(sp[a].ty==1)
            {
                auto it=se.lower_bound(ar[sp[a].nu]);
                if(it!=se.end() and intersect(*it, ar[sp[a].nu]))
                {
                    ok=1;
                    break;
                }
                if(it!=se.begin() and intersect(*(--it), ar[sp[a].nu]))
                {
                    ok=1;
                    break;
                }

                ptr[sp[a].nu]=se.insert(ar[sp[a].nu]).first;
            }
            else
            {
                auto it=ptr[sp[a].nu];
                it++;

                se.erase(ptr[sp[a].nu]);

                if(it!=se.begin() and it!=se.end())
                {
                    seg s1=(*it);
                    it--;
                    seg s2=(*it);
                    if(intersect(s1, s2))
                    {
                        ok=1;
                        break;
                    }
                }
            }
        }
        if(ok) fo=1, r=mid;
        else l=mid;
    }
    if(fo) cout<<fixed<<setprecision(10)<<r;
    else cout<<"No show :(";
}