#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define long long long
#define ve vector
#define vi ve<int>
#define xx first
#define yy second
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max())
#define ii pair<int, int>
#define sz(v) ((int) v.size())

ve<string> a(4);
int dr[] = {0, 1, 1, -1};
int dc[] = {1, 1, 0, 1};
bool check() {
    for (int i = 0; i < 4; ++i)
    for (int f = 0; f < 4; ++f) {
        if (a[i][f] != 'x') continue;
        for (int g = 0; g < 4; ++g) {
            int cnt = 1;
            int r = i, c = f;
            for (int h = 0; h < 2; ++h) {
                r += dr[g], c += dc[g];
                if (r >= 4 or r < 0 or c >= 4 or c < 0) break;
                if (a[r][c] != 'x') break;
                ++cnt;
            }
            if (cnt == 3) return true;
        }
    }
    return false;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    for (int i = 0; i < 4; ++i)
        cin >> a[i];

    for (int i = 0; i < 4; ++i)
    for (int f = 0; f  <4; ++f) {
        if (a[i][f] != '.') continue;
        a[i][f] = 'x';
        if (check()) return cout << "YES", 0;
        a[i][f] = '.';
    }
    cout << "NO";

    return 0;
}