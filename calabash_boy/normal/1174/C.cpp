#include<bits/stdc++.h>
using namespace std;
const int MAXN= 2e5 +5;
int vis[MAXN];
int a[MAXN];
int n;
void init()
{
    vis[0] = 1;
    vis[1] = 1;
    for(int i = 2;i < MAXN;i ++)
    {
        if(! vis[i])
        {
            vis[i] = 0;
            for(int j = 2*i;j <= MAXN; j += i)
            {
                vis[j] = 1;
            }
        }
    }
}
int gcd(int a,int b)
{
    if(b == 0)
    return a;
    else return gcd(b,a%b);
}
int main()
{
    int n;
    scanf("%d",&n);
    memset(vis,0,sizeof(vis));
    init();
    int cnt = 1;
    for(int i = 2;i <= n;i++)
    {
        if(!vis[i]) a[i] = cnt++;
        else
        {
            for(int j = 2;j <= i;j++)
            {
                if(gcd(i,j) != 1)
                {
                    a[i] = a[j];
                    break;
                }
            }
        }
    }
    for(int i = 2;i <= n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}