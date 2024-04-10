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
#define M 140005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
struct Edge
{
    int from,to,cap,flow,pre;
    int num,op;
}e[M];
int cou,h[N],n,m,tot=0,s,t,d[N],cur[N];
bool vis[N];

inline void Addedge(int from,int to,int cap,int num,int op)
{
    cou++;
    e[cou]=(Edge){from,to,cap,0,h[from],num,op};
    //MakeEdge(e[cou],from,to,cap,0,h[from]);
    h[from]=cou;
    cou++;
    e[cou]=(Edge){to,from,cap,0,h[to],0,0};
    //MakeEdge(e[cou],to,from,0,0,h[to]);
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

int du[N];
pii E[M];

int main()
{
    int T,n,m,i,j,a,b,cnt;
    cin>>T;
    while(T--)
    {
        cou=0;
        tot=0;
        memset(h,0,sizeof(h));
        memset(du,0,sizeof(du));
        cin>>n>>m;
        cnt=n;
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&E[i].fi,&E[i].se);
            du[E[i].fi]++;
            du[E[i].se]++;
        }
        for(i=1;i<=m;i++)
        {
            a=E[i].fi,b=E[i].se;
            if(du[a]%2==1&&du[b]%2==1)
                continue;
            //if(du[a]%2==0&&du[b]%2==1)
                //Addedge(s,a,1,i,3);
            //if(du[b]%2==0&&du[a]%2==1)
                //Addedge(s,b,1,i,4);
            if(du[a]%2==0&&du[b]%2==0)
            {
                cnt++;
                Addedge(s,cnt,1,0,0);
                Addedge(cnt,a,1,i,1);
                Addedge(cnt,b,1,i,2);
            }
        }
        s=0,t=cnt+1;
        for(i=1;i<=n;i++)
            if(du[i]%2==0)
            {
                Addedge(i,t,du[i]/2,0,0);
                tot++;
            }
        //Maxflow();
        Maxflow();
        for(i=1;i<=m;i++)
        {
            a=E[i].fi,b=E[i].se;
            if(du[a]%2==1&&du[b]%2==1)
                continue;
            if(du[a]%2==0&&du[b]%2==1)
                Addedge(s,a,1,i,3);
            if(du[b]%2==0&&du[a]%2==1)
                Addedge(s,b,1,i,4);
            //if(du[a]%2==0&&du[b]%2==0)
            //{
                //Addedge(s,a,1,i,1);
                //Addedge(s,b,1,i,2);
            //}
        }
        Maxflow();
        for(i=1;i<=cou;i++)
        {
            if(!e[i].num)
                continue;
            //debug(e[i].from);
            //debug(e[i].to);
            //debug(e[i].flow);
            //debug(e[i].num);
            //debug(e[i].op);
            //cout<<endl;
            if(e[i].op==1)
                ;
            else if(e[i].op==2&&e[i].flow)
                swap(E[e[i].num].fi,E[e[i].num].se);
            else if(e[i].op==3&&!e[i].flow)
                swap(E[e[i].num].fi,E[e[i].num].se);
            else if(e[i].op==4&&e[i].flow)
                swap(E[e[i].num].fi,E[e[i].num].se);
        }
        cout<<tot<<endl;
        for(i=1;i<=m;i++)
            printf("%d %d\n",E[i].fi,E[i].se);
    }
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/