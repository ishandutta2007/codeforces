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
#define N 100005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int p[N][2],du[N];
int st[N],zt[N],flag=1;
int vis1[N],vis2[N];
vector<int> G[N];
vector<int> ch,vi;

void dfs(int x)
{
    int i,v,j;
    vis2[x]=1;
    for(i=0;i<G[x].size();i++)
    {
        v=G[x][i];
            if(vis2[p[v][0]]&&vis2[p[v][1]])
            {
                if((st[v]^zt[p[v][0]]^zt[p[v][1]])==0)
                    flag=0;
            }
            else
                for(j=0;j<=1;j++)
                    if(!vis2[p[v][j]])
                    {
                        zt[p[v][j]]=st[v]^zt[p[v][j^1]]^1;
                        dfs(p[v][j]);
                    }

    }
}

int main()
{
    int n,m,i,k,j,x;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        scanf("%d",&st[i]);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&k);
        for(j=1;j<=k;j++)
        {
            scanf("%d",&x);
            G[i].push_back(x);
            p[x][du[x]++]=i;
        }
    }
    for(i=1;i<=m;i++)
    {
        if(!vis2[i])
            dfs(i);
    }
    if(flag==0)
        printf("NO\n");
    else printf("YES\n");
    return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*
3 3
0 1 0
2 1 3
2 2 3
2 1 2

*/