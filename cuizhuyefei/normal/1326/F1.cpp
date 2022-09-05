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
typedef pair<ll,ll> Pll;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
mt19937 R(chrono::system_clock().now().time_since_epoch().count());

const int N = 1<<14|3;//4782969+3;
int n,cnt[N];char s[66][66];
//ll dp[N][15];int mi[15];
vector<ll>dp[N][15];
int main() {
	read(n);rep(i,1,1<<n)cnt[i]=cnt[i>>1]+(i&1);
	rep(i,1,n)scanf("%s",s[i]+1);
//	mi[0]=1;rep(i,1,n)mi[i]=mi[i-1]*3;
	rep(i,1,(1<<n)-1)rep(j,1,n)if(i>>j-1&1)dp[i][j].resize(1<<cnt[i]-1);
	rep(i,1,n)dp[1<<i-1][i][0]=1;
	rep(i,1,(1<<n)-1)rep(j,1,n)if(i>>j-1&1)rep(k,0,(1<<cnt[i]-1)-1)if(dp[i][j][k]){
	//	printf("%d %d %d\n",i,j,k);
		rep(x,1,n)if(!(i>>x-1&1))dp[i|(1<<x-1)][x][k|((s[j][x]=='1')<<cnt[i]-1)]+=dp[i][j][k];
	}
	rep(i,0,(1<<n-1)-1){
		ll res=0;rep(j,1,n)res+=dp[(1<<n)-1][j][i];
		printf("%lld ",res);
	}
	return 0;
}