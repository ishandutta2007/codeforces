#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll ans=0;

void gcd(ll a,ll b)
{
    if(b==0)
        return;
    ans+=a/b;
    gcd(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll x,y;
    cin>>x>>y;
    gcd(x,y);
    cout<<ans<<"\n";
    return 0;
}
/**

**/