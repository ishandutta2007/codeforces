#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

int d[50][50], u[50][50];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            for (int j = 1; j <= m; j++)
                d[i][j] = (s[j - 1] == '*'), u[i][j] = 0;
        }
        bool ok = 1;
        for (int i = n; i >= 1; i--)
            for (int j = 1; j <= m; j++) {
                int len = 0;
                while (1)
                    if (i - len >= 1 && j - len >= 1 && j + len <= m && d[i - len][j + len] && d[i - len][j - len])
                        ++len;
                    else
                        break;
                --len;
                if (len >= k)
                    for (int x = 0; x <= len; x++)
                        u[i - x][j - x] = u[i - x][j + x] = 1;
                if (d[i][j] && !u[i][j]) {
                    ok = 0;
                    break;
                }
            }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}