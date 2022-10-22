#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
    int N, M;
    cin >> N >> M;
    string a;
    cin >> a;
    int mix = 1, max1 = 1, miy = 1, may = 1;
    int x = 1, y = 1;
    int ansx = 1, ansy = 1;
    for (char p : a) {
        ansy = 2 - miy;
        ansx = 2 - mix;

        if (p == 'L') x--;
        if (p == 'R') x++;
        if (p == 'U') y--;
        if (p == 'D') y++;
        mix = min(mix, x);
        miy = min(miy, y);
        max1 = max(max1, x);
        may = max(may, y);

        // cout << "pos: " << x << " " << y << endl;
        if (max1 - mix >= M || may - miy >= N) {
            cout << ansy << " " << ansx << endl;
            return ;
        }
    }
    ansy = 2 - miy;
    ansx = 2 - mix;
    cout << ansy << " " << ansx << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}