#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define MAXN 5010
 
ll N,K,X;
deque<pi> dq;
ll memo[MAXN][2];
ll V[MAXN];
 
void ins(ll ind,ll val){
	if (SZ(dq) && dq[0].f + K <= ind){
		dq.pop_front();
	}
	while(SZ(dq)){
		if (dq.back().s < val){
			dq.pop_back();
		}else break;
	}
	dq.pb(mp(ind,val));
}
 
ll ans=-1;
 
int main(){
	// freopen("in.txt","r",stdin);
	cin>>N>>K>>X;
	for (ll i=1;i<=N;++i)cin>>V[i];
	memset(memo,-1,sizeof(memo));
	memo[0][0] = 0;
 
	for (ll j=1;j<=X;++j){
		dq.clear();
		for (ll i=0;i<=N;++i)memo[i][j%2]=-1;
		for (ll i=1;i<=N;++i){
			ins(i, memo[i-1][1-j%2]);
			if (dq[0].s == -1)memo[i][j%2] = -1;
			else memo[i][j%2] = dq[0].s + V[i];
		}
		// for (ll i=1;i<=N;++i)cout<<memo[i][j%2]<<' ';
		// cout<<'\n';
	}
	for (ll i=N;i>N-K;--i){
		// cout<<memo[i][X%2]<<' ';
		ans = max(ans, memo[i][X%2]);
	}
	cout<<ans;
}