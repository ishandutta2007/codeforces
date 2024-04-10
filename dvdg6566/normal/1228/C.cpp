#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define MAXN 210000
#define MAXL 18
ll MOD = 1e9+7;
vi P;
ll X,N;

ll exp(ll a, ll b){
	if(b==0)return 1;
	ll h = exp(a,b/2);
	h = (h*h)%MOD;
	if(b%2)return (a*h)%MOD;
	return h;
}

int main(){
	cin>>X>>N;
	for (int i=2;i*i<=X;++i){
		if(X%i==0)P.pb(i);
		while(X%i==0){
			X /= i;
		}
	}
	if(X>1)P.pb(X);
	ll ans = 1;
	for (auto i : P){
		ll R = N;
		ll c=0;
		while(R){
			c += R/i;
			R = R/i;
		}
		ans = ans * exp(i, c) % MOD;
	}
	cout<<ans;
}