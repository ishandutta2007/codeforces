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

int t, n;
string s;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		cin>>n>>s;
		map<int, int> mp;
		ll ans = 0;
		int sum = 0;
		mp[0]++;
		for(auto c: s){
			sum += c-'1';
			ans += mp[sum];
			mp[sum]++;
		}
		cout<<ans<<'\n';
	}
}