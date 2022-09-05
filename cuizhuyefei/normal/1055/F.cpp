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
typedef pair<ll,ll> Pii;
inline void read(ll &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 2020000;
ll n,k,fa[N],w[N],res;vector<Pii>e[N];
struct seg{
	int l,r,L,R;
}a[N],b[N];int len;
void dfs(int u, ll val){
	w[u]=val;
	per(i,SZ(e[u])-1,0)dfs(e[u][i].fi,val^e[u][i].se);
}
inline void init(int &l, ll tp,ll val){
	l=0;
	rep(i,1,len){
		int m,M;
		for(m=a[i].l;m<=a[i].r;m++)if((w[m]&val))break;
		for(M=a[i].L;M<=a[i].R;M++)if((w[M]&val))break;
		m--;M--;
		if(!tp){
			if(a[i].l<=m&&a[i].L<=M)b[++l]=(seg){a[i].l,m,a[i].L,M};
			if(m+1<=a[i].r&&M+1<=a[i].R)b[++l]=(seg){m+1,a[i].r,M+1,a[i].R};
		}
		else{
			if(a[i].l<=m&&M+1<=a[i].R)b[++l]=(seg){a[i].l,m,M+1,a[i].R};
			if(m+1<=a[i].r&&a[i].L<=M)b[++l]=(seg){m+1,a[i].r,a[i].L,M};
		}
	}
}
inline ll calc(ll len){//b[1..len]
	ll res=0;rep(i,1,len)res+=1LL*(b[i].r-b[i].l+1)*(b[i].R-b[i].L+1);
	return res;
}
int main() {
	read(n);read(k);
	rep(i,2,n){ll f,x;read(f);read(x);fa[i]=f;e[f].pb(Pii(i,x));}
	dfs(1,0);sort(w+1,w+n+1);
	
	len=1;a[1].l=a[1].L=1;a[1].r=a[1].R=n;
	
	ll now=0;
	per(bit,62,0){
	//	ll x=calc(now,bit);
		int l;init(l,0,1LL<<bit);ll tmp=calc(l);
	//	printf("%d:%lld %lld\n",bit,tmp,(ll)l);
		if(k>tmp){
			k-=tmp,now|=1LL<<bit;
			init(l,1,1LL<<bit);len=l;rep(i,1,len)a[i]=b[i];
		}
		else {len=l;rep(i,1,len)a[i]=b[i];}
	}
	cout<<now;
	return 0;
}