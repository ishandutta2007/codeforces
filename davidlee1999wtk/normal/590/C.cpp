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
#define N 100005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
char mp[1005][1005];
int dis[5][5],dx[5]={-1,1,0,0},dy[5]={0,0,-1,1},n,m,d[4][1005][1005];
bool vis[1005][1005];
void BFS(int num)
{
    queue<pii> q;
    memset(vis,0,sizeof(vis));
    int i,j,ti,tj,k;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(mp[i][j]-48==num)
                vis[i][j]=1,d[num][i][j]=-1,q.push(MP(i,j));
            else d[num][i][j]=-1;
    while(!q.empty())
    {
        i=q.front().fi;
        j=q.front().se;
        q.pop();
        for(k=0;k<4;k++)
        {
            ti=i+dx[k];
            tj=j+dy[k];
            if(ti<=n&&ti>=1&&tj<=m&&tj>=1)
                if(!vis[ti][tj]&&mp[ti][tj]!='#')
                {
                    d[num][ti][tj]=d[num][i][j]+1;
                    vis[ti][tj]=1;
                    q.push(MP(ti,tj));
                    if(mp[ti][tj]!='.')
                        if(dis[num][mp[ti][tj]-48]==-1)
                            dis[num][mp[ti][tj]-48]=d[num][i][j]+1;
                }

        }
    }
    return ;
}

int main()
{
    memset(mp,'#',sizeof(mp));
    memset(dis,-1,sizeof(dis));
    int i,j,sum,k;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        scanf("%s",mp[i]+1);
    BFS(1);
    BFS(2);
    BFS(3);
    for(i=1;i<=3;i++)
        for(j=1;j<=3;j++)
            if(i!=j&&dis[i][j]==-1)
            {
                printf("-1\n");
                return 0;
            }
    int ans=min(min(dis[1][2]+dis[1][3],dis[2][1]+dis[2][3]),dis[3][1]+dis[3][2]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(mp[i][j]=='.')
            {
                sum=0;
                for(k=1;k<=3;k++)
                    if(d[k][i][j]==-1)
                        break;
                    else sum+=d[k][i][j];
                if(k==4)
                    ans=min(ans,sum+1);
            }
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))