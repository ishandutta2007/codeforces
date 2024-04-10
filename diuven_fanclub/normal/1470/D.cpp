#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
vector<int> E[300005];
int C[300005];

int main() {
    int t;
    scanf("%d", &t);
    for (int _t = 0; _t < t; _t++) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            E[i].clear();
            C[i] = 0;
        }
        for (int i = 1; i <= m; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            E[a].push_back(b);
            E[b].push_back(a);
        }
        vector<int> ans(1, 1);
        C[1] = 3;
        vector<int> V[4];
        V[3].push_back(1);
        while (1) {
            if (V[3].size()) {
                int x = V[3].back();
                V[3].pop_back();
                for (int i : E[x]) {
                    if (C[i] < 2) C[i] = 2, V[2].push_back(i);
                }
            }
            else if (V[2].size()) {
                int x = V[2].back();
                V[2].pop_back();
                if (C[x] != 2) continue;
                for (int i : E[x]) {
                    if (C[i] < 1) C[i] = 1, V[1].push_back(i);
                }
            }
            else if (V[1].size()) {
                int x = V[1].back();
                V[1].pop_back();
                if (C[x] != 1) continue;
                C[x] = 3;
                V[3].push_back(x);
                ans.push_back(x);
            }
            else break;
        }
        for (int i = 1; i <= n; i++) if (!C[i]) ans.clear();
        if (ans.size()) {
            printf("YES\n%d\n", (int)ans.size());
            for (int i : ans) printf("%d ", i);
            printf("\n");
        }
        else printf("NO\n");
    }
}