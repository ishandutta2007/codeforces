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
	int t; ll n;
	cin>>t;
	while(t--){
		cin>>n;
		for(ll i = 1; i*i <= n; i++){
			if(i*i*2 == n or i*i*4 == n){
				cout<<"YES\n";
				goto out;
			}
		}
		cout<<"NO\n";
		out:;
	}
}