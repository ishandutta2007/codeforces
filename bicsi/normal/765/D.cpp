#include <bits/stdc++.h>

using namespace std;

struct DSU {
	vector<int> Link;
	
	DSU(int n) : Link(n, -1) {}

	int Find(int x) {
		if(Link[x] != -1)
			return Link[x] = Find(Link[x]);
		return x;
	}
	void Union(int a, int b) {
		a = Find(a);
		b = Find(b);
		if(a != b) {
			// cerr << "Uniting: " << a << " " << b << endl;
			Link[a] = b;
		}
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
	int n;
	cin >> n;

	vector<int> f(n), g, h;
	DSU dsu(n);

	for(int i = 0; i < n; ++i) {
		cin >> f[i];
		--f[i];
		dsu.Union(i, f[i]);
	}

	map<int, int> have;
	int cnt = 0;


	for(int i = 0; i < n; ++i) {
		// cerr << i << " " << dsu.Find(i) << endl;
		auto &now = have[dsu.Find(i)];
		if(now == 0) {
			now = ++cnt;
			h.push_back(dsu.Find(i));
		}
		g.push_back(now - 1);
	}

	cerr << "Git: " << cnt << endl;


	int m = h.size();
	for(int i = 0; i < m; ++i) {
		if(g[h[i]] != i) {
			cout << -1 << endl;
			return 0;
		}
	}

	for(int i = 0; i < n; ++i) {
		if(h[g[i]] != f[i]) {
			cout << -1 << endl;
			return 0;
		}
	}

	cout << m << endl;
	for(int i = 0; i < n; ++i) {
		cout << g[i] + 1 << " ";
	}
	cout << endl;
	for(int i = 0; i < m; ++i) {
		cout << h[i] + 1 << " ";
	}
	cout << endl;


	return 0;
}