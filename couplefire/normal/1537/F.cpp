#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 233333;

ll w[N];
vector<int> vec[N];
int col[N], vis[N];

ll sum = 0;
bool dfs(int x, int c) {
    if(col[x]) return col[x] == c;
    col[x] = c;
    sum += col[x] * w[x];
    for(int y : vec[x])
        if(!dfs(y, -c))
            return 0;
    return 1;
}

void gao(int x) {
    if(vis[x]) return;
    vis[x] = 1;
    sum += w[x];
    for(int y : vec[x]) {
        gao(y);
    }
}

void Solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i) w[i] = 0, col[i] = 0, vis[i] = 0;
    for(int i = 1; i <= n; ++i) vec[i].clear();
    for(int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        w[i] -= x;
    }
    for(int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        w[i] += x;
    }
    for(int i = 1; i <= m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    bool f = 1;
    sum = 0;
    if(dfs(1, 1)) {
        if(sum) f = 0;
    } else {
        sum = 0;
        gao(1);
        if(sum & 1) f = 0;
    }
    if(f) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        Solve();
    }
}