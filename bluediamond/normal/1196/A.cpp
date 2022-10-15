#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define pb push_back

ll calc(ll a,ll b,ll c)
{
        if(a>b)
                swap(a,b);
        ll dif=b-a;
        ll t=min(c,dif);
        c-=t;
        a+=t;
        return a+c/2;
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int q;
        cin>>q;

        while(q--)
        {
                ll a,b,c;
                cin>>a>>b>>c;
                ll r=0;
                r=max(r,calc(a,b,c));
                r=max(r,calc(a,c,b));
                r=max(r,calc(b,a,c));
                r=max(r,calc(b,c,a));
                r=max(r,calc(c,a,b));
                r=max(r,calc(c,b,a));
                cout<<r<<"\n";
        }

        return 0;
}
/**

**/