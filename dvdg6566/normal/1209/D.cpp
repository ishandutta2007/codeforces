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

vi V[MAXN];
int vis[MAXN];
int N,E,a,b,d;

void dfs(int x){
	for (auto v : V[x]){
		++d;
		if(!vis[v]){
			vis[v] = 1;
			dfs(v);
		}
	}
}

int main(){
	cin >> N >>E;
	for (int i=1;i<=E;++i){
		cin>>a>>b;
		V[a].pb(b);
		V[b].pb(a);
	}
	int ans=-N;
	for (int i=1;i<=N;++i)if(!vis[i]){
		d = 0;
		vis[i]=1;
		dfs(i);
		ans += d/2+1;
	}
	cout<<ans;
}