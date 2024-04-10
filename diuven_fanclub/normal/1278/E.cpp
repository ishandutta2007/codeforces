#include <bits/stdc++.h>

using namespace std;

vector<int> E[500005];

int L[500005], R[500005];
set<int> rem;
void dfs(int x, int p) {
    R[x] = *rem.begin();
    for (int i : E[x]) {
        if (i == p) continue;
        L[i] = R[x];
        rem.erase(R[x]);
        R[x] = *rem.lower_bound(R[x] + 1);
    }
    rem.erase(R[x]);
    reverse(E[x].begin(), E[x].end());
    for (int i : E[x]) {
        if (i == p) continue;
        dfs(i, x);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        E[x].push_back(y);
        E[y].push_back(x);
    }
    for (int i = 2; i <= 2 * n; i++) {
        rem.insert(i);
    }
    L[1] = 1;
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", L[i], R[i]);
    }
}