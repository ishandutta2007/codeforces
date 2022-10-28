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
#define N 405
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
struct Edge
{
    int from,to,cap,flow;
    double d;
    int p;
}e[N*N];
int cou,h[N*2];
int s,t,pre[N*2],pos[N*2];
bool inq[N*2];
double dis[N*2];
pair<double,double> p[N];
void Addedge(int from,int to,int cap,double dis)
{
    cou++;
    e[cou].from=from;e[cou].to=to,e[cou].cap=cap,e[cou].flow=0,e[cou].d=dis,e[cou].p=h[from];
    //e[cou]=(Edge){from,to,cap,0,dis,h[from]};
    h[from]=cou;

    cou++;
    e[cou].from=to;e[cou].to=from,e[cou].cap=0,e[cou].flow=0,e[cou].d=-dis,e[cou].p=h[to];
    //e[cou]=(Edge){to,from,0,0,-dis,h[to]};
    h[to]=cou;
}

inline double get_dis(double x_1,double y_1,double x_2,double y_2)
{
    return sqrt((x_1-x_2)*(x_1-x_2)+(y_1-y_2)*(y_1-y_2));
}

bool SPFA()
{
    queue<int> q;
    int i,x,v;
    memset(pre,-1,sizeof(pre));
    memset(inq,0,sizeof(inq));
    for(i=s+1;i<=t;i++)
        dis[i]=INF;
    dis[s]=0;
    q.push(s);
    while(!q.empty())
    {
        x=q.front();
        //debug(x);
        q.pop();
        inq[x]=0;
        for(i=h[x];i;i=e[i].p)
        {
            Edge &te=e[i];
            v=te.to;
            //debug(v);
            if(te.cap>te.flow&&dis[v]>dis[x]+te.d)
            {
                //debug(v);
                dis[v]=dis[x]+te.d;
                pre[v]=x;
                pos[v]=i;
                if(!inq[v])
                    q.push(v),inq[v]=1;
            }
        }
    }
    return pre[t]==-1?0:1;
}

void MCMF(int &flow,double &cost)
{
    flow=cost=0;
    int i,f;
    while(SPFA())
    {
        //debug(flow);
        //debug(dis[t]);
        f=INF;
        for(i=t;i!=s;i=pre[i])
            f=min(f,e[pos[i]].cap-e[pos[i]].flow);
        flow+=f;
        cost+=f*dis[t];
        for(i=t;i!=s;i=pre[i])
        {
            e[pos[i]].flow+=f;
            e[((pos[i]-1)^1)+1].flow-=f;
        }
    }
}

int main()
{
    int n,i,j;
    cin>>n;
    for(i=1;i<=n;i++)
        scanf("%lf%lf",&p[i].se,&p[i].fi);
    sort(p+1,p+1+n);
    reverse(p+1,p+1+n);
    s=0,t=n*2+1;
    for(i=1;i<=n;i++)
    {
        Addedge(s,i,2,0);
        for(j=i+1;j<=n;j++)
            if(p[i].fi>p[j].fi)
            {
                Addedge(i,j+n,1,get_dis(p[i].fi,p[i].se,p[j].fi,p[j].se));
                //debug(i);
                //debug(j);
            }
    }
    for(i=2;i<=n;i++)
        Addedge(i+n,t,1,0);

    int flow;
    double cost;
    MCMF(flow,cost);
    if(flow!=n-1)
        printf("-1\n");
    else printf("%.8f\n",cost);
    return 0;
}
// davidlee1999WTK 2016/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/