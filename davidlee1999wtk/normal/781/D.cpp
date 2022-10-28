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
#define N 505
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
bitset<505> f[61][N],ff[61][N],g[61][N],gg[61][N],vd;
bool vis[N][61];
int calc(LL x)
{
    int cnt=0;
    while(x)
        x-=x&-x,cnt++;
    return cnt%2;
}//1

vector<int> ver;
int main()
{
    int i,j,k,n,m,a,b,op,x,sz,flag,ch;
    LL ans=0;
    //debug(LL(1e18));
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&op);
        if(op==0)
        {
            f[0][a][b]=1;
            ff[0][b][a]=1;
        }
        else
        {
            g[0][a][b]=1;
            gg[0][b][a]=1;
        }
    }
    for(k=1;k<=60;k++)
    {
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                if((f[k-1][i]&gg[k-1][j])!=vd)
                {
                    f[k][i][j]=1;
                    ff[k][j][i]=1;
                }
                if((g[k-1][i]&ff[k-1][j])!=vd)
                {
                    g[k][i][j]=1;
                    gg[k][j][i]=1;
                }
            }
    }
    for(i=1;i<=n;i++)
        if(f[60][1][i]==1)
        {
            printf("-1\n");
            return 0;
        }
    queue<int> q;
    q.push(1);
    k=59;
    //vis[1][59]=1;
    while(!q.empty())
    {
        sz=q.size();
        flag=0;
        ver.clear();
        while(sz--)
        {
            x=q.front();
            q.pop();
            ver.push_back(x);
        }
        while(k>=0)
        {
            flag=0;
            ch=calc(ans+1);
            for(i=0;i<ver.size();i++)
            {
                x=ver[i];
                for(j=1;j<=n;j++)
                    if(!vis[j][k])
                        if(ch==1)
                        {
                            if(f[k][x][j]==1)
                            {
                                flag=1;
                                vis[j][k]=1;
                                q.push(j);
                            }
                        }
                        else
                            if(g[k][x][j]==1)
                            {
                                flag=1;
                                vis[j][k]=1;
                                q.push(j);
                            }
            }
            if(flag) break;
            k--;
        }
        if(k!=-1)
        {
            ans+=(1ll<<k);
            k--;
        }
        else break;
    }
    if(ans>1e18)
    {
        printf("-1\n");
        return 0;
    }
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/