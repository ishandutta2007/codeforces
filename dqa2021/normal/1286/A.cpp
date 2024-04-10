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

int n,p[110];
int tot[110];
int dp[2][110][110];

void chk(int &x,const int &y){
	if (y<x) x=y;
}

void solve(){
	n=read();
	rep(i,1,n) p[i]=read(),tot[i]=tot[i-1]+(!p[i]);
	int A=n+1>>1,B=n>>1;
	rep(i,1,n) if (p[i]) (p[i]&1?A:B)--;
	memset(dp,0x3f,sizeof dp);
	if (p[1]) dp[p[1]&1][1][A]=0;
	else{
		if (A) dp[1][1][A-1]=0;
		if (B) dp[0][1][A]=0;
	}
	rep(i,1,n-1){
		rep(e,0,1)
			rep(s,0,A){
				if (dp[e][i][s]>1e8) continue;
				int t=A+B-tot[i]-s;
				assert(t>=0&&t<=B);
				if (p[i+1]){
					chk(dp[p[i+1]&1][i+1][s],dp[e][i][s]+(p[i+1]&1^e));
					continue;
				}
				if (s) chk(dp[1][i+1][s-1],dp[e][i][s]+(e^1));
				if (t) chk(dp[0][i+1][s],dp[e][i][s]+(e));
			}
	}
	int z=1e9;
	rep(s,0,A) rep(e,0,1) z=min(z,dp[e][n][s]);
	printf("%d\n",z);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}