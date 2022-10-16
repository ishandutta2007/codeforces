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

int t, n, k, a[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i = 1; i <= n; i++){
			cin>>a[i];
		}
		if(k == 1){
			cout<<(n-1)/2<<'\n';
			continue;
		}
		int ans = 0;
		for(int i = 2; i < n; i++){
			if(a[i] > a[i-1]+a[i+1])
				ans++;
		}
		cout<<ans<<'\n';
	}
}