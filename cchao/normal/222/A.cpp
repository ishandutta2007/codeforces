#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    for(int i = 1; i <= n ; i ++) scanf("%d", &a[i]);
    for(int i = k + 1; i <= n; i++)
    {
        if(a[i] != a[k])
        {
            printf("-1\n");
            return 0;
        }
    }
    int i;
    for(i = k - 1; i >= 1; i--)
    {
        if(a[i] != a[k]) break;
    }
    printf("%d\n",i);
    return 0;
}