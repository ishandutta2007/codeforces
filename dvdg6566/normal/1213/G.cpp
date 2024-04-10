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
#define MAXN 210000
#define MAXL 18

ll p[MAXN], sz[MAXN];

ll par(ll x){return (x==p[x]) ? x : p[x] = par(p[x]);}

vi des;

struct edge{
	ll a,b,w;
};

vector<edge> EL;

ll N,E,a,b,w;

bool cmp(edge a, edge b){
	return a.w < b.w;
}

ll out[MAXN];

int main(){
	cin>>N>>E;
	EL.resize(N-1);
	for (ll i=0;i<N-1;++i){
		cin>>EL[i].a>>EL[i].b>>EL[i].w;
		des.pb(EL[i].w);
	}
	vi Q;
	for (ll i=0;i<E;++i){
		cin>>a;
		des.pb(a);
		Q.pb(a);
	}
	sort(ALL(des));
	des.resize(unique(ALL(des)) - des.begin());
	for (auto &&i:EL){
		i.w = lb(ALL(des), i.w) - des.begin();
	}
	for (auto &&i:Q){
		i = lb(ALL(des), i)  - des.begin();
	}
	sort(ALL(EL), cmp);
	for (ll i=1;i<=N;++i)p[i]=i,sz[i] = 1;
	for (auto i : EL){
		ll a = par(i.a);
		ll b = par(i.b);
		out[i.w] += sz[a] * sz[b];
		ll t = sz[a] + sz[b];
		p[a] = b;
		sz[a] = sz[b] = t;
	}
	for (ll i=1;i<SZ(des);++i)out[i] +=out[i-1];
	for (auto i : Q)cout<<out[i]<<' ';
}