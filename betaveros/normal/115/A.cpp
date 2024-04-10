#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int n;
vector<int> children[2008];
int parent[2008];
int maxDepth;
void dfs(int v, int d) {
    maxDepth = max(maxDepth, d);
    for (int w : children[v]) {
        dfs(w, d + 1);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        parent[i] = x;
        if (x != -1) children[x].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (parent[i] == -1) dfs(i, 1);
    }
    printf("%d\n", maxDepth);
}