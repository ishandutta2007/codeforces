#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
int const MM = 2e5+5;

int t, n, k;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		cin>>n>>k;
		map<int, vector<int>> mp;
		vector<int> ans(n);
		for(int i = 0,a; i < n; i++){
			cin>>a;
			mp[a].emplace_back(i);
		}
		vector<vector<int>> v(k);
		int i = 0;
		for(auto [a, b]: mp){
			int rem = min(k, (int)size(b));
			while(rem--){
				v[i].emplace_back(b.back());
				b.pop_back();
				i = (i+1)%k;
			}
		}
		int sz = v.back().size();
		for(int i = 0; i < k; i++){
			v[i].resize(sz);
			for(auto j: v[i]){
				ans[j] = i+1;
			}
		}
		for(auto i: ans)
			cout<<i<<' ';
		cout<<'\n';
	}
}