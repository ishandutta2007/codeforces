#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> stlb(m), strk(m);
    int res = 0;
    int lastone = n * m + 300;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            lastone++;
            if ( s[i * m + j] == '1')
                lastone = 0;
            if (stlb[j] == 0 and s[i * m + j] == '1') {
                res++;
                stlb[j] = 1;
            }
            strk[j] = strk[j] + (lastone < m);
            cout << res + strk[j] << ' ';
        }
    }
    cout << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}