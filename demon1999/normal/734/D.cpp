#include <bits/stdc++.h>
   
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
   
using namespace std;
   
typedef long long ll;
typedef pair<int, int> pii;

ll n, x, y, a[8], b[8], q[8];
ll xx, yy;
char c;
int main() {
    iostream::sync_with_stdio(0), cin.tie(0);
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    cin >> n >> x >> y;
    forn (i, n) {
        cin >> c >> xx >> yy;
        int qq = 3;
        if (c == 'B')
            qq = 1;
        if (c == 'R')
            qq = 2;

        if (xx == x) {
            if (yy < y && (q[0] == 0 || b[0] < yy)) {
                q[0] = qq;
                b[0] = yy;
            }
            if (yy > y && (q[1] == 0 || b[1] > yy)) {
                q[1] = qq;
                b[1] = yy;
            }
        }
        if (yy == y) {
            if (xx < x && (q[2] == 0 || a[2] < xx)) {
                q[2] = qq;
                a[2] = xx;
            }
            if (xx > x && (q[3] == 0 || a[3] > xx)) {
                a[3] = xx;
                q[3] = qq;
            }
        }
        if (xx + yy == x + y) {
            if (xx < x && (q[4] == 0 || a[4] < xx)) {
                a[4] = xx;
                q[4] = qq;
            }
            if (xx > x && (q[5] == 0 || a[5] > xx)) {
                a[5] = xx;
                q[5] = qq;
            }
        }
        if (xx - yy == x - y) {
            if (xx < x && (q[6] == 0 || a[6] < xx)) {
                a[6] = xx;
                q[6] = qq;
            }
            if (xx > x && (q[7] == 0 || a[7] > xx)) {
                a[7] = xx;
                q[7] = qq;
            }
        }
    }
    forn (i, 4) {
        if (q[i] == 3 || q[i] == 2) {
            cout << "YES\n";
            re 0;
        }
    }
    forn (i, 4) {
        if (q[i + 4] == 3 || q[i + 4] == 1) {
            cout << "YES\n";
            re 0;
        }
    }
    cout << "NO\n";
    return 0;
}