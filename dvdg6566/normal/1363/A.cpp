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
const ll MAXN = 1010;
const ll MAXK = 17;
const ll INF = 1e18;
const ll MOD = 1e9+7;

string S;

int main(){
	ll N,T,K,a;
	cin>>T;
	while(T--){
		cin>>N>>K;
		ll z=0;
		ll o=0;
		for (int i=1;i<=N;++i){
			cin>>a;
			if(a%2)++o;
			else ++z;
		}
		bool can=0;
		for (int w=1;w<=N;w+=2){
			if(w>o||w>K)continue;
			if(z+w<K)continue;
			can=1;
		}
		if(can)cout<<"Yes\n";
		else cout<<"No\n";
	}
}