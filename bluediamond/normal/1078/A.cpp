#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ld a,b,c;

struct point
{
    ld x;
    ld y;
};

point p1;
point p2;

ld gty(ld x)
{
    return -(c+a*x)/b;
}

ld gtx(ld y)
{
    return -(c+b*y)/a;
}

inline ld dist(point p1,point p2)
{
    ld dx=p1.x-p2.x;
    ld dy=p1.y-p2.y;
    return sqrt(dx*dx+dy*dy);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>a>>b>>c;
    cin>>p1.x>>p1.y>>p2.x>>p2.y;
    ld ans=abs(p1.x-p2.x)+abs(p1.y-p2.y);
    for(int a=0;a<=1;a++)
    {
        for(int b=0;b<=1;b++)
        {
            point f,s;
            if(a==0)
            {
                f={p1.x,gty(p1.x)};
            }
            else
            {
                f={gtx(p1.y),p1.y};
            }
            if(b==0)
            {
                s={p2.x,gty(p2.x)};
            }
            else
            {
                s={gtx(p2.y),p2.y};
            }
            ans=min(ans,dist(p1,f)+dist(f,s)+dist(s,p2));
        }
    }
    cout<<fixed<<setprecision(6)<<ans<<"\n";
    return 0;
}