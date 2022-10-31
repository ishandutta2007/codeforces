#include <bits/stdc++.h>
using namespace std;

int t, cnt[2][4];
string str[2];
vector<int> val[2], ve;

int modify(int u) {
    return __builtin_popcount(u) == 1 ? 3 - u : u;
}

void move(int u) {
    if (u == 0) {
        return;
    }
    ve.push_back(2 * u);
    for (int i = 0; i < u; i++) {
        val[0][i] = modify(val[0][i]);
    }
    reverse(val[0].begin(), val[0].begin() + u);
}

void solve() {
    for (int i = 0; i < 2; i++) {
        fill(cnt[i], cnt[i] + 4, 0);
    }
    val[0].clear(); val[1].clear(); ve.clear();
    int n = str[0].size() / 2;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            int cur = (str[i][2 * j] - '0') * 2 + (str[i][2 * j + 1] - '0');
            val[i].push_back(cur);
            cnt[i][cur]++;
        }
    }
    if (cnt[0][0] != cnt[1][0] || cnt[0][3] != cnt[1][3]) {
        return void(cout << "-1\n");
    }
    int sw = 0;
    for (int i = 0; i < 2; i++) {
        int dif = cnt[i][1] - cnt[i ^ 1][2];
        for (int j = 0; j < n; j++) {
            if (val[i][j] == 1) {
                dif--;
            } else if (val[i][j] == 2) {
                dif++;
            }
            if (dif == 0) {
                sw = (j + 1) * (i ? -1 : 1);
            }
        }
    }
    if (sw < 0) {
        for (int i = 0; i < -sw; i++) {
            val[1][i] = modify(val[1][i]);
        }
        reverse(val[1].begin(), val[1].begin() + (-sw));
    } else {
        move(sw);
    }
    for (int i = n - 1; i >= 0; i--) {
        int des = (__builtin_popcount(val[1][i]) == 1 ? 3 - val[1][i] : val[1][i]);
        for (int j = n - 1 - i; j < n; j++) {
            if (val[0][j] == des) {
                move(j);
                move(j + 1);
                break;
            }
        }
    }
    if (sw < 0) {
        move(-sw);
    }
    cout << ve.size() << '\n';
    for (int &v : ve) {
        cout << v << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> str[0] >> str[1];
        solve();
    }
}