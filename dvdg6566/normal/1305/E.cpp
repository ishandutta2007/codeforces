#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MAXN = 1010;

vi out;
ll N;
ll tot;

int main(){
	cin>>N>>tot;
	if (N == 1){
		if (tot==0)cout<<1;
		else cout<<-1;
		return 0;
	}
	out.pb(1);
	out.pb(2);
	while (tot > 0){
		if (SZ(out) == N){
			cout<<"-1";
			return 0;
		}
		ll can_get = SZ(out)/2;
		if (can_get > tot)break;
		else{
			out.pb(out.back() + 1);
			tot -= can_get;
		}
	}

	if (tot > 0){
		ll desired_length = SZ(out) - 2*tot;
		out.pb(out[desired_length]+out.back());
	}

	ll mult = out.back()+1;
	ll useless = N+1;

	while (SZ(out) < N){
		out.pb(useless*mult);
		++useless;
	}
	assert(SZ(out)==N);
	for (auto i : out){
		assert(i<=1e9);
		cout<<i<<' ';
	}
	cout<<'\n';
}