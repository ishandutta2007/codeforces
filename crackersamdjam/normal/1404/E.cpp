// https://cp-algorithms.com/graph/kuhn_maximum_bipartite_matching.html
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;

struct kuhns{
	
	int n, k;
	vector<vector<int>> adj;
	vector<int> mt;
	vector<bool> used;
	
	void init(int nn){
		adj.resize(nn);
	}
	
	int next_small(){
		return n++;
	}
	
	int next_large(){
		return k++;
	}
	
	void addedge(int a, int b){
		// add edge from small side to large side
		adj[a].emplace_back(b);
	}
	
	bool dfs(int cur){
		if(used[cur])
			return 0;
		used[cur] = 1;
		for(int u: adj[cur]){
			if(mt[u] == -1 or dfs(mt[u])){
				mt[u] = cur;
				return 1;
			}
		}
		return 0;
	}
	
	vector<pair<int, int>> run(){
		vector<pair<int, int>> matching;
		mt.assign(k, -1);
		vector<bool> used1(n, 0);
		for(int cur = 0; cur < n; cur++){
			for(int u: adj[cur]){
				if(mt[u] == -1){
					mt[u] = cur;
					used1[cur] = 1;
					break;
				}
			}
		}
		for(int cur = 0; cur < n; cur++){
			if(used1[cur])
				continue;
			used.assign(n, false);
			dfs(cur);
		}
		
		for(int i = 0; i < k; i++){
			if(~mt[i]){
				matching.emplace_back(mt[i]+1, i+1);
			}
		}
		return matching;
	}
} B;

//https://dmoj.ca/problem/coci20c3p4
namespace coci20c3p4{
	
	int nn, mm;
	char s[1005][15];
	int down[1005][15], rs[1005][15];
	int ans;
	
	int main() {
		scanf("%d%d", &nn, &mm);
		for(int i = 1; i <= nn; i++){
			scanf("%s", s[i]+1);
			for(int j = 1; j <= mm; j++){
				if(s[i][j] == '#'){
					ans++;
				}
			}
		}
		
		memset(down, -1, sizeof down);
		memset(rs, -1, sizeof rs);
		B.init(nn*mm);
		
		auto addedge = [](int a, int b){
			if(~a and ~b){
				B.addedge(a, b);
			}
		};
		
		for(int i = 1; i <= nn; i++){
			for(int j = 1; j <= mm; j++){
				if(s[i][j] == '#' and s[i+1][j] == '#'){
					down[i][j] = B.next_small();
					ans--;
				}
				if(s[i][j] == '#' and s[i][j+1] == '#'){
					rs[i][j] = B.next_large();
					ans--;
				}
				
				addedge(down[i-1][j], rs[i][j-1]);
				addedge(down[i][j], rs[i][j-1]);
				addedge(down[i-1][j], rs[i][j]);
				addedge(down[i][j], rs[i][j]);
			}
		}
		
		auto v = B.run();
		ans += (int)size(v);
		
		printf("%d\n", ans);
		return 0;
	}
}

// https://codeforces.com/contest/1404/problem/E
namespace cf1404E{
	
	int nn, mm;
	char s[205][205];
	int down[205][205], rs[205][205];
	int ans;
	
	int main() {
		scanf("%d%d", &nn, &mm);
		for(int i = 1; i <= nn; i++){
			scanf("%s", s[i]+1);
			for(int j = 1; j <= mm; j++){
				if(s[i][j] == '#'){
					ans++;
				}
			}
		}
		
		memset(down, -1, sizeof down);
		memset(rs, -1, sizeof rs);
		B.init(nn*mm);
		
		auto addedge = [](int a, int b){
			if(~a and ~b){
				B.addedge(a, b);
			}
		};
		
		for(int i = 1; i <= nn; i++){
			for(int j = 1; j <= mm; j++){
				if(s[i][j] == '#' and s[i+1][j] == '#'){
					down[i][j] = B.next_small();
					ans--;
				}
				if(s[i][j] == '#' and s[i][j+1] == '#'){
					rs[i][j] = B.next_large();
					ans--;
				}
				
				addedge(down[i-1][j], rs[i][j-1]);
				addedge(down[i][j], rs[i][j-1]);
				addedge(down[i-1][j], rs[i][j]);
				addedge(down[i][j], rs[i][j]);
			}
		}
		
		auto v = B.run();
		ans += (int)size(v);
		
		printf("%d\n", ans);
		return 0;
	}
}

int main(){
	// coci20c3p4::main();
	cf1404E::main();
}