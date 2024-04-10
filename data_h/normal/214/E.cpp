#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int N, Mat[400][400];
int f[610][310][310];

void Init()
{
    scanf("%d", &N);
    for(int i = 1;i <= N;i++)
        for(int j = 1;j <= N;j++)
            scanf("%d", &Mat[i][j]);
}

void Work()
{
    for(int i = 0;i <= 2 * N;i++)
        for(int j = 0;j <= N;j++)
            for(int k = 0;k <= N;k++)
                f[i][j][k] = -2000000000;
    f[0][0][0] = 0;
    for(int i = 0;i < 2 * (N - 1);i++)
        for(int j = 0;j <= i && j < N;j++)
            for(int k = 0;k <= i && k < N;k++)
            if (f[i][j][k] >= -200000000)
            {
                int j1 = j + 1, j2 = 1 + i - j, k1 = k + 1, k2 = 1 + i - k, tmp = Mat[j1][j2] + Mat[k1][k2];
                if (j1 == k1 && j2 == k2)
                    tmp /= 2;
                if (j1 + 1 <= N && k1 + 1 <= N)
                    f[i + 1][j + 1][k + 1] = max(f[i + 1][j + 1][k + 1], f[i][j][k] + tmp);
                if (j1 + 1 <= N && k2 + 1 <= N)
                    f[i + 1][j + 1][k] = max(f[i + 1][j + 1][k], f[i][j][k] + tmp);
                if (j2 + 1 <= N && k1 + 1 <= N)
                    f[i + 1][j][k + 1] = max(f[i + 1][j][k + 1], f[i][j][k] + tmp);
                if (j2 + 1 <= N && k2 + 1 <= N)
                    f[i + 1][j][k] = max(f[i + 1][j][k], f[i][j][k] + tmp);
            }
    printf("%d\n", f[2 * (N - 1)][N - 1][N - 1] + Mat[N][N]);
}

int main()
{

    Init();
    Work();
    return 0;
}