#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define lb lower_bound
const int MAXN=1001000;
const ll MOD=998244353;

vi V;
ll N,Q,T,E,K,M,a,b,c,d;
ll A[MAXN],B[MAXN];
ll dp[MAXN][2];
ll ans;

void ask(ll n,ll s){
	// s=0 means the boss is on full health
	// s=1 means boss is on half health and everything else dead
	ll cb = min((A[n]+1)*a,b);
	if(s == 1){
		dp[n+1][0] = min(dp[n+1][0], dp[n][s]+min(a,b)+d);
		// dp[n][s] = ask(n+1,0) + a + d; // kill everything one by one
	}else{
		dp[n+1][0] = min(dp[n+1][0], dp[n][s] + A[n]*a+c+d);
		// dp[n][s] = ask(n+1,0) + A[n]*a + c + d;
		// hit everybody, move up, hit everybody, come back, kill
		dp[n+1][1] = min(dp[n+1][1],dp[n][s]+min(b,a*(A[n]+1))+min(b,a*(A[n+1]+1))+min(a,b)+3*d);

		// dp[n][s] = min(dp[n][s], ask(n+1,1) + 2*b + a + 3*d);
		// hit everybody, move up, do noth, come back, kill
		dp[n+1][0]=min(dp[n+1][0],dp[n][s]+min(b,a*(A[n]+1))+ min(a,b)+3*d);
		// dp[n][s] = min(dp[n][s], ask(n+1,0) + b + a + 3*d);
	}

	if(n == N-1 & s==0){
		// try fancy stuff
		ans=min(ans,b+A[N]*a+a+c+2*d+dp[n][s]);
	}
	// cerr<<n<<' '<<s<<' '<<cb<<' '<<dp[n][s]<<'\n';
	// return dp[n][s];
}

ll suffcst[MAXN];

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>a>>b>>c>>d;
	for(int i=1;i<=N+1;++i){
		dp[i][0]=dp[i][1]=1e18;
	}
	dp[1][0]=0;
	for(int i=1;i<=N;++i)cin>>A[i];
	a=min(a,c);
	ans=1e18;

	for(int i=1;i<=N;++i){
		ask(i,0);ask(i,1);
		// cerr<<dp[i][0]<<' '<<dp[i][1]<<'\n';
	}
	assert(dp[N+1][0]<=dp[N+1][1]);
	ans=min(ans,dp[N+1][0]-d);
	cout<<ans;
	
	// for(int i=1;i<=N;++i){
	// 	// total cost to clear one stage
	// 	suffcst[i]=min({
	// 		b + min(a,b), A[i]*a + c, A[i]*a+2*min(a,b)
	// 	});

	// 	if(i == N){
	// 		suffcst[i] = min({
	// 			b+min(a,b)+d+d, A[i]*a+c, A[i]*a+2*min(a,b)+d+d
	// 		});
	// 	}
	// }
	// for(int i=N-1;i>=1;--i)suffcst[i]+=suffcst[i+1];
	// // for(int i=1;i<=N;++i)cout<<suffcst[i]<<' ';cout<<'\n';

	// for(int i=1;i<=N;++i){
	// 	// cerr<<i<<' '<<dp[i][0]<<'\n';
	// 	ll x=dp[i][0] + suffcst[i] + d*(N-i)*2;
	// 	ans=min(ans,x);
	// 	// cerr<<"U turn "<<x<<'\n';
	// }
	// cout<<ans<<'\n';
	// cout<<ans;
}