#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
#define db long double
using namespace std;
const int N=1e6+6,P=1e9+7;
ll a[N]; pair<ll,pr> e[N];
int fa[N],st[N],tp;
int getfa(int u){ return fa[u]==u?u:fa[u]=getfa(fa[u]); }
void back(){ while (tp) fa[st[tp]]=st[tp],--tp; }
int merge(int u,int v){
	u=getfa(u),v=getfa(v);
	if (u==v) return 0;
	fa[u]=v,st[++tp]=u; return 1;
}
int fpw(int x,int y){
	int s=1;
	for (;y;y>>=1,x=(ll)x*x%P) if (y&1) s=(ll)s*x%P;
	return s;
}
int main(){
	int n,m,k; scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n) scanf("%lld",&a[i]);
	rep(i,1,m){
		int u,v; scanf("%d%d",&u,&v);
		e[i]=mp(a[u]^a[v],mp(u,v));
	}
	sort(e+1,e+1+m);
	rep(i,1,n) fa[i]=i;
	int c=n,ans=0,num=0;
	rep(i,1,m){
		if (e[i].fi!=e[i-1].fi){
			++num;
			if (i!=1) ans=(ans+fpw(2,c))%P,back(),c=n;
		}
		c-=merge(e[i].se.fi,e[i].se.se);
	}
	if (m) ans=(ans+fpw(2,c))%P;
	printf("%d\n",(ans+(ll)(fpw(2,k)+P-num)*fpw(2,n))%P);
	return 0;
}