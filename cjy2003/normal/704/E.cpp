#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
struct bian{int nxt,to;}bi[200020];
int n,m,head[100010],num;
inline void add(int from,int to){bi[++num]=bian{head[from],to};head[from]=num;}
int siz[100010],zson[100010],f[100010],dep[100010],tp[100010];
void dfs1(int v,int fa)
{
	f[v]=fa,siz[v]=1,dep[v]=dep[fa]+1;
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==fa)continue;
		dfs1(u,v);
		if(siz[u]>siz[zson[v]])zson[v]=u;
		siz[v]+=siz[u];
	}
}
void dfs2(int v,int topp)
{
	tp[v]=topp;
	if(zson[v])dfs2(zson[v],topp);
	for(int i=head[v],u;i;i=bi[i].nxt)
	{
		u=bi[i].to;
		if(u==f[v]||u==zson[v])continue;
		dfs2(u,u);
	}
}
long long gcd(long long a,long long b)
{
	if(!a||!b)return a+b;
	return gcd(b,a%b);
}
struct frac
{
	long long a,b;
	frac(long long _a=0,long long _b=0){static long long g;g=gcd(_a,_b);a=_a/g,b=_b/g;}
	friend bool operator == (frac a,frac b){return a.a*b.b==a.b*b.a;}
	friend bool operator <= (frac a,frac b){return a.a*b.b<=a.b*b.a;}
	friend bool operator < (frac a,frac b){return a.a*b.b<a.b*b.a;}
	friend frac operator * (frac a,frac b){return frac(a.a*b.a,a.b*b.b);}
	friend frac operator + (frac a,frac b){static long long g;g=gcd(a.b,b.b);return frac(b.b/g*a.a+a.b/g*b.a,a.b/g*b.b);}
	friend frac operator - (frac a,frac b){static long long g;g=gcd(a.b,b.b);return frac(b.b/g*a.a-a.b/g*b.a,a.b/g*b.b);}
}ans={1,0};
struct data
{
	frac bg,ed;
	int s,v;
};
vector<data>d[100010];
int dis(int x,int y)
{
	int res=dep[x]+dep[y];
	while(tp[x]!=tp[y])
	{
		if(dep[tp[x]]<dep[tp[y]])y=f[tp[y]];
		else x=f[tp[x]];
	}
	if(dep[x]>dep[y])x=y;
	return res-2*dep[x];
}
struct line
{
	frac t;
	int id,op;
	friend bool operator < (line a,line b)
	{
		if(a.t==b.t)return a.op>b.op;
		return a.t<b.t;
	}
}st[200020];
int cnt;
frac now;
struct data1
{
	frac bg;
	int s,v;
	friend bool operator < (data1 a,data1 b){return frac(a.s,1)+(now-a.bg)*frac(a.v,1)<frac(b.s,1)+(now-b.bg)*frac(b.v,1);}
};
multiset<data1>S;
multiset<frac>goal;
frac calc(data1 a,data1 b)
{
	if(a.v==b.v)
	{
		if(frac(a.s,1)-frac(a.v,1)*a.bg==frac(b.s,1)-frac(b.v,1)*b.bg)return max(a.bg,b.bg);
		else return frac{1,0};
	}
	frac mt=(frac(b.s-a.s,1)+frac(a.v,1)*a.bg-frac(b.v,1)*b.bg)*frac(1,a.v-b.v);
	if(mt<max(a.bg,b.bg))return frac{1,0};
	else return mt;
}
void solve(vector<data>&p)
{
//	for(int i=0;i<p.size();++i)printf("%lld %lld %lld %lld %d %d\n",p[i].bg.a,p[i].bg.b,p[i].ed.a,p[i].ed.b,p[i].s,p[i].v);
	cnt=0;
	for(int i=0;i<p.size();++i)
	{
		st[++cnt]=line{p[i].bg,i,1};
		st[++cnt]=line{p[i].ed,i,-1};
	}
	sort(st+1,st+1+cnt);
	now=frac{0,1};
	S.clear();goal.clear();
	for(int i=1;i<=cnt;++i)
	{
		if(goal.size()&&*goal.begin()<=st[i].t)
		{
			ans=min(ans,*goal.begin());
			return ;
		}
		now=st[i].t;
		if(st[i].op==1)
		{
			auto it=S.insert(data1{p[st[i].id].bg,p[st[i].id].s,p[st[i].id].v});
			if(it!=S.begin()&&next(it)!=S.end())goal.erase(goal.lower_bound(calc(*prev(it),*next(it))));
			if(it!=S.begin())goal.insert(calc(*prev(it),*it));
			if(next(it)!=S.end())goal.insert(calc(*it,*next(it)));
		}
		else
		{
			auto it=S.lower_bound(data1{p[st[i].id].bg,p[st[i].id].s,p[st[i].id].v});
			if(it!=S.begin())goal.erase(goal.lower_bound(calc(*prev(it),*it)));
			if(next(it)!=S.end())goal.erase(goal.lower_bound(calc(*it,*next(it))));
			if(it!=S.begin()&&next(it)!=S.end())goal.insert(calc(*prev(it),*next(it)));
			S.erase(it);
		}
	//	printf("%lld %lld %d %d\n",st[i].t.a,st[i].t.b,st[i].id,st[i].op);
	//	for(auto p:goal)printf("%lld %lld   ",p.a,p.b);printf("\n");
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	int x,y;
	for(int i=1;i<n;++i)
	{
		scanf("%d %d",&x,&y);
		add(x,y),add(y,x);
	}
	dfs1(1,0);dfs2(1,1);
//	for(int i=1;i<=n;++i)printf("%d ",tp[i]);printf("\n");
	int t,c;
	for(int i=1;i<=m;++i)
	{
		scanf("%d %d %d %d",&t,&c,&x,&y);
		frac nx,ny,nnx,nny;
		nx.a=t,nx.b=1;
		ny=nx+frac(dis(x,y),c);
		while(tp[x]!=tp[y])
		{
			if(dep[tp[x]]>dep[tp[y]])
			{
				nnx=nx+frac(dep[x]-dep[f[tp[x]]],c);
				d[tp[x]].emplace_back(data{nx,nnx,dep[x]-dep[f[tp[x]]],-c});
				nx=nnx;x=f[tp[x]];
			}
			else
			{
				nny=ny-frac(dep[y]-dep[f[tp[y]]],c);
				d[tp[y]].emplace_back(data{nny,ny,0,c});
				ny=nny;y=f[tp[y]];
			}
		}
		if(dep[x]>dep[y])d[tp[x]].emplace_back(data{nx,ny,dep[x]-dep[f[tp[x]]],-c});
		else d[tp[x]].emplace_back(data{nx,ny,dep[x]-dep[f[tp[x]]],c});
	}
	for(int i=1;i<=n;++i)if(tp[i]==i)/*printf("%d:\n",i),*/solve(d[i]);
	if(ans.b==0)printf("-1");
	else printf("%lf",1.0*ans.a/ans.b);
	return 0;
}