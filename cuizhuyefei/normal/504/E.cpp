#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 633333;
struct SA{
	int sa[N],rk[N*2],tt[N],buc[N],h[N],v[20][N],Log[N];
	void init(char *s, int n){
		rep(i,1,n)buc[s[i]]++;
		rep(j,1,255)buc[j]+=buc[j-1];
		rep(i,1,n)sa[buc[s[i]]--]=i;
		rep(i,1,n)rk[sa[i]]=rk[sa[i-1]]+(s[sa[i]]!=s[sa[i-1]]);
		for(int j=1;j<n;j<<=1){
			int p=0;rep(i,n-j+1,n)h[++p]=i;
			rep(i,1,n)if(sa[i]>j)h[++p]=sa[i]-j;
			memset(buc,0,sizeof(buc));
			rep(i,1,n)buc[rk[i]]++;
			rep(i,1,n)buc[i]+=buc[i-1];
			per(i,n,1)sa[buc[rk[h[i]]]--]=h[i];
			rep(i,1,n)tt[sa[i]]=tt[sa[i-1]]+(rk[sa[i]]!=rk[sa[i-1]]||rk[sa[i]+j]!=rk[sa[i-1]+j]);
			rep(i,1,n)rk[i]=tt[i];
		}
		int p=0;
		rep(i,1,n){
			if(p)p--;
			while(i+p<=n&&sa[rk[i]-1]+p<=n&&s[i+p]==s[sa[rk[i]-1]+p])p++;
			h[rk[i]]=p;
		}
		rep(i,1,n)v[0][i]=h[i];
		rep(j,1,19)rep(i,1,n-(1<<j)+1)v[j][i]=min(v[j-1][i],v[j-1][i+(1<<j-1)]);
		rep(j,1,19)Log[1<<j]++;rep(i,1,n)Log[i]+=Log[i-1];
		
		/*rep(i,1,n)printf("%c",s[i]);puts("");
		rep(i,1,n)printf("%d ",sa[i]);puts("");
		rep(i,1,n)printf("%d ",rk[i]);puts("");
		rep(i,1,n)printf("%d ",h[i]);puts("");*/
	}
	inline int getlcp(int l, int r){
		if(l==r)return N;
		l=rk[l];r=rk[r];if(l>r)swap(l,r);l++;
		int k=Log[r-l+1];return min(v[k][l],v[k][r-(1<<k)+1]);
	}
}sa;
int n,top[N],fa[N],dep[N],sz[N],son[N],dfn[N],num;char t[N],s[N];Vi e[N];
void dfs1(int u, int Dep, int Fa){
	dep[u]=Dep;fa[u]=Fa;sz[u]=1;
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=Fa){
		dfs1(e[u][i],Dep+1,u);sz[u]+=sz[e[u][i]];
		if(sz[son[u]]<sz[e[u][i]])son[u]=e[u][i];
	}
}
void dfs2(int u, int Top){
	top[u]=Top;dfn[u]=++num;s[num]=s[2*n+1-num]=t[u];
	if(son[u])dfs2(son[u],Top);
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa[u]&&e[u][i]!=son[u])
		dfs2(e[u][i],e[u][i]);
}
Pii a[N],b[N];int l1,l2;
int getlca(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);u=fa[top[u]];
	}
	return dep[u]<dep[v]?u:v;
}
void getpath(int u, int v, int &len, Pii *a){
	int lca=getlca(u,v);
	while(top[u]!=top[lca]){
		a[++len]=Pii(2*n+1-dfn[u],dep[u]-dep[top[u]]+1);
		u=fa[top[u]];
	}
	if(dep[u]>dep[lca])a[++len]=Pii(2*n+1-dfn[u],dep[u]-dep[lca]);
	vector<Pii>b;
	while(top[v]!=top[lca]){
		b.pb(Pii(dfn[top[v]],dep[v]-dep[top[v]]+1));
		v=fa[top[v]];
	}
	if(dep[v]>=dep[lca])b.pb(Pii(dfn[lca],dep[v]-dep[lca]+1));
	per(i,SZ(b)-1,0)a[++len]=b[i];
}
int main() {
	read(n);scanf("%s",t+1);
	rep(i,1,n-1){
		int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);
	}
	dfs1(1,0,0);dfs2(1,1);
	sa.init(s,2*n);
	int q;read(q);while(q--){
		int u,v;read(u);read(v);l1=l2=0;getpath(u,v,l1,a);
		read(u);read(v);getpath(u,v,l2,b);
	//	rep(i,1,l1)printf("<%d,%d> ",a[i].fi,a[i].se);puts("");
	//	rep(i,1,l2)printf("<%d,%d> ",b[i].fi,b[i].se);puts("");
		int p1=1,pos1=1,p2=1,pos2=1,res=0;
		while(p1<=l1&&p2<=l2){
			int len=min(a[p1].se-pos1+1,b[p2].se-pos2+1);
			int lcp=min(sa.getlcp(a[p1].fi+pos1-1,b[p2].fi+pos2-1),len);
		//	cerr<<lcp<<endl;
			if(lcp<len){res+=lcp;break;}
			res+=lcp;pos1+=lcp;pos2+=lcp;if(pos1>a[p1].se)p1++,pos1=1;
			if(pos2>b[p2].se)p2++,pos2=1;
		}
		printf("%d\n",res);
	}
	return 0;
}