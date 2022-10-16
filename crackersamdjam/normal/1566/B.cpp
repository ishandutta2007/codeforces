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
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int zero = 0, one = 0, ans = 0;
		for(auto c: s){
			if(c == '0'){
				ans = 1;
				zero = 1;
				if(one){
					ans = 2;
				}
			}
			else{
				if(zero){
					one = 1;
				}
			}
		}
		cout<<ans<<'\n';
	}
}