// Problem: CF757F Team Rocket Rises Again
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF757F
// Memory Limit: 500 MB
// Time Limit: 2500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
const int N=200000,M=300000;
struct cmllrangwoyongnamespacedanshiwopianbuyongnamespace{
typedef long long LL;
int n,m;
struct side{
  int y,next;
}e[M*2+N+9];
int lin[3][N+9],cs;

void Ins(int id,int x,int y){e[++cs].y=y;e[cs].next=lin[id][x];lin[id][x]=cs;}
void add(int x,int y){Ins(0,x,y),Ins(1,y,x);}
int dfn[N+9],ord[N+9],co;
int fa[N+9];

void Tarjan(int k){
  ord[dfn[k]=++co]=k;
  for (int i=lin[0][k];i;i=e[i].next)
    if (!dfn[e[i].y]){
      fa[e[i].y]=k;
      Tarjan(e[i].y);
    }
}

int idom[N+9],sdom[N+9];
int uni[N+9],mn[N+9];

int Query_uni(int k){
  if (k==uni[k]) return k;
  int res=Query_uni(uni[k]);
  if (dfn[sdom[mn[uni[k]]]]<dfn[sdom[mn[k]]]) mn[k]=mn[uni[k]];
  return uni[k]=res;
}

void Contract(int st){
  Tarjan(st);
  for (int i=1;i<=n;++i) sdom[i]=uni[i]=mn[i]=i;
  for (int i=co;i>=2;--i){
    int t=ord[i];
    for (int i=lin[1][t];i;i=e[i].next){
      int y=e[i].y;
      if (!dfn[y]) continue;
      Query_uni(y);
      if (dfn[sdom[mn[y]]]<dfn[sdom[t]]) sdom[t]=sdom[mn[y]];
    }
    uni[t]=fa[t];
    Ins(2,sdom[t],t);
    for (int i=lin[2][t=fa[t]];i;i=e[i].next){
      int y=e[i].y;
      Query_uni(y);
      idom[y]=t==sdom[mn[y]]?t:mn[y];
    }
    lin[2][t]=0;
  }
  for (int i=2;i<=co;++i){
    int t=ord[i];
    if (idom[t]^sdom[t]) idom[t]=idom[idom[t]];
  }
}

int ans[N+9];

void Get_ans(){
  for (int i=co;i>=2;--i) ans[idom[ord[i]]]+=++ans[ord[i]];
  ++ans[1];
}

void work(int s){
  Contract(s);
  Get_ans();
}

void OTTO(int s){
	int t=0;
	for(int i=1;i<=n;++i) if(i!=s) t=max(t,ans[i]);
	printf("%d\n",t);
	return ;
}
}T;
#define int long long
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
vector<pair<int,int> > v[1000003];
int dis[1000003];
bool vis[1000003];
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
signed main()
{
    int n=read(),m=read(),s=read();
    memset(dis,0x3f,sizeof(dis));
    for(int i=1,x,y,z; i<=m; i++) 
    {
    	x=read(),y=read(),z=read();
    	if(x==1) x=s; else if(x==s) x=1;
    	if(y==1) y=s; else if(y==s) y=1;
    	v[x].push_back(make_pair(y,z)),
    	v[y].push_back(make_pair(x,z));
    }
    s=1;
    dis[s]=0,q.push(make_pair(0,s));
    while(!q.empty())
    {
    	int x=q.top().second;
    	q.pop();
    	if(vis[x]) continue;
    	vis[x]=1;
    	for(pair<int,int> y:v[x]) 
    		if((!vis[y.first])&&dis[y.first]>dis[x]+y.second) 
    			dis[y.first]=dis[x]+y.second,
    			q.push(make_pair(dis[y.first],y.first));
    }
    for(int i=1; i<=n; ++i)
    	for(auto [j,k]:v[i])
    		if(dis[j]==dis[i]+k)
    			T.add(i,j);
    		T.n=n;
    T.work(s),T.OTTO(s);
	return 0;
}