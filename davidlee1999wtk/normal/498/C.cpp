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
#define INF 100000000
#define fi first
#define se second
#define N 200005
#define MN 105
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
struct Edge
{
    int from,to,cap,flow,pre;
}e[N];
int cou,h[N],n,m,tot=0,s,t,d[N],cur[N],cnt=0;
bool vis[N];
inline void MakeEdge(Edge &x,int t1=0,int t2=0,int t3=0,int t4=0,int t5=0)
{
    x.from=t1,x.to=t2,x.cap=t3,x.flow=t4,x.pre=t5;
}
inline void Addedge(int from,int to,int cap)
{
    cou++;
    //e[cou]=(Edge){from,to,cap,0,h[from]};
    MakeEdge(e[cou],from,to,cap,0,h[from]);
    h[from]=cou;
    cou++;
    //e[cou]=(Edge){to,from,0,0,h[to]};
    MakeEdge(e[cou],to,from,0,0,h[to]);
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
        for(i=s;i<=tot;i++)
            cur[i]=h[i];
        cur[t]=h[t];
        flow+=DFS(s,INF);
    }
    return flow;
}
map<int,int> mp;
int a[MN],b[MN];
int c1[MN][3000],c2[MN][3000];
void fj1(int num,int x)
{
    int i,y,sum=0;
    for(i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            if(!mp[i])
                mp[i]=++cnt;
            y=mp[i];
            c1[num][y]=++tot;
            sum=0;
            while(x%i==0)
                sum++,x/=i;
            Addedge(s,tot,sum);
        }
    }
    if(x>1)
    {
        i=x;
        if(!mp[i])
            mp[i]=++cnt;
        y=mp[i];
        c1[num][y]=++tot;
        sum=0;
        while(x%i==0)
            sum++,x/=i;
        Addedge(s,tot,sum);
    }
}
void fj2(int num,int x)
{
    int i,y,sum=0;
    for(i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            if(!mp[i])
                mp[i]=++cnt;
            y=mp[i];
            c2[num][y]=++tot;
            sum=0;
            while(x%i==0)
                sum++,x/=i;
            Addedge(tot,t,sum);
        }
    }
    //printf("BUG\n");
    if(x>1)
    {
        i=x;
        if(!mp[i])
            mp[i]=++cnt;
        y=mp[i];
        c2[num][y]=++tot;
        sum=0;
        while(x%i==0)
            sum++,x/=i;
        Addedge(tot,t,sum);
    }
}
int main()
{
    int n,m,i,j,fr,to;
    s=0,t=200000;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        if(i%2==1)
            scanf("%d",&a[i/2+1]);
        else scanf("%d",&b[i/2]);
    }
    for(i=1;i<=(n+1)/2;i++)
        fj1(i,a[i]);
    //cout<<tot<<endl;
    for(i=1;i<=n/2;i++)
        fj2(i,b[i]);
    //cout<<tot<<endl;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&fr,&to);
        if(fr%2==0) swap(fr,to);
        fr=fr/2+1;
        to=to/2;
        for(j=1;j<=cnt;j++)
            if(c1[fr][j]&&c2[to][j])
                Addedge(c1[fr][j],c2[to][j],INF);
    }
    cout<<Maxflow()<<endl;
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);
/*
2 1
4 4
1 2
*/