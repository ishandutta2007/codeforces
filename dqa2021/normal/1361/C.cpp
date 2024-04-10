#include<bits/stdc++.h>
#define pb emplace_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
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
#define all(x) (x).begin(),(x).end()
typedef pair<int,int> P;
/*const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}*/
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)

int n,a[500010],b[500010];
vector<P> e[1<<20];

bool vis[500010];

vector<int> S;

int lim;

void dfs(int x){
	while (e[x].size()){
		const auto &[id,dir]=e[x].back();
		e[x].pop_back();
		if (vis[id]) continue;
		vis[id]=1;
		dfs((dir?a[id]:b[id])&(lim-1));
		if (dir) S.pb(id+id-1),S.pb(id+id);
		else S.pb(id<<1),S.pb(id*2-1);
	}
}

bool check(int d,bool f=0){
	lim=1<<d;
	rep(i,0,lim-1) e[i].clear();
	memset(vis,0,sizeof vis);
	rep(i,1,n){
		int u=a[i]&(lim-1),v=b[i]&(lim-1);
		e[u].pb(i,0);
		e[v].pb(i,1);
	}
	rep(i,0,lim-1) if (e[i].size()&1) return 0;
	rep(i,0,lim-1) if (e[i].size()){
		S.clear();
		dfs(i);
		if (S.size()!=n+n) return 0;
		if (f){
			//S.pb(S[0]);
			//S.erase(S.begin());
			for (int x: S) printf("%d ",x);
			puts("");
			
			/*for (int x: S){
				printf("%d%d ",x&1,x>>1&1);
			}
			puts("");*/
		}
		return 1;
	}
}

void solve(){
	n=read();
	rep(i,1,n) a[i]=read(),b[i]=read();
	int ans=0;
	while (ans<20&&check(ans+1)) ++ans;
	printf("%d\n",ans);
	check(ans,1);
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}