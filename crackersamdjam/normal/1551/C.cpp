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

int t, n;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>t;
	while(t--){
		cin>>n;
		vector<array<int, 6>> cnt(n);
		vector<vector<int>> vals(5);
		for(int i = 0; i < n; i++){
			string s;
			cin>>s;
			for(auto c: s){
				cnt[i][c-'a']++;
				cnt[i][5]++;
			}
			for(int j = 0; j < 5; j++){
				vals[j].emplace_back(2*cnt[i][j]-cnt[i][5]);
			}
		}
		int ans = 0;
		for(int j = 0; j < 5; j++){
			sort(all(vals[j]));
			int val = 0, num = 0;
			while(size(vals[j]) and val+vals[j].back() > 0){
				num++;
				val += vals[j].back();
				vals[j].pop_back();
			}
			ans = max(ans, num);
		}
		cout<<ans<<'\n';
	}
}