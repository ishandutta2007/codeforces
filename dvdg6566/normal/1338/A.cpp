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
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MAXN = 500100;
const ll INF = 1e18;
const ll MOD = 1e9+7;

ll N,a,b,c,d,T,A[MAXN];
ll sum,ans;
ll B[MAXN];
vi V;


int main(){
	cin>>T;
	while(T--){
		cin>>N;
		for (int i=1;i<=N;++i)cin>>A[i];
		B[1] = A[1];
		ll ans = 0;
		for (int j=2;j<=N;++j){
			B[j]=max(A[j],B[j-1]);
			ans = max(ans, B[j] - A[j]);
		}
		ll p = 0;
		while (ans){
			ans /= 2;
			++p;
		}
		cout<<p<<'\n';
	}
}