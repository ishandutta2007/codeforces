//The scars of your love remind me of us they keep me thinking that we almost had it all..

#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>

using namespace std;

const int max_n = 500 + 10;

int n, m;
char c[max_n][max_n];
vector<pair<int, int>>	adj[max_n][max_n];
vector<pair<pair<char, int>, int>>	ans;
bool mark[max_n][max_n];

void dfs(int r, int c){
	mark[r][c] = 1;
	ans.push_back({{'B', r}, c});
	if (r + 1 < n)	
		if (mark[r + 1][c] == 0){
			dfs(r + 1, c);
			adj[r][c].push_back({r + 1, c});
		}
	if (r - 1 >= 0)	
		if (mark[r - 1][c] == 0){
			dfs(r - 1, c);
			adj[r][c].push_back({r - 1, c});
		}
	if (c + 1 < m)	
		if (mark[r][c + 1] == 0){
			dfs(r, c + 1);
			adj[r][c].push_back({r, c + 1});
		}
	if (c - 1 >= 0)	
		if (mark[r][c - 1] == 0){
			dfs(r, c - 1);
			adj[r][c].push_back({r, c - 1});
		}
}

void paint(int r, int c, int par){
	for (pair<int, int>	temp:adj[r][c])
		paint(temp.first, temp.second, 1);
	
	if (par != -1){
		ans.push_back({{'D', r}, c});
		ans.push_back({{'R', r}, c});
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		string temp;	cin >> temp;
		for (int j = 0; j < m; j++){
			c[i][j] = temp[j];
			if (c[i][j] == '#')
				mark[i][j] = 1;
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			if (c[i][j] == '#')	continue;
			if (mark[i][j])	continue;
			dfs(i, j);
			paint(i, j, -1);
		}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].first.first << " " << ans[i].first.second + 1 << " " << ans[i].second + 1 << "\n";
	return 0;	
}