#include <bits/stdc++.h>

using namespace std;

const int N = 500043;
const int K = 750;

int a[N];
int sum[K][K];

int main()
{
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++)
    {
        int t, x, y;
        scanf("%d %d %d", &t, &x, &y);
        if(t == 1)
        {
            a[x] += y;
            for(int i = 1; i < K; i++)
                sum[i][x % i] += y;
        }
        else
        {
            if(x >= K)
            {
                int ans = 0;
                for(int i = y; i <= 500000; i += x)
                    ans += a[i];
                printf("%d\n", ans);
            }
            else
                printf("%d\n", sum[x][y]);
        }
    }
    return 0;
}