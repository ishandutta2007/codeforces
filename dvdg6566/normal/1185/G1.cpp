#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
ll MOD = 1e9+7;
ll INF = 1e9;
ll BM = 65536;
ll MAXL = 230;

ll memo[32768][230][4];
vpi V;
ll N,T,a,b;

ll dp(ll a, ll b, ll c){
	if (b < 0)return 0;
	if (b == 0)return 1;
	if (memo[a][b][c] != -1)return memo[a][b][c];

	ll ans = 0;

	for (int i=0;i<N;++i){
		if (((1<<i) & a) == 0)continue; // already
		if (V[i].s == c)continue;
		ll newa = a - (1<<i); // Switch off the bit
		ll newb = b - V[i].f;
		ans = (ans + dp(newa,newb,V[i].s)) %MOD;
	}
	// cout<<a<<' '<<b<<' '<<c<<' '<<ans<<'\n';
	return memo[a][b][c] = ans;
}

int main(){
	// freopen("in.txt","r",stdin);
	cin>>N>>T;
	for (int i=1;i<=N;++i){
		cin>>a>>b;
		V.pb(mp(a,b));
	}
	ll bm = (1<<N)-1;
	memset(memo,-1,sizeof(memo));
	cout<<dp(bm,T,0);
}