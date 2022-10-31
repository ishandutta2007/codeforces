#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << "\n";
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int N = 1e5+5;
int c[N];
vector<int> T[N];
ll max_sum[N];
int max_freq[N];
int sz[N];

void dfs_sz(int u, int p) {
	sz[u] = 1;
	for(int v : T[u]) {
		if(v == p) continue;
		dfs_sz(v, u);
		sz[u] += sz[v];
	}
}

void merge_into(map<int,int>& freq, int col, int amt, int v) {
	int new_f = freq[col] + amt;
	if(new_f > max_freq[v]) {
		max_freq[v] = new_f;
		max_sum[v] = col;
	} else if(new_f == max_freq[v]) {
		max_sum[v] += col;
	}
	freq[col] = new_f;
}

// returns max#, maxsum
void dfs(int u, int p, map<int, int>& freq) {
	int largest = -1;
	for(int v : T[u]) {
		if(v == p) continue;
		if(largest == -1 || sz[v] > sz[largest])
			largest = v;
	}
	if(largest == -1) {
		freq[c[u]] = 1;
		max_freq[u] = 1;
		max_sum[u] = c[u];
		return;
	}

	dfs(largest, u, freq);
	max_sum[u] = max_sum[largest];
	max_freq[u] = max_freq[largest];
	for(int v : T[u]) {
		if(v == p || v == largest) continue;
		map<int,int> f2;
		dfs(v, u, f2);
		for(auto x : f2) {
			merge_into(freq, x.first, x.second, u);
		}
	}
	merge_into(freq, c[u], 1, u);
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	for(int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		T[u].push_back(v);
		T[v].push_back(u);
	}
	dfs_sz(1,1);

	map<int,int> freq;
	dfs(1, 1, freq);
	for(int i = 1; i <= n; ++i)
		cout << max_sum[i] << " ";
	cout << "\n";

}