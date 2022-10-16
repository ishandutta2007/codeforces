#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	int t;
	cin>>t;
	while(t--){
		int a, b;
		cin>>a>>b;
		if(a == 0 and b == 0){
			cout<<"0\n";
		}
		else if(a == b){
			cout<<"1\n";
		}
		else if(a%2 == b%2){
			cout<<"2\n";
		}
		else{
			cout<<"-1\n";
		}
	}
}