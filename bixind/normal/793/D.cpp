#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <set>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;

const int MN = 90;
const int inf = 1000000000;

int ld[MN][MN][MN];
int rd[MN][MN][MN];

vector<vector<int> > tr;
vector<vector<int> > ct;

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int h = 1; h <= n; ++h)
                ld[i][j][h] = rd[i][j][h] = inf;
        }
    }
    tr.resize(n);
    ct.resize(n);
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a>> b >> c;
        --a;
        --b;
        tr[a].push_back(b);
        ct[a].push_back(c);
    }
    for (int kk = 1; kk <= k; ++kk)
        for (int ln = 1; ln < n; ++ln) {
            for (int i = 0; i < n - ln; ++i) {
                for (int j = 0; j < tr[i].size(); ++j) {
                    int p = tr[i][j];
                    if (p > i && p <= i + ln) {
                        ld[i][i + ln][kk] = min(ld[i][i + ln][kk], ct[i][j] + rd[i + 1][p][kk - 1]);
                        ld[i][i + ln][kk] = min(ld[i][i + ln][kk], ct[i][j] + ld[p][i + ln][kk - 1]);
                    }
                }
                for (int j = 0; j < tr[i + ln].size(); ++j) {
                    int p = tr[i + ln][j];
                    if (p >= i && p < i + ln) {
                        rd[i][i + ln][kk] = min(rd[i][i + ln][kk], ct[i + ln][j] + rd[i][p][kk - 1]);
                        rd[i][i + ln][kk] = min(rd[i][i + ln][kk], ct[i + ln][j] + ld[p][i + ln - 1][kk - 1]);
                    }
                }
            }
        }
//    for (int kk = 0; kk <= k; ++kk) {
//        for (int i = 0; i < n; ++i) {
//            for (int j = i; j < n; ++j)
//                cout << ld[i][j][kk] << ' ';
//            cout << endl;
//        }
//        cout << "-----------------\n";
//        for (int i = 0; i < n; ++i) {
//            for (int j = i; j < n; ++j)
//                cout << rd[i][j][kk] << ' ';
//            cout << endl;
//        }
//        cout << "====================\n";
//    }
    int ans = inf;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, rd[0][i][k - 1]);
        ans = min(ans, ld[i][n - 1][k - 1]);
    }
    if (ans == inf)
        cout << -1 << endl;
    else
        cout << ans << endl;
}

int main() {
    iostream::sync_with_stdio(false);
    cout.precision(20);
    solve();
}