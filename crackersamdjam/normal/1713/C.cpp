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

struct hopcroft_karp{
	vector<vector<int>> adj;
	vector<int> btoa;
	
	bool dfs(int cur, int L, vector<int>& A, vector<int>& B){
		if(A[cur] != L)
			return 0;
		A[cur] = -1;
		for(int u: adj[cur]){
			if(B[u] == L+1){
				B[u] = 0;
				if(btoa[u] == -1 or dfs(btoa[u], L+1, A, B))
					return btoa[u] = cur, 1;
			}
		}
		return 0;
	}
	
	vector<pair<int, int>> run(){
		vector<int> A(adj.size()), B(btoa.size()), cur, nx;
		// A stores the levels of left side nodes, B stores the levels of right side nodes
		while(1){
			fill(all(A), 0);
			fill(all(B), 0);
			cur.clear();
			// Unmatched A nodes are sources of first layer
			for(int i: btoa)
				if(~i) A[i] = -1;
			for(int i = 0; i < size(adj); i++)
				if(A[i] == 0) cur.push_back(i);

			/// Find all layers using BFS
			for(int lay = 1;; lay++){
				bool islast = 0;
				nx.clear();
				for(int i: cur){
					for(int j: adj[i]){
						if(btoa[j] == -1){
							B[j] = lay;
							islast = 1;
						}
						else if(btoa[j] != i and !B[j]){
							B[j] = lay;
							nx.push_back(btoa[j]);
						}
					}
				}
				if(islast) break;
				if(nx.empty()) goto out;
				for(int i: nx){
					A[i] = lay;
				}
				swap(cur, nx);
			}
			/// Use DFS to scan for augmenting paths
			for(int i = 0; i < size(adj); i++)
				dfs(i, 0, A, B);
		}
		out:;
		vector<pair<int, int>> matching;
		for(int i = 0; i < size(btoa); i++){
			if(~btoa[i]){
				matching.emplace_back(btoa[i], i);
			}
		}
		return matching;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		hopcroft_karp h;
		h.adj.resize(n);
		h.btoa.resize(n, -1);
		for(int i = 0; i < n; i++){
			for(ll j = 0; j*j-i < n; j++){
				ll val = j*j-i;
				if(val >= 0){
					h.adj[i].emplace_back(val);
					// pr(i, val, i+val);
				}
			}
		}

		auto ans = h.run();
		if(size(ans) == n){
			for(auto [a, b]: ans){
				cout<<a<<' ';
				// pr("  ", a, b);
			}
			cout<<'\n';
		}
		else{
			cout<<"-1\n";
		}
	}
}