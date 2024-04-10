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
#include<functional>
#include<sstream>
#define INF 1000000000
#define fi first
#define se second
#define N 1000005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int du[N],lp[N];
vector<int> G[N];
int x;
int vis[N],cnt;
void dfs(int x)
{
    vis[x]=1;
    cnt+=G[x].size()+lp[x];
    for(int i=0;i<G[x].size();i++)
        if(!vis[G[x][i]])
            dfs(G[x][i]);
}
int main()
{
    int n,m,a,b,i;
    LL ans=0,sl=0;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        if(a==b)
        {
            sl++;
            lp[a]++;
            continue;
        }
        ans+=du[a];
        du[a]++;
        ans+=du[b];
        du[b]++;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(i=1;i<=n;i++)
    {
        if(!vis[i])
            dfs(i);
        if(cnt!=0)
            break;
    }

    ans=ans+sl*(m-sl)+sl*(sl-1)/2;
    if(cnt==(m-sl)*2+sl)
        cout<<ans<<endl;
    else cout<<0<<endl;

}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/