#include <bits/stdc++.h>
using namespace std;

const int K = 1<<18;
const int MOD = 998244353;
const int R = 3, IR = (MOD+1)/R;

inline int add(int a, int b){return a+b>=MOD?a+b-MOD:a+b;}
inline int sub(int a, int b){return a-b<0?a-b+MOD:a-b;}
inline void inc(int &a, int b){a=add(a, b);}
inline void dec(int &a, int b){a=sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a=mul(a, b);}
inline int norm(int a){return (a%MOD+MOD)%MOD;}

int bpow(int a, int b){
    int res = 1;
    while(b>0){
        if(b&1) grow(res, a);
        grow(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int a){return bpow(a, MOD-2);}

void ntt(int* a, bool iv){
    for(int i = 1, j=0; i<K; i++){
        int bit = K>>1;
        for(; j&bit; bit>>=1) j^=bit;
        j^=bit;
        if(i < j) swap(a[i], a[j]);
    }
    for(int len = 2; len<=K; len <<= 1){
        int wlen = bpow(iv?IR:R, (MOD-1)/len);
        for(int i = 0; i<K; i+=len){
            int w = 1;
            for(int j = 0; j<len/2; j++){
                int u = a[i+j], v = mul(w, a[i+j+len/2]);
                a[i+j] = add(u, v);
                a[i+j+len/2] = sub(u, v);
                grow(w, wlen);
            }
        }
    }
    if(iv){
        int in = inv(K);
        for(int i = 0; i<K; i++) grow(a[i], in);
    }
}

void mult(int* a, int* b, int* res){
    ntt(a, 0); ntt(b, 0);
    for(int i = 0; i<K; i++)
        res[i] = mul(a[i], b[i]);
    ntt(res, 1);
}

int n, k;
int fact[K], s[K], a[K], b[K], ans[K];

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    fact[0] = 1;
    for(int i = 1; i<=k; i++) fact[i] = mul(fact[i-1], i);
    for(int i = 0; i<=k; i++){
        a[i] = inv(fact[i]);
        if(i%2) a[i] = MOD-a[i];
    }
    for(int i = 0; i<=k; i++){
        b[i] = bpow(i, k);
        grow(b[i], inv(fact[i]));
    }
    mult(a, b, s);
    int ans = 0, cur = 1;
    for(int i = 0; i<=k; i++){
        int res = s[i];
        grow(res, cur);
        grow(res, fact[i]);
        grow(res, bpow(norm(n+1), n-i));
        inc(ans, res);
        grow(cur, norm(n-i)); grow(cur, inv(i+1));
    }
    cout << ans << endl;
}