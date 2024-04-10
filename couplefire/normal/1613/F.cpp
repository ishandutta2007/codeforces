#include <bits/stdc++.h>
using namespace std;

const int N = 250005;
const int MOD = 998244353;
const int R = 3;
const int IR = 332748118;

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

void ntt(vector<int>& a, bool inv){
    int n = a.size();
    for(int i = 1, j = 0; i<n; i++){
        int bit = n>>1;
        for(; j&bit; bit>>=1) j^=bit;
        j ^= bit;
        if(i < j) swap(a[i], a[j]);
    }
    for(int len = 2; len<=n; len<<=1){
        int wlen = bpow(inv?IR:R, (MOD-1)/len);
        for(int i = 0; i<n; i+=len){
            int w = 1;
            for(int j = 0; j<len/2; ++j){
                int u = a[i+j], v = mul(a[i+j+len/2], w);
                a[i+j] = add(u, v);
                a[i+j+len/2] = sub(u, v);
                grow(w, wlen);
            }
        }
    }
    if(inv){
        int in = bpow(n, MOD-2);
        for(auto &x : a) grow(x, in);
    }
}

vector<int> multiply(vector<int> a, vector<int> b){
    vector<int> na(a.begin(), a.end()), nb(b.begin(), b.end());
    int n = 1;
    while(n < a.size()+b.size()) n <<= 1;
    na.resize(n), nb.resize(n);
    ntt(na, 0); ntt(nb, 0);
    for(int i = 0; i<n; i++) grow(na[i], nb[i]);
    ntt(na, 1);
    return na;
}

int n, fact[N], deg[N], ans;

vector<int> dnq(int l, int r){
    if(l==r) return {1, deg[l]-(l>0)};
    int m = (l+r)>>1;
    return multiply(dnq(l, m), dnq(m+1, r));
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i<n-1; ++i){
        int u, v; cin >> u >> v; --u; --v;
        ++deg[u]; ++deg[v];
    }
    vector<int> res = dnq(0, n-1);
    fact[0] = 1;
    for(int i = 1; i<=n; ++i)
        fact[i] = mul(fact[i-1], i);
    res.resize(n+1);
    for(int i = 0; i<=n; ++i){
        if(i&1) dec(ans, mul(fact[n-i], res[i]));
        else inc(ans, mul(fact[n-i], res[i]));
    }
    cout << ans << '\n';
}