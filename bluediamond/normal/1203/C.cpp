#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{

        bool ishome=0;

        if(ishome)
        {
                freopen("__input__","r",stdin);
        }
        else
        {
                ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        }

        int n;
        cin>>n;
        ll g=0;
        for(int i=1;i<=n;i++)
        {
                ll x;
                cin>>x;
                g=__gcd(g,x);
        }

        int cnt=0;
        for(ll d=1;d*d<=g;d++)
        {
                if(g%d==0)
                {
                        cnt++;
                        if(d*d==g)
                                break;
                        cnt++;
                }
        }

        cout<<cnt<<"\n";

        return 0;
}