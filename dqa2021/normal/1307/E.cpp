#pragma GCC optimize(2,3,"Ofast")
#pragma GCC optimize("unroll-loops")

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

typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)

int n,m;
int s[5010],f[5010],h[5010];
int p[5010][5010],q[5010][5010];

void checkans(P &x,const P &y){
//	if (!y.se) return;
	if (y.fi>x.fi) x=y;
	else if (y.fi==x.fi) add(x.se,y.se);
}

P dp[5010];
//P operator+(P x,int y){return P(~x.fi?x.fi+y:x.fi,x.se);}

ll getval(int x,int y){
	if (x>y) swap(x,y);
	return 1LL*x*(y-1);
}

P solve(int md){
	bool ok=md==0;
	if (md) rep(i,1,m) if (f[i]==s[md]&&h[i]==p[s[md]][md]) ok=1;  //caution md==0
	if (!ok) return P(-1,0);
	rep(i,0,n) dp[i]=P(-1,0);
	dp[0]=P(0,1);
	rep(i,1,n){
		P v=dp[i-1];
//		assert(~v.fi&&v.se);
		int L=q[i][p[i][md]],R=q[i][p[i][n]-p[i][md]];
//		printf("test L %d R %d\n",L,R);
		if (md&&s[md]==i){
			assert(L);
			if (R>=L) R--;
			if (R) checkans(dp[i],P(v.fi+2,1LL*v.se*R%mod));
			else checkans(dp[i],P(v.fi+1,v.se));
		}
		else{
			const ll &V=getval(L,R);
			if (V) checkans(dp[i],P(v.fi+2,V%mod*v.se%mod));
			else if (L+R) checkans(dp[i],P(v.fi+1,1LL*v.se*(L+R)%mod));
			else checkans(dp[i],P(v.fi,v.se));
//			checkans(dp[i],P(v.fi+1,1LL*v.se*(L+R)%mod));
//			checkans(dp[i],P(v.fi+1,1LL*v.se*R%mod));
		}
	}
//	printf("solve %d: %d %d\n",md,dp[n].fi,dp[n].se);
//	assert(~dp[n].fi&&dp[n].se);
	return dp[n];
}
void solve(){
	n=read(),m=read();
	rep(i,1,n) s[i]=read(),p[s[i]][i]++;
	rep(i,1,m) f[i]=read(),h[i]=read(),q[f[i]][h[i]]++;
	rep(i,1,n) rep(j,1,n) p[i][j]+=p[i][j-1],q[i][j]+=q[i][j-1];
	P ans(-1,0);
	rep(i,0,n) checkans(ans,solve(i));
//	assert(~ans.fi&&ans.se);
//	assert(ans.se);
	printf("%d %d\n",ans.fi,ans.se);
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}