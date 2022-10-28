#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<utility>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<queue>
#include<stack>
#include<bitset>
#include<ctime>
#include<deque>
#define N 100005
#define M 1005
#define P 1000000007
#define INF 1000000000
#define fi first
#define se second
#define debug(x) cerr<<#x<<' '<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
vector<int> G[N];
int a[M][M],flip[M],op[N],qx[N],qy[N],ans[N],sz[M];
int n,m,now=0;
void dfs(int x)
{
    int flag=0,i;
    if(op[x]==1)
        if(!(a[qx[x]][qy[x]]^flip[qx[x]]))
        {
            a[qx[x]][qy[x]]^=1;
            now++;
            sz[qx[x]]++;
            flag=1;
        }
    if(op[x]==2)
        if((a[qx[x]][qy[x]]^flip[qx[x]]))
        {
            a[qx[x]][qy[x]]^=1;
            now--;
            sz[qx[x]]--;
            flag=2;
        }
    if(op[x]==3)
    {
        flip[qx[x]]^=1;
        now+=m-sz[qx[x]]*2;
        sz[qx[x]]=m-sz[qx[x]];
        flag=3;
    }
    if(op[x]==4)
        ;

    ans[x]=now;
    for(i=0;i<G[x].size();i++)
        dfs(G[x][i]);

    if(flag==1)
    {
        a[qx[x]][qy[x]]^=1;
        now--;
        sz[qx[x]]--;
    }
    if(flag==2)
    {
        a[qx[x]][qy[x]]^=1;
        now++;
        sz[qx[x]]++;
    }
    if(flag==3)
    {
        flip[qx[x]]^=1;
        now+=m-sz[qx[x]]*2;
        sz[qx[x]]=m-sz[qx[x]];
    }
}

int main()
{
    int q,i;
    cin>>n>>m>>q;
    for(i=1;i<=q;i++)
    {
        scanf("%d",&op[i]);
        if(op[i]==1)
            scanf("%d%d",&qx[i],&qy[i]);
        else if(op[i]==2)
            scanf("%d%d",&qx[i],&qy[i]);
        else if(op[i]==3)
            scanf("%d",&qx[i]);
        else
        {
            scanf("%d",&qx[i]);
            G[qx[i]].push_back(i);
        }
        if(op[i]!=4)
            G[i-1].push_back(i);
    }
    dfs(0);
    for(i=1;i<=q;i++)
        printf("%d\n",ans[i]);
    return 0;
}
//ios::sync_with_stdio(false);