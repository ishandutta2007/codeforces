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

int mod;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}

//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])
int C[410][410],pw[410];
void init(int x){
	rep(i,0,x){
		C[i][0]=1;
		rep(j,1,i) C[i][j]=upd(C[i-1][j]+C[i-1][j-1]-mod);
	}
	rep(i,0,x) pw[i]=qpow(2,i);
}

int n;
int dp[410][410];

void solve(){
	n=read(); mod=read();
	init(n+3);
	dp[0][0]=1;
	rep(i,0,n-1){
		rep(j,0,n){
			const int &V=dp[i][j];
			if (!V) continue;
			rep(k,i+2,n+1){
				add(dp[k][j+k-i-1],1LL*V*C[j+k-i-1][j]%mod*pw[k-i-2]%mod);
			}
		}
	}
	int z=0;
	rep(j,0,n) add(z,dp[n+1][j]);
	printf("%d\n",z);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}