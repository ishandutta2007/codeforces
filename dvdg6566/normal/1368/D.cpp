#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define emp emplace
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MAXN = 210000;
const ll MAXK = 17;
const ll INF = 1e18;
const ll MOD = 1e9+7;
ll N,a;
vi V[20];

int main(){
	cin>>N;
	for (int i=1;i<=N;++i){
		cin>>a;
		for (int w=0;w<20;++w){
			if((1<<w)&a)V[w].pb(1);
			else V[w].pb(0);
		}
	}
	for(int i=0;i<20;++i)sort(ALL(V[i]));
	ll ans=0;
	for (int i=0;i<N;++i){
		ll r=0;
		for (int w=0;w<20;++w){
			if(V[w][i])r+=(1<<w);
		}
		ans+=r*r;
	}
	cout<<ans;
}