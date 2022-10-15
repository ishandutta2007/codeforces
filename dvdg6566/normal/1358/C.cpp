#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
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
const ll MAXN = 1000100;
const ll MAXB = 128;
const ll INF = 1e18;
const ll MOD = 1e9+7;

ll a,b,c,d,e,f,g,sum,N,M,E,K;

int main(){
	cin>>K;
	while(K--){
		cin>>a>>b>>c>>d;
		cout<<(c-a)*(d-b)+1<<'\n';
	}
}