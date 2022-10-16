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
		int n; string a, b;
		cin>>n>>a>>b;
		int allone = 0, allzero = 0, ans = 0;
		for(int i = 0; i < n; i++){
			if(a[i] == '0' and b[i] == '0'){
				ans++;
				// take this for sure

				if(allone){
					ans++;
					allone = 0;
				}
				else{
					allzero = 1;
				}
			}
			else if(a[i] == '1' and b[i] == '1'){
				if(allzero){
					ans++;
					allzero = 0;
				}
				else{
					allone = 1;
				}
			}
			else{
				ans += 2;
				allzero = 0;
				allone = 0;
			}
		}
		cout<<ans<<'\n';
	}
}