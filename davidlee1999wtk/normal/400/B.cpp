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
int dis[1005]={-1};
char mp[1005][1005];
int main()
{
    int i,j,n,m,flag=0,ans=0;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        scanf("%s",mp[i]);
    for(i=1;i<=n;i++)
    {
        flag=0;
        for(j=0;j<m;j++)
        {
            if(!flag&&mp[i][j]=='G')
                flag=j+1;
            if(flag==0&&mp[i][j]=='S')
            {
                printf("-1\n");
                return 0;
            }
            else if(flag&&mp[i][j]=='S')
                dis[i]=j+1-flag;
        }
    }
    sort(dis+1,dis+1+n);
    for(i=1;i<=n;i++)
        if(dis[i]>dis[i-1])
            ans++;
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2014/