#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
namespace io
{
	const int N=1<<20;
	char buf[N],*t1=buf,*t2=buf;
	#define getc() t1==t2&&(t2=(t1=buf)+fread(buf,1,N,stdin),t1==t2)?EOF:*t1++
	inline int read()
	{
		static int an;an=0;
		static char ch;ch=getc();
		while(ch<48||ch>57)ch=getc();
		while(ch>=48&&ch<=57)an=(an<<3)+(an<<1)+(ch^48),ch=getc();
		return an;
	}
}
using namespace io;
int n,m,t,q,b[500050][2],c[500050],cb[500050],cc[500050],rp[500050],last[500050];
vector<pair<int,int> >E[2000020];
int *p[1500010],w[1500010],cnt;
inline void upd(int &x,int y){if(x!=y)p[++cnt]=&x,w[cnt]=x,x=y;}
struct DSU
{
	int f[500050],dis[500050],df[500050];
	void init(){for(int i=1;i<=n;++i)f[i]=i,dis[i]=1;}
	inline pair<int,int> find(int x)
	{
		bool ds=0;
		while(x!=f[x])ds^=df[x],x=f[x];
		return make_pair(x,ds);
	}
	inline void ins(int e)
	{
		auto s1=find(b[e][0]),s2=find(b[e][1]);
		int x=s1.first,y=s2.first;
		if(x!=y)
		{
			if(dis[x]>dis[y])swap(x,y);
			if(dis[x]==dis[y])upd(dis[y],dis[x]+1);
			upd(f[x],y);
			upd(df[x],s1.second^s2.second^1);
		}
	}
	inline bool check(int e)
	{
		auto s1=find(b[e][0]),s2=find(b[e][1]);
		return s1.first!=s2.first||(s1.second^s2.second);
	}
}d[51];
void upd(int k,int l,int r,int ll,int rr,pair<int,int>dt)
{
	if(l>rr||r<ll)return ;
	if(l>=ll&&r<=rr)return E[k].push_back(dt),void();
	upd(k<<1,l,l+r>>1,ll,rr,dt);
	upd(k<<1|1,(l+r>>1)+1,r,ll,rr,dt);
}
void solve(int k,int l,int r)
{
	int cur=cnt;
	for(auto p:E[k])d[p.first].ins(p.second);
	if(l==r)
	{
		if(d[cc[l]].check(cb[l]))c[cb[l]]=cc[l],puts("YES");
		else puts("NO");
		if(c[cb[l]])upd(1,1,q,l+1,rp[l],make_pair(c[cb[l]],cb[l]));
	}
	else solve(k<<1,l,l+r>>1),solve(k<<1|1,(l+r>>1)+1,r);
	while(cnt>cur)*p[cnt]=w[cnt],--cnt;
}
int main()
{
	n=read(),m=read(),t=read(),q=read();
	for(int i=1;i<=m;++i)b[i][0]=read(),b[i][1]=read();
	int x,y;
	for(int i=1;i<=q;++i)
	{
		x=read(),y=read();
		cb[i]=x,cc[i]=y;
		if(last[x])rp[last[x]]=i-1;
		last[x]=i;
	}
	for(int i=1;i<=m;++i)if(last[i])rp[last[i]]=q;
//	printf("!!!\n");
	for(int i=1;i<=t;++i)d[i].init();
//	printf("!!!\n");
	solve(1,1,q);
	return 0;
}