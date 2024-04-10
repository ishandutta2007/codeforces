#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1.5e7+7;
 
int a[maxn],prime[maxn],cot,cnt[maxn];
bool vis[maxn];
 
void primeall()
{
    memset(vis,true,sizeof(vis));
    for(int i=2;i<maxn-7;i++)
    {
        if(vis[i])
            prime[++cot]=i;
        for(int j=1;j<=cot;j++)
        {
            if(i*prime[j]>maxn-7) break;
            vis[i*prime[j]]=false;
            if(i%prime[j]==0) break;
        }
    }
}
 
int main()
{
    primeall();
    int n;
    scanf("%d",&n);
 
    int gcd=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        gcd=__gcd(gcd,a[i]);
    }
 
    for(int i=1;i<=n;i++)
    {
        a[i]/=gcd;
        for(int j=1;prime[j]*prime[j]<=a[i];j++)
        {
            int p=prime[j];
            if(a[i]%p==0) cnt[p]++;
            while(a[i]%p==0) a[i]/=p;
        }
        if(a[i]>1) cnt[a[i]]++;
    }
 
    int ans=n;
    for(int i=2;i<maxn;i++)
        ans=min(ans,n-cnt[i]);
 
    printf("%d\n",ans==n?-1:ans);
    return 0;
}