#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
const int MAXN=500010;
const int mod=1e9+7;
inline int MOD(int x){return x+((x>>31)&mod);}
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,head[MAXN],tot=1,sum[MAXN],deg[MAXN],deep[MAXN],jump[MAXN][22],all;
struct node
{
	int to,nextn;
}a[MAXN*2];
void ADD(int from,int to)
{
	a[++tot].to=to,a[tot].nextn=head[from];
	head[from]=tot;
}
void format(int u,int fa)
{
	deep[u]=deep[fa]+1;
	int LOG=log2(deep[u]);
	jump[u][0]=fa;
	for(int i=1;i<=LOG;++i) jump[u][i]=jump[jump[u][i-1]][i-1];
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(v==fa) continue;
		format(v,u);
	}
}
int LCA(int x,int y)
{
	if(deep[x]<deep[y]) swap(x,y);
	int C=deep[x]-deep[y],LOG=log2(C);
	for(int i=0;i<=LOG;++i) if(C&(1<<i)) x=jump[x][i];
	if(x==y) return x;
	LOG=log2(deep[x]);
	for(int i=LOG;i>=0;--i) if(jump[x][i]!=jump[y][i]) x=jump[x][i],y=jump[y][i];
	return jump[x][0];
}
struct data
{
	int u,v;
	data(int _u=0,int _v=0){u=_u,v=_v;}
};
int flag,can[MAXN],tag[MAXN],z[MAXN],top;
vector<data> Q[MAXN];
void solve(int x,int y)
{
	int lca=LCA(x,y);
	++tag[x],++tag[y];
	--tag[lca],--tag[jump[lca][0]];
	//------
	top=0;
	for(int i=x;i!=lca;i=jump[i][0]) z[++top]=i;
	z[++top]=lca;
	int mem=top;
	for(int i=y;i!=lca;i=jump[i][0]) z[++top]=i;
	reverse(z+mem+1,z+top+1);
	//------
	z[0]=n+1,z[++top]=n+2;
	for(int i=1;i+1<=top;++i) Q[z[i]].push_back(data(z[i-1],z[i+1]));
	all+=top-3;
	if(all>2*n-2) flag=1;
}
void Pick(int u,int fa)
{
	for(int i=head[u];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		if(v==fa) continue;
		Pick(v,u);
		tag[u]+=tag[v];
	}
	deg[u]-=tag[u];
}
int pre[MAXN],suf[MAXN],pd[MAXN];
void check(int x)
{
	for(int i=head[x];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		pd[v]=pre[v]=suf[v]=0;
	}
	pd[n+1]=pd[n+2]=pre[n+1]=suf[n+1]=pre[n+2]=suf[n+2]=0;
	for(int i=0;i<Q[x].size();++i)
	{
		int u=Q[x][i].u,v=Q[x][i].v;
		if((suf[u] && suf[u]!=v) || (pre[v] && pre[v]!=u)) {flag=1;return;}
		suf[u]=v,pre[v]=u;
	}
	for(int i=head[x];i!=0;i=a[i].nextn)
	{
		int v=a[i].to;
		//pd[v]=1;
		for(int j=suf[v];j && !pd[j];pd[j]=1,j=suf[j])
		{
			if(j==v) {flag=1;return;}
		}
		pd[v]=1;
	}
	for(int i=n+1,cnt=1;i!=0;i=suf[i],++cnt)
	{
		if(i==n+2)
		{
			if(cnt!=deg[x]+2) flag=1;
			break;
		}
	}
}
int main()
{
	n=read();
	sum[0]=1;
	for(int i=1;i<=n;++i) sum[i]=(ll)sum[i-1]*i%mod;
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read();
		ADD(u,v);
		ADD(v,u);
		++deg[u];
		++deg[v];
	}
	format(1,0);
	for(int i=1;i<=n && !flag;++i)
	{
		int v=read();
		if(v)
		{
			if(i==v) {flag=1;break;}
			if(can[v]) {flag=1;break;}
			can[v]=1;
			solve(v,i);
		}
	}
	for(int i=1;i<=n && !flag;++i) check(i);
	if(flag) {puts("0");return 0;}
	Pick(1,0);
	int ans=1;
	for(int i=1;i<=n;++i) if(deg[i]!=-1) ans=(ll)ans*sum[deg[i]]%mod;
	printf("%d\n",ans);
	return 0;
}