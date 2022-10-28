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
int chat[15],sp[20005],sum[20005];
int mp[20005][15];
int main()
{
    int n,m,k,i,j,a,b;
    cin>>n>>m>>k;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&mp[i][j]);
    for(i=1;i<=k;i++)
    {
        scanf("%d%d",&a,&b);
        sp[a]++;
        chat[b]++;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            sum[i]+=mp[i][j]*chat[j];
        sum[i]-=sp[i];
        printf("%d ",sum[i]);
    }
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);