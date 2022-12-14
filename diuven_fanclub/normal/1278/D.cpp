#include <bits/stdc++.h>

using namespace std;

int P[1000005];
bool V[1000005];
vector<int> E[1000005];

void dfs(int x) {
    V[x] = true;
    for (int i : E[x]) {
        if (V[i]) continue;
        dfs(i);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        P[l] = r;
    }
    int e = 0;
    set<int> s;
    for (int i = 1; i <= 2 * n; i++) {
        if (i > 1 && s.empty()) {
            printf("NO\n");
            return 0;
        }
        if (P[i] > 0) {
            for (int j : s) {
                if (j > P[i]) break;
                if (++e >= n) {
                    printf("NO\n");
                    return 0;
                }
                E[P[i]].push_back(j);
                E[j].push_back(P[i]);
            }
            s.insert(P[i]);
        }
        else {
            s.erase(i);
        }
    }
    if (e != n - 1) {
        printf("NO\n");
        return 0;
    } 
    dfs(P[1]);
    for (int i = 1; i <= 2 * n; i++) {
        if (P[i] == 0 && !V[i]) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
}