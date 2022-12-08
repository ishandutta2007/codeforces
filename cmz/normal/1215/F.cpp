#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int v, nxt;
} e[15000010];
int head[2000010], tot;
inline void addedge(int u, int v)
{
    // cerr << "edge " << u << ' ' << v << endl;
    e[++tot] = edge{v, head[u]};
    head[u] = tot;
}
int dfn[2000010], low[2000010], id[2000010], idcnt, sta[2000010], top, insta[2000010];
inline void tarjan(int now)
{
    static int dfsnow = 0;
    dfn[now] = low[now] = ++dfsnow;
    sta[++top] = now;
    insta[now] = 1;
    for (int i = head[now]; i; i = e[i].nxt)
    {
        if (!dfn[e[i].v])
            tarjan(e[i].v);
        if (insta[e[i].v])
            low[now] = min(low[now], low[e[i].v]);
    }
    if (dfn[now] == low[now])
    {
        idcnt++;
        do
        {
            insta[sta[top]] = 0;
            id[sta[top]] = idcnt;
        } while (sta[top--] != now);
    }
}
int n, m, p, cnt, M;
int L[400010], R[400010];
pair<int, int> nd1[400010], nd2[400010];
int main()
{
    scanf("%d%d%d%d", &p, &n, &M, &m);
    for (int i = 1; i <= p; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        addedge(x << 1, y << 1 | 1);
        addedge(y << 1, x << 1 | 1);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &nd1[i].first, &nd2[i].first);
        L[i] = nd1[i].first;
        R[i] = nd2[i].first;
        nd1[i].second = i;
        nd2[i].second = i;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        addedge(u << 1 | 1, v << 1);
        addedge(v << 1 | 1, u << 1);
    }
    sort(nd1 + 1, nd1 + 1 + n);
    sort(nd2 + 1, nd2 + 1 + n);
    cnt = n * 2 + 1;
    int last1 = 0, last2 = 0;
    for(int i = 1, j = 1; i <= n; i++) {
        for(; j <= n && nd2[j].first < nd1[i].first; j++) {
            cnt++;
            if(last1) addedge(cnt, last1);
            addedge(cnt, nd2[j].second << 1);
            last1 = cnt;
            cnt++;
            if(last2) addedge(last2, cnt);
            addedge(nd2[j].second << 1 | 1, cnt);
            last2 = cnt;
            // cerr << "add " << nd2[j].second << endl;
        }
        // cerr << "to " << nd1[i].second << endl;
        if(last1) addedge(nd1[i].second << 1 | 1, last1), addedge(last2, nd1[i].second << 1);
    }
    for (int i = 2; i <= cnt; i++)
    {
        if (!dfn[i])
            tarjan(i);
    }
    for (int i = 1; i <= n; i++) {
        // cerr << id[i << 1] << ' ' << id[i << 1 | 1] << endl;
        if (id[i << 1] == id[i << 1 | 1]) {
            // for(int i = 2; i <= cnt; i++) cerr << id[i] << ' ';
            return puts("-1"), 0;
        }
    }
    int l = 1, r = M, cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(id[i << 1] > id[i << 1 | 1]) {
            l = max(l, L[i]);
            r = min(r, R[i]);
            cnt++;
        }
    }
    printf("%d %d\n", cnt, l);
    for (int i = 1; i <= n; i++)
        if(id[i << 1] > id[i << 1 | 1]) printf("%d ", i);
    return 0;
}