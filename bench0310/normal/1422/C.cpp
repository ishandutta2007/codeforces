#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const ll mod=1000000007;
    string s;
    cin >> s;
    int n=s.size();
    s="$"+s;
    vector<ll> ten(n,1);
    for(int i=1;i<n;i++) ten[i]=(ten[i-1]*10)%mod;
    ll res=0;
    ll x=0;
    for(int i=n;i>=1;i--)
    {
        int d=(s[i]-'0');
        res=(res+d*x)%mod;
        ll p=((ll)(i-1)*(i)/2)%mod;
        res=(res+d*ten[n-i]*p)%mod;
        x=(x+ten[n-i]*(n-i+1))%mod;
    }
    cout << res << "\n";
    return 0;
}