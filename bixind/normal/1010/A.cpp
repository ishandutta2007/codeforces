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

void solve(istream &cin = cin, ostream &cout = cout) {
    ld ans = 0;
    int m, n;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (b[i] == 1) {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        ans += (m + ans) / (b[(i + 1) % n] - 1);
        ans += (m + ans) / (a[i] - 1);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);

    solve();
    return 0;
}