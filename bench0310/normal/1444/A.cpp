#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll fpow(ll b,ll e)
{
    ll res=1;
    while(e)
    {
        if(e&1) res=(res*b);
        b=(b*b);
        e/=2;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll p,q;
        cin >> p >> q;
        ll res=1;
        vector<array<ll,2>> a,b;
        ll x=q;
        ll y=p;
        for(ll i=2;i*i<=x;i++)
        {
            if((x%i)!=0) continue;
            a.push_back({i,0});
            b.push_back({i,0});
            while((x%i)==0)
            {
                a.back()[1]++;
                x/=i;
            }
            while((y%i)==0)
            {
                b.back()[1]++;
                y/=i;
            }
        }
        if(x>1)
        {
            a.push_back({x,1});
            b.push_back({x,0});
            while((y%x)==0)
            {
                b.back()[1]++;
                y/=x;
            }
        }
        for(int i=0;i<(int)a.size();i++)
        {
            auto [prime,c]=a[i];
            ll d=b[i][1];
            res=max(res,p/fpow(prime,d)*fpow(prime,min(d,c-1)));
        }
        cout << res << "\n";
    }
    return 0;
}