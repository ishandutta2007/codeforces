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
typedef pair<int,ll> Pil;
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
const int N = 233333,mo=1e9+7;
int mi[N],n,m,dep[N];vector<Pil>e[N];bool vis[N];
ll val[N],s[N],res,a[61];int len;
inline void add(ll x){
	per(i,59,0)if(x>>i&1)
		if(!a[i]){a[i]=x;break;}
		else x^=a[i];
}
void dfs(int u, int Dep, int fa, ll v){
	vis[u]=1;dep[u]=Dep;s[++len]=v;val[u]=v;
	rep(i,0,SZ(e[u])-1)if(!vis[e[u][i].fi])dfs(e[u][i].fi,Dep+1,u,v^e[u][i].se);
	else if(dep[e[u][i].fi]<dep[u]&&e[u][i].fi!=fa){
		add(val[u]^val[e[u][i].fi]^e[u][i].se);
	}
}
inline ll calc(int bit){
	int cnt[2]={0};rep(i,0,59)if(a[i])cnt[a[i]>>bit&1]++;
	int b[2]={0};rep(i,1,len)b[s[i]>>bit&1]++;
	if(!cnt[1]){return 1LL*b[0]*b[1]%mo*mi[cnt[0]]%mo;}
	return (1LL*b[0]*b[1]%mo+1LL*b[0]*(b[0]-1)/2+1LL*b[1]*(b[1]-1)/2)%mo*mi[cnt[0]+cnt[1]-1]%mo;
}
int main() {
	memset(dep,-1,sizeof(dep));mi[0]=1;rep(i,1,N-1)mi[i]=2LL*mi[i-1]%mo;
	read(n);read(m);
	while(m--){
		int u,v;ll w;read(u);read(v);read(w);
		e[u].pb(Pil(v,w));e[v].pb(Pil(u,w));
	}
	rep(i,1,n)if(!vis[i]){
		memset(a,0,sizeof(a));len=0;dfs(i,0,0,0);
		rep(bit,0,59)res=(res+(1LL<<bit)%mo*calc(bit))%mo;
	}
	cout<<(res%mo+mo)%mo;
	return 0;
}