#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define f first
#define s second
#define MAXN 101000
ll N,M,a,b;
ll MOD = 1e9+7;

ll dp[20][1010];
ll ans = 0;

ll ask(ll a, ll b){
	if (dp[a][b] != -1)return dp[a][b];
	if (a == 0)return dp[a][b] = 1;

	dp[a][b] = 0;
	for (int t=1;t<=b;++t){
		dp[a][b] = (dp[a][b] + ask(a-1, t))% MOD;
	}
	// cout<<a<<' '<<b<<' '<<dp[a][b]<<'\n';
	return dp[a][b];
}

int main(){
	memset(dp,-1,sizeof(dp));
	cin>>N>>M;
	for (int l=1;l<=N;++l){
		for (int r = l;r<=N;++r){
			ll sp = N-r+1;
			// cout<<l<<' '<<sp<<'\n';
			ans += ((ask(M-1,l)%MOD) * (ask(M-1,sp)%MOD))%MOD;
			ans %= MOD;
		}
	}
	cout<<ans;
}