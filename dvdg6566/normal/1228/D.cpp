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
#define MAXN 110000
#define MAXL 18

int nxt[MAXN];
vi V[MAXN];
int N,E,a,b;
int ans[MAXN];
vpi EL;

void dfs(int x, int v){
	if(ans[x]!=0){
		cout<<-1;
		exit(0);
	}
	ans[x] = v;
	if(nxt[x] == 0)return;
	dfs(nxt[x], v);
}

int main(){
	cin>>N>>E;
	for (int i=0;i<E;++i){
		cin>>a>>b;V[a].pb(b);V[b].pb(a);EL.pb(a,b);
	}
	for (int i=1;i<=N;++i){
		sort(ALL(V[i]));
		V[i].pb(MAXN);
	}
	for (int i=1;i<N;++i){
		auto t = lb(ALL(V[i]), i);
		int c = i+1;
		while (t != V[i].end() && c == *t){
			++c;
			++t;
		}
		if (c > N)continue;
		nxt[i] = c;
	}
	// for (int i=1;i<=N;++i)cout<<nxt[i]<<' ';cout<<'\n';
	int c=0;
	for (int i=1;i<=N;++i)if(nxt[i]==0)++c;
	if(c!=3){
		cout<<-1;
		return 0;
	}
	int t = 1;
	for (int i=1;i<=N;++i){
		if(ans[i]!=0)continue;
		dfs(i, t);
		++t;
	}
	vi V;
	for (int i=1;i<=3;++i){
		ll c=0;
		for (int j=1;j<=N;++j){
			if(ans[j] == i)++c;
		}
		V.pb(c);
	}
	ll rep = V[0]*V[1] + V[1]*V[2] + V[2]*V[0];
	if(rep != E){
		cout<<-1;
		return 0;
	}
	for (auto i : EL){
		if (ans[i.f] == ans[i.s]){cout<<-1;return 0;}
	}
	for (int i=1;i<=N;++i)cout<<ans[i]<<' ';
}