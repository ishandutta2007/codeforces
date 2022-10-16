#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
int const MM = 2e5+5;

int t;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		map<char, int> mp;
		for(auto c: s)
			mp[c]++;
		int ans = 0;
		for(auto [a, b]: mp){
			ans += min(2, b);
		}
		ans -= ans%2;
		cout<<ans/2<<'\n';
	}
}