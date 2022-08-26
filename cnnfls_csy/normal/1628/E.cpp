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
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,i,j,pa[600005],cnt,val[600005];
int fnd(int x){if(pa[x]==x)return x;return pa[x]=fnd(pa[x]);}
struct ii{int x,y,z;}a[300005];
int fa[600005],sz[600005],tp[600005],son[600005],dfn[600005],ti,mp[600005],dep[600005];
vector<int> bi[600005];
void dfs1(int x,int fa){::fa[x]=fa;sz[x]=1;ff(bi[x],it)if(*it!=fa){dep[*it]=dep[x]+1;dfs1(*it,x);sz[x]+=sz[*it];if(!son[x]||sz[son[x]]<sz[*it]){son[x]=*it;}}}
void dfs2(int x,int t){mp[dfn[x]=++ti]=x;tp[x]=t;if(son[x])dfs2(son[x],t);ff(bi[x],it)if(*it!=fa[x]&&*it!=son[x]){dfs2(*it,*it);} }
int lca(int x,int y){if(!x||!y) return x+y;while(tp[x]!=tp[y]){if(dep[tp[x]]<dep[tp[y]])swap(x,y);x=fa[tp[x]];}return mp[min(dfn[x],dfn[y])];}
bool cmp(ii x,ii y){return x.z<y.z;}
int tr[2400005],tag[2400005],ori[2400005];
void build(int x,int l,int r)
{
	if(l==r){ori[x]=l;return;}
	int mid=(l+r)/2;
	build(x+x,l,mid);
	build(x+x+1,mid+1,r);
	ori[x]=lca(ori[x+x],ori[x+x+1]);
}
void upd(int x,int c)
{
	tag[x]=c;
	if(c==1) tr[x]=ori[x]; else tr[x]=0;
}
void pushdo(int x)
{
	if(tag[x]){
		upd(x+x,tag[x]);
		upd(x+x+1,tag[x]);
		tag[x]=0;
	}
}
void update(int x,int l,int r,int ql,int qr,int c)
{
	if(ql<=l&&r<=qr){
		upd(x,c);return;
	}
	int mid=(l+r)/2;pushdo(x);
	if(ql<=mid) update(x+x,l,mid,ql,qr,c);
	if(qr>mid) update(x+x+1,mid+1,r,ql,qr,c);
	tr[x]=lca(tr[x+x],tr[x+x+1]);
}
int main()
{
	read(n);read(m);fz1(i,n)pa[i]=i;
	fz1(i,n-1)read(a[i].x),read(a[i].y),read(a[i].z);
	sort(a+1,a+n,cmp);cnt=n;
	fz1(i,n-1){
		int x=fnd(a[i].x),y=fnd(a[i].y);cnt++;
		bi[cnt].push_back(x);bi[cnt].push_back(y);
		pa[x]=pa[y]=pa[cnt]=cnt;val[cnt]=a[i].z;
	}
	dfs1(cnt,0);dfs2(cnt,cnt);
	build(1,1,n);
	while(m--){
		int op;read(op);
		if(op==1){
			int l,r;read(l);read(r);
			update(1,1,n,l,r,1);
		}
		if(op==2){
			int l,r;read(l);read(r);
			update(1,1,n,l,r,-1);
		}
		if(op==3){
			int x;read(x);
			if(tr[1]&&tr[1]!=x) printf("%d\n",val[lca(x,tr[1])]); else puts("-1");
		}
	}
	return 0;
}