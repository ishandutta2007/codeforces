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

int t, n, a[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 0; i < n; i++){
			cin>>a[i];
		}
		a[n] = 0;
		ll ans = 0, mx = *max_element(a, a+n);
		for(int i = 1; i <= n; i++){
			if(a[i] < a[i-1]){
				ans += a[i-1]-a[i];
			}
		}
		if(ans <= mx){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
}