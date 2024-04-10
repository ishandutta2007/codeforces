// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define fi first
#define se second
#define pb push_back
 
#define ll long long
#define pii pair<int, int>
//#define int ll
const int MOD = 1000000007;

int sqt(ll t) {
    ll ans = 0;
    for(int i=20; i>=0; i--)
        if((ans|(1<<i)) * (ans|(1<<i)) <= t) ans |= (1<<i);
    return ans;
}

ll cl(ll x, ll n) {
    if(x*x > n) return 0;
    ll x2 = x*x%MOD;
    ll x3 = x2*x % MOD;
    ll x4 = x3*x % MOD;
    ll T = sqt(n-x*x);
    ll T2 = T*T % MOD;
    ll T3 = T2*T % MOD;
    ll T4 = T3*T % MOD;
    ll T5 = T4*T % MOD;
    ll T6 = T5*T % MOD;
    n = n % MOD;
    ll n2 = n*n % MOD;
    ll n3 = n2*n % MOD;
    ll ans = 0;
    ans +=35*n3%MOD;
    ans +=105*n2%MOD;
    ll ip = 0;
    ip += 3*T4%MOD;
    ip += 6*T3%MOD;
    ip += T2*(10*x2%MOD-3)%MOD;
    ip += 2*T%MOD*(5*x2%MOD-3)%MOD;
    ip += 5*(3*x4%MOD-3*x2%MOD-2)%MOD;
    ans -= 7*n%MOD*(ip%MOD)%MOD;
    ip = 0;
    ip += 5*T6%MOD;
    ip += 15*T5%MOD;
    ip += T4*(21*x2%MOD-11)%MOD;
    ip += T3*(42*x2%MOD-47)%MOD;
    ip += T2*(35*x4%MOD-56*x2%MOD+6)%MOD;
    ip += T*(35*x4%MOD-77*x2%MOD+32)%MOD;
    ip += 35*x2%MOD*(x4-3*x2%MOD+2)%MOD;
    ans += 2*ip%MOD;
    ans = (2*T+1)*ans%MOD;
    if(ans < 0) ans += MOD;
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long n; cin >> n;
    int ans = 0;
    rep(i, (1<<20)) ans = (ans + (1+!!i)*cl(i, n)) % MOD;
    cout << 1ll * ans *604761909 % MOD;
}