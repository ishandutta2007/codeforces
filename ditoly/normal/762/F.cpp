#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 1000
#define MM 13
#define MOD 1000000007
struct edge{int nx,t;}e[MN*2+MM*4+5];
int h[MN+5],H1[MM+5],H2[MM+5],en;
int m,s[MM+5],rts,rtx,rty,t[MM+5],cnt;
vector<int> v[MM+5],vv[MM+5];
map<long long,int> mp;
int f[MN+5][MN+5][MM+5];
inline void ins(int*h,int x,int y)
{
	e[++en]=(edge){h[x],y};h[x]=en;
	e[++en]=(edge){h[y],x};h[y]=en;
}
void dfs(int x,int fa)
{
	s[x]=1;
	int mx=0;
	for(int i=H1[x];i;i=e[i].nx)if(e[i].t!=fa)
	{
		dfs(e[i].t,x);
		s[x]+=s[e[i].t];
		mx=max(mx,s[e[i].t]);
	}
	mx=max(mx,m-s[x]);
	if(mx<rts)rts=mx,rtx=x,rty=0;
	else if(mx==rts)rty=x;
}
void solve(int x,int fa)
{
	long long hash=0;
	for(int i=H2[x];i;i=e[i].nx)if(e[i].t!=fa)
	{
		solve(e[i].t,x);
		vv[x].push_back(t[e[i].t]);
	}
	sort(vv[x].begin(),vv[x].end());
	for(int i=0;i<vv[x].size();++i)hash=hash*14+vv[x][i];
	t[x]=mp[hash]?mp[hash]:(v[++cnt]=vv[x],mp[hash]=cnt);
}
inline void rw(int&a,int b){if((a+=b)>=MOD)a-=MOD;}
int cal(int x,int fa,int t)
{
	if(f[x][fa][t])return f[x][fa][t]-1;
	int *F=new int[1<<v[t].size()];
	for(int i=F[0]=1;i<1<<v[t].size();++i)F[i]=0;
	for(int i=h[x];i;i=e[i].nx)if(e[i].t!=fa)
		for(int j=1<<v[t].size();j--;)
			for(int k=0;k<v[t].size();++k)
				if(!(j&(1<<k))&&(!k||(j&(1<<k-1))||v[t][k]!=v[t][k-1]))
					rw(F[j|(1<<k)],1LL*F[j]*cal(e[i].t,x,v[t][k]));
	f[x][fa][t]=F[(1<<v[t].size())-1]+1;delete F;
	return f[x][fa][t]-1;
}
int main()
{
	int n,i,j,ans=0;
	for(n=read(),i=1;i<n;++i)ins(h,read(),read());
	for(m=read(),i=1;i<m;++i)ins(H1,read(),read());
	rts=m;dfs(1,0);
	if(rty)
	{
		if(rtx>rty)swap(rtx,rty);
		for(i=1;i<=m;++i)for(j=H1[i];j;j=e[j].nx)
			if(i<e[j].t&&(i!=rtx||e[j].t!=rty))ins(H2,i,e[j].t);
		ins(H2,rtx,++m);ins(H2,rty,m);rtx=m;
	}
	else for(i=1;i<=m;++i)for(j=H1[i];j;j=e[j].nx)if(i<e[j].t)ins(H2,i,e[j].t);
	solve(rtx,0);
	if(rty)for(i=1;i<=n;++i)for(j=h[i];j;j=e[j].nx)if(i<e[j].t)
	{
		rw(ans,1LL*cal(i,e[j].t,v[t[m]][0])*cal(e[j].t,i,v[t[m]][1])%MOD);
		if(v[t[m]][0]!=v[t[m]][1])
		rw(ans,1LL*cal(i,e[j].t,v[t[m]][1])*cal(e[j].t,i,v[t[m]][0])%MOD);
	}else;
	else for(i=1;i<=n;++i)rw(ans,cal(i,0,t[rtx]));
	printf("%d",ans);
}