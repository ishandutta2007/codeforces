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
#define MAXN 201010

ll BSIZ = 450;
ll A[MAXN];
ll S[MAXN];
string st;
ll N;
ll ans;

ll B[MAXN];
pi L[MAXN];
int U[90000000];

main(){
	cin>>st;
	N = SZ(st);
	for (ll i=1;i<=N;++i)if(st[i-1] == '1')++A[i];
	for (ll i=1;i<=BSIZ;++i){
		// if(i%100==0)cerr<<"A "<<i<<'\n';
		U[N] = 1;
		for (ll j=1;j<=N;++j){
			if (A[j])B[j] = i*A[j]-1;
			else B[j] = -1;
			B[j] += B[j-1];
			// cout<<B[j]<<' ';
			ans += U[N+B[j]];
			++U[N+B[j]];
		}
		for (ll j=1;j<=N;++j)--U[N+B[j]];
		// cout<<'\n';
	}
	vi V;
	for (ll i=1;i<=N;++i)if(A[i]){
		V.pb(i);
		ll t = i-1;
		while (t && A[t] == 0)--t;
		L[i].f = i-t-1;
		t = i+1;
		while (t <= N && A[t] == 0)++t;
		L[i].s = t-1-i;
		// cout<<i<<' '<<L[i].f<<' '<<L[i].s<<'\n';
	}
	// BSIZ = 2;
	// cout<<C(9,2);
	// return 0;
	for (ll sum=1;sum<=SZ(V) && sum*BSIZ <= N;++sum){
		if(sum%100==0)cerr<<"B "<<sum<<'\n';
		// cout<<"Sum "<<sum<<'\n';
		ll right=V[0];
		ll l = 2;
		for (auto left:V){
			--l;
			while(l < sum){
				if (right == V.back())break;
				++l;
				right = right + L[right].s + 1;
				// cout<<"Slide right to "<<right<<'\n';
			}
			if (l<sum)break;
			// cout<<left<<' '<<right<<'\n';
			ll leftstop = left-L[left].f;
			ll rightstop = right+L[right].s;
			for (ll leftpt = leftstop; leftpt<=left;++leftpt){
				// cout<<"Left poller "<<leftpt<<'\n';
				ll minlen = right - leftpt + 1;
				ll maxlen = rightstop - leftpt + 1;
				// cout<<minlen<<' '<<maxlen<<'\n';
				ll t = maxlen/sum - max(BSIZ, (minlen-1)/sum);
				if(t>0)ans += t;
			}
			// cout<<ans<<'\n';
		}
		// cout<<ans<<'\n';
		// return 0;
	}
	cout<<ans;
}