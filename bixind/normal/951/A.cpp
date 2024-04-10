#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 2e9 + 10;
const ll LONGINF = 4e18;
const ll mod = 1e9 + 7;
const ld PI = 3.141592653589793;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    s = s + s;
    int ans = 1;
    int cur = 1;
    for (int i = 1; i < 2 * n; ++i) {
        if (s[i] != s[i - 1]) {
            ++cur;
        } else {
            cur = 1;
        }
        ans = max(ans, cur);
    }
    ans = min(ans, n);
    cout << ans << endl;
}

int main() {
    iostream::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}