#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, x1, y1, x2, y2;
    double inf=1e18, eps=1e-11, l=0, r=1e19;
    cin>>n>>x1>>y1>>x2>>y2;
    for(int a=0; a<n; a++)
    {
        int x, y, vx, vy;
        scanf("%lld%lld%lld%lld", &x, &y, &vx, &vy);
        double mi=1e19, ma=-1, ti, x3, y3;
        if(x>x1 and x<x2 and y>y1 and y<y2) mi=0;
        if(vx==0 and vy==0) ma=inf;
        if(vy!=0)
        {
            ti=1.0*(y1-y)/vy;
            if(ti>-eps)
            {
                x3=x+ti*vx;
                if(x3>x1+eps and x3<x2-eps)
                {
                    mi=min(mi, ti), ma=max(ma, ti);
                }
                if(abs(x3-x1)<eps)
                {
                    if(vx*vy>0)
                    {
                        mi=min(mi, ti), ma=max(ma, ti);
                    }
                }
                if(abs(x3-x2)<eps)
                {
                    if(vx*vy<0)
                    {
                        mi=min(mi, ti), ma=max(ma, ti);
                    }
                }
            }
            ti=1.0*(y2-y)/vy;
            if(ti>-eps)
            {
                x3=x+ti*vx;
                if(x3>x1+eps and x3<x2-eps)
                {
                    mi=min(mi, ti), ma=max(ma, ti);
                }
                if(abs(x3-x1)<eps)
                {
                    if(vx*vy<0)
                    {
                        mi=min(mi, ti), ma=max(ma, ti);
                    }
                }
                if(abs(x3-x2)<eps)
                {
                    if(vx*vy>0)
                    {
                        mi=min(mi, ti), ma=max(ma, ti);
                    }
                }
            }
        }
        if(vx!=0)
        {
            ti=1.0*(x1-x)/vx;
            if(ti>-eps)
            {
                y3=y+ti*vy;
                if(y3>y1+eps and y3<y2-eps)
                {
                    mi=min(mi, ti), ma=max(ma, ti);
                }
            }
            ti=1.0*(x2-x)/vx;
            if(ti>-eps)
            {
                y3=y+ti*vy;
                if(y3>y1+eps and y3<y2-eps)
                {
                    mi=min(mi, ti), ma=max(ma, ti);
                }
            }
        }
        if(ma-mi>eps)
        {
            l=max(l, mi), r=min(r, ma);
        }
        else r=-1;
    }
    if(r-l>eps) cout<<fixed<<setprecision(10)<<l;
    else cout<<-1;
}