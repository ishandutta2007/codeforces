#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define MAXN 200100
ll INF = 2e9;
ll MOD = 1e9+7;

ll ans;
vector<pii> A;
vi vals;
ll N,K,a;

struct SparseTable{
	ll N,K;
	vector<vi> ST;

	SparseTable(ll _N): N(_N){
		K=MSB(N);
		ST.resize(K);
		ST[0]=vals;
		for (ll k=1;k<K;++k){
			for (ll i=0;i+(1<<k)<=N;++i){
				ST[k].pb(max(ST[k-1][i], ST[k-1][i+(1<<(k-1))]));
			}
		}
	}

	inline int MSB(unsigned int x){return 32-__builtin_clz(x);}

	ll query(ll x, ll y){
		ll k=MSB(y-x+1)-1;
		return max(ST[k][x],ST[k][y-(1<<k)+1]);
	}
}*S;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
	// freopen("in.txt","r",stdin);
	cin>>N>>K;
	vals.pb(INF);
	A.pb(mp(INF,mp(0,0)));
	for (ll i=1;i<=N;++i){
		cin>>a;
		vals.pb(a);
		if (SZ(A) && A.back().f == a){
			++A.back().s.s;
		}else {
			A.pb(mp(a,mp(i,i)));
		}
	}
	A.pb(mp(INF,mp(N+1,N+1)));
	vals.pb(INF);
	S = new SparseTable(SZ(vals));
	ll p = K-1;
	ll ans=0;
	// for (auto i : A)cout<<i.f<<' '<<i.s<<'\n';
	for (ll i=1;i<SZ(A)-1;++i){
		// if (A[i].f!=11)continue;
		// cout<<A[i].f<<'\n';
		ll lb = 1;
		ll ub = A[i].s.f;
		while (ub > lb){
			ll mid = (lb+ub)/2;
			ll t = S->query(mid, A[i].s.f-1);
			if (t > A[i].f)lb = mid+1;
			else ub = mid;
		}
		ll start = lb;
		lb = A[i].s.s;
		ub = N;
		while (ub > lb){
			ll mid = (lb+ub+1)/2;
			ll t = S->query(A[i].s.s+1, mid);
			if (t >= A[i].f)ub = mid-1;
			else lb = mid;
		}
		ll stop = lb;
		ll leftlen = A[i].s.f - start;
		ll rightlen = stop - A[i].s.s;
		// cout<<leftlen<<' '<<rightlen<<'\n';
		ll len = A[i].s.s - A[i].s.f + 1;
		// cout<<start<<' '<<stop<<'\n';
		// cout<<leftlen<<' '<<len<<' '<<rightlen<<'\n';
		ll rep = (leftlen+rightlen+len+p-1)/(p);
		// cout<<"R "<<rep<<' '<<(rep-1)*len<<'\n';
		// cout<<leftlen+rightlen+len-2<<' '<<rep<<'\n';
		ll L = (rep-1)*len+p*(rep)*(rep-1)/2;
		// cout<<L<<'\n';

		ll timeleft = rep - (leftlen+p-1) / p;
		ll leftover = (p - leftlen%p) % p;
		// cout<<"L "<<timeleft<<' '<<leftover<<'\n';

		ll l = (leftover) * timeleft + p * (timeleft)*(timeleft-1)/2;
		// cout<<l<<'\n';
		L -= l;

		timeleft = rep - (rightlen+p-1) / p;
		leftover = (p - rightlen%p) % p;
		// cout<<"R "<<timeleft<<' '<<leftover<<'\n';

		l = (leftover) * timeleft + p * (timeleft)*(timeleft-1)/2;
		// cout<<l<<'\n';
		L -= l;

		// cout<<L*A[i].f<<'\n';
		ans += ((L%MOD)*(A[i].f%MOD))%MOD;
	}
	cout<<ans%MOD<<'\n';
}