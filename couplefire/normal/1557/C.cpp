#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1000000007;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int bpow(int a, int b){
    int res = 1;
    for(; b; grow(a, a), b>>=1)
        if(b&1) grow(res, a);
    return res;
}

void solve(){
    int n, k; cin >> n >> k;
    if(n%2) return void(cout << bpow(add(bpow(2, n-1), 1), k) << '\n');
    int res = 0, tmp = 1;
    for(int i = 0; i<k; ++i){
        inc(res, mul(tmp, bpow(2, (k-i-1)*n)));
        grow(tmp, sub(bpow(2, n-1), 1));
    }
    inc(res, tmp);
    cout << res << '\n';
}

signed main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}