#include <cstdio>
#include <iostream>
using namespace std;
#define MAXN 200003
typedef long long LL;
int n, k;
int a[MAXN];
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    LL lft = 0; 
    LL ans = 0;
    for (int i = 0; i < n; ++i)
    {
        bool yest = lft > 0;
        lft += a[i];
        if (yest && lft < k)
        {
            ++ans;
            lft = 0;
        }
        ans += lft / k;
        lft %= k;
    }
    if (lft)
        ans++;
    cout << ans << endl;
    return 0;
}