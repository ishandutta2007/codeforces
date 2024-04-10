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
const int mod=1004535809;
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
char s[1000010];
int dp[1000010],f[1000010];
int geth(int x,int y){return (x-1)*m+y;}
void solve(){
	n=read(),m=read();
	rep(i,1,n) scanf("%s",s+(i-1)*m+1);
	dp[n*m]=1;
	per(i,1,n) per(j,1,m){
		int o=geth(i,j);
		if (s[o]=='#') continue;
		if (i<n){
			int t=geth(i+1,j);
			add(dp[o],dp[t]);
		}
		if (j<m){
			int t=geth(i,j+1);
			add(dp[o],dp[t]);
		}
	}
	f[1]=1;
	rep(i,1,n) rep(j,1,m){
		int o=geth(i,j);
		if (s[o]=='#') continue;
		if (i>1){
			int t=geth(i-1,j);
			add(f[o],f[t]);
		}
		if (j>1){
			int t=geth(i,j-1);
			add(f[o],f[t]);
		}
	}
	if (!dp[1]) puts("0");
	else{
		bool f=0;
		rep(i,2,n*m-1)
			if (1LL*dp[i]*::f[i]%mod==dp[1]){
				puts("1"); f=1; break;
			}
		if (!f) puts("2");
	}
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}