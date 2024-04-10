#include <cstdio>
bool e[10] = {0};
int find(int x)
{
    while(x)
    {
        if(e[x%10]==true) return 1;
        x /= 10;
    }
    return 0;
}
int main()
{
    int n;
    scanf("%d", &n);
    int tmp = n;
    while(tmp)
    {
        e[tmp % 10] = true;
        tmp /= 10;
    }
    int ans = 0;
    for(int k = 1; k * k <= n; k++)
    {
        if(n % k == 0)
        {
            if(find(k))
                ans++;
            if(k * k != n && find(n/k)) ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}