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

int n;
vector<int> e[100010];
int L[100010],R[100010];
ll dp[100010][2];

void dfs(int x,int f){
	dp[x][0]=dp[x][1]=0;
	forall(x,y) if (y^f){
		dfs(y,x);
		dp[x][0]+=max(dp[y][0]+abs(L[y]-L[x]),dp[y][1]+abs(R[y]-L[x]));
		dp[x][1]+=max(dp[y][0]+abs(L[y]-R[x]),dp[y][1]+abs(R[y]-R[x]));
	}
}

void solve(){
	n=read();
	rep(i,1,n) e[i].clear();
	rep(i,1,n) L[i]=read(),R[i]=read();
	rep(i,2,n){
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	dfs(1,0);
	printf("%lld\n",max(dp[1][0],dp[1][1]));
}

int main()
{
	for (int T=read();T--;) solve();
	return 0;
}