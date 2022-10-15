#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD=1000000007;

ll expow(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b%2==1)
            ans=(ll)ans*a%MOD;
        a=(ll)a*a%MOD;
        b/=2;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    ll ans=expow(3,3*n)-expow(7,n);
    if(ans<0)
        ans+=MOD;
    cout<<ans<<"\n";
    return 0;
}