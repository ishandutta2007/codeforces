#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pi;
typedef pair<int,pi> pii;
typedef vector<pi> vpi;
typedef set<int> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e9;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define MAXN 200100
#define MAXL 18

vi V[MAXN];
int on[MAXN], off[MAXN], pon[MAXN];
int N,a,b;

void dfs(int x, int p){
	if (x != 1 && SZ(V[x]) == 1){ // Leaf Node
		off[x]=0;
		pon[x]=1;
		on[x]=1;
		return;
	}
	for (auto v : V[x])if (v != p)dfs(v,x);
	// First we compute PON, which is sum of all children off + 1
	for (auto v : V[x])if (v!=p)pon[x] += min({off[v], on[v], pon[v]});
	pon[x]++;
	
	// off is the sum of on of every child
	for (auto v : V[x])if (v!=p)off[x] += min({on[v], pon[v]});

	// on is the sum of all the children's on, + the smallest change from on to PON

	vi ponchange;
	bool flip=0;

	for (auto v : V[x])if (v!=p){
		if (pon[v] <= on[v]){
			on[x] += pon[v];
			flip = 1;
		}
		else{
			ponchange.pb(pon[v] - on[v]);
			on[x] += on[v];
		}
	}

	if (flip == 0){
		sort(ALL(ponchange));
		on[x] += ponchange[0];
	}
}

int main(){
	// freopen("in.txt","r",stdin);
	cin>>N;
	for (int i=1;i<N;++i){
		cin>>a>>b;
		V[a].pb(b);
		V[b].pb(a);
	}
	int ans=0;
	for (auto v : V[1]){
		for (auto i : V[v]){
			if (i == 1)continue;
			dfs(i, v);
			ans += min({off[i],on[i],pon[i]});
		}
	}
	cout<<ans<<'\n';
	// for (int x=1;x<=N;++x){
	// 	cout<<"Node "<<x<<' '<<off[x]<<' '<<on[x]<<' '<<pon[x]<<'\n';
	// }
}