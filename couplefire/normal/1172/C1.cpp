#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int M = 3005;
const int MOD = 998244353;

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int bpow(int a, int b, int res = 1){
    for(; b; grow(a, a), b>>=1)
        if(b&1) grow(res, a); return res;
}

int inv(int a){return bpow(a, MOD-2);}

int n, m, w[N], g[N], dp[M][M], s1, s2, p1[M], p2[M], v1, v2;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i<=n; ++i)
        cin >> g[i];
    for(int i = 1; i<=n; ++i)
        cin >> w[i];
    for(int i = 1; i<=n; ++i)
        if(g[i]) s1 += w[i];
        else s2 += w[i];
    p1[0] = p2[0] = 1;
    for(int i = 1, t1 = s1; i<=m; ++i)
        p1[i] = mul(p1[i-1], add(1, inv(t1))), inc(t1, 1);
    for(int i = 1, t2 = s2; i<=m; ++i)
        p2[i] = mul(p2[i-1], sub(1, inv(t2))), dec(t2, 1);
    dp[0][0] = 1;
    for(int i = 1; i<=m; ++i)
        for(int j = 0; j<=i; ++j){
            int x1 = sub(s2, sub(i-1, j)), x2 = add(s1, sub(j, 1));
            int y1 = inv(add(s1+s2, sub(2*j, i-1))), y2 = inv(add(s1+s2, sub(2*j, i+1)));
            if(j<i) inc(dp[i][j],  mul(dp[i-1][j], mul(x1, y1)));
            if(j) inc(dp[i][j], mul(dp[i-1][j-1], mul(x2, y2)));
        }
    for(int i = 0; i<=m; ++i)
        inc(v1, mul(dp[m][i], p1[i])), inc(v2, mul(dp[m][i], p2[m-i]));
    for(int i = 1; i<=n; ++i)
        cout << mul(w[i], g[i]?v1:v2) << '\n';
}