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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> v;
		vector<int> t[2];
		for(int i = 0; i < n; i++){
			int a;
			cin>>a;
			t[i%2].emplace_back(i);
			if(a%2){
				v.emplace_back(i);
			}
		}
		ll ans = LLONG_MAX;
		for(int i = 0; i < 2; i++){
			if(size(v) == size(t[i])){
				ll cur = 0;
				for(int j = 0; j < size(v); j++){
					cur += abs(v[j]-t[i][j]);
				}
				ans = min(ans, cur);
			}
		}
		if(ans == LLONG_MAX)
			ans = -1;
		cout<<ans<<'\n';
	}
}