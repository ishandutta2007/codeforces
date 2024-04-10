#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll n,m;
ll g;

ll ct(ll x,ll y)
{
        ll val;
        if(x==1)
                val=n;
        else
                val=m;
        val/=g;
        return (y-1)/val;
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
       /// freopen("__input__","r",stdin);

        cin>>n>>m;
        g=__gcd(n,m);
        int q;
        cin>>q;
        while(q--)
        {
                ll x1,y1,x2,y2;
                cin>>x1>>y1>>x2>>y2;
                ll a=ct(x1,y1);
                ll b=ct(x2,y2);
                if(a==b)
                        cout<<"YES\n";
                else
                        cout<<"NO\n";
        }

        return 0;
}
/**

**/