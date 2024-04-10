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
#define SZ(x) (ll)x.size()
#define MAXN 210000
#define INF 1e9
#define MAXL 20

vector<pair<pi,pi>> V;
ll N,a,b,c;
vector<pair<ll, pi>> E;
ll done[MAXN];

int main(){
	cin>>N;
	for (ll i=1;i<=N;++i){
		cin>>a>>b>>c;
		V.pb(mp(a,b),mp(c,i));
	}
	for (ll i=0;i<N;++i){
		for (ll j=0;j<N;++j){
			ll d = abs(V[i].f.f - V[j].f.f)*abs(V[i].f.f - V[j].f.f) + abs(V[i].f.s - V[j].f.s)*abs(V[i].f.s - V[j].f.s) + abs(V[i].s.f - V[j].s.f)*abs(V[i].s.f - V[j].s.f);
			E.pb(d,mp(i,j));
		}
	}
	sort(ALL(E));
	for (auto i : E){
		ll a = i.s.f;
		ll b = i.s.s;
		if (a==b)continue;
		if (done[a] || done[b])continue;
		cout<<a+1<<' '<<b+1<<'\n';
		done[a] = 1;
		done[b] = 1;
	}
}