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
#define N 205
#define M 205 * 205 * 2
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int cou_p;
int pri[20005],vis_p[20005]={0};
void getprime()
{
    int i,j;
    for(i=2;i<=20000;i++)
        if(!vis_p[i])
        {
            pri[++cou_p]=i;
            for(j=i+i;j<=20000;j+=i)
                vis_p[j]=1;
        }
}

struct Edge
{
    int from,to,cap,flow,pre;
}e[M];
int cou=0,ST,TE;
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
    q.push(ST),d[ST]=0,vis[ST]=1;
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
                if(v==TE) return 1;
            }
        }
    }
    return 0;
}

int DFS(int x,int a)
{
    if(x==TE||a==0) return a;
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

//please specify the range!
int Maxflow()
{
    int i,flow=0;
    while(BFS())
    {
        for(i=ST;i<=TE;i++)
            cur[i]=h[i];
        flow+=DFS(ST,INF);
    }
    return flow;
}

pii a[N], b[N];
int v[N];
vector<int> G[N];
int cnt;
vector<int> ans[N];
bool vis_d[N];

void dfs_d(int x)
{
    vis_d[x] = 1;
    ans[cnt].push_back(x);
    for (auto u : G[x])
    {
        if(!vis_d[u])
        {
            dfs_d(u);
        }
    }
}

int main()
{
    int n, m0 = 0, m1 = 0, m;
    getprime();
    cin >> n;
    if(n % 2 == 1)
    {
        printf("Impossible\n");
        return 0;
    }
    m = n >> 1;
    int i, j;
    for(i=1;i<=n;i++)
    {
        scanf("%d", &v[i]);
        if(v[i] % 2 == 0)
        {
            a[++m0] = MP(v[i], i);
        }
        else
            b[++m1] = MP(v[i], i);
    }
    if(m1 != m)
    {
        printf("Impossible\n");
        return 0;
    }

    // build gragh
    ST = 0;
    TE = n+1;
    for(i=1;i<=n;i++)
    {
        if(v[i] % 2 == 0)
        {
            Addedge(ST, i, 2);
        }
        else
        {
            Addedge(i, TE, 2);
        }
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(!vis_p[a[i].fi + b[j].fi])
            {
                Addedge(a[i].se, b[j].se, 1);
            }
        }
    }
    int flow = Maxflow();
    //debug(flow);
    if(flow != n)
    {
        printf("Impossible\n");
        return 0;
    }
    for(i=1;i<=cou;i+=2)
    {
        if(e[i].from != ST && e[i].to != TE && e[i].flow == 1)
        {
            G[e[i].from].push_back(e[i].to);
            G[e[i].to].push_back(e[i].from);
        }
    }
    for(i=1;i<=n;i++)
    {
        if(!vis_d[i])
        {
            cnt++;
            dfs_d(i);
        }
    }
    cout<<cnt<<endl;
    for(i=1;i<=cnt;i++)
    {
        cout<< ans[i].size() << " ";
        for(auto x : ans[i])
            cout<<x << " ";
        cout<<endl;
    }
    return 0;
}
// davidlee1999WTK 2022/
// Team NewType, UT Austin
// srO myk Orz
//ios::sync_with_stdio(false);