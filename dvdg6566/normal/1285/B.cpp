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
#define MAXN 1000100

ll N,a,b,c,d,e,f,x,y,E;
ll A[MAXN];
ll B[MAXN];
ll MOD =1e9+7;
ll ans,cnt,sub;
string S;

int main(){
	cin>>E;
	while(E--){
		cin>>N;
		x = -LONG_LONG_MAX;
		for (int i=1;i<=N;++i)cin>>A[i], B[i] = A[i] + B[i-1];
		ll t = B[N];
		ll min_val = 1000000000000000LL;
		for (int i=1;i<=N;++i){
			ll cur = B[i];
			x = max(x, cur-min_val);
			min_val = min(min_val, cur);
			if (i!=N)x = max(x, cur);
		}
		if (t > x){
			cout<<"YES\n";
		}else cout<<"NO\n";
	}
}