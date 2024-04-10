#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=613;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1100;const ll inf=1.3e18;
int n,m,lcp[N][N];char s[N];Pii a[N*N];int sz;ll k,dp[N][N];
bool cmp(Pii a, Pii b){
	int l=lcp[a.fi][b.fi];
	if(a.se-a.fi+1>l&&b.se-b.fi+1>l)return s[a.fi+l]<s[b.fi+l];
	return a.se-a.fi<b.se-b.fi;
}
ll calc(Pii bas){
	memset(dp,0,sizeof(dp));static int pos[N];
	rep(i,1,n){
		pos[i]=i;while(pos[i]<=n&&cmp(mp(i,pos[i]),bas))pos[i]++;
	}
	dp[0][n+1]=1;
	rep(tt,1,m){
		static ll hz[N];
		per(i,n+1,1)hz[i]=min(hz[i+1]+dp[tt-1][i],inf);
		per(i,n,1)dp[tt][i]=hz[pos[i]+1];
	}
	return dp[m][1];
}
int main() {
	read(n);read(m);read(k);
	scanf("%s",s+1);
	per(i,n,1)per(j,n,1)lcp[i][j]=s[i]==s[j]?1+lcp[i+1][j+1]:0;
	rep(i,1,n)rep(j,i,n)a[++sz]=mp(i,j);
	sort(a+1,a+sz+1,cmp);
//	rep(i,1,sz)printf("%d %d:%lld\n",a[i].fi,a[i].se,calc(a[i]));
	int l=1,r=sz;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(calc(a[mid])>=k)l=mid;else r=mid-1;
	}
	rep(i,a[l].fi,a[l].se)printf("%c",s[i]);
	return 0;
}