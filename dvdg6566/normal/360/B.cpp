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

ll dp[MAXN];
ll N,K;
ll A[MAXN];

ll ask(ll dif){
	memset(dp,0,sizeof(dp));
	for (int i=1;i<=N;++i){
		for (int j=i+1;j<=N;++j){
			ll w = abs(A[i] - A[j]);
			ll dst = j-i;
			ll t = (w+dst-1)/dst;
			if (t>dif){continue;}
			dp[j] = max(dp[j], dp[i]+1);
		}
	}
	return *max_element(dp,dp+N+1);
}

int main(){
	cin>>N>>K;
	for (int i=1;i<=N;++i)cin>>A[i];
	ll l = 0;
	ll u = 2*1e9;
	ll ranges = N-K-1;
	while (u>l){
		ll m = (l+u)/2;
		if (ask(m) >= ranges)u=m;
		else l=m+1;
	}
	cout<<l;
}