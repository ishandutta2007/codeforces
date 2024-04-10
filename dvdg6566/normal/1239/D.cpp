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
#define MAXN 1010000
#define INF 1e9
#define MAXL 20

vi cur;
vi V[MAXN], G[MAXN];
int N,E,a,b,T;
int vis[MAXN];

void dfs(int x){
	for (auto v:V[x])if(!vis[v]){
		vis[v] = 1;
		cur.pb(v);
		dfs(v);
	}
}

void dfs2(int x){
	for (auto v:G[x])if(!vis[v]){
		vis[v] = 1;
		cur.pb(v);
		dfs2(v);
	}
}


int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>N>>E;
		for (int i=1;i<=N;++i)V[i].clear();
		for (int i=1;i<=N;++i)G[i].clear();
		for (int i=1;i<=N;++i)vis[i] = 0;
		cur.clear();
		for (int i=0;i<E;++i){
			cin>>a>>b;
			V[a].pb(b);
			G[b].pb(a);
		}
		vis[1] = 1;
		cur.pb(1);
		dfs(1);
		if (SZ(cur) == N){
			for (int i=1;i<=N;++i)vis[i] = 0;
			cur.clear();
			cur.pb(1);
			vis[1]=1;	
			dfs2(1);
			if(SZ(cur) == N){
				cout<<"No\n";
				continue;
			}
			cout<<"Yes\n";
			cout<<N-SZ(cur)<<' '<<SZ(cur)<<'\n';
			for (int i=1;i<=N;++i)if(!vis[i])cout<<i<<' ';cout<<'\n';
			for (auto i : cur)cout<<i<<' ';cout<<'\n';
		}else{
			cout<<"Yes\n";
			cout<<SZ(cur)<<' '<<N-SZ(cur)<<'\n';
			for (auto i : cur)cout<<i<<' ';cout<<'\n';
			for (int i=1;i<=N;++i)if(!vis[i])cout<<i<<' ';cout<<'\n';
		}
	}
}