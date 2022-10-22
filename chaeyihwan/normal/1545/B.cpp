#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 998244353;

ll inv(ll x)
{
    ll ans = 1; int k = 0;
    while((1LL << k) <= mod - 2)
    {
        if((1LL << k) & (mod - 2))
        {
            ans *= x;
            ans %= mod;
        }
        x *= x;
        x %= mod;
        k++;
    }
    return ans;
}

ll fact[100002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    fact[0] = 1;
    for(int i=1;i<=100000;i++)
    {
        fact[i] = (fact[i-1] * i)%mod;
    }
    while(t--){
        int n; string s;
        cin >> n >> s;
        int c0 = 0, c1 = 0, now = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '0')
            {
                c1 += now/2;
                now = 0;
                c0++;
            }
            else now++;
        }
        c1 += now/2;
        ll ans = fact[c1+c0];
        ans *= inv(fact[c1]);
        ans %= mod;
        ans *= inv(fact[c0]);
        ans %= mod;

        cout << ans << "\n";
    }
}