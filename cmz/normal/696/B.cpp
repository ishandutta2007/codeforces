#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n;
int sz[maxn];
vector<int> son[maxn];
double ans[maxn];
void dfs(int x) {
    sz[x] = 1;
    for (int i = 0; i < (int)son[x].size(); ++i) {
        int v = son[x][i];
        dfs(v);
        sz[x] += sz[v];
    }
}
void solve(int x) {
    for (int i = 0; i < (int)son[x].size(); ++i) {
        int v = son[x][i];
        ans[v] = ans[x] + 1 + 0.5 * (sz[x] - sz[v] - 1);
        solve(v);
    }
}
int main() {
   scanf("%d", &n);
   for (int i = 2, x; i <= n; ++i) {
       scanf("%d", &x);
       son[x].push_back(i);
   }
   dfs(1); ans[1] = 1.; 
   solve(1);
   for (int i = 1; i <= n; ++i) printf("%.1lf ", ans[i]);
}