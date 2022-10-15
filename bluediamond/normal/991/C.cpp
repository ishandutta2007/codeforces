#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll n;

ll f(ll k)
{
    if(k==0)
        return 0;
    ll am=n;
    ll cnt1=0;
    ll cnt2=0;
    ll p=0;
    while(am)
    {
        p++;
        if(p%2==1)
        {
            ll t=min(am,k);
            cnt1+=t;
            am-=t;
        }
        else
        {
            ll val=am/10;
            cnt2+=val;
            am-=val;
        }
    }
   /// cout<<cnt1<<" "<<cnt2<<"\n";
    if(cnt1>=cnt2)
        return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    ll r=-1,pas=(1LL<<60);
    while(pas)
    {
        if(f(r+pas)==0)
            r+=pas;
        pas/=2;
    }
    r++;
    cout<<r<<"\n";
    return 0;
}
/**

1000000000000000000

5

**/