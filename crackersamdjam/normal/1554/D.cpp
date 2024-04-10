#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;

string rep(string s, int i){
	string t;
	while(i--){
		t += s;
	}
	return t;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		if(n == 1){
			cout<<"a\n";
			continue;
		}
		string f, s = "ab";

		while(size(f)+size(s)+2 <= n){
			f.push_back('a');
			s.push_back('a');
		}
		f += s;
		if(size(f) < n)
			f += "c";
		cout<<f<<'\n';
	}
}