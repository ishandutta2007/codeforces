#ifndef LOCAL
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#endif

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

// #ifndef ONLINE_JUDGE
// template<typename T>
// void pr(T a){std::cerr<<a<<std::endl;}
// template<typename T,typename... Args>
// void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
// #else
// template<typename... Args>
// void pr(Args... args){}
// #endif

using namespace std;
using stt = pair<int, pair<int, int>>;
constexpr int MM = 601;

int n, m, k;
int dp[MM][MM];
vector<pair<int, int>> adj[MM];
queue<pair<int, int>> q;
bool inq[MM][MM];
array<int, 3> e[MM*MM/2];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i = 0,a,b,c; i < m; i++){
		cin>>a>>b>>c;
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
		e[i] = {a, b, c};
	}

	for(int i = 1; i <= n; i++){
		sort(all(adj[i]), [](auto x, auto y){
			return x.second < y.second;
		});
	}

	cin>>k;
	while(k--){
		int a, b, c;
		cin>>a>>b>>c;
		if(c > dp[a][b]){
			dp[a][b] = c;
			inq[a][b] = 1;
			q.emplace(a, b);
		}
	}
	while(size(q)){
		auto [a, b] = q.front(); q.pop();
		int curd = dp[a][b];
		inq[a][b] = 0;
		for(auto [c, w]: adj[b]){
			if(curd-w <= 0)
				break;
			if(curd-w > dp[a][c] and a != c){
				dp[a][c] = curd-w;
				if(!inq[a][c]){
					inq[a][c] = 1;
					q.emplace(a, c);
				}
			}
		}
		if(curd > dp[b][a]){
			dp[b][a] = curd;
			if(!inq[b][a]){
				inq[b][a] = 1;
				q.emplace(b, a);
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < m; i++){
		auto [a, b, c] = e[i];
		if(dp[a][b] >= c){
			ans++;
		}
	}
	cout<<ans<<'\n';
}