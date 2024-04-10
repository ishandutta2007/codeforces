#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

const int MOD = 998244353, R = 3, IR = (MOD+1)/R;
const int K = 1<<15;

inline int bpow(int a, int b){
    int res = 1;
    while(b){
        if(b&1) res = 1ll*res*a%MOD;
        a= 1ll*a*a%MOD;
        b >>= 1;
    }
    return res;
}

inline int inv(int a){return bpow(a, MOD-2);}

inline void ntt(vector<int>&a, bool invert){
    int n = a.size();
    for(int i = 1, j = 0; i<n; ++i){
        int bit = n>>1;
        for(; j&bit; bit>>=1) j^=bit;
        j^=bit;
        if(i<j) swap(a[i], a[j]);
    }

    for(int len = 2; len<=n; len <<= 1){
        int wlen = bpow(invert?IR:R, (MOD-1)/len);
        vector<int> rts(len>>1); rts[0] = 1;
        for(int i = 1; i<(len>>1); ++i)
            rts[i] = 1ll*rts[i-1]*wlen%MOD;
        for(int i = 0; i<n; i+=len){
            for(int j = 0; j<(len>>1); ++j){
                int u = a[i+j], v = 1ll*a[i+j+(len>>1)]*rts[j]%MOD;
                a[i+j] = (u+v>=MOD?u+v-MOD:u+v);
                a[i+j+(len>>1)] = (u-v<0?u-v+MOD:u-v);
            }
        }
    }
    if(invert){
        int n1 = inv(n);
        for(int &x : a) x = 1ll*x*n1%MOD;
    }
}

inline vector<int> operator * (const vector<int>&a, const vector<int>&b){
    if(a.empty() || b.empty()) return {0};
    vector<int> na = a, nb = b;
    int n = 1;
    while(n < a.size()+b.size()) n <<= 1;
    na.resize(n); nb.resize(n);
    ntt(na, 0); ntt(nb, 0);
    for(int i = 0; i<n; ++i)
        na[i] =  1ll*na[i]*nb[i]%MOD;
    ntt(na, 1);
    na.resize(min((int)a.size()+(int)b.size()-1, K));
    return na;
}

inline void operator *= (vector<int>&a, const vector<int>&b){a = a*b;}

inline vector<int> operator + (const vector<int>&a, const vector<int>&b){
    vector<int> res = a;
    if(b.size() > a.size()) res.resize(b.size());
    for(int i = 0; i<b.size(); ++i)
        res[i] = (res[i]+b[i]>=MOD?res[i]+b[i]-MOD:res[i]+b[i]);
    return res;
}

inline void operator += (vector<int>&a, const vector<int>&b){a=a+b;}

struct mat{
    vector<int> a[2][2];
    inline mat operator * (const mat& o) const{
        mat res;
        for(int i = 0; i<2; ++i)
            for(int j = 0; j<2; ++j)
                for(int k = 0; k<2; ++k)
                    res.a[i][j] += a[i][k]*o.a[k][j];
        return res;
    }
} ans;

inline mat mpow(mat a, int b){
    mat res = a; --b;
    while(b){
        if(b&1) res = res*a;
        a = a*a;
        b >>= 1;
    }
    return res;
}

int n, k;

int main(){
    scanf("%d %d", &n, &k);
    ans.a[0][0] = {1, 1}, ans.a[0][1] = {0, 1}, ans.a[1][0] = {1};
    ans = mpow(ans, n);
    vector<int> res = ans.a[1][0]*vector<int>{1, 1}+ans.a[1][1];
    for(int i = 1; i<=k; ++i)
        printf("%d ", (i>n?0:res[i]));
}