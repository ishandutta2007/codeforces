#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 2e5 + 10;
const int S = 17;
int deep[N], dfn[N];
int fa[N][S + 1];
int e[N * 2][2], st[N];
int belong[N];
int sp[N],v[N];
int bz[N], tag, tote;
int n, q;
vector<int>g[N];
void dfs(int x) {
    static int cnt = 0;
    dfn[x] = ++cnt;
    deep[x] ++;
    for (int i = 0; fa[fa[x][i]][i]; i ++) fa[x][i + 1] = fa[fa[x][i]][i];
    for (auto u:g[x])
        if (u != fa[x][0]) {
            fa[u][0] = x;
            deep[u] = deep[x];
            dfs(u);
        }
}
int up(int x, int y){
    for (int i = S; i >= 0; i --)
        if (y >= (1 << i))
            y -= (1 << i), x = fa[x][i];
    return x;
}
int getlca(int x, int y) {
    if (deep[x] < deep[y])
        swap(x, y);
    x = up(x, deep[x] - deep[y]);
    for (int i = S; i >= 0; i --)
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return x != y ? fa[x][0] : x;
}

void update(int x) {
    if (bz[x] != tag) {
        bz[x] = tag;
        st[x] = 0;
        belong[x] = 0;
    }
}
vector<int> d;
void ins(int x, int y) {
    e[++tote][0] = y;
    e[tote][1] = st[x];
    st[x] = tote;
}
void link(int x,int y) {
    update(x), update(y);
    ins(x, y);
    ins(y, x);
}
void add(int x) {//dfs
    if (d.empty()){
        d.push_back(x);
    } else {
        if (getlca(d[d.size() - 1], x) != d[d.size() - 1]) {
            int last = d[d.size() - 1];
            d.pop_back();
            while (!d.empty() && getlca(d[d.size() - 1], x) != d[d.size() - 1]) {
                link(d[d.size() - 1], last);
                last = d[d.size() - 1];
                d.pop_back();
            }
            if (d.empty() || getlca(last, x) != d[d.size() - 1] ) {
                int u = getlca(last, x);
                link(u, last);
                d.push_back(u);
            } else {
                link(d[d.size() - 1], last);
            }
        }
        d.push_back(x);
    }
}
int dis(int x, int y) {
    int lca = getlca(x, y);
    return deep[x] + deep[y] - 2 * deep[lca];
}
pair<int, int> did(int x, int y) {
    return make_pair((dis(v[x], y)  + sp[x] - 1)/ sp[x], x);
}
void dfs1(int x, int fa) {
    int s = belong[x];
    for (int i = st[x]; i ; i = e[i][1])
        if (e[i][0] != fa) {
            dfs1(e[i][0], x);
            if (belong[e[i][0]] && (!s || did(s, x) > did(belong[e[i][0]], x)))
                s = belong[e[i][0]];
        }
    belong[x] = s;
}
void dfs2(int x, int fa, int up) {
    if (up && (!belong[x]||did(up, x) < did(belong[x], x))) belong[x] = up;
    else
        if (belong[x] && (!up || did(up, x) > did(belong[x], x))) up = belong[x];
    for (int i = st[x]; i ; i = e[i][1])
        if (e[i][0] != fa) {
            dfs2(e[i][0], x, up);
        }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    scanf("%d", &q);
    while (q--) {
        tag ++;
        int k, m;
        scanf("%d %d", &k, &m);
        vector<int> dd;
        for (int i = 1; i <= k; i ++) {
            int x, y;
            scanf("%d %d", &x, &y);
            update(x);
            belong[x] = i;
            sp[i] = y;
            v[i] = x;
            dd.push_back(x);
        }
        vector<int>dm;
        for (int i= 1; i <= m; i ++) {
            int x;
            scanf("%d", &x);
            update(x);
            dm.push_back(x);
            dd.push_back(x);
        }
        sort(dd.begin(), dd.end(), [](int x, int y) {
            return dfn[x] <dfn[y];
        });
        int last = 0;
        d.clear();
        tote = 0;
        for (auto u:dd)
            if (last != u)
                add(last = u);
        while (d.size() > 1) {
            link(d[d.size() - 2], d[d.size() - 1]);
            d.pop_back();
        }
        dfs1(d[0], 0);
        dfs2(d[0], 0, 0);
        for (auto u:dm)
            printf("%d ", belong[u]);
        printf("\n");
    }
    return 0;
}