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
const ll MOD = 998244353;
const ll INF = 1e18;
const ll MAXN = 1e6+10;

// Query (0,l,r,ind);
// Update (1,l,r);
// Sort by L
int N,Q,a,b;
typedef pair<int,pi> pii;
vector<pii> T[MAXN];
int ans[MAXN];
int fw[MAXN];

void up(int x, int v){
	for (;x<MAXN;x+=x&(-x))fw[x]+=v;
}

int query(int x){
	int res=0;
	for (;x;x-=x&(-x))res+=fw[x];
	return res;
}

int main(){
	cin>>N>>Q;
	for (int i=0;i<N;++i){
		cin>>a>>b;
		T[a].pb(mp(1,mp(b,0)));
	}
	for (int i=0;i<Q;++i){
		cin>>a;
		vi tmp;
		tmp.pb(0);
		for (int j=0;j<a;++j){
			cin>>b;
			tmp.pb(b);
		}
		tmp.pb(1e6+1);
		for (int j=0;j<SZ(tmp)-1;++j){
			int l = tmp[j]+1;
			int r = tmp[j+1]-1;
			if (l>r)continue;
			// cout<<"Adding "<<l<<' '<<r<<" to "<<i<<'\n';
			T[l].pb(mp(0, mp(r, i)));
		}
	}
	for (int l=MAXN-5;l>=0;--l){
		for (auto t:T[l]){
			// pii t = T[l].back();T[l].pop_back();
			if (t.f == 1){
				up(t.s.f, 1);
			}else{
				// cout<<l<<' '<<t.s.f<<' '<<query(t.s.f)<<'\n';
				ans[t.s.s] += query(t.s.f);
			}
		}
	}
	for (int i=0;i<Q;++i)cout<<N-ans[i]<<'\n';
}