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
const ll MAXN = 100100;
const ll MAXK = 17;
const ll INF = 1e18;
const ll MOD = 1e9+7;

ll N,K,W,T,a,b,c,d,e;


int main(){
	cin>>T;
	while(T--){
		cin>>a>>b>>c;
		d=min(a/c,b);
		e=b-d;
		cout<<d-(e+c-2)/(c-1)<<'\n';
	}	
}