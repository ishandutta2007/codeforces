#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
char B[1<<26],*S=B;
inline int read()
{
	int x;char c;
	while((c=*S++)<'0'||c>'9');
	for(x=c-'0';(c=*S++)>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 300000
#define K 19
#define M 998244353
char s[MN+5],ss[MN*10+5];
struct edge{int nx,t;}e[MN*2+5];
int h[MN+5],en,fa[K][MN+5],d[MN+5],t[MN+5],mx[MN+5],f[MN+5],o[MN+5];
int p[MN+5],r[MN+5],a[MN+5],b[MN+5],sn;
vector<int> v1[MN+5],v2[MN+5];
inline void ins(int x,int y)
{
	e[++en]=(edge){h[x],y};h[x]=en;
	e[++en]=(edge){h[y],x};h[y]=en;
}
void dfs(int x)
{
	a[x]=(a[fa[0][x]]+1LL*s[x]*p[d[x]])%M;
	b[x]=(233LL*b[fa[0][x]]+s[x])%M;
	for(int i=h[x];i;i=e[i].nx)if(e[i].t!=fa[0][x])
	{
		fa[0][e[i].t]=x;d[e[i].t]=d[x]+1;
		dfs(e[i].t);
		if(t[e[i].t]+1>t[x])t[x]=t[e[i].t]+1,mx[x]=e[i].t;
	}
}
void build(int x)
{
	if(!f[x])
	{
		f[x]=x;
		for(int i=0,j=x;i<t[x];++i,j=fa[0][j])v2[x].push_back(j);
	}
	v1[f[x]].push_back(x);
	if(mx[x])f[mx[x]]=f[x];
	for(int i=h[x];i;i=e[i].nx)if(e[i].t!=fa[0][x])build(e[i].t);
}
inline int up(int x,int k)
{
	if(k<=d[x]-d[f[x]])return v1[f[x]][d[x]-d[f[x]]-k];
	x=fa[o[k]][x];k-=1<<o[k];
	if(k<=d[x]-d[f[x]])return v1[f[x]][d[x]-d[f[x]]-k];
	return v2[f[x]][k-d[x]+d[f[x]]];
}
inline int lca(int x,int y)
{
	if(d[x]<d[y])swap(x,y);
	x=up(x,d[x]-d[y]);
	if(x==y)return x;
	for(int i=K;i--;)if(fa[i][x]!=fa[i][y])x=fa[i][x],y=fa[i][y];
	return fa[0][x];
}
inline int inv(int x)
{
	int r=1,y=M-2;
	for(;y;y>>=1,x=1LL*x*x%M)if(y&1)r=1LL*r*x%M;
	return r;
}
inline int cala(int x,int y){return 1LL*(a[x]+M-a[fa[0][y]])*r[d[y]]%M;}
inline int calb(int x,int y){return (b[x]+M-1LL*b[y]*p[d[x]-d[y]]%M)%M;}
int cal(int x,int y,int l,int z)
{
	if(z<=d[x]-d[l])return cala(x,up(x,z));
	y=up(y,d[x]+d[y]-2*d[l]-z);
	return (1LL*cala(x,l)*p[d[y]-d[l]]+calb(y,l))%M;
}
inline void out(int x)
{
	int z[10],zn=0;
	if(!x)z[zn++]=0;
	while(x)z[zn++]=x%10,x/=10;
	while(zn--)ss[sn++]=z[zn]+'0';ss[sn++]='\n'; 
}
int main()
{
	B[fread(B,1,1<<26,stdin)]=0;
	int n=read(),i,j,x1,x2,y1,y2,l1,l2,ll,rr,mid,ans;
	for(i=2;i<=n;++i)o[i]=o[i>>1]+1;
	for(i=1;i<=n;++i)while((s[i]=*S++)<'a'||s[i]>'z');
	for(i=1;i<n;++i)ins(read(),read());
	for(p[0]=i=1;i<=n;++i)p[i]=233LL*p[i-1]%M;
	for(r[i=n]=inv(p[n]);i--;)r[i]=233LL*r[i+1]%M;
	dfs(1);build(1); 
	for(i=1;i<K;++i)for(j=1;j<=n;++j)fa[i][j]=fa[i-1][fa[i-1][j]];
	for(i=read();i--;)
	{
		x1=read();y1=read();l1=lca(x1,y1);
		x2=read();y2=read();l2=lca(x2,y2);
		for(ans=ll=0,rr=min(d[x1]+d[y1]-2*d[l1],d[x2]+d[y2]-2*d[l2]);ll<=rr;)
		{
			int mid=ll+rr>>1;
			if(cal(x1,y1,l1,mid)==cal(x2,y2,l2,mid))ans=ll=mid+1;else rr=mid-1;
		}
		out(ans);
	}
	fwrite(ss,1,sn,stdout);
}