#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int mod = 1000000007;

long long f[10][200][2], C[300][300];
int a[200], N;

int main()
{

    for(int i = 0;i <= 100;i++)
        C[i][0] = 1;
    for(int i = 1;i <= 100;i++)
        for(int j = 1;j <= 100;j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    scanf("%d", &N);
    int cnt = 0;
    for(int i = 0;i < 10;i++)
        scanf("%d", &a[i]), cnt += a[i];
    if (cnt > N)
    {
        printf("0\n");
        return 0;
    }
    N--;
    long long Ans = 0;
    for(int len = max(cnt - 1, 0);len <= N;len++)
    {
        for(int i = 0;i <= 9;i++)
            for(int j = 0;j <= N;j++)
                for(int k = 0;k <= 1;k++)
                    f[i][j][k] = 0;
        f[0][0][0] = 1;
        for(int i = 0;i < 9;i++)
            for(int j = 0;j <= len;j++)
                for(int k = 0;k <= 1;k++)
                    if (f[i][j][k])
                    {
                        for(int l = a[i + 1];j + l <= len;l++)
                        {
                            f[i + 1][j + l][k] += f[i][j][k] * C[len - j][l] % mod;
                            f[i + 1][j + l][k] %= mod;
                        }
                        for(int l = max(a[i + 1] - 1, 0);k == 0 && j + l <= len;l++)
                        {
                            f[i + 1][j + l][1] += f[i][j][k] * C[len - j][l] % mod;
                            f[i + 1][j + l][1] %= mod;
                        }
                    }
        
        for(int i = 0;i + a[0] <= len;i++)
        {
            Ans += f[9][i][1];
            Ans %= mod;
        }
    }
    printf("%I64d\n", Ans);
//  system("pause");
    return 0;
}