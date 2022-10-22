#include <iostream>

using namespace std;
typedef long long ll;
const ll mod = 998244353;

int a[200002], inva[200002];
ll fac[200002], ifac[200002];

ll inv(ll x)
{
    int k = 0; ll ans = 1;
    while((1LL << k) <= (mod-2))
    {
        if((1LL << k) & (mod-2))
        {
            ans = (ans * x)%mod;
        }
        x = (x * x)%mod;
        k++;
    }
    return ans;
}

ll comb(ll n, ll k)
{
    if(k > n) return 0;
    ll ans = fac[n];
    ans = (ans * ifac[k])%mod;
    ans = (ans * ifac[n-k])%mod;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        inva[a[i]] = i;
    }
    a[n] = -1;
    int cnt = 0;
    for(int i=0;i<n;i++) swap(a[i], inva[i]);
    for(int i=1;i<n;i++)
    {
        if(a[inva[i-1]+1] < a[inva[i]+1]) cnt++;
    }

    fac[0] = 1;
    for(int i=1;i<=200000;i++) fac[i] = (fac[i-1] * i)%mod;
    ifac[200000] = inv(fac[200000]);
    for(int i=199999;i>0;i--) ifac[i] = (ifac[i+1] * (i+1))%mod;
    ifac[0] = 1;

    ll ans = 0;
    for(int i=0;i<=cnt;i++)
    {
        ll tmp = comb(k, n-i) * comb(cnt, i);
        tmp %= mod;
        ans = (ans + tmp)%mod;
    }

    cout << ans;
}