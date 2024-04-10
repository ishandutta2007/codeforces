// Create your own template by modifying this file!
#include <bits/stdc++.h>

using namespace std;

string String[30000];
int GetNode(string s) {
	assert(s.size() >= 3);
	int ret = (s[0] - 'A') * 30 * 30 + (s[1] - 'A') * 30 + s[2] - 'A';
	assert(ret < 30000);
	String[ret] = s;

	return ret;
}

string a[30000], b[30000];
int Count[30000];

pair<string, string> GetNames(int i) {
	assert(a[i].size() >= 3);
	assert(b[i].size() >= 3);

	string name1, name2;
	name1 += a[i][0];
	name1 += a[i][1];
	name1 += a[i][2];

	name2 += a[i][0];
	name2 += a[i][1];
	name2 += b[i][0];

	return {name1, name2};
}

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

int main() {
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
		Count[GetNode(GetNames(i).first)] += 1;
	}

/*	for(int i = 0; i < n; ++i) {
		cerr << i << " " << GetNames(i).first << " " << GetNames(i).second << endl;
	}
*/
	
	BipartiteMatcher m(n, 30000);
	for(int i = 0; i < n; ++i) {
		auto p = GetNames(i);
		if(Count[GetNode(p.first)] == 1)
			m.AddEdge(i, GetNode(p.first));
		m.AddEdge(i, GetNode(p.second));
	}

	m.Solve();
	auto L = m.L;

	for(int i = 0; i < n; ++i) {
		if(L[i] == -1) {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES\n";
	for(int i = 0; i < n; ++i) {
		cout << String[L[i]] << '\n';
	}


	return 0;
}