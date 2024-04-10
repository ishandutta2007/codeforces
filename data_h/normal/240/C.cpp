#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 1100;

struct group
{
    int num;
    int bak[MAXN];
    void insert(int x)
    {
        bak[++num] = x;
    }
}w;

int N, ans[MAXN][MAXN], len[MAXN], MD;
void Init()
{
    scanf("%d", &N);
}

void Dfs(int dep, group q)
{
    if (q.num <= 1)
        return;
    MD = max(MD, dep);
    group a, b;
    a.num = b.num = 0;
    for(int i = 1;i <= (q.num + 1) / 2;i++)
    {
        ans[dep][++len[dep]] = q.bak[i];
        a.insert(q.bak[i]);
    }
    for(int i = (q.num + 1) / 2 + 1;i <= q.num;i++)
        b.insert(q.bak[i]);
    Dfs(dep + 1, a);
    Dfs(dep + 1, b);
}

void Work()
{
    w.num = 0;
    for(int i = 1;i <= N;i++)
        w.insert(i);
    Dfs(1, w);
    printf("%d\n", MD);
    for(int i = 1;i <= MD;i++)
    {
        printf("%d ", len[i]);
        for(int j = 1;j <= len[i];j++)
            printf("%d ", ans[i][j]);
        printf("\n");
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Init();
    Work();
    return 0;
}