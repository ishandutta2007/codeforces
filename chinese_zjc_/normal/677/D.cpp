//This Code was made by Chinese_zjc_.
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<set>
#include<time.h>
// #include<windows.h>
#define int long long
#define PI 3.14159265358979323
#define INF 0x3fffffffffffffff
using namespace std;
int n,m,k,a[305][305],ans=INF,dis[305][305];
vector<pair<int,int> >  g[90005];
vector<int> dp[90005];
struct node{
    pair<int,int> l;
    const int first()
    {
        return l.first;
    }
    const int second()
    {
        return l.second;
    }
};
bool operator <(node A,node B)
{
    return dis[A.first()][A.second()]>dis[B.first()][B.second()];
}
priority_queue<node> que;
const int xx[]={1,0,-1,0},yy[]={0,1,0,-1};
void BFS(int now)
{
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            dis[i][j]=-1;
        }
    }
    for(int i=0;i<(int)g[now].size();++i)
    {
        dis[g[now][i].first][g[now][i].second]=dp[now][i];
        que.push((node){g[now][i]});
    }
    while(!que.empty())
    {
        pair<int,int> h=que.top().l;
        que.pop();
        for(int i=0;i<4;++i)
        {
            pair<int,int> nxt=make_pair(h.first+xx[i],h.second+yy[i]);
            if(!~dis[nxt.first][nxt.second])
            {
                dis[nxt.first][nxt.second]=dis[h.first][h.second]+1;
                que.push((node){nxt});
            }
        }
    }
    for(int i=0;i<(int)g[now+1].size();++i)
    {
        dp[now+1].push_back(dis[g[now+1][i].first][g[now+1][i].second]);
    }
}
void DP(int now)
{
    for(int i=0;i<(int)g[now+1].size();++i)
    {
        dp[now+1].push_back(INF);
        for(int j=0;j<(int)g[now].size();++j)
        {
            dp[now+1][i]=min(dp[now+1][i],dp[now][j]+abs(g[now+1][i].first-g[now][j].first)+abs(g[now+1][i].second-g[now][j].second));
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin>>a[i][j];
            g[a[i][j]].push_back(make_pair(i,j));
        }
    }
    g[0].push_back(make_pair(1,1));
    dp[0].push_back(0);
    for(int i=0;i<k;++i)
    {
        if((int)g[i].size()*(int)g[i+1].size()>n*m*log2(n*m))
        {
            BFS(i);
        }
        else
        {
            DP(i);
        }
    }
    for(int i=0;i<(int)dp[k].size();++i)
    {
        ans=min(ans,dp[k][i]);
    }
    cout<<ans<<endl;
    return 0;
}