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
#define MAXL 18
ll INF = 1e12;

vi V[MAXN];
int topoord[MAXN];
vi topo;
int N,E,a,b;
vpi EL;
int vis[MAXN];

void dfs(int x){
	vis[x] = 1;
	for (auto v : V[x])if(!vis[v]){
		vis[v] = 1;
		dfs(v);
	}
	topo.pb(x);
}

int main(){
	cin>>N>>E;
	for (int i=0;i<E;++i){
		cin>>a>>b;
		V[a].pb(b);
		EL.pb(a,b);
	}
	memset(topoord,-1,sizeof(topoord));

	for (int i=1;i<=N;++i){
		if(!vis[i])dfs(i);
	}
	reverse(ALL(topo));
	
	for (int i=0;i<N;++i){
		topoord[topo[i]] = i;
	}

	int isdag = 1;
	for (auto i : EL){
		if (topoord[i.f] > topoord[i.s])isdag = 0;
	}
	if (isdag){
		cout<<1<<'\n';
		for (int i=0;i<E;++i)cout<<1<<' ';
	}else{
		cout<<2<<'\n';
		for (auto i : EL){
			if (topoord[i.f] > topoord[i.s])cout<<2<<' ';
			else cout<<1<<' ';
		}
	}
}