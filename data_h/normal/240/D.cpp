#include <cstdio>
#include <cstdlib>

const int MAXN = 210000;

int n, m, a[MAXN], b[MAXN], ans[MAXN], len, bak[MAXN];

void Init()
{
    scanf("%d", &n);
    for(int i = 1;i <= n;i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for(int i = 1;i <= m;i++)
        scanf("%d", &b[i]);
}

int Calc(int now, int put = 0)
{
    int nn = 1, mm = 1;
    len = 0;
    while(nn <= n || mm <= m)
    {
        while(nn <= n && a[nn] == now)
        {
            if (put) printf("%d ", nn);
            ans[++len] = a[nn];
            nn++;
        }
        while(mm <= m && b[mm] == now)
        {
            if (put) printf("%d ", mm + n);
            ans[++len] = b[mm];
            mm++;
        }
        now ^= 1;
    }   
    ans[len + 1] = 0;
    int res = 0;
    for(int i = 1;i <= len;i++)
    {
        if (ans[i] != ans[i + 1])
        {
            bak[++res] = i;
        }
    }
    if (put)
    {
        printf("\n%d\n", res);
        for(int i = 1;i <= res;i++)
            printf("%d ", bak[i]);
    }
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Init();
    if (Calc(1) < Calc(0))
        Calc(1, 1);
    else
        Calc(0, 1);
    return 0;
}