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
/*
const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
*/
//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)
#define all(x) (x).begin(),(x).end()
const ll INF=3e14;

bool ask(ll x){
//	if (x<=0) return 1;
//	if (x>ll(1e14)) return 0;
	assert(0<x&&x<=ll(1e14));
	printf("? %lld\n",x);
	fflush(stdout);
	static char s[32];
	scanf("%s",s);
	if (s[0]=='L') return 1;
	else if (s[1]=='r') return 0;
	else return assert(0),0;
}

void report(ll x){
	printf("! %lld\n",x);
	fflush(stdout);
}

ll dp[64][64];

void solve(ll l,ll r,int x,int y){
	if (l==r) return report(l);
	assert(x);
	if (!y) return ask(l),solve(l,r,x-1,y+1);
	ll u=dp[x-1][y-1],v=dp[x-1][y+3>>1],md;
	u=min(u,v);
	assert(u+v>=r-l+1);
	if (u*2<=r-l+1) md=u;
	else md=r-l+1>>1;
	assert(md<=r-l+1-md);
	md+=l;
	if (ask(md)) solve(md,r,x-1,y+3>>1);
	else solve(l,md-1,x-1,y-1);
}

void solve(){
	int id=47;
	rep(i,0,46){
		if (!ask(1LL<<i)){
			id=i; break;
		}
	}
	if (!id) return report(0);
	ll l=1LL<<id-1,r=min(1LL<<id,ll(1e14)+1)-1;
	ask(l); ask(l);
	solve(l,r,56,1);
}

int main()
{
	rep(i,0,56) dp[0][i]=1;
	dp[1][0]=1;
	rep(i,1,56) dp[1][i]=2;
	rep(i,2,56){
		rep(j,0,56){
			if (!j) dp[i][j]=dp[i-1][j+1];
			else{
				const ll u=dp[i-1][j-1],v=dp[i-1][(j-1>>1)+2];
				dp[i][j]=min(u,v)+v;
				dp[i][j]=min(dp[i][j],INF);
			}
//			printf("%lld%c",dp[i][j]," \n"[j==50]);
		}
	}
	
	for (int T=read();T--;) solve();
	return 0;
}