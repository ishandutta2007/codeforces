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
#define SZ(x) (int)x.size()
#define f first
#define s second
#define MAXN 200010

ll N,Q,T,a,b,c,d,e;
ll A[MAXN];
ll B[31];
vpi V;

int main(){
	cin>>N;
	for (int i=1;i<=N;++i)cin>>A[i];
	for (int i=1;i<=N;++i){
		for (int j=0;j<31;++j)if (A[i] & (1LL<<j)){
			B[j]++;
		}
	}
	for (int i=1;i<=N;++i){
		ll t = 0;
		for (int j=0;j<31;++j)if (A[i] & (1LL<<j)){
			if (B[j] == 1)t += (1LL<<j);
		}
		// cout<<t<<' '<<i<<'\n';
		V.pb(mp(t,i));
	}
	sort(ALL(V));reverse(ALL(V));
	for (auto i:V)cout<<A[i.s]<<' ';
}