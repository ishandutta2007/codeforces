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
#define K 60
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

struct Edge
{
    int from,to;
    LL dis;
    int pre;
}e[N*2];
int h[N],cou,vis[N];
int tot,cnt,zy[65],c[65][2],sz,dfn;
bool app[65];
LL lb[N],dep[N];
void Addedge(int from,int to,LL dis)
{
    cou++;
    e[cou]=(Edge){from,to,dis,h[from]};
    h[from]=cou;
}

void Add_vec(LL v)
{
    int i,flag=0;
    //debug(v);
    lb[++tot]=v;
    for(i=0;i<=K;i++)
        if(lb[tot]&(1ll<<i))
        {
            app[i]=1;
            if(!zy[i])
            {
                if(!flag)
                {
                    zy[i]=tot;
                    cnt++;
                    flag=1;
                    //break;
                }
            }
            else
                lb[tot]^=lb[zy[i]];
        }
}

void dfs(int x,int fa)
{
    vis[x]=++dfn;
    //debug(dep[x]);
    //debug(x);
    sz++;
    int i,v;
    for(i=0;i<=K;i++)
        if(dep[x]&(1ll<<i))
            c[i][1]++;
        else c[i][0]++;
    for(i=h[x];i;i=e[i].pre)
    {
        v=e[i].to;
        if(vis[v]&&v!=fa&&vis[v]<vis[x])
        {
            //debug(x);
            //debug(v);
            Add_vec(e[i].dis^dep[x]^dep[v]);
        }
        else if(!vis[v])
        {
            dep[v]=dep[x]^e[i].dis;
            dfs(v,x);
        }
    }
}

int main()
{
    int n,m,a,b,i,ans=0,rt;
    LL d;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%I64d",&a,&b,&d);
        Addedge(a,b,d);
        Addedge(b,a,d);
    }
    for(rt=1;rt<=n;rt++)
        if(!vis[rt])
        {
            //debug(rt);
            tot=cnt=sz=0;
            memset(zy,0,sizeof(zy));
            memset(c,0,sizeof(c));
            memset(app,0,sizeof(app));
            dfs(rt,0);
            for(i=0;i<=K;i++)
            {
                //debug(app[i]);
                //debug(c[i][0]);
                //debug(c[i][1]);
                if(app[i])
                    ans=(ans+((1ll<<i)%P)*((1ll<<cnt-1)%P)%P*((LL)sz*(sz-1)/2%P))%P;
                else ans=(ans+((1ll<<i)%P)*((1ll<<cnt)%P)%P*((LL)c[i][0]*c[i][1]%P))%P;
            }
            //debug(ans);
        }
    //debug(vis[7]);
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*
6 5
1 2 2
2 3 1
2 4 4
4 5 5
4 6 3
*/