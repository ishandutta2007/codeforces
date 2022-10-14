#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

auto QUERY(int u) {
    cout << "? " << u << endl;
    int ans;
    cin >> ans;
    return ans;
}

void ANSWER(int N, vector<int> color) {
    cout << "!";
    for (int i = 1; i <= N; i++) {
        cout << " " << color[i];
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> deg(N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> deg[i];
        }

        vector<int> color(N + 1), count(N + 1), sum(N + 1);
        for (int i = 1; i <= N; i++) {
            color[i] = i;
            count[i] = 1;
            sum[i] = deg[i];
        }

        vector<int> merge(N + 1), order(N);
        iota(begin(order), end(order), 1);
        sort(begin(order), end(order), [&](int u, int v) {
            return make_pair(deg[u], u) > make_pair(deg[v], v); //
        });

        for (int u : order) {
            if (merge[u]) {
                continue;
            }
            vector<int> who = {u};
            for (int k = 1; k <= deg[u]; k++) {
                int v = QUERY(u);
                if (merge[v]) {
                    int c = color[v];
                    for (int w : who) {
                        color[w] = c;
                        count[c]++;
                        sum[c] += deg[w];
                    }
                    count[u] = sum[u] = 0;
                    merge[u] = true;
                    break;
                } else {
                    color[v] = u;
                    count[u]++;
                    sum[u] += deg[v];
                    count[v] = sum[v] = 0;
                    merge[v] = true;
                    who.push_back(v);
                }
            }
        }

        ANSWER(N, color);
    }
    return 0;
}