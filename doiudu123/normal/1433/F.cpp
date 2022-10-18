#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pdd pair<ld,ld>
typedef long double ld;
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 1001, logN = 17, K = 500;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, tmp;
    cin >> n >> m >> k;
    int mx[n][k];
    fop (t,0,n) {
        fop (i,0,k) mx[t][i] = -1 << 30;
        int dp[m + 1][k];
        fop (i,0,m + 1) fop (j,0,k) dp[i][j] = -1;
        dp[0][0] = 0;
        fop (i,0,m) {
            cin >> tmp;
            FOP (j,m,0) {
                fop (ii,0,k) if (dp[j][ii] != -1) {
                    dp[j + 1][(ii + tmp) % k] = max(dp[j + 1][(ii + tmp) % k], dp[j][ii] + tmp);
                }
            }
        }
        fop (i,0,m / 2 + 1) fop (j,0,k) if (dp[i][j] != -1) {
            mx[t][j] = max(mx[t][j], dp[i][j]);
        }
    }
    vector <int> dp(k, -1);
    dp[0] = 0;
    fop (i,0,n) {
        vector <int> cur(k, -1);
        fop (j,0,k) if (dp[j] >= 0) {
            fop (ii,0,k) if (mx[i][ii] >= 0) {
                cur[(dp[j] + mx[i][ii]) % k] = max(cur[(dp[j] + mx[i][ii]) % k], dp[j] + mx[i][ii]);
            }
        }
        swap(dp, cur);
    }
    cout << dp[0] << endl;
}