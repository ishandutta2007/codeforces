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
#define MAXN 1000100

ll N,a,b,c,d,e,f,x,y,E;
ll A[MAXN];
ll B[MAXN];
ll MOD =1e9+7;
ll ans,cnt,sub;
string S;
ll P[MAXN];
vi primes;

int main(){
	cin>>N;
	for (int i=2;i<MAXN;++i){
		if (P[i] == 1)continue;
		if (N%i == 0){
			ll t = 1;
			while (N%i == 0){
				// cerr<<N<<' '<<i<<'\n';
				t *= i;
				N /= i;
			}
			primes.pb(t);
		}
		for (int j=i*i;j<MAXN;j+=i)P[i] = 1;
	}	
	if (N)primes.pb(N);
	ll tmax = 1000000000000000LL;
	pi out=mp(1,1);
	for (int i=0;i<(1<<(SZ(primes)));++i){
		ll l = 1;
		ll r = 1;
		for (int j=0;j<SZ(primes); ++j){
			if (i&(1<<j))l *= primes[j];
			else r *= primes[j];
		}
		// cout<<l<<' '<<r<<'\n';
		if (max(l,r) < tmax){
			tmax = max(l,r);
			out = mp(l,r);
		}
	}
	cout<<out.f<<' '<<out.s;
}