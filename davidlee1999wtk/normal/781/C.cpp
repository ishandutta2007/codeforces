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
#include<string>
#include<bitset>
#include<iomanip>
#include<deque>
#include<utility>
#define INF 1000000000
#define fi first
#define se second
#define N 200005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int n;
int xl[N*2],vis[N],tot;
vector<int> G[N];
void dfs(int x)
{
    xl[++tot]=x;
    int v,i;
    vis[x]=1;
    for(i=0;i<G[x].size();i++)
    {
        v=G[x][i];
        if(!vis[v])
        {
            dfs(v);
            xl[++tot]=x;
        }
    }
}

int main()
{
    int m,k,a,b,l,i,j,t;
    cin>>n>>m>>k;
    l=(2*n-1)/k+1;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1);
    for(i=1;i<=k;i++)
    {
        j=(i-1)*l+1;
        if(j>tot) j=tot;
        printf("%d ",min(tot-j+1,l));
        t=min(tot,j+l-1);
        for(;j<=t;j++)
            printf("%d ",xl[j]);
        printf("\n");
    }
    return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/