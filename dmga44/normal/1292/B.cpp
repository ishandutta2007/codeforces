#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;

ll man(ll x0,ll y0,ll x1,ll y1)
{
    return abs(x0-x1)+abs(y0-y1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll x,y,ax,bx,ay,by;
    ll x0,y0,t;
    cin >> x >> y >> ax >> ay >> bx >> by;
    cin >> x0 >> y0 >> t;
    vector<pii> v;
    v.push_back(pii(x,y));
    int p=1;
    while((((1ll<<62)-bx)/ax)>x && (((1ll<<62)-by)/ay>y))
    {
        x*=ax;
        x+=bx;
        y*=ay;
        y+=by;
        v.push_back(pii(x,y));
        p++;
    }

//    for(auto y : v)
//        cout << y.first << ' ' << y.second << '\n';

    ll res=0;
    for(int i=0;i<p;i++)
    {
        if(man(x0,y0,v[i].first,v[i].second)>t)
            continue;

        ll s=1;
        ll cant=man(x0,y0,v[i].first,v[i].second);
        for(int j=i+1;j<p && cant+man(v[j-1].first,v[j-1].second,v[j].first,v[j].second)<=t;j++)
        {
            s++;
            cant+=man(v[j-1].first,v[j-1].second,v[j].first,v[j].second);
        }
        res=max(res,s);

        s=1;
        cant=man(x0,y0,v[i].first,v[i].second);
        for(int j=i-1;j>=0 && cant+man(v[j+1].first,v[j+1].second,v[j].first,v[j].second)<=t;j--)
        {
            s++;
            cant+=man(v[j+1].first,v[j+1].second,v[j].first,v[j].second);
        }
        res=max(res,s);
    }
    db(res)

    return 0;
}