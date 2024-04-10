#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1000 + 7;
int t, n, m, a[N][N];
bool has[N][2];

void solve() {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
                has[i][0] = has[i][1] = 0;
                string s;
                cin >> s;
                for (int j = 1; j <= n; j++)
                        a[i][j] = (s[j - 1] == 'a');
                a[i][i] = -1;
                for (int j = 1; j <= n; j++)
                        if (i != j)
                                has[i][a[i][j]] = 1;
        }

        for (int i = 1; i <= n; i++)
                for (int j = i + 1; j <= n; j++)
                        if (a[i][j] == a[j][i]) {
                                cout << "YES\n";
                                for (int k = 1; k <= m + 1; k++)
                                        if (k & 1)
                                                cout << i << " ";
                                        else
                                                cout << j << " ";
                                cout << "\n";
                                return;
                        }
        /// stiu ca a[i][j] != a[j][i] :))
        /// daca m e impar atunci pot scoate abababababababa
        if (m & 1) {
                cout << "YES\n";
                for (int k = 1; k <= m + 1; k++)
                        if (k & 1)
                                cout << "1 ";
                        else
                                cout << "2 ";
                cout << "\n";
                return;
        }
        for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                {
                        if (i == j)
                                continue;
                        if (!has[j][a[i][j]])
                                continue;
                        int k = 1;
                        while (a[j][k] != a[i][j]) {
                                k++;
                                assert(k <= n);
                        }
                        cout << "YES\n";
                        vector<int> ret;
                        if (m % 4 == 2) {
                                for (int it = 1; it <= m + 1; it++)
                                {
                                        if (it % 4 == 1)
                                                ret.push_back(i);
                                        if (it % 4 == 2)
                                                ret.push_back(j);
                                        if (it % 4 == 3)
                                                ret.push_back(k);
                                        if (it % 4 == 0)
                                                ret.push_back(j);
                                }
                        } else {
                                for (int it = 1; it <= m + 1; it++)
                                {
                                        it++;
                                        if (it % 4 == 1)
                                                ret.push_back(i);
                                        if (it % 4 == 2)
                                                ret.push_back(j);
                                        if (it % 4 == 3)
                                                ret.push_back(k);
                                        if (it % 4 == 0)
                                                ret.push_back(j);
                                        it--;
                                }
                        }
                        for (auto &i : ret)
                                cout << i << " ";
                        cout << "\n";
                        return;
                        for (int it = 1; it < (int) ret.size(); it++)
                                cout << a[ret[it - 1]][ret[it]] << " ";
                        cout << "\n";
                        return;
                }
        cout << "NO\n";
}

signed main() {
        ios::sync_with_stdio(0); cin.tie(0);

        cin >> t;
        for (int tc = 1; tc <= t; tc++) {
                solve();
        }


}