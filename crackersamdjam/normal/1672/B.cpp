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
		string s; cin>>s;
		int ok = 1;
		if(s.back() == 'A') ok = 0;
		if(s[0] == 'B') ok = 0;
		if(size(s) < 2) ok = 0;
		int cnt = 0;
		for(auto c: s){
			if(c == 'A'){
				cnt++;
			}
			else{
				cnt--;
				if(cnt < 0) ok = 0;
			}
		}
		cout<<(ok?"YES":"NO")<<'\n';
	}
}