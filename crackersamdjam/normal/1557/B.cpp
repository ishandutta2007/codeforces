#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
int const MM = 1e5+5;

int a[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	int t, n, k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		map<int, int> mp;
		for(int i = 1; i <= n; i++){
			cin>>a[i];
			mp[a[i]] = 0;
		}
		int x = 0;
		for(auto &i: mp){
			i.second = x++;
		}
		int need = 1;
		for(int i = 2; i <= n; i++){
			if(mp[a[i]] == mp[a[i-1]]+1){

			}
			else{
				need++;
			}
		}
		if(need <= k){
			cout<<"Yes\n";
		}
		else{
			cout<<"No\n";
		}
	}
}