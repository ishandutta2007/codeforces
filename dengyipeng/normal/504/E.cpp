#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 300005
#define ll long long 
using namespace std;

int n,m,i,j,k,s[maxn];
int em,e[maxn*2],nx[maxn*2],ls[maxn];

void read(int &x){
	x=0; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
}

void write(int x){
	static int d[100];
	if (!x) putchar('0'); else {
		while (x) d[++d[0]]=x%10,x/=10;
		while (d[0]) putchar('0'+d[d[0]--]);
	}
	putchar('\n');
}

void insert(int x,int y){
	em++; e[em]=y; nx[em]=ls[x]; ls[x]=em;
	em++; e[em]=x; nx[em]=ls[y]; ls[y]=em;
}

int tot,dfn[maxn],sz[maxn],g[maxn],Idfn[maxn],dep[maxn],top[maxn],fa[maxn];
struct Hash{
	ll p,mo,f[maxn],g[maxn],mul[maxn];
	void build(ll _p,ll _mo){
		p=_p,mo=_mo;
		mul[0]=1;for(i=1;i<=n;i++) mul[i]=mul[i-1]*p%mo;
		for(int i=1;i<=n;i++) f[i]=(f[i-1]*p+s[Idfn[i]])%mo;
		for(int i=n;i>=1;i--) g[i]=(g[i+1]*p+s[Idfn[i]])%mo;
	}
	ll get(int l,int r){
		if (l<=r) return (f[r]-f[l-1]*mul[r-l+1])%mo;
		return (g[r]-g[l+1]*mul[l-r+1])%mo;
	}
	int check(int l0,int r0,int l1,int r1){
		return (get(l0,r0)-get(l1,r1))%mo==0;
	}
} hs1,hs2;

void dfs1(int x,int p){
	dep[x]=dep[p]+1,sz[x]=1,fa[x]=p;
	for(int i=ls[x];i;i=nx[i]) if (e[i]!=p){
		dfs1(e[i],x),sz[x]+=sz[e[i]];
		if (!g[x]||sz[e[i]]>sz[g[x]]) g[x]=e[i];
	}
}
void dfs2(int x,int p){
	if (x==1) top[x]=x;dfn[x]=++tot,Idfn[tot]=x;
	if (g[x]) top[g[x]]=top[x],dfs2(g[x],x);
	for(int i=ls[x];i;i=nx[i]) if (e[i]!=g[x]&&e[i]!=p)
		top[e[i]]=e[i],dfs2(e[i],x);
}

int l[2][maxn],r[2][maxn],cnt[2],len[2][maxn],d[2][maxn];
void getlca(int x,int y,int tp){
	static int tmp[maxn][2],cntt;
	cntt=0,cnt[tp]=0;
	while (top[x]!=top[y]){
		if (dep[top[x]]>dep[top[y]])
			cnt[tp]++,l[tp][cnt[tp]]=dfn[x],r[tp][cnt[tp]]=dfn[top[x]],x=fa[top[x]];
		else 
			cntt++,tmp[cntt][0]=dfn[top[y]],tmp[cntt][1]=dfn[y],y=fa[top[y]];
	}
	cnt[tp]++,l[tp][cnt[tp]]=dfn[x],r[tp][cnt[tp]]=dfn[y];
	while (cntt) cnt[tp]++,l[tp][cnt[tp]]=tmp[cntt][0],r[tp][cnt[tp]]=tmp[cntt][1],cntt--;
	for(int i=1;i<=cnt[tp];i++) len[tp][i]=len[tp][i-1]+abs(r[tp][i]-l[tp][i])+1;
	for(int i=1;i<=cnt[tp];i++) d[tp][i]=(r[tp][i]>l[tp][i])?1:-1;
}

int doit(){
	static int id[2];
	id[0]=id[1]=0;
	while (id[0]<cnt[0]&&id[1]<cnt[1]){
		int t=(len[1][id[1]+1]<len[0][id[0]+1]);
		if (len[t][id[t]+1]==len[t^1][id[t^1]]) {id[t]++;continue;}
		int L[2],R[2];
		for(int k=0;k<2;k++){
			if (len[k^1][id[k^1]]>len[k][id[k]]) 
				L[k]=l[k][id[k]+1]+d[k][id[k]+1]*(len[k^1][id[k^1]]-len[k][id[k]]);
			else L[k]=l[k][id[k]+1];
			R[k]=l[k][id[k]+1]+d[k][id[k]+1]*(len[t][id[t]+1]-len[k][id[k]]-1);
		}
		if (hs1.check(L[0],R[0],L[1],R[1])&&hs2.check(L[0],R[0],L[1],R[1])) id[t]++;
		else {
			int lenl=0,lenr=abs(R[0]-L[0]),mid,mx=-1;
			while (lenl<=lenr){
				mid=(lenl+lenr)>>1;
				if (hs1.check(L[0],L[0]+mid*d[0][id[0]+1],L[1],L[1]+mid*d[1][id[1]+1]))	
					mx=mid,lenl=mid+1; else lenr=mid-1;
			}
			return max(len[0][id[0]],len[1][id[1]])+mx+1;
		}
	}
	return max(len[0][id[0]],len[1][id[1]]);
}

int main(){
	read(n);
	char ch=getchar();while(ch<'a'||ch>'z') ch=getchar();
	for(i=1;i<=n;i++) s[i]=ch-'a'+1,ch=getchar();
	for(i=1;i<n;i++) read(j),read(k),insert(j,k);
	dfs1(1,0),dfs2(1,0);
	hs1.build(29,1000000009);
	hs2.build(31,998244353);
	read(m);
	while (m--){
		int x,y,xx,yy;read(x),read(y),read(xx),read(yy);
		getlca(x,y,0),getlca(xx,yy,1);
		write(doit());
	}
}