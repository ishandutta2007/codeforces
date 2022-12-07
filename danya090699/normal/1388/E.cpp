#include <bits/stdc++.h>
using namespace std;
const int sz=2e3+10;
int l[sz], r[sz], h[sz];
struct event
{
    int vx, vy;
    int a, b, add;
};
long long s(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return 1ll*(x2-x1)*(y2+y1)+1ll*(x3-x2)*(y3+y2)+1ll*(x1-x3)*(y1+y3);
}
bool comp(event &a, event &b)
{
    long long x=1ll*b.vx*a.vy-1ll*a.vx*b.vy;

    if(x!=0) return x<0;
    else return a.add>b.add;
}
bool comp2(int a, int b)
{
    if(h[a]!=h[b]) return h[a]>h[b];
    else return l[a]<l[b];
}
double f(int x, int y, int vx, int vy)
{
    return x+1.0*y*vx/(-vy);
}
bool comp3(int x1, int y1, int x2, int y2, int vx, int vy)
{
    long long S=s(x1, y1, x2, y2, x1+vx, y1+vy);
    if(S!=0) return S>0;
    else return y1<y2;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ot[n];
    for(int a=0; a<n; a++)
    {
        cin>>l[a]>>r[a]>>h[a];
        ot[a]=a;
    }
    sort(ot, ot+n, comp2);

    vector <event> sp;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++)
        {
            if(h[a]>h[b])
            {
                sp.push_back({l[b]-r[a], h[b]-h[a], a, b, -1});
                sp.push_back({r[b]-l[a], h[b]-h[a], a, b, 1});
            }
        }
    }
    if(sp.size())
    {
        sort(sp.begin(), sp.end(), comp);
        int q=n, ll=ot[0], rr=ot[n-1];
        double an=1e18;
        for(int a=0; a<sp.size(); a++)
        {
            int vx=sp[a].vx, vy=sp[a].vy;

            if(q==n)
            {
                an=min(an, f(r[rr], h[rr], vx, vy)-f(l[ll], h[ll], vx, vy));
            }

            q+=sp[a].add;

            if(sp[a].add==1)
            {
                int u=sp[a].a, v=sp[a].b;
                if(ll!=v and comp3(l[v], h[v], l[ll], h[ll], vx, vy)) ll=v;

                if(rr!=u and comp3(l[rr], h[rr], l[u], h[u], vx, vy)) rr=u;
            }

            if(q==n)
            {
                an=min(an, f(r[rr], h[rr], vx, vy)-f(l[ll], h[ll], vx, vy));
            }
        }
        cout<<fixed<<setprecision(10)<<an;
    }
    else cout<<r[ot[n-1]]-l[ot[0]];
}