#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 7;
const int OO = (int) 1e9;
int want;
int n;
bool have[N];
int best[2 * N];
vector<int> g[2 * N];
vector<int> who;

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> want >> n;
        for (int i = 1; i <= n; i++) {
                int x;
                cin >> x;
                have[x] = 1;
        }
        vector<int> all;
        for (int i = 0; i <= 1000; i++) {
                if (have[i]) {
                        all.push_back(i - want);
                }
        }
        for (int i = 0; i <= 2000; i++) {
                for (auto &x : all) {
                        if (0 <= i + x && i + x <= 2000) {
                                g[i].push_back(i + x);
                                if (i + x == 1000) {
                                        who.push_back(i);
                                }
                        }
                }
                best[i] = OO;
        }
        queue<int> q;
        q.push(1000);
        best[1000] = 0;
        while (!q.empty()) {
                int a = q.front();
                q.pop();
                for (auto &b : g[a]) {
                        if (best[b] == OO) {
                                best[b] = 1 + best[a];
                                q.push(b);
                        }
                }
        }
        int ans = OO;
        for (auto &b : who) {
                ans = min(ans, best[b] + 1);
        }
        if (ans == OO) {
                cout << "-1\n";
        } else {
                cout << ans << "\n";
        }
}