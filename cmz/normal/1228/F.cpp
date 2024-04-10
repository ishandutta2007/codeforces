#include <bits/stdc++.h>
using namespace std;
const int maxn = (1 << 17) + 10;
int ans, anstag;
vector<int> son[maxn];
int h[maxn], tag[maxn];
inline void dfs(int now, int f) {
    tag[now] = 0;
    for(int i = 0; i < son[now].size(); i++) {
        if(son[now][i] == f) swap(son[now][i], son[now][son[now].size() - 1]);
    }
    if(f == 0) son[now].push_back(0);
    if(son[now].size() == 1) {
        h[now] = 0, tag[now] = 0;
    }
    else if(son[now].size() == 2) {
        dfs(son[now][0], now);
        ans = now;
        if(tag[son[now][0]] || h[son[now][0]]) anstag = 0;
        else h[now] = 1, tag[now] = 1;
    }
    else if(son[now].size() == 3) {
        dfs(son[now][0], now);
        dfs(son[now][1], now);
        if((tag[son[now][0]] && tag[son[now][1]]) || h[son[now][0]] != h[son[now][1]]) anstag = 0;
        else if(tag[son[now][0]] || tag[son[now][1]]) tag[now] = 1;
        else tag[now] = 0;
        h[now] = h[son[now][0]] + 1;
    }
    else if(son[now].size() == 4) {
        dfs(son[now][0], now);
        dfs(son[now][1], now);
        dfs(son[now][2], now);
        ans = now;
        sort(son[now].begin(), son[now].begin() + 3, [&] (int a, int b) {
            return h[a] < h[b];
        });
        if(tag[son[now][0]] || tag[son[now][1]] || tag[son[now][2]]) anstag = 0;
        else if(h[son[now][0]] != h[son[now][1]] || h[son[now][1]] != h[son[now][2]] - 1) anstag = 0;
        else tag[now] = 1, h[now] = h[son[now][2]] + 1;
    }
    else anstag = 0;
    if(f == 0) son[now].pop_back();
}
int n, m;
int wsze[maxn], sze[maxn];
inline void dfs2(int now, int f) {
    sze[now] = 1;
    for(auto i : son[now]) {
        if(i != f) dfs2(i, now), sze[now] += sze[i], wsze[now] = max(wsze[now], sze[i]);
    }
    wsze[now] = max(wsze[now], n - sze[now]);
}
int main() {
    scanf("%d", &m);
    if(m == 1) return puts("1\n1"), 0;
    else if(m == 2) return puts("2\n1 2"), 0;
    n = (1 << m) - 2;
    for(int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        son[u].push_back(v);
        son[v].push_back(u);
    }
    dfs2(1, 0);
    int _min = n + 1;
    vector<int> answ;
    for(int i = 1; i <= n; i++) _min = min(wsze[i], _min);
    for(int i = 1; i <= n; i++) {
        if(wsze[i] == _min) {
            anstag = 1;
            dfs(i, 0);
            if(tag[i] == 1 && h[i] == m - 1 && anstag) {
                answ.push_back(ans);
            }
        }
    }
    printf("%d\n", answ.size());
    for(auto i : answ) printf("%d ", i);
    return 0;
}