#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a[1 << 20];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    
    sort(a, a + n);
    long long ans = 0;
    long long sm = 0;
    for (int i = 0; i < n; ++i)
        sm += a[i];
    ans = sm;
    if (n > 1)
    {
        for (int i = 0; i < n - 1; ++i)
        {
            ans += sm;
            sm -= a[i];
        }
    }

    cout << ans << endl;
    return 0;
}