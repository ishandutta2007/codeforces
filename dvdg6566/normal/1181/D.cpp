#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
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
#define MAXN 500100
ll INF =1e18;

ll N,M,Q,a,b;
vpi query;
ll out[MAXN];
ll A[MAXN];
vi V[MAXN];

struct node{
	ll s,e,m,v;
	node *l,*r;
	node (ll _s,ll _e):s(_s), e(_e){
		m=(s+e)/2;
		v=0;
		if (s!=e){
			l=new node(s,m);r=new node(m+1,e);
		}
	}
	void update(ll x){
		if (s == e){
			++v;
			return;
		}
		if (x <= m)l->update(x);
		else r->update(x);
		++v;
	}
	ll query(ll x){
		if (s == e)return s;
		if (l->v >= x)return l->query(x);
		else return r->query(x-l->v);
	}
}*root;

int main(){
	// freopen("in.txt","r",stdin);
	cin>>N>>M>>Q;
	for (ll i=0;i<N;++i){
		cin>>a;
		A[a]++;
	}
	for (ll i=1;i<=M;++i){
		V[A[i]].pb(i);
	}
	for (ll i=0;i<Q;++i){
		cin>>a;
		query.pb(mp(a-N,i));
	}
	sort(ALL(query));
	root =new node(0,M+1);

	ll tot=0;
	ll curlen = 0;
	ll ind=-1;
	query.pb(mp(INF,INF));

	for(ll i=0;i<MAXN;++i){
		curlen += SZ(V[i]);
		for (auto v: V[i]){
			root->update(v);
		}
		ll p=tot;
		tot += curlen;
		// cout<<p<<' '<<tot<<'\n';
		while (query[ind+1].f <= tot){
			ll x = query[ind+1].s;
			ll r = query[ind+1].f -p;
			out[x] = root->query(r);
			++ind;
		}
	}
	++ind;
	while (ind < Q){
		out[query[ind].s] = (query[ind].f-tot)%curlen;
		if (out[query[ind].s] ==0)out[query[ind].s]=M;
		++ind;
	}

	for (ll i=0;i<Q;++i)cout<<out[i]<<'\n';
}