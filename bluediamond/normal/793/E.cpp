#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <set> 
#include <iomanip> 
#include <queue> 
#include <deque> 
#include <unordered_set> 
#include <unordered_map> 
#include <functional> 
#include <cmath> 
#include <map> 
#include <random> 
#include <chrono> 
#include <cstdio> 
#include <bitset> 
#include <numeric> 

bool home = true;
using namespace std;

const int N = 5000 + 7;
int n;
int par[N], color[N], sub[N];
vector<int> g[N];
vector<int> all;

void dfs_color(int a) {
	for (auto& b : g[a]) {
		color[b] = color[a];
		dfs_color(b);
	}
}

void dfs_build(int a) {
	sub[a] = (g[a].empty());
	for (auto& b : g[a]) {
		dfs_build(b);
		sub[a] += sub[b];
	}
}

bool is_achievable[N];

bool test_achievability(vector<int> dims, int goal) {
	if (goal < 0 || goal >= N) return 0;
	assert(0 <= goal && goal < N);
	for (int i = 0; i < N; i++) is_achievable[i] = 0;
	is_achievable[0] = 1;
	for (auto& x : dims) {
		for (int i = N - 1; i >= x; i--) {
			if (is_achievable[i - x]) {
				is_achievable[i] = 1;
			}
		}
	}
	return is_achievable[goal];
}

void addtodims(vector<int>& dims, int vertex) {
	while (par[vertex] > 1) {
		// (par[vertex], vertex)
		for (auto& i : g[par[vertex]]) {
			if (i != vertex) {
				dims.push_back(sub[i]);
			}
		}
		vertex = par[vertex];
	}
}

bool is_ok_skip(int va, int vb, int vskip) {
	vector<int> dims;
	int dim_vskip = -1;
	for (auto& i : g[1]) {
		bool join = 1;
		for (auto& vertex : all) {
			if (color[vertex] == color[i]) {
				join = 0;
				break;
			}
		}
		if (join) {
			dims.push_back(sub[i]);
		}
		if (color[i] == color[vskip]) {
			assert(!join);
			dim_vskip = sub[i];
		}
	}
	assert(dim_vskip != -1);
	addtodims(dims, va);
	addtodims(dims, vb);

	int goal = sub[1] / 2 - dim_vskip - 1;
	return test_achievability(dims, goal);
}

bool is_ok(int va, int vb, int vc, int vd) {
	// va, vc, vb, vd
	return is_ok_skip(va, vb, vc) && is_ok_skip(vc, vd, vb);
}

signed main() {
#ifdef ONLINE_JUDGE
	home = 0;
#endif

	if (home) {
		FILE* stream;
		freopen_s(&stream, "iron_man.txt", "r", stdin);
	}
	else {
		ios::sync_with_stdio(0); cin.tie(0);
	}

	int va, vb, vc, vd;
	cin >> n;

	cin >> va >> vb >> vc >> vd;
	all = { va, vb, vc, vd };
	for (int i = 2; i <= n; i++) {
		cin >> par[i];
		g[par[i]].push_back(i);
	}
	for (auto& vertex : g[1]) {
		color[vertex] = vertex;
		dfs_color(vertex);
	}
	{
		for (int i = 0; i < 4; i++) {
			for (int j = i + 1; j < 4; j++) {
				assert(color[all[i]] != color[all[j]]);
			}
		}
	}
	{
		assert(color[1] == 0);
		for (int i = 2; i <= n; i++) {
			assert(color[i] > 0);
		}
	}
	dfs_build(1);
	{
		assert(g[va].empty());
		assert(g[vb].empty());
		assert(g[vc].empty());
		assert(g[vd].empty());
	}
	if (sub[1] % 2) {
		cout << "NO\n";
		return 0;
	}
	{
		for (int i = 1; i <= n; i++) {
			assert(sub[i] > 0);
		}
	}
	if (is_ok(va, vb, vc, vd)) {
		cout << "YES\n";
		return 0;
	}
	cout << "NO\n";
}