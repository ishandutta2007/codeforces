#include <cstdio>
#include <cstdlib>

const int MAXN = 2000000;

int N, r, ans = 2000000000;
char opt[MAXN], ap[MAXN];

void Update(int B, int T)
{
    int len = 0;
    while(T != B && B >= 0 && T >= 0)
    {
        if (T > B)
        {
            opt[++len] = 'T';
            T -= B;
        }
        else
        {
            opt[++len] = 'B';
            B -= T;
        }
    }
    if (len != N - 1 || (B != 0 && T != 1))
        return;
    opt[++len] = 'T';
    int cnt = 0;
    for(int i = 1;i < len;i++)
        if (opt[i] == opt[i + 1])
            cnt++;
    if (cnt < ans)
    {
        ans = cnt;
        for(int i = 1;i <= len;i++)
            ap[len - i + 1] = opt[i];
    }
}

int main()
{
 
    scanf("%d %d", &N, &r);
    for(int i = 1;i <= r;i++)
    {
        Update(i, r);
        Update(r, i);
        
    }
    if (ans > 1000000000)
        printf("IMPOSSIBLE\n");
    else
    {
        printf("%d\n%s\n", ans, ap + 1);
    }
    return 0;
}