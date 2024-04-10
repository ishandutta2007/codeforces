#include <cstdio>
#include <cstdlib>
#pragma comment(linker, "/STACK:66777216")
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 210000;

int N, M;
int color[MAXN], tot, DFN[MAXN], low[MAXN], Index, stack[MAXN], len, visit[MAXN];

struct edge
{
    int a, b, id;
}e1[MAXN], ee[MAXN];
int e1num, ans[MAXN], eid[MAXN], ansnum, eenum, d[MAXN];

struct edlist
{
    int other[MAXN * 2], succ[MAXN * 2], last[MAXN], sum, id[MAXN * 2];
    void clear()
    {
        memset(last, 0, sizeof(last));
        sum = 0;
    }
    void AddEdge(int a, int b, int dd = 0)
    {
        other[++sum] = b, succ[sum] = last[a], last[a] = sum, id[sum] = dd;
    }
}e, r, t;

void Tarjan(int x)
{
    stack[++len] = x;
    DFN[x] = low[x] = ++Index;
    for(int i = e.last[x];i;i = e.succ[i])
    {
        int y = e.other[i];
        if (!DFN[y])
        {
            Tarjan(y);
            low[x] = min(low[y], low[x]);
        }
        else
        if (visit[y])
            low[x] = min(low[x], DFN[y]);
    }
    if (low[x] == DFN[x])
    {
        ++tot;
        while(stack[len + 1] != x)
        {
            color[stack[len]] = tot;
            visit[stack[len]] = 0;
            len--;
        }
    }
}

int flag[MAXN];

void Dfs(int x)
{
    if (flag[x])
        return ;
    flag[x] = 1;
    for(int i = e.last[x];i;i = e.succ[i])
    {
        int y = e.other[i];
        ee[++eenum] = (edge){i, y, e.id[i]};
    }
    for(int i = r.last[x];i;i = r.succ[i])
        Dfs(r.other[i]);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d %d", &N, &M);
    e.clear();
    
    e1num = 0;
    for(int i = 1;i <= M;i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (c == 0)
            e.AddEdge(a, b);
        else
            e1[++e1num] = (edge){a, b, i};
    }
    memset(DFN, 0, sizeof(DFN));
    memset(visit, 0, sizeof(visit));
    memset(stack, 0, sizeof(stack));
    len = Index = 0;
    for(int i = 1;i <= N;i++)
        if (!DFN[i])
            Tarjan(i);
            
    memset(d, 0, sizeof(d));
    r.clear();
    for(int i = 1;i <= N;i++)
    {
        for(int j = e.last[i];j;j = e.succ[j])
        {
            int y = e.other[j];
            if (color[i] != color[y])
            {
                r.AddEdge(color[i], color[y]);
                d[color[y]]++;
            }
        }
    }
    e.clear();
    for(int i = 1;i <= e1num;i++)
    {
        if (color[e1[i].a] != color[e1[i].b])
            e.AddEdge(color[e1[i].a], color[e1[i].b], e1[i].id);
    }
    memset(visit, 0, sizeof(visit));
    for(int i = 1;i <= tot;i++)
        if (d[i] == 0 && i != color[1])
            visit[i] = 1;
    memset(flag, 0, sizeof(flag));
    eenum = 0;
    ansnum = 0;
    Dfs(color[1]);
    for(int i = 1;i <= eenum;i++)
    {
        if (visit[ee[i].b])
        {
            visit[ee[i].b] = 0;
            ans[++ansnum] = ee[i].id;
            Dfs(ee[i].b);
        }
    }
    int cnt = 0;
    for(int i = 1;i <= tot;i++)
        cnt += visit[i];
    if (cnt)
        printf("-1\n");
    else
    {
        printf("%d\n", ansnum);
        sort(ans + 1, ans + ansnum + 1);
        for(int i = 1;i <= ansnum;i++)
            printf("%d ", ans[i]);
    }
    return 0;
}