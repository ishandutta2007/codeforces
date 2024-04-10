#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 200000;
int N, M, father[MAXN];
struct Edge
{
    int x, y, val, num;
}edge[MAXN * 2];

struct fetch
{
    int y, num;
    fetch *next, *op;
}*f[MAXN];
int DFN[MAXN], low[MAXN], Index;
int Ans[MAXN];

int cmp(Edge a,Edge b)
{
    return a.val < b.val;
}

void Init()
{
    scanf("%d %d",&N,&M);
    for(int i = 1;i <= M;i++)
    {
        scanf("%d %d %d",&edge[i].x,&edge[i].y,&edge[i].val);
        edge[i].num = i;
    }
    sort(edge + 1,edge + M + 1,cmp);
}

void Link(int x,int y,int num)
{
    fetch *Tmp = f[x];
    f[x] = new(fetch);
    f[x]->y = y;
    f[x]->next = Tmp;
    f[x]->num = num;
    
        Tmp = f[y];
    f[y] = new(fetch);
    f[y]->num = num;
    f[y]->y = x;
    f[y]->next = Tmp;
    f[x]->op = f[y];
    f[y]->op = f[x];
}

int find(int x)
{
    int p = x, t;
    while(father[p] != p)
        p = father[p];
    while(father[x] != x)
    {
        t = father[x];
        father[x] = p;
        x = t;
    }
    return p;
}

void Tarjan(int x,fetch *Fe)
{
    DFN[x] = low[x] = ++Index;
    for(fetch *Tmp = f[x];Tmp != NULL;Tmp = Tmp->next)
    if (Tmp != Fe)
    {
        int y = Tmp->y;
        if (!DFN[y])
        {
            Tarjan(y, Tmp->op);
            low[x] = min(low[x], low[y]);
            if (low[y] > DFN[x])
            {
                Ans[Tmp->num] = 1;
            }
        }
        else
            low[x] = min(low[x], DFN[y]);
    }
}

void Work()
{
    for(int i = 1;i <= N;i++)
        father[i] = i;
    for(int i = 1, j;i <= M;i++)
    {
        if (i == 4)
            i = 4;
        for(j = i;edge[j].val == edge[i].val && j <= M;j++);
        for(int k = i;k < j;k++)
        {
            int u = find(edge[k].x), v = find(edge[k].y);
            if (u == v)
                continue;
            Ans[edge[k].num] = 2;
            DFN[u] = low[u] = 0;
            DFN[v] = low[v] = 0;
            f[u] = f[v] = NULL;
        }
        for(int k = i;k < j;k++)
        {
            int u = father[edge[k].x], v = father[edge[k].y];
            if (u == v)
                continue;
            Link(u, v, edge[k].num);
        }
        Index = 0;
        for(int k = i;k < j;k++)
        {
            int u = father[edge[k].x], v = father[edge[k].y];
            if (u == v)
                continue;
            if (!DFN[u])
                Tarjan(u, NULL);
            if (!DFN[v])
                Tarjan(v, NULL);
        }
        for(int k = i;k < j;k++)
        {
            int u = find(edge[k].x), v = find(edge[k].y);
            father[father[u]] = v;
        }
        i = j - 1;
    }
}

void Write()
{
    for(int i = 1;i <= M;i++)
    if (Ans[i] == 2)
        printf("at least one\n");
    else
    if (Ans[i] == 1)
        printf("any\n");
    else
    printf("none\n");
}

int main()
{
    Init();
    Work();
    Write();
    return 0;
}