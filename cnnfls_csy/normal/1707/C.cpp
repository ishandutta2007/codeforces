#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<bitset>
#include<cassert>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mk make_pair
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
#ifndef ONLINE_JUDGE
	FILE *___=freopen("1.in","r",stdin);
#endif
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,i,j,sm,px[200005],py[200005],it[200005],pa[200005],pre[200005];
int fnd(int x){if(pa[x]==x)return x;return pa[x]=fnd(pa[x]);}
int fa[200005],sz[200005],tp[200005],son[200005],dfn[200005],dfe[200005],ti,mp[200005],dep[200005];
vector<int> bi[200005];
void dfs1(int x,int fa){::fa[x]=fa;sz[x]=1;ff(bi[x],it)if(*it!=fa){dep[*it]=dep[x]+1;dfs1(*it,x);sz[x]+=sz[*it];if(!son[x]||sz[son[x]]<sz[*it]){son[x]=*it;}}}
void dfs2(int x,int t){mp[dfn[x]=++ti]=x;tp[x]=t;if(son[x])dfs2(son[x],t);ff(bi[x],it)if(*it!=fa[x]&&*it!=son[x]){dfs2(*it,*it);}dfe[x]=ti;}
int lca(int x,int y){while(tp[x]!=tp[y]){if(dep[tp[x]]<dep[tp[y]])swap(x,y);x=fa[tp[x]];}return mp[min(dfn[x],dfn[y])];}
int gtp(int x,int d)
{
	while(dep[x]-dep[tp[x]]<d){
		d-=dep[x]-dep[fa[tp[x]]];
		x=fa[tp[x]];
	}
	return mp[dfn[x]-d];
}
int main()
{
	read(n);read(m);fz1(i,n)pa[i]=i;
	fz1(i,m){
		read(px[i]);read(py[i]);
		if(fnd(px[i])!=fnd(py[i])){
			it[i]=1;
			pa[fnd(px[i])]=fnd(py[i]);
			bi[px[i]].push_back(py[i]);
			bi[py[i]].push_back(px[i]);
		}
	}
	dfs1(1,0);dfs2(1,1);
	fz1(i,m)if(!it[i]){
		int x=px[i],y=py[i];sm++;
		if(dep[x]<dep[y]) swap(x,y);
		int z=lca(x,y);
		if(z==y){
			z=gtp(x,dep[x]-dep[y]-1);
			pre[1]++;
			pre[dfn[z]]--;
			pre[dfe[z]+1]++;
			pre[dfn[x]]++;
			pre[dfe[x]+1]--;
		}
		else{
			pre[dfn[x]]++;
			pre[dfe[x]+1]--;
			pre[dfn[y]]++;
			pre[dfe[y]+1]--;
		}
	}
	fz1(i,n) pre[i]+=pre[i-1];
	fz1(i,n) putchar('0'+(pre[dfn[i]]==sm));
	return 0;
}