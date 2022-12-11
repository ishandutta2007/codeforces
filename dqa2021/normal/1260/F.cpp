#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
typedef long long ll;
const int Mod=1e9+7,MAXW=1e5;
int qpow(int x,int y)
{
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%Mod)
		if (y&1) res=1LL*res*x%Mod;
	return res;
}

int n,w[100010],p[100010];
int ans,sum;
struct Edge{
	int to,nxt;
}edge[200010];
int cnt=1,last[100010];
inline void addedge(int x,int y)
{
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y]},last[y]=cnt;
}
namespace R
{
	int fat[100010]; bool mrk[100010];
	int siz[100010],maxsiz[100010],Rt,Siz;
	int dis[100010][17],ftot[100010];
	void dfs(int cur,int fat,int dep)
	{
		dis[cur][ftot[cur]++]=dep;
		for (int i=last[cur],v;i;i=edge[i].nxt)
			if (v=edge[i].to,!mrk[v]&&v!=fat)
				dfs(v,cur,dep+1);
	}
	void getsiz(int cur,int fat)
	{
		siz[cur]=1;
		for (int i=last[cur],v;i;i=edge[i].nxt)
			if (v=edge[i].to,!mrk[v]&&v!=fat)
				getsiz(v,cur),siz[cur]+=siz[v];
	}
	void getroot(int cur,int fat)
	{
		maxsiz[cur]=0;
		for (int i=last[cur],v;i;i=edge[i].nxt)
			if (v=edge[i].to,!mrk[v]&&v!=fat)
				getroot(v,cur),maxsiz[cur]=max(maxsiz[cur],siz[v]);
		maxsiz[cur]=max(maxsiz[cur],Siz-siz[cur]);
		if (Rt==-1||maxsiz[cur]<maxsiz[Rt]) Rt=cur;
	}
	
	void build(int cur)
	{
		dfs(cur,0,0);
		mrk[cur]=true;
		for (int i=last[cur],v;i;i=edge[i].nxt)
			if (v=edge[i].to,!mrk[v])
			{
				getsiz(v,0); Siz=siz[v],Rt=-1;
				getroot(v,0); fat[Rt]=cur;
				build(Rt);
			}
	}
	
	int f[100010],g[100010],ff[100010],gg[100010];  //g/gg: son to fat
	void ins(int x)
	{
		sum=(sum+1LL*w[x]*ff[x])%Mod;
		f[x]=(f[x]+w[x])%Mod;
		for (int i=x,j=ftot[x]-2;fat[i];i=fat[i],j--)
		{
			int t=dis[x][j];
			sum=(sum+1LL*t*w[x]%Mod*(f[fat[i]]-g[i])%Mod+1LL*w[x]*(ff[fat[i]]-gg[i]))%Mod;
			f[fat[i]]=(f[fat[i]]+w[x])%Mod; g[i]=(g[i]+w[x])%Mod;
			ff[fat[i]]=(ff[fat[i]]+1LL*w[x]*t)%Mod; gg[i]=(gg[i]+1LL*w[x]*t)%Mod;
		}
	}
	void del(int x)
	{
		f[x]=(f[x]-w[x])%Mod;
		sum=(sum-1LL*w[x]*ff[x])%Mod;
		for (int i=x,j=ftot[x]-2;fat[i];i=fat[i],j--)
		{
			int t=dis[x][j];
			f[fat[i]]=(f[fat[i]]-w[x])%Mod; g[i]=(g[i]-w[x])%Mod;
			ff[fat[i]]=(ff[fat[i]]-1LL*w[x]*t)%Mod; gg[i]=(gg[i]-1LL*w[x]*t)%Mod;
			sum=(sum-1LL*t*w[x]%Mod*(f[fat[i]]-g[i])%Mod-1LL*w[x]*(ff[fat[i]]-gg[i]))%Mod;
		}
	}
}
struct Rec{
	int tim,opt,id;
}rec[200010]; int rectop;
bool operator<(const Rec x,const Rec y)
{
	return x.tim<y.tim;
}
int main()
{
	n=read();
	for (int i=1,l,r;i<=n;i++)
	{
		l=read(),r=read(),w[i]=qpow(r-l+1,Mod-2),p[i]=r-l+1;
		rec[++rectop]=(Rec){l,0,i};
		rec[++rectop]=(Rec){r+1,1,i};
	}
	sort(rec+1,rec+rectop+1);
	for (int i=1;i<n;i++) addedge(read(),read());
	R::getsiz(1,0); R::Rt=-1,R::Siz=n; R::getroot(1,0); R::build(R::Rt);
	
	for (int i=1,j=0;i<=MAXW;i++)
	{
		while (j<rectop&&rec[j+1].tim==i)
		{
			j++;
			if (rec[j].opt) R::del(rec[j].id);
			else R::ins(rec[j].id);
		}
		ans=(ans+sum)%Mod;
	}
	for (int i=1;i<=n;i++) ans=1LL*ans*p[i]%Mod;
	printf("%d\n",(ans+Mod)%Mod);
	return 0;
}