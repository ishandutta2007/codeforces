#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args> void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	using ll = long long;
	ll t, a, b;
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(a%(a*b) == 0){
			cout<<"NO\n";
		}
		else{
			cout<<"YES\n"<<a*b<<' '<<a<<' '<<a*b+a<<'\n';
		}
	}	
}