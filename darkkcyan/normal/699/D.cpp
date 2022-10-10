#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define long long long
#define ve vector
#define vi ve<int>
#define xx first
#define yy second
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max())
#define ii pair<int, int>
#define sz(v) ((int) v.size())

int n;
ve<vi> gr;
vi dad;
void read() {
    scanf("%d", &n);
    gr.resize(n);
    dad.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &dad[i]); -- dad[i];
        gr[dad[i]].push_back(i);
    }
}

int findroot(int u) {
    int v = dad[u];
    while (u != v) {
        u = dad[u], v = dad[dad[v]];
    }
    return u;
}

int root;
vi pp, r;
int findp(int u) { return pp[u] = u == pp[u] ? u : findp(pp[u]); }
void join(int u, int v) { pp[findp(u)] = findp(v); }

int process() {
    pp.resize(n); for (int i = 0; i < n; ++i) pp[i] = i;
    for (int i = 0; i < n; ++i)
        join(i, dad[i]);

    r.resize(n, -1);
    root = -1;
    int lastroot;
    for (int i = 0; i < n; ++i) {
        int u = findp(i);
        if (u != i) continue;
        lastroot = r[u] = findroot(u);
        if (r[u] == dad[r[u]]) root = r[u];
    }

    int ans = 0;
    if (root == -1) {
        root = lastroot;
        dad[root] = root;
        ans = 1;
    }

    for (int i = 0; i < n; ++i) {
        int u = r[i];
        if (u == -1) continue;
        if (u == root) continue;
        ++ans;
        dad[u] = root;
    }
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    read();
    printf("%d\n", process());
    for (int i = 0; i < n; ++i) printf("%d ", dad[i] + 1);

    return 0;
}