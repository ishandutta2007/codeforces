#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#define INF 100000000
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int m[2005],t[2005],h[2005];
bool vis[2005];
int main()
{
    int n,i,j,x,sum,p=0,mx,mi,tot,ans=0;
    cin>>n>>x;
    for(i=1;i<=n;i++)
        scanf("%d%d%d",&t[i],&h[i],&m[i]);
    sum=x;
    tot=0;
    memset(vis,0,sizeof(vis));
    for(i=1;i<=n;i++,p^=1)
    {
        mx=0;
        for(j=1;j<=n;j++)
            if(t[j]==p&&m[j]>mx&&!vis[j]&&h[j]<=sum)
            {
                mx=m[j];
                mi=j;
            }
        if(!mx) break;
        tot++;
        sum+=mx;
        vis[mi]=1;
    }
    ans=max(ans,tot);

    p=1;
    sum=x;
    tot=0;
    memset(vis,0,sizeof(vis));
    for(i=1;i<=n;i++,p^=1)
    {
        mx=0;
        for(j=1;j<=n;j++)
            if(t[j]==p&&m[j]>mx&&!vis[j]&&h[j]<=sum)
            {
                mx=m[j];
                mi=j;
            }
        if(!mx) break;
        tot++;
        sum+=mx;
        vis[mi]=1;
    }
    ans=max(ans,tot);
    cout<<ans<<endl;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);