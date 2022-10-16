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

int t, n, a[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		cin>>n;
		int lo = 1e9, hi = 0;
		for(int i = 0; i < n; i++){
			cin>>a[i];
			if(i and a[i] == a[i-1]){
				lo = min(lo, i);
				hi = max(hi, i);
			}
		}
		int ans = max(0, hi-lo);
		if(ans > 1) ans--;
		cout<<ans<<'\n';
	}
}