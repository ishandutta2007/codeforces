#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long long ll;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
/*
const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
*/
typedef pair<ll,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])

int n,m,X;
ll w[300010];

struct E{
	int t,n;
}e[600010];
int cnt=1,last[300010],tot[300010];
inline void addedge(int x,int y){
	e[++cnt]=(E){y,last[x]},last[x]=cnt,++tot[x];
	e[++cnt]=(E){x,last[y]},last[y]=cnt,++tot[y];
}

int f[300010];
int find(int x){return f[x]?f[x]=find(f[x]):x;}
priority_queue<P> A,B;

void merge(int x,int y){
	x=find(x),y=find(y);
	assert(x^y);
	B.push(P(w[y],y));
	f[y]=x; w[x]+=w[y]-X;
	assert(w[x]>=0);
	A.push(P(w[x],x));
	if (tot[x]<tot[y]) swap(tot[x],tot[y]),swap(last[x],last[y]);
	if (!last[y]) return;
	for (int i=last[y];i;i=e[i].n){
		if (!e[i].n){
			e[i].n=last[x];
			break;
		}
	}
	last[x]=last[y],tot[x]+=tot[y];
}

void solve(){
	n=read(),m=read(),X=read();
	ll S=0;
	rep(i,1,n) w[i]=read(),S+=w[i];
	if (S<1LL*(n-1)*X) return puts("NO"),void();
	rep(i,1,m){
		int u=read(),v=read();
		addedge(u,v);
	}
	puts("YES");
	rep(i,1,n) A.push(P(w[i],i));
	while (A.size()-B.size()>1){
		while (B.size()&&A.top()==B.top()) A.pop(),B.pop();
		const int o=A.top().se; A.pop();
		for (int &i=last[o];i;i=e[i].n){
			const int v=e[i].t;
			if (find(v)==find(o)) continue;
			printf("%d ",i>>1); i=e[i].n;
			merge(o,v);
			break;
		}
	}
	puts("");
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}