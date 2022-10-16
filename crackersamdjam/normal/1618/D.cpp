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
int const MM = 2e5+5;

int t, n, k;
int a[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i = 0; i < n; i++){
			cin>>a[i];
		}
		sort(a, a+n, greater<>());
		ll ans = 0;
		for(int i = 0; i < k; i++){
			ans += a[i+k]/a[i];
		}
		for(int i = 2*k; i < n; i++){
			ans += a[i];
		}
		cout<<ans<<'\n';
	}
}