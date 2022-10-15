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
#define MAXN 310000
#define INF 1e9
#define MAXL 20

vector<pair<pi,pi> > V;

bool cmp(int a, int b){
	if (V[a].f.f != V[b].f.f)return V[a].f.f < V[b].f.f;
	if (V[a].f.s != V[b].f.s)return V[a].f.s < V[b].f.s;
	return V[a].s.f < V[b].s.f;
}

int N,a,b,c;
vi T,T2;
int done[MAXN];

int main(){
	cin>>N;
	for (int i=0;i<N;++i){
		cin>>a>>b>>c;
		V.pb(mp(mp(a,b), mp(c,i)));
		T.pb(i);
	}
	sort(ALL(T), cmp);
	for (int i=0;i<N;++i){
		int t = T[i];
		if (done[t])continue;
		if (i+1 == SZ(T))continue;
		int nxtind = T[i+1];
		if (V[t].f.f == V[nxtind].f.f && V[t].f.s == V[nxtind].f.s){
			cout<<t+1<<' '<<nxtind+1<<'\n';
			done[t] = done[nxtind] = 1;
		}
	}
	swap(T,T2);
	T.clear();
	for (auto i : T2)if (!done[i])T.pb(i);
	T2.clear();

	for (int i=0;i<SZ(T);++i){
		int t = T[i];
		if (done[t])continue;
		if (i+1 == SZ(T))continue;
		int nxtind = T[i+1];
		if (V[t].f.f == V[nxtind].f.f){
			cout<<t+1<<' '<<nxtind+1<<'\n';
			done[t] = done[nxtind] = 1;
		}
	}
	swap(T,T2);
	T.clear();
	for (auto i : T2)if (!done[i])T.pb(i);
	T2.clear();

	for (int i=0;i<SZ(T);++i){
		int t = T[i];
		if (done[t])continue;
		if (i+1 == SZ(T))continue;
		int nxtind = T[i+1];
		cout<<t+1<<' '<<nxtind+1<<'\n';
		done[t] = done[nxtind] = 1;
	}
}