#include<bits/stdc++.h>
#define pb push_back
using namespace std;
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
typedef long long ll;
const int mod=998244353;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,int y){x=upd(x+y-mod);}
inline void iadd(int &x,int y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}

int n; char s[100010];
int dp[4][100010];
void check(int &x,int y){
	if (y<x) x=y;
}
void solve(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=0;i<=n;i++)
		for (int j=0;j<4;j++)
			dp[j][i]=1e9;
	dp[0][0]=0;
	for (int i=0;i<n;i++)
		for (int j=0;j<4;j++){
			if (dp[j][i]==1e9) continue;
			bool f=i&&!(j&1)&&s[i]==s[i+1];
			f|=i>1&&!(j&2)&&s[i-1]==s[i+1];
			if (f) check(dp[(j<<1|1)&3][i+1],dp[j][i]+1);
			else check(dp[(j<<1)&3][i+1],dp[j][i]);
		}
	int ans=1e9;
	for (int i=0;i<4;i++) check(ans,dp[i][n]);
	printf("%d\n",ans);
}
int main()
{
	for (int T=read();T--;) solve();
}