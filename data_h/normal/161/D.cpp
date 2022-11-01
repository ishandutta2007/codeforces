#include <cstdio>
#include <cstdlib>
const int MAXN = 51000;
int dp[MAXN][510], up[MAXN][510];
int q[MAXN];
struct fetch
{
    int y;
    fetch *next;
}*e[MAXN * 2], Me[MAXN * 2];
int use, N, K, visit[MAXN], fa[MAXN];

void Link(int x,int y)
{
    fetch *Tmp = e[x];
    e[x] = &Me[++use];
    e[x]->y = y;
    e[x]->next = Tmp;
}

void Init()
{
    scanf("%d %d",&N,&K);
    for(int i = 1;i < N;i++)
    {
        int x, y;
        scanf("%d %d",&x,&y);
        Link(x, y);
        Link(y, x);
    }
    q[1] = 1; visit[1] = 1;
    int t = 0,w = 1;
    while(t < w)
    {
        int x = q[++t];
        for(fetch *Tmp = e[x];Tmp != NULL;Tmp = Tmp->next)
        {
            if (!visit[Tmp->y])
            {
                int y = Tmp->y;
                fa[y] = x;
                visit[y] = 1;
                q[++w] = y;
            }
        }
    }
}

void Work()
{
    for(int i = N;i >= 1;i--)
    {
        int x = q[i];
        for(fetch *Tmp = e[x];Tmp != NULL;Tmp = Tmp->next)
        {
            int y = Tmp->y;
            if (y == fa[x])
                continue;
            for(int l = 1;l <= K;l++)
                dp[x][l] += dp[y][l - 1];
        }
        dp[x][0]++;
    }
    for(int i = 2;i <= N;i++)
    {
        int x = q[i];
        int p = fa[x];
        for(int l = 1;l <= K;l++)
        {
            up[x][l] += up[p][l - 1];
            up[x][l] += dp[p][l - 1];
            if (l > 1)
                up[x][l] -= dp[x][l - 2];
        }
    }
    long long Ans = 0;
    for(int i = 1;i <= N;i++)
    {
        Ans += dp[i][K];
        Ans += up[i][K];
    }
    printf("%I64d\n",Ans / 2);
}

int main()
{
    Init();
    Work();
    return 0;
}