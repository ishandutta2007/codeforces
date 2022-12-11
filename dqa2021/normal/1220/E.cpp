#include<bits/stdc++.h>
#define pb push_back
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
//typedef pair<int,int> P;
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
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define forall(x,y) for (const int &y: e[x])

int n,m;
vector<int> e[200010];
int w[200010];

bool ok[200010];
ll dp[200010];
bool vis[200010];

void dfs(int x,int f){
	vis[x]=1;
	forall(x,y)
		if (y^f){
			if (!vis[y]){
				dfs(y,x);
				dp[x]=max(dp[x],dp[y]);
				ok[x]=ok[x]||ok[y];
			}
			else ok[x]=1;
		}
	dp[x]+=w[x];
}

void solve(){
	n=read(),m=read();
	rep(i,1,n) w[i]=read();
	rep(i,1,m){
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	dfs(read(),0);
	ll z=0,y=0;
	rep(i,1,n) if (ok[i]) z+=w[i];
		else y=max(y,dp[i]);
	printf("%lld\n",z+y);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}