#include <bits/stdc++.h>

using namespace std;

const int max_x = 1000, inf = 1000111222;
const int max_bal = 2222;
const int sd = max_bal / 2;

int a;
pair<int, pair<int, int>> par[max_x][max_bal];
bool dp[max_x][max_bal];

int get_sum(int x) {
    int sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> a;
    queue<pair<int, int>> q;
    dp[0][sd] = 1;
    q.push({0, sd});
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for (int d = 0; d <= 9; ++d) {
            int y = p.first + a * d;
            int to = y / 10;
            int w = d - a * (y % 10);
            if (p.second + w >= 0 && p.second + w < max_bal && !dp[to][p.second + w]) {
                dp[to][p.second + w] = 1;
                par[to][p.second + w] = {d, p};
                q.push({to, p.second + w});
            }
        }
    }
    for (int i = 1; i < max_x; ++i) {
        int need = get_sum(i) * a + sd;
        if (need < max_bal && dp[i][need]) {
            string ans;
            int x = i, bal = need;
            while (x != 0 || bal != sd) {
                ans += '0' + par[x][bal].first;
                if (ans == "0") {
                    ans = "";
                }
                int nx = par[x][bal].second.first;
                int nbal = par[x][bal].second.second;
                //cout << nx << " " << nbal - sd << ", d = " << par[x][bal].first << " -> " << x << " " << bal - sd << endl;
                x = nx;
                bal = nbal;
            }
            cout << ans << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}