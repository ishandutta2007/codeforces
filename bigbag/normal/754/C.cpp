#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111, inf = 1011111111;

int t, n, m, f[max_n][max_n], dp[max_n][max_n];
int name[max_n], ans[max_n];
string s[max_n], mes[max_n];
map<string, int> q;

bool ok(char c) {
    return ('0' <= c && c <= '9') || ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

bool ok(int pos, int num) {
    return (name[pos] == -1 || name[pos] == num) && (f[pos][num] == 0);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n;
        q.clear();
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            q[s[i]] = i;
        }
        cin >> m;
        getline(cin, s[n]);
        memset(f, 0, sizeof(f));
        for (int i = 0; i < m; ++i) {
            string s;
            getline(cin, s);
            int st = s.find(':') + 1;
            mes[i] = s.substr(st - 1);
            string nm = s.substr(0, st - 1);
            if (nm == "?") {
                name[i] = -1;
            } else {
                name[i] = q[nm];
            }
            for (int j = st; j < s.length(); ++j) {
                string t = "";
                while (j < s.length() && ok(s[j])) {
                    t += s[j];
                    ++j;
                }
                if (q.count(t)) {
                    f[i][q[t]] = 1;
                }
            }
        }
        if (0) {
            for (int i = 0; i < m; ++i) {
                cout << name[i] << " ";
                for (int j = 0; j < n; ++j) {
                    cout << f[i][j];
                }
                cout << endl;
            }
        }
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            if (ok(0, i)) {
                dp[0][i] = 0;
            }
        }
        for (int i = 0; i + 1 < m; ++i) {
            for (int last = 0; last < n; ++last) {
                if (dp[i][last] != -1) {
                    //cout << i << " " << last << endl;
                    for (int nxt = 0; nxt < n; ++nxt) {
                        if (nxt != last && ok(i + 1, nxt)) {
                            dp[i + 1][nxt] = last;
                        }
                    }
                }
            }
        }
        int num = -1;
        for (int i = 0; i < n; ++i) {
            if (dp[m - 1][i] != -1) {
                num = i;
            }
        }
        if (num == -1) {
            cout << "Impossible" << endl;
        } else {
            for (int i = m - 1; i >= 0; --i) {
                ans[i] = num;
                num = dp[i][num];
            }
            for (int i = 0; i < m; ++i) {
                cout << s[ans[i]] << mes[i] << endl;
            }
        }
    }
    return 0;
}