#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 200005;
const int M = 16;

inline int add(int a, int b) { return a+b >= MOD ? a+b-MOD : a+b; }
inline int sub(int a, int b) { return a-b<0 ? a-b+MOD : a-b; }
inline int mul(int a, int b) { return 1ll*a*b%MOD; }
inline void inc(int& a, int b) { a = add(a, b); }
inline void dec(int& a, int b) { a = sub(a, b); }
inline void grow(int& a, int b) { a = mul(a, b); }

int d, n, m, q;
int lans[N], pts[M];
int left_val[M], right_val[M], core_val[M][M];
int dp[1<<M], sum_dp[1<<M];

int main() {
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> d >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> lans[i];
    sort(lans, lans+n);
    for (int i = 0; i < m; ++i)
        cin >> pts[i];
    sort(pts, pts+m);
    
    for (int i = 0; i < m; ++i) {
        left_val[i] = 1;
        for (int j = 0; j < n; ++j) {
            if (lans[j] >= pts[i]) 
                break;
            grow(left_val[i], pts[i]-lans[j]);
        }
    }
    for (int i = 0; i < m; ++i) {
        right_val[i] = 1;
        for (int j = n-1; j >= 0; --j) {
            if (lans[j] <= pts[i]) 
                break;
            grow(right_val[i], lans[j]-pts[i]);
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = i+1; j < m; ++j) {
            core_val[i][j] = 1;
            for (int k = 0; k < n; ++k) {
                if (lans[k] >= pts[j]) 
                    break;
                if (lans[k] > pts[i]) 
                    grow(core_val[i][j], min(lans[k]-pts[i], pts[j]-lans[k]));
            }
        }
    }
    dp[0] = 1;
    for (int i = 0; i < n; ++i) 
        grow(dp[0], d+1);
    for (int msk = 1; msk < (1<<m); ++msk) {
        dp[msk] = 1;
        int prv = -1;
        for (int i = 0; i < m; ++i) {
            if (msk&(1<<i)) {
                if (prv == -1)
                    grow(dp[msk], left_val[i]);
                else
                    grow(dp[msk], core_val[prv][i]);
                prv = i;
            }
        }
        grow(dp[msk], right_val[prv]);
        if (__builtin_popcount(msk)&1)
            dp[msk] = MOD-dp[msk];
    }
    for (int i = 0; i < (1<<m); ++i) 
        sum_dp[i] = dp[i];
    for (int i = 0; i < m; ++i) 
        for (int msk = 0; msk < (1<<m); ++msk)
            if (msk&(1<<i))
                inc(sum_dp[msk], sum_dp[msk^(1<<i)]);
    cin >> q;
    while (q--) {
        int f; cin >> f;
        int l = m-1, r = m;
        for (int i = m-1; i >= 0; --i) 
            if (pts[i] > f) 
                l = i-1, r = i;
        int msk = (1<<m)-1, ans = 0;
        while (l >= 0 || r < m) {
            if(r == m || (l >= 0 && f-pts[l] <= pts[r]-f)) {
                inc(ans, mul(f-pts[l], sub(sum_dp[msk], sum_dp[msk^(1<<l)])));
                msk ^= (1<<l); --l;
            } else {
                inc(ans, mul(pts[r]-f, sub(sum_dp[msk], sum_dp[msk^(1<<r)])));
                msk ^= (1<<r); ++r;
            }
        }
        inc(ans, mul(d+1, sum_dp[0]));
        cout << ans << '\n';
    }
}