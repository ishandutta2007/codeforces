#include <bits/stdc++.h>
using namespace std;

const int N = 1000006;
const int MOD = 998244353;

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

int inv(int a){return bpow(a, MOD-2);}

int fac[N], ifac[N];

void solve(){
    int n; cin >> n;
    vector<int> tmp_cnt(n, 0), cnt;
    for(int i = 0; i<n; ++i){
        int a; cin >> a;
        --a; ++tmp_cnt[a];
    }
    for(int i = 0; i<n; ++i)
        if(tmp_cnt[i]) cnt.push_back(tmp_cnt[i]);
    int m = cnt.size();
    if((*max_element(cnt.begin(), cnt.end()))==n)
        return cout << 1 << '\n', void();
    int mx_gcd = 0;
    for(int i = 0; i<m; ++i)
        mx_gcd = __gcd(mx_gcd, cnt[i]);
    vector<int> pre_ans(n+1, 0), pre_ways(n+1, 0);
    for(int i = 1; i<=n; ++i){
        if(n%i) continue;
        if(mx_gcd%i) continue;
        int nn = n/i;
        vector<int> ncnt = cnt;
        for(int j = 0; j<m; ++j)
            ncnt[j] /= i;
        int tmp_inv = inv(mul(nn, nn-1));
        for(int j = 0; j<m; ++j)
            inc(pre_ans[i], mul(mul(ncnt[j], nn-ncnt[j]), tmp_inv));
        grow(pre_ans[i], n);
        pre_ways[i] = fac[nn];
        for(int j = 0; j<m; ++j)
            grow(pre_ways[i], ifac[ncnt[j]]);
        grow(pre_ans[i], pre_ways[i]);
    }
    int tot_cnt = 0, tot_val = 0;
    for(int i = 0; i<n; ++i){
        int cur_gcd = n/__gcd(i, n);
        if(mx_gcd%cur_gcd) continue;
        inc(tot_cnt, pre_ways[cur_gcd]);
        inc(tot_val, pre_ans[cur_gcd]);
    }
    cout << mul(tot_val, inv(tot_cnt)) << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    fac[0] = 1;
    for(int i = 1; i<N; ++i)
        fac[i] = mul(fac[i-1], i);
    for(int i = 0; i<N; ++i)
        ifac[i] = inv(fac[i]);
    int t; cin >> t;
    while(t--) solve();
}