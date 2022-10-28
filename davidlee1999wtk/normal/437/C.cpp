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
#define fi first
#define se second
#define INF 100000000
using namespace std;
typedef long long LL;
vector<int> e[1005];
typedef pair<int,int> pii;
pii u[1005];
int len[1005],vis[1005],v[1005];
int main()
{
    int i,n,m,a,b,x,j;
    LL sum=0;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        scanf("%d",&u[i].fi),u[i].se=i,v[i]=u[i].fi;
    sort(u+1,u+1+n);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        len[a]++,len[b]++;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for(i=n;i>=1;i--)
    {
        x=u[i].se;
        vis[x]=1;
        for(j=0;j<len[x];j++)
        {
           // printf("124");
            if(!vis[e[x][j]])
            {
             //   printf("12324\n");
                sum+=v[e[x][j]];
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
// davidlee1999WTK 2014/