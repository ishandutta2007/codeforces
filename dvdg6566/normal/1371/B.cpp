#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define f first
#define s second
const int MAXN=500100;
const int MAXK=16;
const int INF = 1e9;
const ll MOD = 1e9+7;

ll N,a,b;
int main(){
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>a>>b;
		ll ans=0;
		if(b>=a)++ans;
		b=min(b,a-1);
		ans+=b*(b+1)/2;
		cout<<ans<<'\n';
	}
}