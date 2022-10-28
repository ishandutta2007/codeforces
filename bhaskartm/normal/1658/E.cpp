#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
bool f[N][N];
int l, r, u, d, n, k;
vector<array<int, 5>> v;

bool check(int i, int j) {
    return (abs(i - u) <= k && abs(i - d) <= k && abs(j - l) <= k && abs(j - r) <= k);
}

void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            f[i][j] = false;
            int x; cin >> x;
            v.push_back({x, i, j, i + j, j - i});
        }
    }

    sort(v.begin(), v.end(), greater<array<int, 5>>());
    l = v[0][4], r = v[0][4], u = v[0][3], d = v[0][3];
    for (array<int, 5> cell: v) {
        if (check(cell[3], cell[4])) {
            f[cell[1]][cell[2]] = true;
            l = min(l, cell[4]);
            r = max(r, cell[4]);
            u = min(u, cell[3]);
            d = max(d, cell[3]);
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (f[i][j]) cout << 'M';
            else cout << 'G';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}