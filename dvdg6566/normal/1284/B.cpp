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
#define All(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
#define MAXN 1001010

ll N,E,Q,a,b,c,d,cnt,ans,res;
ll A[MAXN], B[MAXN];
vpi V;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for (int i=0;i<N;++i){
		cin>>E;
		b=1;
		for (int j=0;j<E;++j)cin>>A[j];
		for (int j=1;j<E;++j){
			if (A[j-1] < A[j])b=0;
		}
		if (b == 0)continue;
		V.pb(A[0], A[E-1]);
	}
	// for (auto i : V)cout<<i.f<<' '<<i.s<<'\n';
	for (auto i : V)B[i.f]++;
	ll ans = 0;
	for (int i=1;i<MAXN;++i)B[i] += B[i-1];
	for (auto i : V)ans += B[i.s];
	cout<<N*N-ans;
}