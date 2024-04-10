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
#define SZ(x) (int)x.size()
#define MAXN 5000000
#define MAXL 22

ll N,M,K;
ll G[MAXL][MAXL];
int PLEN;
vi V[MAXL][MAXL];

int main(){
	cin>>N>>M>>K;
	if(N==1&&M==1){
		cin>>G[0][0];
		if (G[0][0] == K)cout<<1;
		else cout<<0;
		return 0;
	}
	for (int i=0;i<N;++i)for (int j=0;j<M;++j)cin>>G[i][j];
	PLEN = N+M-2;
	int FHALF = (PLEN+1)/2;
	int SHALF = PLEN/2;
	assert(SHALF + FHALF == PLEN);
	int L = (1<<FHALF)-1;
	// cout<<FHALF<<' '<<SHALF<<'\n';
	for (int i=0;i<=L;++i){
		pi c = mp(0,0);
		ll v = G[0][0];
		for (int k=0;k<FHALF;++k){
			if ((1<<k) & i){
				++c.f;
			}else ++c.s;
			if (c.f >= N || c.s >= M)break;
			if (k+1 != FHALF)v^=G[c.f][c.s];
		}
		if (c.f >= N || c.s >= M)continue;
		V[c.f][c.s].pb(v);
	}
	for (int i=0;i<N;++i)for (int j=0;j<M;++j){
		if (SZ(V[i][j]) == 0)continue;
		sort(ALL(V[i][j]));
		// cout<<"At "<<i<<' '<<j<<' '<<SZ(V[i][j])<<'\n';
		// for (auto x : V[i][j])cout<<x<<' ';
		// cout<<'\n';
	}
	ll ans = 0;
	L =(1<<SHALF)-1;
	for (int i=0;i<=L;++i){
		pi c = mp(N-1,M-1);
		ll v = G[N-1][M-1];
		for (int k=0;k<SHALF;++k){
			if ((1<<k) & i){
				--c.f;
			}else --c.s;
			if (c.f < 0||c.s < 0)break;
			v^=G[c.f][c.s];
		}
		if (c.f < 0||c.s < 0)continue;;
		ll req = K ^ v;
		// cout<<"At "<<c.f<<' '<<c.s<<" want "<<req<<'\n';
		ll rep = ub(ALL(V[c.f][c.s]), req) - lb(ALL(V[c.f][c.s]), req);
		ans += rep;
	}
	cout<<ans<<'\n';
}