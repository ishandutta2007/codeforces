#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mod ((ll)(1000000007))

ll res(ll x)
{
    ll p=1,r=0;
    ll s[2];
    s[0]=s[1]=0;
    while(x)
    {
        ll pp=min(p,x);
        s[r]+=pp;
        x-=pp;
        p*=2;
        r=1-r;
    }
    ll s1=((s[0]%mod)*(s[0]%mod))%mod;
    ll s2=(((s[1])%mod)*((s[1]+1)%mod))%mod;
    return (s1+s2)%mod;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll l,r;
    cin >> l >> r;
    l--;
    db((res(r)-res(l)+mod)%mod)

    return 0;
}