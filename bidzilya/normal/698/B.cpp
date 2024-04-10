#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#ifdef LOCAL
    #define LLD_SPEC "%lld"
#else
    #define LLD_SPEC "%I64d"
#endif

int n;
vector<int> pr;
vector<int> used;
vector<int> needRoot;
int changes;
int root;

void Dfs(int v) {
    used[v] = 1;

    int u = pr[v];

    if (used[u] == 0) {
        Dfs(u);
    } else if (used[u] == 1) {
        if (u == v) {
            if (root == -1) {
                root = v;
            } else {
                pr[v] = root;
                ++changes;
            }
        } else {
            needRoot.push_back(v);
            pr[v] = v;
        }
    }

    used[v] = 2;
}

int main() {
    scanf("%d", &n);
    pr.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &pr[i]);
        --pr[i];
    }

    changes = 0;
    root = -1;
    used.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        int v = i;
        if (!used[v]) {
            Dfs(v);
        }
    }

    if (root == -1) {
        root = needRoot.back();
        needRoot.pop_back();
        pr[root] = root;
        ++changes;
    }
    for (int v : needRoot) {
        pr[v] = root;
        ++changes;
    }

    printf("%d\n", changes);
    for (int i = 0; i < n; ++i) {
        printf("%d ", pr[i] + 1);
    }

    return 0;
}