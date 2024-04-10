#include <bits/stdc++.h>

using namespace std;

#define se second
#define fi first
#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define mp make_pair 

typedef long long ll;


int main() {
    iostream::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    string s[200];
    int x = n, y = m, xx = 0, yy = 0;
    forn (i, n) {
        cin >> s[i];
        forn (j, m) {
            if (s[i][j] == 'B') {
                x = min(x, i);
                y = min(y, j);
                xx = max(xx, i);
                yy = max(yy, j);
            }
        }
    }
    cout << (x + xx) / 2 + 1 << " " << (y + yy) / 2 + 1 << "\n";
    return 0;
}