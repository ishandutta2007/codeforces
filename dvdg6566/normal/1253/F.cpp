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
const ll MAXN=100100;
const ll MAXK=17;
const ll INF = 1e9;
const ll MOD = 1e9+7;

ll N,M,K,Q,R,C,T,a,b,c,OX;
ll depth[MAXN];
vpi V[MAXN];
ll d[MAXN];
ll h[MAXN];
vpi V2[MAXN];
priority_queue<pi,vpi,greater<pi>> pq;
typedef pair<ll,pi> pip;
vector<pip> E;
ll p[MAXN];
ll par(ll x){return(p[x]==x)?x:p[x]=par(p[x]);}
ll pp[MAXN][MAXK];
ll dd[MAXN][MAXK];

void dfs(ll x,ll pa){
	if(pa!=-1)depth[x]=depth[pa]+1;
	// cout<<x<<' '<<dd[x][0]<<'\n';
	pp[x][0]=pa;
	for(ll i=1;i<MAXK;++i){
		if(pp[x][i-1]!=-1){
			ll y=pp[x][i-1];
			pp[x][i]=pp[y][i-1];
			dd[x][i]=max(dd[x][i-1], dd[y][i-1]);
		}
	}
	for(auto v:V2[x])if(v.f!=pa){dd[v.f][0]=v.s;dfs(v.f,x);}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>M>>K>>Q;
	for(ll i=0;i<M;++i){
		cin>>a>>b>>c;V[a].pb(b,c);V[b].pb(a,c);
	}
	memset(d,-1,sizeof(d));
	for(ll i=1;i<=K;++i){
		pq.emplace(0,i);d[i]=0;
		h[i]=i;
	}
	while(SZ(pq)){
		pi t=pq.top();pq.pop();
		ll n=t.s;ll cd=t.f;
		// cout<<n<<' '<<cd<<'\n';
		if(d[n]<cd)continue;
		for(auto t:V[n]){
			ll vn=t.f;
			ll vd=t.s+cd;
			if(d[vn]==-1){
				d[vn]=vd;
				pq.emplace(vd,vn);
				h[vn]=h[n];
				continue;
			}
			if(h[vn]!=h[n]){
				ll cd=d[n]+d[vn]+t.s;
				E.pb(cd,mp(h[n],h[vn]));
			}
			if(d[vn]>vd){
				d[vn]=vd;
				pq.emplace(vd,vn);
				h[vn]=h[n];
			}
		}
	}
	memset(pp,-1,sizeof(pp));
	for(ll i=1;i<=N;++i)p[i]=i;
	sort(ALL(E));
	for(auto t:E){
		a=t.s.f;
		b=t.s.s;
		ll w=t.f;
		if(par(a)==par(b))continue;
		a=par(a);b=par(b);
		p[a]=b;
		cerr<<a<<' '<<b<<' '<<w<<'\n';
		V2[a].pb(b,w);
		V2[b].pb(a,w);
	}
	dfs(1,-1);
	while(Q--){
		cin>>a>>b;
		ll res=0;
		if(depth[a]<depth[b])swap(a,b);
		ll h=depth[a]-depth[b];
		for(ll i=0;i<MAXK;++i)if((1<<i)&h){
			res=max(res,dd[a][i]);
			a=pp[a][i];
		}
		assert(depth[a]==depth[b]);
		if(a!=b){
			for(ll i=MAXK-1;i>=0;--i){
				if(pp[a][i]!=pp[b][i]){
					res=max({res,dd[a][i],dd[b][i]});
					a=pp[a][i];
					b=pp[b][i];
				}
			}
			assert(a!=b);
			assert(pp[a][0]==pp[b][0]);
			res=max({res,dd[a][0],dd[b][0]});
		}
		cout<<res<<'\n';
	}
}