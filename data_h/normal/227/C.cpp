#include <cstdio>
#include <cstdlib>
int N, M;
struct mat
{
    long long dat[2][2];
    friend mat operator *(mat a, mat b)
    {
        mat c;
        for(int i = 0;i <= 1;i++)
            for(int j = 0;j <= 1;j++)
            {
                c.dat[i][j] = 0;
                for(int k = 0;k <= 1;k++)
                    c.dat[i][j] = (c.dat[i][j] + a.dat[i][k] * b.dat[k][j]) % M;
            }
        return c;
    }
}a, b;

int main()
{
 
    scanf("%d %d", &N, &M);
    a.dat[0][0] = 0; a.dat[1][0] = 1;
    b.dat[0][0] = 3, b.dat[0][1] = 2;
    b.dat[1][0] = 0, b.dat[1][1] = 1;
    while(N)
    {
        if (N % 2 == 1)
            a = b * a;
        N /= 2;
        b = b * b;
    }
    printf("%I64d", a.dat[0][0]);
    return 0;
}