#include<bits/stdc++.h>
#define N 100009
using namespace std;
typedef long long LL;

LL a[N];

int main()
{
    int n, x, y, m;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    scanf("%d", &m);
    LL h = 1;
    LL mx = 0;
    for(int i = 1; i <= n; i++) mx = max(mx, a[i]);
    while(m--)
    {
        scanf("%d%d", &x, &y);
        if(mx > h) h = max(h, a[x]);
        printf("%I64d\n", h);
        h = h + y;
    }
    return 0;
}