#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2000 + 7;
int n;
int k;
int c[N][N];
vector<int> g[N];

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
                for (int j = i + 1; j <= n; j++) {
                        cin >> c[i][j];
                        c[j][i] = c[i][j];
                        if (c[i][j] != -1) {
                                g[i].push_back(j);
                                g[j].push_back(i);
                        }
                }
        }
        if (k == 1) {
                if (n % 2) {
                        cout << "error on k = 1\n";
                }
                ll sol = 0;
                for (int i = 1; i <= n; i++) {
                        for (int j = i + 1; j <= n; j++) {
                                if (c[i][j] != -1) {
                                        sol += c[i][j];
                                }
                        }
                }
                sol /= (n / 2);
                cout << sol << "\n";
                return 0;
        }
        if (k == 2) {
                int ce = 1;
                for (int i = 2; i <= n; i++) {
                        if ((int) g[i].size() > (int) g[ce].size()) {
                                ce = i;
                        }
                }
                ll sol = 0;
                for (auto &i : g[ce]) {
                        sol += c[ce][i] * (ll) (n - 1);
                }
                for (int i = 1; i <= n; i++) {
                        if (i != ce) {
                                for (auto &j : g[i]) {
                                        if (j != ce) {
                                                sol += c[i][j];
                                        }
                                }
                        }
                }
                sol /= (n * (ll) (n - 1) / 2);
                cout << sol << "\n";
                return 0;
        }
        if (n == k + 1) {
                ll sol = 0;
                for (int i = 1; i <= n; i++) {
                        for (int j = i + 1; j <= n; j++) {
                                sol += c[i][j] * 2;
                        }
                }
                sol /= n;
                cout << sol << "\n";
                return 0;
        }
}