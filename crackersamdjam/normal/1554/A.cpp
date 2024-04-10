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

int t, n;
ll a[100005];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		cin>>n;
		ll ans = LLONG_MIN;
		for(int i = 0; i < n; i++){
			cin>>a[i];
			if(i){
				ans = max(ans, a[i]*a[i-1]);
			}
		}
		cout<<ans<<'\n';
	}
}