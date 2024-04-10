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

int t, n, a[1005], b[1005];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		cin>>n;
		set<int> st;
		for(int i = 1; i <= n; i++){
			cin>>a[i];
			st.insert(i);
		}
		if(n == 1){
			cout<<"-1\n";
			continue;
		}
		for(int i = 1; i < n; i++){
			b[i] = *st.begin();
			st.erase(st.begin());
			if(b[i] == a[i]){
				b[i] = *st.begin();
				st.erase(st.begin());
				st.insert(a[i]);
			}
		}
		b[n] = *st.begin();
		if(b[n] == a[n]){
			swap(b[n], b[n-1]);
		}
		for(int i = 1; i <= n; i++){
			cout<<b[i]<<' ';
			assert(b[i] != a[i]);
		}
		cout<<'\n';
	}
}