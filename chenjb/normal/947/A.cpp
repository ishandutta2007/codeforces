#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;
int cnt;
int prime[2000000],save[2000000];
int vis[2000000];
void prepare()
{
    memset(vis,0,sizeof(vis));
    save[1] = 1;
    for(int i=2;i<=1000001;i++)
    {
        if (!vis[i])
        {
            prime[++cnt]=i;
            save[i]=i;
        }
        for (int j=1;j<=cnt&&i*prime[j]<=1000001;j++)
        {
            vis[i*prime[j]]=1;
            save[i*prime[j]]=prime[j];
            if (i%prime[j]==0)break;
        }
    }
}
int a[1100000];
int main()
{
    prepare();
    int n;
    cin>>n;
    int start = n;
    int ans = n;
    for(int i=1;i<=cnt;i++)
        if (n%prime[i])continue;
        else start = min(start, n - prime[i] + 1);
    
    for(int i=start;i<=n;i++)
    {
        cnt=0;
        int now=i;
        while (1)
        {
            if (now<=1)break;
            a[++cnt]=save[now];
            now/=save[now];
        }
        for(int j=1;j<=cnt;j++)
            if (i-a[j]>0)ans=min(ans,i-a[j]+1);
    }
    cout<<ans<<endl;
    return 0;
}