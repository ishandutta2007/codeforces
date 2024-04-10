#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define FOR(i, n) for(int i = 0; i < n; ++i)

using namespace std;

const int nax = 2005;

int n;
int p;
int c[nax];
vector <int> v[nax];
vector <int> g[nax];
int siz[nax];


void dfs(int u, int p) {
    siz[u] = 1;
    for(auto it : v[u]) {
        dfs(it, u);
        siz[u] += siz[it];
        for(int i : g[it])
            g[u].pb(i);
    }
    if(c[u] > siz[u] - 1) {
        printf("NO\n");
        exit(0);
    }
    g[u].insert(g[u].begin() + c[u], u);
}

int ans[nax];

int main () {
    //cin.tie(0);
    //ios_base::sync_with_stdio(0);
    scanf("%d", &n);
    int root = 0;
    for(int i = 1; i <= n; ++i) {
        scanf("%d %d", &p, c + i);
        v[p].pb(i);
        if(!p) root = i;
    }

    dfs(root, 0);

    int val = 1;
    for(auto it : g[root])
        ans[it] = val++;
    printf("YES\n");
    for(int i = 1; i <= n; ++i)
        printf("%d ", ans[i]);



    return 0;
}