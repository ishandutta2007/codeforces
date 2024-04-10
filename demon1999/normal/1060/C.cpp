#include <bits/stdc++.h>

using namespace std;

#define se second
#define fi first
#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define mp make_pair 

typedef long long ll;

ll n, m, x, a[3000], b[3000], qmi[3000], ymi[3000];
string s;

int main() {
    iostream::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    forn (i, n) {
        cin >> a[i + 1];
        a[i + 1] += a[i];
    }
    forn (j, m) {
        cin >> b[j + 1];
        b[j + 1] += b[j];
    }
    cin >> x;
    for (int l = 1; l <= n; l++) {
        qmi[l] = x + 1;
        for (int j = 0; j + l <= n; j++) {
            qmi[l] = min(qmi[l], a[j + l] - a[j]);
        }
    }
    for (int l = 1; l <= m; l++) {
        ymi[l] = x + 1;
        for (int j = 0; j + l <= m; j++) {
            ymi[l] = min(ymi[l], b[j + l] - b[j]);
        }
    }
    int ans = 0;
    for (int l = 1; l <= n; l++) {
        for (int xl = 1; xl <= m; xl++) {
            if (qmi[l] <= x / ymi[xl]) {
                ans = max(ans, l * xl);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}