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



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		vector<int> x(n+1), y(n+1);
		for(int i = 0; i < n; i++){
			cin>>x[i]>>y[i];
		}
		int ans = *max_element(all(x)) - *min_element(all(x));
		ans += *max_element(all(y)) - *min_element(all(y));
		cout<<ans*2<<'\n';
	}
}