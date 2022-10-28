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
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
struct Edge
{
    int to,pre;
}e[N*2];
int h[N]={0},cou=0,sz[N],ms[N],sum,rt,col[N];
bool vis[N];
void Addedge(int from,int to)
{
    //debug(from);
    //debug(to);
    cou++;
    e[cou]=((Edge){to,h[from]});
    h[from]=cou;
}

void calc(int x,int fa)
{
    //debug(x);
    sz[x]=0;
    int i,v;
    for(i=h[x];i;i=e[i].pre)
    {
        v=e[i].to;
        if(!vis[v]&&v!=fa)
        {
            calc(v,x);
            sz[x]+=sz[v];
        }
    }
    sz[x]++;
}

void getr(int x,int fa)
{
    //debug(x);
    sz[x]=ms[x]=0;
    int i,v;
    for(i=h[x];i;i=e[i].pre)
    {
        v=e[i].to;
        if(!vis[v]&&v!=fa)
        {
            getr(v,x);
            ms[x]=max(ms[x],sz[v]);
            sz[x]+=sz[v];
        }
    }
    sz[x]++;
    //debug(mx[x]);
    ms[x]=max(ms[x],sum-sz[x]);
    //debug(x);
    //debug(ms[x]);
    if(ms[x]<ms[rt])
        rt=x;
}

/*
void get(int x,int dep,int fa)
{
    k[dep]++;
    for(int i=h[x];i;i=e[i].pre)
        if(!vis[e[i].to]&&e[i].to!=fa)
            get(e[i].to,(e[i].d+dep)%3,x);
}
*/
void fz(int x,int depth)
{
    int i,v;
    vis[x]=1;
    col[x]=depth;
    for(i=h[x];i;i=e[i].pre)
    {
        v=e[i].to;
        if(!vis[v])
        {
            calc(v,x);
            rt=0;
            sum=sz[v];
            getr(v,x);
            //debug(rt);
            //debug(sum);
            //if(ms[rt]*2>sum)
                //printf("%d\n",1/0);
            fz(rt,depth+1);
        }
    }
}

vector<int> G[N],son[N];
int out[N],num[N];
pii bg[N];
stack<int> s;

bool cmp(int a,int b)
{
    return bg[a]<bg[b];
}

int main()
{
    int n,m,i,j,k,a,b,cnt=0,x;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        if(a>b)
            swap(a,b);
        G[a].push_back(b);
        //G[b].push_back(a);
    }
    cnt++;
    bg[1]=MP(n,1);
    s.push(1);
    for(i=1;i<=n;i++)
    {
        while(out[i])
        {
            cnt++;
            bg[cnt]=MP(i,s.top());
            k=s.size();
            //debug(i);
            //debug(k);
            //debug(now);
            for(j=0;j<son[k].size();j++)
            {
                Addedge(cnt,son[k][j]);
                Addedge(son[k][j],cnt);
            }
            son[k].clear();
            s.pop();
            son[k-1].push_back(cnt);
            out[i]--;
        }
        sort(G[i].begin(),G[i].end());
        reverse(G[i].begin(),G[i].end());
        for(j=0;j<G[i].size();j++)
        {
            x=G[i][j];
            out[x]++;
            //debug(i);
            s.push(i);
        }
    }
    //debug(bg[4].fi);
    //debug(bg[4].se);
    //debug(bg[5].fi);
    //debug(bg[5].se);
    k=1;
    for(j=0;j<son[k].size();j++)
    {
        Addedge(1,son[k][j]);
        Addedge(son[k][j],1);
    }
    son[k].clear();
    s.pop();
    //debug(cnt);
    for(i=1;i<=cnt;i++)
        num[i]=i;
    sort(num+1,num+1+cnt,cmp);
    ms[0]=cnt+1;
    rt=0;
    sum=cnt;
    getr(1,0);
    //if(sz[1]!=cnt||cnt!=m+1)
        //while(1);
    //debug(rt);
    //debug(rt);
    //debug(ms[5]);
    fz(rt,1);
    //if(cou!=m*2)
        //while(1);
    //for(i=1;i<=cnt;i++)
        //debug(num[i]);
    for(i=1;i<=cnt;i++)
    {
        //debug(num[i]);
        printf("%d ",col[num[i]]);
    }
    return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*
4 1
1 3

8 5
1 7
2 5
4 2
5 7
2 7
*/