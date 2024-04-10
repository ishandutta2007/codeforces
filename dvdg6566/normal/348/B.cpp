#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const int MAXN = 100100;

ll gcd(ll a, ll b){
	if (b==0)return a;
	return gcd(b,a%b);
}

ll hcf(ll a, ll b){
	if (b>a)swap(a,b);
	return a*b/gcd(a,b);
}

ll sz[MAXN];
vi V[MAXN];
ll dp[MAXN];
ll ans;
ll N,a,b,T;
ll A[MAXN];

void dfs(int x, int p){
	if (SZ(V[x]) == 1 && x != 1){
		sz[x] = 1;
		dp[x] = A[x];
		return;
	}
	ll running_gcd=1;
	for (auto v:V[x])if(v!=p){
		dfs(v,x);
		running_gcd = hcf(running_gcd, sz[v]);
	}
	ll max_fact = 1e18;
	for (auto v:V[x])if(v!=p){
		ll rep = dp[v] / running_gcd;
		if (running_gcd > 1e15){
			cout<<T;
			exit(0);
		}
		max_fact = min(max_fact, rep*running_gcd);
	}
	for (auto v:V[x])if(v!=p)ans += dp[v] - max_fact;
	ll child = SZ(V[x]) - 1;
	if (x==1)++child;

	dp[x] = max_fact * child;
	sz[x] = child*running_gcd;
	// cout<<x<<' '<<sz[x]<<' '<<dp[x]<<'\n';
}

int main(){
	cin>>N;
	for (int i=1;i<=N;++i){cin>>A[i];T+=A[i];}
	for (int i=0;i<N-1;++i){
		cin>>a>>b;
		V[a].pb(b);V[b].pb(a);
	}
	dfs(1,-1);
	cout<<ans;
}