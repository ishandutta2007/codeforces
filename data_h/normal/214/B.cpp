#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 200000;

int a[MAXN], N;
int f[MAXN][4], hash[MAXN][4];

int cmp(int a, int b)
{
    return a > b;
}

int main()
{
   
    scanf("%d", &N);
    for(int i = 1;i <= N;i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + N + 1, cmp);
    if (a[N] != 0)
    {
        printf("-1\n");
        return 0;
    }
    N--;
    if (a[1] == 0)
    {
        printf("%d\n", 0);
        return 0;
    }
    for(int i = 0;i <= N;i++)
        for(int j = 0;j < 3;j++)
            f[i][j] = -2000000;
    f[0][0] = 0;
    for(int i = 0;i < N;i++)
        for(int j = 0;j < 3;j++)
            if (f[i][j] >= 0)
            {
                f[i + 1][j] = max(f[i + 1][j], f[i][j]);
                f[i + 1][(j + a[i + 1]) % 3] = max(f[i + 1][(j + a[i + 1]) % 3], f[i][j] + 1);
            }
    int Ans = f[N][0];
    hash[N][0] = 1;
    for(int i = N - 1;i >= 0;i--)
        for(int j = 0;j < 3;j++)
        {
            if (f[i][j] == f[i + 1][j] && hash[i + 1][j])
                hash[i][j] = 1;
            if (f[i][j] + 1 == f[i + 1][(j + a[i + 1]) % 3] && hash[i + 1][(j + a[i + 1]) % 3])
                hash[i][j] = 1;
        }
    int flag = 0;
    int i = 0, j = 0;
    while(i < N)
    {
        if (hash[i + 1][(j + a[i + 1]) % 3])
        {
            if (flag == 0 && a[i + 1] == 0)
                break;
            flag = 1;
            printf("%d", a[i + 1]);
            j = (j + a[i + 1]) % 3;
        }
        i++;
    }
    printf("0\n");
    //system("pause");
    return 0;
}