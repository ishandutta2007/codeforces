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
using namespace std;
typedef long long LL;
int n,m,k;
int x[105][105],lc[105],lm[105],use[105];
int main()
{
    int i,j;
    cin>>n>>m>>k;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&x[i][j]);
    for(j=1;j<=m;j++)
    {
        memset(use,0,sizeof(use));
        for(i=1;i<=n;i++)
        {
            if(lc[i]) continue;
            if(x[i][j]==0) continue;
            if(lm[x[i][j]])
            {
                lc[i]=j;
                continue;
            }
            if(use[x[i][j]])
            {
                lm[x[i][j]]=1;
                lc[i]=lc[use[x[i][j]]]=j;
                continue;
            }
            else use[x[i][j]]=i;
        }
    }
    for(i=1;i<=n;i++)
        printf("%d\n",lc[i]);
    return 0;
}
// davidlee1999WTK 2014/
//ios::sync_with_stdio(false);