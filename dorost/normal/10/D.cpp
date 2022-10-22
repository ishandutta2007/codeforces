/*  * In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 501;
const int NINF = -3210;
int dp[2][N][N];
int a[N], b[N];
short p[N][N][N];

int f(int x) {
    return x & 1;
}

int32_t main() {
    set <int> cc, cc2;
    vector <int> c;
    c.push_back(-1);
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cc.insert(a[i]);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        cc2.insert(b[i]);
    }
    for (auto x : cc) {
        if (cc2.count(x)) {
            c.push_back(x);
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k < c.size(); k++) {
                dp[f(i)][j][k] = NINF;
                if (i == 0 || j == 0) {
                    p[i][j][k] = -1;
                    if (k != 0) {
                        dp[f(i)][j][k] = NINF;
                    } else {
                        dp[f(i)][j][k] = 0;
                    }
                } else {
                    if (dp[f(i - 1)][j][k] > dp[f(i)][j - 1][k]) {
                        p[i][j][k] = 1000;
                    } else {
                        p[i][j][k] = 2000;
                    }
                    dp[f(i)][j][k] = max(dp[f(i - 1)][j][k], dp[f(i)][j - 1][k]);
                    if (a[i - 1] == b[j - 1] && a[i - 1] == c[k]) {
                        for (int l = 0; l < k; l++) {
                            if (dp[f(i - 1)][j - 1][l] + 1 > dp[f(i)][j][k]) {
                                dp[f(i)][j][k] = (dp[f(i - 1)][j - 1][l] + 1);
                                p[i][j][k] = l;
                            }
                        }
                    }
                }
            }
        }
    }
    int mx = -1;
    int in = -1;
    for (int k = 0; k < c.size(); k++) {
        if (dp[f(n)][m][k] > mx) {
            mx = dp[f(n)][m][k];
            in = k;
        }
    }
    int aa = n, bb = m, ccc = in;
    cout << mx << '\n';
    vector <int> ans;
    while (true) {
        if (p[aa][bb][ccc] == -1)
            break;
        if (p[aa][bb][ccc] == 1000) {
            aa--;
        } else if (p[aa][bb][ccc] == 2000) {
            bb--;
        } else {
            ans.push_back(c[ccc]);
            ccc = p[aa][bb][ccc];
            aa--;
            bb--;
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans) {
        cout << x << ' ';
    }
}