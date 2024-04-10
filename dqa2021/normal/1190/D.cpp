#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
using namespace std;

//#define DEBUG
#ifdef DEBUG
template<typename ...Args>
int debug(const Args &...args){
	return fprintf(stderr,args...);
}
#else
#define debug(...) void()
#endif

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
typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])

int n;
P p[200010];
int tri[200010];
void add(int x){
	for (;x<=n;x+=x&-x) tri[x]++;
}
int ask(int x){
	int z=0;
	for (;x;x-=x&-x) z+=tri[x];
	return z;
}
bool vis[200010];
ll W(int x){
	return 1LL*x*(x+1)/2;
}

void solve(){
	n=read();
	vector<int> S; S.pb(0);
	rep(i,1,n){
		int x=read(),y=read();
		p[i]={x,y}; S.pb(x);
	}
	sort(all(S)); S.erase(unique(all(S)),S.end()); int m=S.size()-1;
	rep(i,1,n) p[i].fi=lower_bound(all(S),p[i].fi)-S.begin();
	sort(p+1,p+n+1,[](P x,P y){return x.se>y.se||(x.se==y.se&&x.fi<y.fi);});
	ll z=0; int q=0;
	for (int i=1,j;i<=n;i=j+1){
		for (j=i;j<n&&p[j+1].se==p[j].se;++j);
		rep(k,i,j+1){
			if (k==i) z-=W(ask(p[i].fi-1));
			else if (k==j+1) z-=W(ask(n)-ask(p[j].fi));
			else z-=W(ask(p[k].fi-1)-ask(p[k-1].fi));
		}
//		printf("i %d j %d\n",i,j);
//		printf("  z0 %lld\n",z);
		rep(k,i,j){
			if (!vis[p[k].fi]) vis[p[k].fi]=1,++q,add(p[k].fi);
		}
		z+=W(q);
//		printf("  z1 %lld\n",z);
	}
	printf("%lld\n",z);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}