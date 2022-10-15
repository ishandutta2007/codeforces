#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll prefix(ll n)
{
        ll r=0;
        for(int b=0;(1LL<<b)<=n;b++)
                r+=(((n/(2*(1LL<<b)))*(1LL<<b)+((n%(2*(1LL<<b)))>=(1LL<<b))*((n%(2*(1LL<<b)))-(1LL<<b)+1))%2==1)*(1LL<<b);
        return r;
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int n;
        ll x=0;
        cin>>n;
        while(n--)
        {
                ll l,r;
                cin>>l>>r;
                l--;
                r+=l;
                x^=prefix(r);
                x^=prefix(l);
        }
        if(x)
                cout<<"t";
        else
                cout<<"b";
        cout<<"olik\n";
        return 0;
}