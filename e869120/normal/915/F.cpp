#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

const int MAX_N = 1000000;

class MergeTech {
public:
	vector<int>G[MAX_N + 9]; int group[MAX_N + 9];

	void init() {
		for (int i = 0; i < MAX_N + 9; i++) {
			G[i].push_back(i); group[i] = i;
		}
	}
	void unite(int u, int v) {
		u = group[u]; v = group[v];
		if (G[u].size() < G[v].size()) swap(u, v);

		for (int i = 0; i < G[v].size(); i++) {
			G[u].push_back(G[v][i]); group[G[v][i]] = u;
		}
		G[v].clear();
	}
	int getsize(int pos) {
		return G[group[pos]].size();
	}
};

long long N, A[MAX_N + 9]; vector<pair<long long, int>>vec;
vector<int>X[MAX_N + 9]; bool used[MAX_N + 9];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
		vec.push_back(make_pair(A[i], i));
	}
	sort(vec.begin(), vec.end());
	for (int i = 1; i <= N - 1; i++) {
		long long x, y; scanf("%lld%lld", &x, &y);
		X[x].push_back(y);
		X[y].push_back(x);
	}

	// Max 
	long long Maxret = 0; MergeTech TC1; TC1.init();
	for (int i = 0; i < vec.size(); i++) {
		int to = vec[i].second;
		for (int j = 0; j < X[to].size(); j++) {
			if (used[X[to][j]] == false) continue;
			long long B = TC1.getsize(X[to][j]);
			Maxret -= vec[i].first * B * (B - 1) / 2;
			TC1.unite(X[to][j], to);
		}
		long long Z = TC1.getsize(to);
		Maxret += vec[i].first * Z * (Z - 1) / 2;
		used[to] = true;
	}

	// Min 
	reverse(vec.begin(), vec.end()); for (int i = 1; i <= N; i++) used[i] = false;

	long long Minret = 0; MergeTech TC2; TC2.init();
	for (int i = 0; i < vec.size(); i++) {
		int to = vec[i].second;
		for (int j = 0; j < X[to].size(); j++) {
			if (used[X[to][j]] == false) continue;
			long long B = TC2.getsize(X[to][j]);
			Minret -= vec[i].first * B * (B - 1) / 2;
			TC2.unite(X[to][j], to);
		}
		long long Z = TC2.getsize(to);
		Minret += vec[i].first * Z * (Z - 1) / 2;
		used[to] = true;
	}

	cout << Maxret - Minret << endl;
	return 0;
}