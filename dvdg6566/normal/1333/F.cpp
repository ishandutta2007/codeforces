#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define lb lower_bound
#define ub upper_bound
const ll MAXN=501000;
const int INF=1e9;
// segment tree over prefix ranges
vi fact[MAXN];
vi tmp;
vpi V;
vpi cur;
int ans;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	for(int i=2;i<MAXN;++i)if(!SZ(fact[i])){
		for(int j=i;j<MAXN;j+=i)fact[j].pb(i);
	}
	
	int N;cin>>N;
	for(int i=2;i<=N;++i){
		// int bp=fact[i].back();
		
		int r=i;
		V.pb(i/fact[i][0],i);
		// if(SZ(fact[i]) == 1){
		// 	V.pb(i/fact[i][0],i);
		// 	continue;
		// }
		// int lm=0;
		// for(auto k:fact[i]){
		// 	int occ=0;
		// 	while(r%k==0){++occ;r/=k;}
		// 	int w=1;
		// 	for(int i=0;i<occ;++i)w*=k;
		// 	lm=max(lm,w);
		// }
		// cerr<<i<<' '<<lm<<'\n';
		// V.pb(lm,i);
		// cerr<<i<<' '<<V.back().f<<'\n';
	}
	sort(ALL(V));
	// for(auto i:V)cerr<<i.f<<' ';cerr<<'\n';
	for(int i=0;i<N-1;++i)cout<<V[i].f<<' ';
}