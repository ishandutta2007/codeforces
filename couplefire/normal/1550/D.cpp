#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int MOD = 1e9+7;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int bpow(int a, int b){
    int res = 1;
    while(b){
        if(b&1) grow(res, a);
        grow(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int a){return bpow(a, MOD-2);}

int fact[N], ifact[N];

void pcalc(){
    fact[0] = 1;
    for(int i = 1; i<N; i++)
        fact[i] = mul(fact[i-1], i);
    for(int i = 0; i<N; i++)
        ifact[i] = inv(fact[i]);
}

int comb(int a, int b){
    if(a < 0 || b < 0 || b > a) return 0;
    return mul(fact[a], mul(ifact[b], ifact[a-b]));
}

void solve(){
    int n, l, r; cin >> n >> l >> r;
    int ans = 0;
    int up_end = r-n, down_end = -(l-1);
    if(n%2) inc(ans, mul(min(up_end, down_end)%MOD, mul(2, comb(n, n/2))));
    else inc(ans, mul(min(up_end, down_end)%MOD, comb(n, n/2)));
    for(int i = min(up_end, down_end)+1; ; i++){
        int up_r = n-max(0, i-up_end), down_l = 1+max(0, i-down_end);
        if(up_r <= 0 || down_l > n) break;
        int tot = up_r-down_l+1;
        int bad = down_l-1;
        if(n%2) inc(ans, add(comb(tot, n/2-bad), comb(tot, n/2+1-bad)));
        else inc(ans, comb(tot, n/2-bad));
    }
    cout << ans << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    pcalc();
    int t; cin >> t;
    while(t--) solve();
}