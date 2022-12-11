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
const int mod=1e9+7;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define forall(x,y) for (const int &y: e[x])

int n,m;
char mp[2010][2010];
int tot[2010][2010];
int dp[2][2010][2010];
int f[2010][2010],g[2010][2010];

int getsum(int x,int y,int X,int Y){
	return tot[X][Y]-tot[x-1][Y]-tot[X][y-1]+tot[x-1][y-1];
}

void solve(){
	scanf("%d%d",&n,&m);
	if (max(n,m)==1) return puts("1"),void();
	rep(i,1,n) scanf("%s",mp[i]+1);
	rep(i,1,n) rep(j,1,m){
		tot[i][j]=tot[i-1][j]+tot[i][j-1]-tot[i-1][j-1]+(mp[i][j]=='R');
	}
	dp[0][1][1]=dp[1][1][1]=1;
	rep(i,1,n) rep(j,1,m){
		add(dp[0][i][j],g[i][j]);
		add(dp[1][i][j],f[i][j]);
		int s=n-getsum(i+1,j,n,j);
		add(f[i][j],dp[0][i][j]);
		iadd(f[s+1][j],dp[0][i][j]);
		int t=m-getsum(i,j+1,i,m);
		add(g[i][j],dp[1][i][j]);
		iadd(g[i][t+1],dp[1][i][j]);
		add(f[i+1][j],f[i][j]);
		add(g[i][j+1],g[i][j]);
	}
	int z=0;
	add(z,dp[0][n][m]);
	add(z,dp[1][n][m]);
	printf("%d\n",z);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}