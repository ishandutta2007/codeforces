#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e5 + 7;
int n, m, q, total, r;
ll init[N];
ll v[N];
ll data[N];
ll data2[N];
ll data3[N];
vector<int> pos[N], heavy_sets, com[N];
bool active[N], is_heavy[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        cin >> init[i];
    for (int i = 1; i <= m; i++) {
        int l;
        cin >> l;
        for (int j = 1; j <= l; j++) {
            int x;
            cin >> x;
            pos[i].push_back(x);
            v[i] += init[x];
        }
        total += l;
    }
    r = sqrt(total);
    for (int i = 1; i <= m; i++)
        if ((int) pos[i].size() >= r) {
            is_heavy[i] = 1;
            heavy_sets.push_back(i);
        }
    for (auto &i : heavy_sets) {
        for (int j = 1; j <= n; j++)
            active[j] = 0;
        for (auto &j : pos[i])
            active[j] = 1;
        for (int j = 1; j <= m; j++) {
            com[j].push_back(0);
            for (auto &x : pos[j])
                if (active[x])
                    com[j].back()++;
        }
    }
    while (q--) {
        string s;
        cin >> s;
        if (s == "+") {
            int i;
            ll x;
            cin >> i >> x;
            if (!is_heavy[i]) { /// light update
                for (auto &j : pos[i])
                    data[j] += x;
                for (int j = 0; j < (int) heavy_sets.size(); j++)
                    data2[heavy_sets[j]] += x * com[i][j];
            } else { /// heavy update
                data3[i] += x;
            }
        } else {
            int i;
            cin >> i;
            ll sol = v[i];
            if (!is_heavy[i]) { /// light query
                for (auto &j : pos[i])
                    sol += data[j];
                for (int j = 0; j < (int) heavy_sets.size(); j++)
                    sol += data3[heavy_sets[j]] * com[i][j];
            } else { /// heavy query
                for (int j = 0; j < (int) heavy_sets.size(); j++)
                    sol += data3[heavy_sets[j]] * com[i][j];
                sol += data2[i];
            }
            cout << sol << "\n";
        }
    }
}