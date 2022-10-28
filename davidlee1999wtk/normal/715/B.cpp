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
#define INF 1000000001
#define fi first
#define se second
#define N 1005
#define M 10005
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<LL,int> pii;
struct Edge
{
    int from,to,dis,pre;
}e[M*2];
int cou,h[N],dis[N],pre[N],pos[N],vis[N],flag[M*2];
void Addedge(int from,int to,int dis)
{
    cou++;
    e[cou]=(Edge){from,to,dis,h[from]};
    h[from]=cou;
    cou++;
    e[cou]=(Edge){to,from,dis,h[to]};
    h[to]=cou;
}

vector<int> E,P;

int Dijkstra(int n,int m,int s,int t)
{
    int i,x,v;
    priority_queue<pii,vector<pii>, greater<pii> > q;
    memset(vis,0,sizeof(vis));
    for(i=1;i<=n;i++)
        dis[i]=INF;
    dis[s]=0;

    q.push(MP(0,s));
    while(!q.empty())
    {
        x=q.top().se;
        //debug(x);
        q.pop();
        if(vis[x]) continue;
        if(x==t)
            break;
        vis[x]=1;
        for(i=h[x];i;i=e[i].pre)
        {
            v=e[i].to;
            //debug(v);
            if(e[i].dis!=INF&&dis[v]>dis[x]+e[i].dis)
            {
                dis[v]=dis[x]+e[i].dis;
                pre[v]=x;
                pos[v]=i;
                q.push(MP(dis[v],v));
            }
        }
    }
    return dis[t];
}

int main()
{
    int n,m,L,s,t,i,a,b,c,ans;
    cin>>n>>m>>L>>s>>t;
    s++,t++;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        a++,b++;
        Addedge(a,b,c);
        if(c==0)
        {
            flag[cou-1]=flag[cou]=1;
            E.push_back(cou-1),E.push_back(cou);
        }
    }

    for(i=0;i<E.size();i++)
        e[E[i]].dis=INF;
    ans = Dijkstra(n,m,s,t);
    if(ans < L)
    {
        debug(ans);
        printf("NO\n");
        return 0;
    }

    for(i=0;i<E.size();i++)
        e[E[i]].dis=1;
    ans = Dijkstra(n,m,s,t);
    //debug(ans);
    if(ans > L)
    {
        //debug(ans);
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    for(i=t;i!=s;i=pre[i])
    {
        //debug(i);
        if(flag[pos[i]])
            P.push_back(pos[i]);
    }
    for(i=0;i<E.size();i++)
        e[E[i]].dis=INF;
    for(i=0;i<P.size();i++)
    {
        e[P[i]].dis=1;
        e[((P[i]-1)^1)+1].dis=1;
    }
    for(i=0;i<P.size();i++)
    {
        e[P[i]].dis+=L-ans;
        e[((P[i]-1)^1)+1].dis+=L-ans;
        ans = Dijkstra(n,m,s,t);
        if(ans == L)
            break;
    }
    for(i=1;i<=m;i++)
        printf("%d %d %d\n",e[i*2].from-1,e[i*2].to-1,e[i*2].dis);
    return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/