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
const int MM = 2e5+5;

int t, n, a[MM];

bool go(int l, int r){
	for(int i = l; i <= r; i++){
		for(int j = l; j < i; j++){
			for(int k = l; k < j; k++){
				if(a[k] <= a[j] and a[j] <= a[i])
					return 0;
				if(a[k] >= a[j] and a[j] >= a[i])
					return 0;
			}
		}
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		cin>>n;
		set<int> st;
		ll ans = 0;
		for(int i = 0; i < n; i++){
			cin>>a[i];
			for(int j = i; j >= max(0, i-5); j--){
				ans += go(j, i);
			}
		}
		cout<<ans<<'\n';
	}
}