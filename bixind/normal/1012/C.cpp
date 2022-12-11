#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <queue>
#include <assert.h>
#include <functional>
#include <complex>
#include <unordered_map>
#include <iomanip>
#include <numeric>

using namespace std;

typedef long long ll;
typedef long double ld;

const long double PI = 3.141592653589793;
const int INF = 2e9 + 10;
const ll LONGINF = 4e18;
const ll INF2 = 1e17 + 10;
const ll mod = 1e9 + 7;

int d[5010][5010], md[5010][5010];

void solve(istream &cin = cin, ostream &cout = cout) {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            d[i][j] = INF;
            md[i][j] = INF;
        }
    }
    d[0][1] = 0;
    md[0][1] = max(0, a[1] + 1 - a[0]);
    for (int i = 1; i < n; ++i) {
        d[i][1] = max(0, a[i - 1] - a[i] + 1);
        md[i][1] = d[i][1] + max(0, a[i + 1] + 1 - a[i]);
    }
    for (int i = 1; i < n; ++i) {
        md[i][1] = min(md[i][1], md[i - 1][1]);
    }
    for (int i = 2; i < n; ++i) {
        for (int j = 2; j <= n; ++j) {
            d[i][j] = min(d[i][j], d[i - 2][j - 1] + max(0, a[i - 1] + 1 - min(a[i], a[i - 2])));
            if (i > 2) {
                d[i][j] = min(d[i][j], max(0, a[i - 1] + 1 - a[i]) + md[i - 3][j - 1]);
            }
            md[i][j] = min(md[i][j], d[i][j] + max(0, a[i + 1] + 1 - a[i]));
            md[i][j] = min(md[i][j], md[i - 1][j]);
        }
    }
    
    for (int i = 1; i <= n / 2 + n % 2; ++i) {
        int ans = md[0][i];
        for (int j = 1; j < n; ++j) {
            ans = min(ans, md[j][i]);
        }
        cout << ans << ' ';
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);

    solve();
    return 0;
}