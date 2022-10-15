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
#define MAXN 401010

ll A[MAXN];
ll N,ans;
vi V;
vi O;

int main(){
	cin>>N;
	for (ll i=1;i<=N;++i){
		cin>>A[i];
	}
	for (ll bit=0;bit<=25;++bit){
		// if (bit!=1)continue;
		V.clear();
		O.clear();
		ll tmp=0;
		for (ll i=1;i<=N;++i){
			V.pb(A[i]%(1<<bit));
			O.pb(A[i]%(1<<bit));
			tmp += ((A[i]&(1<<bit)) > 0)*(N-1);
		}
		sort(ALL(V));
		ll ind = N;
		ll x = 0;
		for (auto i : V){
			if (i*2 >= (1<<bit))--x;
			while (ind > 0){
				if (V[ind-1] + i >= (1<<bit)) -- ind;
				else break;
			}
			// cout<<i<<' '<<ind<<'\n';
			x = x + (N-ind);
		}
		tmp += x/2;
		ans += (tmp%2)*(1LL<<bit);
		// return 0;
	}
	// for (ll i=1;i<=N;++i)ans = ans^(2*A[i]);
	// ll t = 0;
	// for (int i=1;i<=N;++i)for (int j=i+1;j<=N;++j)t = t^(A[i]+A[j]);
	cout<<ans;
}