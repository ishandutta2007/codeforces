

//
// Created by calabash_boy on 18-7-6.
//
#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB(x) push_back(x)
#define debug(x) cerr<<"[debug] "<<#x<<":"<<x<<endl;
typedef long long LL;

const int maxn = 1e6+100;
const int MOD = 1e9+7;
typedef long long ll;
const int mod = 998244353, inv_2 = mod+1>>1;
int n, K;
inline void add(int &a, int b) {
    a += b;
    a%=mod;
}

inline int mul(ll a, int b) {
    a *= b;
    return a < mod? a: a - a / mod * mod;
}

const int N = 500+12;
int dp[2][N][N];
void init(){
    memset(dp, 0, sizeof(dp));
    dp[1][1][1] = 2;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k <= i; k++) {
                add(dp[(i&1)][max(j, k + 1)][k + 1], dp[(i&1) ^ 1][j][k]);
                add(dp[(i&1)][j][1], dp[(i&1) ^ 1][j][k]);
            }
        }
        memset(dp[(i&1)^1],0,sizeof(dp[0]));
    }
}
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
void solve(){
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (mul(i, j) < K) {
                int l = 0, r = 0;
                for (int k = 1; k <= n; k++) {
                    add(l, dp[n % 2][i][k]);
                    add(r, dp[n % 2][j][k]);
                }
                add(ans, mul(inv_2, mul(l, r)));
            }
        }
    }
    cout << ans << '\n';
}
int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#endif
    while (cin >> n >> K) {
        init();
        solve();
    }
    return 0;
}