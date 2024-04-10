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
		int x; cin>>x;
		int a[4] = {0};
		for(int i = 1; i <= 3; i++)
			cin>>a[i];
		set<int> st;
		while(!st.count(x)){
			st.insert(x);
			x = a[x];
		}
		cout<<(size(st)==4?"YES\n":"NO\n");
	}
}