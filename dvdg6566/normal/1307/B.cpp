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
#define MAXN 100100

ll A[MAXN],B[MAXN];
ll a,b,c,d,N,E,T,Q;
vi V;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>N>>E;
		V.clear();
		for (ll i=1;i<=N;++i){
			cin>>a;
			V.pb(a);
		}
		sort(ALL(V));
		int ones = 0;
		for (auto i:V)if (i == E)ones = 1;
		if (ones){cout<<"1\n";continue;}
		else{
			ll t = V.back();
			cout<<max(2LL, (E+t-1)/t)<<'\n';
		}
	}
}