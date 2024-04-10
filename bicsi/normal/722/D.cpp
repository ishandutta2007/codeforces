#include <bits/stdc++.h>

using namespace std;

struct BipartiteMatcher {
	vector<vector<int>> G;
	vector<int> L, R, Viz;

	BipartiteMatcher(int n, int m) {
		G.resize(n);
		L.resize(n, -1);
		R.resize(m, -1);
		Viz.resize(n);
	}

	void AddEdge(int a, int b) {
		G[a].push_back(b);
	}

	bool Match(int node) {
		if(Viz[node]) 
			return false;
		Viz[node] = true;
	
		for(auto vec : G[node]) {
			if(R[vec] == -2) continue;
			if(R[vec] == -1 || Match(R[vec])) {
				L[node] = vec;
				R[vec] = node;
				return true;
			}
		}

		return false;
	}
	void Solve() {
		bool ok = true;
		while(ok) {
			ok = false;
			fill(Viz.begin(), Viz.end(), 0);
			for(int i = 0; i < L.size(); ++i)
				if(L[i] == -1)
					ok |= Match(i);
		}
	}
};

vector<int> Vals, V;
BipartiteMatcher T(0, 0);

void Preprocess() {
	for(auto v : V) {
		for(; v; v /= 2)
			Vals.push_back(v); 
	}
	sort(Vals.begin(), Vals.end());
	Vals.resize(unique(Vals.begin(), Vals.end()) - Vals.begin());

	T = BipartiteMatcher(V.size(), Vals.size());
	for(int i = 0; i < V.size(); ++i) {
		for(int v = V[i]; v; v /= 2)
			T.AddEdge(i, lower_bound(Vals.begin(), Vals.end(), v) - Vals.begin());
	}
}

bool Solve(int check) {
	fill(T.L.begin(), T.L.end(), -1);
	for(int i = 0; i < Vals.size(); ++i)
		T.R[i] = (Vals[i] <= check ? -1 : -2);

	T.Solve();
	for(int i = 0; i < V.size(); ++i)
		if(T.L[i] == -1)
			return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	V.resize(n);
	for(auto &v : V)
		cin >> v;

	Preprocess();

	int ans = 0;
	for(int step = (1 << 30); step; step /= 2)
		if(!Solve(ans + step))
			ans += step;
	Solve(ans + 1);

	for(int i = 0; i < n; ++i)
		cout << Vals[T.L[i]] << " ";
	cout << endl;

	return 0;
}