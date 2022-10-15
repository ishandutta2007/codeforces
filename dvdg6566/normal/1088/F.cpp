#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end() 
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MAXN=500100;
const ll MAXK=20;
const ll INF = 1e13;
const ll MOD = 1e9+7;

vi V[MAXN];
ll A[MAXN],N,a,b;
vi ord;
ll ans;
ll p[MAXN][MAXK];
ll d[MAXN][MAXK];

void dfs(ll x,ll pa){
	p[x][0]=pa;
	ord.pb(x);
	if(pa!=-1){
		assert(A[x]>A[pa]);
		d[x][0]=A[pa];
	}
	for(auto v:V[x])if(v!=pa)dfs(v,x);
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N;
	for(ll i=1;i<=N;++i)cin>>A[i];
	for(ll i=1;i<N;++i){
		cin>>a>>b;V[a].pb(b);V[b].pb(a);
	}
	ll rt=min_element(A+1,A+N+1)-A;
	memset(p,-1,sizeof(p));
	dfs(rt,-1);
	for(ll i=1;i<MAXK;++i)for(ll j=1;j<=N;++j){
		if(p[j][i-1]!=-1){
			ll x=p[j][i-1];
			p[j][i]=p[x][i-1];
			d[j][i]=d[x][i-1];
		}
	}
	for(auto n:ord)if(n!=rt){
		ll opt=1e9;
		// cerr<<"Inserting node "<<n<<'\n';
		for(ll i=0;i<N;++i){
			if(p[n][i]==-1){
				// must check root in case of leftover
				opt=min(opt, (i+1)*A[rt]);
				break;
			}
			opt=min(opt, (i+1)*d[n][i]);
		}
		opt+=A[n];
		// cerr<<"Optimal "<<opt<<'\n';
		ans+=opt;
	}
	cout<<ans;

}