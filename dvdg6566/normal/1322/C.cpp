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
#define MAXN 501010

ll T,N,M,a,b;
ll A[MAXN];
vi V[MAXN];

bool cmp(ll a, ll b){
	ll l = min(SZ(V[a]), SZ(V[b]));
	for (ll i=0;i<l;++i){
		if (V[a][i] != V[b][i])return V[a][i] < V[b][i];
	}
	return SZ(V[a]) < SZ(V[b]);
}

bool is_equal(ll x, ll y){
	// cout<<"Is equal "<<x<<' '<<y<<'\n';
	// for (auto t:V[x])cout<<t<<' ';cout<<'\n';
	// for (auto t:V[y])cout<<t<<' ';cout<<'\n';
	if (SZ(V[x]) != SZ(V[y]))return 0;
	for (ll i=0;i<SZ(V[x]);++i)if(V[x][i] != V[y][i]){
		return 0;
	}
	return 1;
}

ll gcd(ll a, ll b){
	if (b==0)return a;
	return gcd(b,a%b);
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	while (T--){
		cin>>N>>M;
		for (ll i=1;i<=N;++i)cin>>A[i];
		for (ll i=1;i<=N;++i)V[i].clear();
		for (ll i=0;i<M;++i){
			cin>>a>>b;
			V[b].pb(a);
		}
		vi tmp;
		for (ll i=1;i<=N;++i){
			if (SZ(V[i]))tmp.pb(i);
			sort(ALL(V[i]));
		}
		ll X = SZ(tmp);
		sort(ALL(tmp), cmp);
		vi store;
		ll curind = 0;
		while (curind < X){
			ll t = curind;
			ll runsum = A[tmp[t]];
			++curind;
			while (curind < X){
				if (is_equal(tmp[t], tmp[curind])){
					runsum += A[tmp[curind]];
					++curind;
				}else break;
			}
			store.pb(runsum);
		}
		sort(ALL(store));
		ll ans = store[0];
		for (ll i=1;i<SZ(store);++i)ans = gcd(store[i], ans);
		cout<<ans<<'\n';
	}
}