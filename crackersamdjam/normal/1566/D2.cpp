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
int const MM = 305;

int n, m;
bool taken[MM][MM];
int a[MM*MM];
int b[MM*MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		memset(taken, 0, sizeof taken);

		for(int i = 0; i < n*m; i++){
			cin>>a[i];
			b[i] = a[i];
		}
		sort(b, b+n*m);
		map<int, vector<pair<int, int>>> mp;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				int id = i*m+j;
				mp[b[id]].emplace_back(i, j);
			}
		}
		for(auto &[key, v]: mp){
			sort(all(v), [](auto x, auto y){
				if(x.first != y.first){
					//front row first
					return x.first < y.first;
				}
				else{
					//rightmost first
					return x.second > y.second;
				}
			});
			reverse(all(v));
		}

		int ans = 0;
		for(int i = 0; i < n*m; i++){
			auto [x, y] = mp[a[i]].back();
			mp[a[i]].pop_back();
			for(int j = 0; j < y; j++){
				ans += taken[x][j];
			}
			taken[x][y] = 1;
		}
		
		cout<<ans<<'\n';
	}
}