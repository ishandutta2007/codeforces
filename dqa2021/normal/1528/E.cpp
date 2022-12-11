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
const int mod=998244353;
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

int n;
int dp[1000010][4];

void solve(){
	n=read();
	dp[0][0]=1;
	rep(i,1,n){
		auto F=dp[i],G=dp[i-1];
		int S=0;
		rep(j,0,2) add(S,G[j]);
		F[0]=1;
		F[1]=S;
		F[2]=1LL*S*(S+1)/2%mod;
		F[3]=1LL*S*(S-1)%mod*(S-2)%mod*((mod+1)/6)%mod;
		add(F[3],1LL*S*(S-1)%mod);
		add(F[3],S);
	}
	per(i,1,n){
		auto F=dp[i],G=dp[i-1];
		//printf("dp %d: ",i); rep(j,0,3) printf("%d ",F[j]); puts("");
		rep(j,0,3) iadd(F[j],G[j]);
	}
	int z=0;
	rep(u,0,3) if (u^1) rep(v,0,3-u){
		rep(i,0,n){
			//printf("test %d %d :: %d %d: %lld\n",u,i,v,n-i,1LL*dp[i][u]*dp[n-i][v]%mod);
			add(z,1LL*dp[i][u]*dp[n-i][v]%mod);
			//printf("test %d %d :: %d %d: %lld\n",u,i,v,n-i,1LL*dp[i][u]*dp[n-i][v]%mod);
			//printf("  z %d\n",z);
		}
	}
	printf("%d\n",z);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}