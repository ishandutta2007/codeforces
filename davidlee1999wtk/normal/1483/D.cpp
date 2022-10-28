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
#define INF 1000000000
#define N 605
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int n, m;
LL dis[N][N], Left[N][N], len[N][N];
bool e[N][N], useful[N][N];
LL qu[N*N], qv[N*N], ql[N*N];
int main()
{
    cin >> n >> m;
    int i, j, k, u, v, t, w, q, ans = 0;
    for(u=1;u<=n;u++)
    {
        for(v=1;v<=n;v++)
            dis[u][v]= LL(INF)*INF;
        dis[u][u]=0;
    }

    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        len[u][v]=len[v][u]=dis[u][v]=dis[v][u]=w;
        e[u][v]=e[v][u]=1;
    }
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
    cin>>q;
    for(i=1;i<=q;i++)
    {
        scanf("%d%d%d", &qu[i], &qv[i], &ql[i]);
    }
    for(u=1;u<=n;u++)
    {
        for(v=1;v<=n;v++)
            Left[u][v]= -INF;
        for(i=1;i<=q;i++)
        {
            Left[u][qv[i]]=max(Left[u][qv[i]], ql[i]-(dis[qu[i]][u]+dis[u][qv[i]]));
        }
        for(v=1;v<=n;v++)
        {
            if(e[u][v])
                for(t=1;t<=n;t++)
                    if(len[u][v]+dis[v][t]-dis[u][t] <= Left[u][t])
                    {
                        ans++;
                        e[u][v]=e[v][u]=0;
                        break;
                    }
        }
    }
    cout<<ans<<endl;
}
// davidlee1999WTK 2021/
// srO myk Orz
//ios::sync_with_stdio(false);