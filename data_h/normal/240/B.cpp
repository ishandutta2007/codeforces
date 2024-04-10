#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 201, inf = 1000000000;

int f[MAXN][MAXN * MAXN];
int g[MAXN][MAXN * MAXN];
int h[MAXN], sum[MAXN], a, b, N;

void Init()
{
    scanf("%d %d %d", &N, &a, &b);
    for(int i = 1;i <= N;i++)
    {
        scanf("%d", &h[i]);
        sum[i] = sum[i - 1] + h[i];
    }       
}

void Work()
{
    for(int i = 1;i <= N;i++)
        for(int j = 0;j <= a;j++)
            f[i][j] = g[i][j] = inf;
    if (h[1] <= a)
        f[1][h[1]] = 0;
    if (h[1] <= b)
        g[1][0] = 0;
    for(int i = 1;i < N;i++)
        for(int j = 0;j <= a;j++)
            {
                if (f[i][j] < inf)
                {
                    if (sum[i + 1] - j <= b)
                    {
                        g[i + 1][j] = min(g[i + 1][j], f[i][j] + min(h[i], h[i + 1]));
                    }
                    if (j + h[i + 1] <= a)
                    {
                        f[i + 1][j + h[i + 1]] = min(f[i + 1][j + h[i + 1]], f[i][j]);
                    }
                }
                if (g[i][j] < inf)
                {
                    if (sum[i + 1] - j <= b)
                    {
                        g[i + 1][j] = min(g[i + 1][j], g[i][j]);
                    }
                    if (j + h[i + 1] <= a)
                    {
                        f[i + 1][j + h[i + 1]] = min(f[i + 1][j + h[i + 1]], g[i][j] + min(h[i], h[i + 1]));
                    }
                }
            }
    int Ans = inf;
    for(int i = 0;i <= a;i++)
        Ans = min(Ans, min(f[N][i], g[N][i]));
    if (Ans == inf)
        printf("-1\n");
    else
        printf("%d\n", Ans);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Init();
    Work();
    return 0;
}