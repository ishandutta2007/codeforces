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
int d[2005][2005],pre[2005],dis[2005];
bool vis[2005];
int main()
{
    int n,i,j,mind,x,p;
    cin>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            scanf("%d",&d[i][j]);
            if(i==j&&d[i][j]!=0)
            {
                printf("NO\n");
                return 0;
            }
            if(i!=j&&d[i][j]==0)
            {
                printf("NO\n");
                return 0;
            }
            if(j<i&&d[i][j]!=d[j][i])
            {
                printf("NO\n");
                return 0;
            }
        }
    dis[1]=0;
    for(i=2;i<=n;i++)
        dis[i]=d[1][i],pre[i]=1;
    vis[1]=1;
    for(i=2;i<=n;i++)
    {
        mind=1000000007;
        for(j=1;j<=n;j++)
        {
            if(mind>dis[j]&&!vis[j])
            {
                x=j;
                mind=dis[j];
            }
        }
        p=pre[x];
        for(j=1;j<=n;j++)
            if(vis[j]&&d[j][p]+d[p][x]!=d[j][x])
            {
                printf("NO\n");
                return 0;
            }
        vis[x]=1;
        for(j=1;j<=n;j++)
            if(!vis[j]&&dis[j]>d[x][j])
                dis[j]=d[x][j],pre[j]=x;
    }
    printf("YES\n");
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);