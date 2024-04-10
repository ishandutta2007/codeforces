#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
int const MM = 1e5+5;

int t, n, k;
ll a[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		ll ans = LLONG_MIN;
		cin>>n>>k;
		for(int i = 1; i <= n; i++){
			cin>>a[i];
			for(int j = i-1; j > max(0, i-805); j--){
				ans = max(ans, (ll)i*j - k*(a[i]|a[j]));
			}
		}
		cout<<ans<<'\n';
	}	
}