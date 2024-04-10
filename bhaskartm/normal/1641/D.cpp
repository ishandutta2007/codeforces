#include <bits/stdc++.h>
 
#define F first
#define S second
 
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
 
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }
 
const int W = 13;
const int ITER = 100;
const int INF = numeric_limits<int>::max();
 
const uint32_t A = 282'337'73;
const uint32_t B = 123'812'312;
 
void solve() {
    int n, m; cin >> n >> m;
    vector a(n, vector<uint32_t>(m));
    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        for (auto& x : a[i]) cin >> x;
        cin >> w[i];
    }
    int ans = INF;
 
    vector<int> mn(1 << W);
    for (int t = ITER; t--; ) {
        for (auto& u : a) for (auto& x : u) x = A * x + B;
 
        fill(mn.begin(), mn.end(), INF);
        for (int i = 0; i < n; ++i) {
            int msk = 0;
            for (int j = 0; j < m; ++j) {
                msk |= 1 << (a[i][j] % W);
            }
            ckmin(mn[msk], w[i]);
            // cout << bitset<W>(msk) << '\n';
        }
        // cout << '\n';
 
 
        for (int i = 1; i < (1 << W); ++i) {
            for (int j = 0; j < W; ++j) {
                int sm = i ^ (1 << j);
                if (sm < i) {
                    ckmin(mn[i], mn[sm]);
                }
            }
        }
 
        int all_bits = (1 << W) - 1;
        for (int i = 1; (i >> (W - 1)) == 0; ++i) {
            if (mn[i] == INF || mn[all_bits ^ i] == INF) continue;
            ckmin(ans, mn[i] + mn[all_bits ^ i]);
        }
    }
 
    if (ans == INF) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
 
    int t = 1; 
    // cin >> t;
    while (t--) solve();
}