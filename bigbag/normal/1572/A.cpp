/**
 *  created: 18/09/2021, 17:38:18
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, need[max_n], ans[max_n];
vector<int> g[max_n];

void clr() {
    for (int i = 0; i < n; ++i) {
        g[i].clear();
        ans[i] = 0;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        deque<int> v1;
        for (int i = 0; i < n; ++i) {
            ans[i] = 0;
            int k;
            cin >> k;
            need[i] = k;
            if (!k) {
                v1.push_back(i);
                ans[i] = 1;
            }
            while (k--) {
                int to;
                cin >> to;
                --to;
                g[to].push_back(i);
            }
        }
        int sz = 0;
        while (!v1.empty()) {
            int v = v1.front();
            v1.pop_front();
            ++sz;
            for (int to : g[v]) {
                --need[to];
                if (v < to) {
                    ans[to] = max(ans[to], ans[v]);
                } else {
                    ans[to] = max(ans[to], ans[v] + 1);
                }
                if (need[to] == 0) {
                    if (ans[to] == ans[v] + 1) {
                        v1.push_back(to);
                    } else {
                        v1.push_front(to);
                    }
                }
            }
        }
        if (sz == n) {
            cout << *max_element(ans, ans + n) << "\n";
        } else {
            cout << "-1\n";
        }
        clr();
    }
    return 0;
}