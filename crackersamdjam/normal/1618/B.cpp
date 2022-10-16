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
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		string s; cin>>s;
		n -= 3;
		cout<<s[0];
		bool b = 0;
		while(n--){
			string t; cin>>t;
			if(s[1] != t[0]){
				cout<<s[1]<<t[0];
				b = 1;
			}
			else{
				cout<<t[0];
			}
			s = t;
		}
		cout<<s[1];
		if(!b) cout<<'a';
		cout<<'\n';
	}
}