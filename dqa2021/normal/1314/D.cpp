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
const int INF=1e9;

int n,k;
int mp[90][90];
int c[90];

int dp[16][90];
int work(){
	rep(i,1,n) dp[0][i]=INF;
	dp[0][1]=0;
	rep(_,1,k){
		rep(i,1,n) dp[_][i]=INF;
		rep(i,1,n){
			const int &V=dp[_-1][i];
			if (V==INF) continue;
			rep(j,1,n) if (c[j]^c[i]) dp[_][j]=min(dp[_][j],V+mp[j][i]);
		}
	}
	return dp[k][1];
}

void solve(){
	srand(time(nullptr));
	n=read(),k=read();
	rep(i,1,n) rep(j,1,n) mp[i][j]=read();
	int ans=1e9;
	int cnt=0;
	while (cnt<=10000&&double(clock())/CLOCKS_PER_SEC<2.7){
		rep(i,1,n) c[i]=rand()&1;
		ans=min(ans,work());
		++cnt;
	}
	printf("%d\n",ans);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}