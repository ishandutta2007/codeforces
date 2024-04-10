#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const ll MAXN=110,INF=1e18;
int T,n,m;
ll a[MAXN][MAXN],ans;
ll dp[MAXN][MAXN];
int num(int i,int j){
	return i+j-2;
}
void DP(int i,int j){
	ll x=a[i][j]-num(i,j);
	dp[1][1]=INF;
	if(a[1][1]>=x)dp[1][1]=a[1][1]-x;
	rep(i,1,n){
		rep(j,1,m){
			if(i==1 && j==1)continue;
			dp[i][j]=INF;
			if(a[i][j]-num(i,j)<x)continue;
			if(i!=1)dp[i][j]=min(dp[i][j],dp[i-1][j]+a[i][j]-num(i,j)-x);
			if(j!=1)dp[i][j]=min(dp[i][j],dp[i][j-1]+a[i][j]-num(i,j)-x);
			//printf("dp[%d][%d]:%lld\n",i,j,dp[i][j]);
		} 
	}
	ans=min(ans,dp[n][m]);
}
void solve(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		rep(j,1,m){
			scanf("%lld",&a[i][j]);
		}
	}
	ans=INF;
	rep(i,1,n)rep(j,1,m){
		DP(i,j);
	}
	printf("%lld\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--){
		solve();
	}

	return 0;
}
/*
1
5 5
2 5 4 8 3
9 10 11 5 1
12 8 4 2 5
2 2 5 4 1
6 8 2 4 2
*/