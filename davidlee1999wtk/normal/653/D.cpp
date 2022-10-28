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
#define N 55
#define M 505
#define P 1000000007
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
struct Edge
{
	int from,to,cap,flow,pre;
}e[M*2];
int cou=0,s,t;
int h[N];
int cur[N],d[N];
bool vis[N];
void Addedge(int from,int to,int cap)
{
	cou++;
	e[cou]=((Edge){from,to,cap,0,h[from]});
	h[from]=cou;
	cou++;
	e[cou]=((Edge){to,from,0,0,h[to]});
	h[to]=cou;
}

bool BFS()
{
    memset(vis,0,sizeof(vis));
    int i,x,v;
    queue<int> q;
    q.push(s),d[s]=0,vis[s]=1;
    while(!q.empty())
    {
        x=q.front(); q.pop();
        for(i=h[x];i;i=e[i].pre)
        {
            v=e[i].to;
            if(!vis[v]&&e[i].cap>e[i].flow)
            {
                q.push(v),vis[v]=1;
                d[v]=d[x]+1;
                if(v==t) return 1;
            }
        }
    }
    return 0;
}

int DFS(int x,int a)
{
    if(x==t||a==0) return a;
    int &i=cur[x];
    int flow=0,f,v;
    for(;i;i=e[i].pre)
    {
        v=e[i].to;
        if(d[v]==d[x]+1&&(f=DFS(v,min(a,e[i].cap-e[i].flow)))>0)
        {
            flow+=f;
            e[i].flow+=f;
            e[((i-1)^1)+1].flow-=f;
            a-=f;
            if(a==0) break;
        }
    }
    return flow;
}

int Maxflow()
{
    int i,flow=0;
    while(BFS())
    {
        for(i=s;i<=t;i++)
            cur[i]=h[i];
        flow+=DFS(s,INF);
    }
    return flow;
}
int n,m,x,fr[M],to[M];
double cap[M];

void build_graph(double lim)
{
    int i;
    memset(h,0,sizeof(h));
    cou=0;
    for(i=1;i<=m;i++)
    {
        Addedge(fr[i],to[i],int(min(cap[i]/lim,double(x)+1.0)));
        //debug(int(cap[i]/lim));
    }
}

int main()
{
    double l=0,r=1000000,mid;
    int i;
    cin>>n>>m>>x;
    for(i=1;i<=m;i++)
        scanf("%d%d%lf",&fr[i],&to[i],&cap[i]);
    s=1,t=n;
    for(i=1;i<=70;i++)
    {
        mid=(l+r)/2;
        build_graph(mid);
        if(mid<1e-9)
            break;
        if(Maxflow()>=x)
            l=mid;
        else r=mid;
    }
    printf("%.12f\n",l*x);
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
//ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000")
//#define O2 __attribute__((optimize("-O2")))