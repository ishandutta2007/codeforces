#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>(m));
	vector<pair<int, int>> v(n*m);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> g[i][j];
			--g[i][j];
			v[g[i][j]] = {i, j};
		}
	}
	int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	
	auto BAD = [&](int i, int j) -> bool {
		if(g[i][j] == 0) return false;
		for(int k = 0; k < 4; k++) {
			int x = i + dir[k][0];
			int y = j + dir[k][1];
			if(x < 0 || y < 0 || x >= n || y >= m) continue;
			if(g[x][y] < g[i][j]) return false;
		}
		return true;
	};
	
	vector<pair<int, int>> bad;
	
	auto CHECK = [&](bool initial) -> bool {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(g[i][j] == 0) continue;
				bool pos = BAD(i, j);
				if(pos && initial) {
					bad.push_back({i, j}); 
				}
				if(pos && !initial) return false;
			}
		}
		if(initial) {
			if((int)bad.size() > 0) return false;
		}	
		return true; 
	};
	
	CHECK(true);
	
	if((int)bad.size() == 0) {
		cout << 0 << '\n';
		return 0;
	}
	set<pair<int, int>> valid;
	 //swap 1 with every possible neighbour of 2 and check.
	for(int k = 0; k < 4; k++) {
		int x = v[1].first + dir[k][0];
		int y = v[1].second + dir[k][1];
		if(x < 0 || y < 0 || x >= n || y >= m) continue;
		int a = v[0].first;
		int b = v[0].second;
		swap(g[x][y], g[a][b]);
		if(CHECK(false)) {
			if(g[x][y] < g[a][b]) valid.insert({g[x][y], g[a][b]});
			else valid.insert({g[a][b], g[x][y]});
		}
		swap(g[x][y], g[a][b]);
	}
	int first;
	for(int i = 1; i < n*m; i++) {
		if(BAD(v[i].first, v[i].second)) {
			first = i;
			break;
		}
	}
	vector<pair<int, int>> f;
	f.push_back(v[first]);
	for(int k = 0; k < 4; k++) {
		int x = v[first].first + dir[k][0];
		int y = v[first].second + dir[k][1];
		if(x < 0 || y < 0 || x >= n || y >= m) continue;
		f.push_back({x, y});
	}
	for(auto [a, b] : f) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				vector<pair<int, int>> f2;
				f2.push_back({i, j});
				for(int k = 0; k < 4; k++) {
					int x = i + dir[k][0];
					int y = j + dir[k][1];
					if(x < 0 || y < 0 || x >= n || y >= m) continue;
					f2.push_back({x, y});
				}
				set <int> initial_bad, final_bad;
				for(auto temp : f) {
					if(BAD(temp.first, temp.second)) {
						initial_bad.insert(g[temp.first][temp.second]);
					}
				}
				for(auto temp : f2) {
					if(BAD(temp.first, temp.second)) {
						initial_bad.insert(g[temp.first][temp.second]);
					}
				}
				swap(g[a][b], g[i][j]);
				for(auto temp : f) {
					if(BAD(temp.first, temp.second)) {
						final_bad.insert(g[temp.first][temp.second]);
					}
				}
				for(auto temp : f2) {
					if(BAD(temp.first, temp.second)) {
						final_bad.insert(g[temp.first][temp.second]);
					}
				}
				
				int fs = final_bad.size();
				int is = initial_bad.size();
				int bs = bad.size();
				
				if(fs == 0 && is == bs) {
					if(g[a][b] < g[i][j]) valid.insert({g[a][b], g[i][j]});
					else valid.insert({g[i][j], g[a][b]});
				}
				
				swap(g[a][b], g[i][j]);
			}
		}
	}
	if((int)valid.size() > 0) {
		cout << 1 << " " << (int)valid.size() << '\n';
		//for(auto i : valid) cout << i.first + 1 << " " << i.second + 1 << '\n';
	} else {
		cout << 2 << '\n';
	}
	return 0;
    
    return 0;
}