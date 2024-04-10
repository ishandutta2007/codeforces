#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    auto intersectb=[](ll a,ll b,ll c,ll d)->bool{return (max(a,c)<=min(b,d));};
    auto mn=[&](ll a,ll b,ll c,ll d)->ll
    {
        if(intersectb(a,b,c,d)) return 0;
        else return max(a,c)-min(b,d);
    };
    auto mx=[](ll a,ll b,ll c,ll d)->ll
    {
        ll m=0;
        for(ll e:{a,b}) for(ll f:{c,d}) m=max(m,abs(e-f));
        return m;
    };
    while(t--)
    {
        vector<array<ll,2>> v(4);
        for(int i=0;i<4;i++) cin >> v[i][0] >> v[i][1];
        sort(v.begin(),v.end());
        ll res=(1ll<<60);
        do
        {
            vector<ll> x(4,0);
            vector<ll> y(4,0);
            for(int i=0;i<4;i++) tie(x[i],y[i])={v[i][0],v[i][1]};
            ll now=abs(x[0]-x[2])+abs(x[1]-x[3])+abs(y[0]-y[1])+abs(y[2]-y[3]);
            ll x1=mn(min(x[0],x[2]),max(x[0],x[2]),min(x[1],x[3]),max(x[1],x[3]));
            ll x2=mx(min(x[0],x[2]),max(x[0],x[2]),min(x[1],x[3]),max(x[1],x[3]));
            ll y1=mn(min(y[0],y[1]),max(y[0],y[1]),min(y[2],y[3]),max(y[2],y[3]));
            ll y2=mx(min(y[0],y[1]),max(y[0],y[1]),min(y[2],y[3]),max(y[2],y[3]));
            res=min(res,now+2*mn(x1,x2,y1,y2));
            
        }while(next_permutation(v.begin(),v.end()));
        cout << res << "\n";
    }
    return 0;
}