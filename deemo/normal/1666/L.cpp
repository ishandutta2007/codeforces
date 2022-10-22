#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int) x.size())
#define all(x) x.begin(), x.end()

using ll = long long;

const char nl = '\n';
const int MX = 2e5 + 10;

vector<int> adj[MX];
int p[MX], top[MX];
int n, m, s;

vector<int> go(int v) {
	vector<int> ans;
	while(v >= 0) {	
		ans.push_back(v);
		v = p[v];
	}
	reverse(all(ans));
	return ans;
}

void print(vector<int> v) {
	cout << v.size() << nl;
	for(int i = 0; i < sz(v); i++) {
		if(i > 0) cout << " ";
		cout << v[i]+1;
	}
	cout << nl;
}

int main() {
	cin >> n >> m >> s;
	--s;
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		adj[a].push_back(b);
	}
	fill_n(p, n, -1);
	fill_n(top, n, -1);
	p[s] = -2;
	queue<int> qu;
	for(int u : adj[s]) {
		p[u] = s;
		top[u] = u;
		qu.push(u);
	}
	while(sz(qu)) {
		int v = qu.front();
	//	cerr << "doing: " << v+1 << ", " << top[v]+1 << nl;
		qu.pop();
		for(int u : adj[v]) {
			if(p[u] == -1) {
				p[u] = v;
				top[u] = top[v];
				qu.push(u);
			} else if(top[u] != -1 && top[u] != top[v]) {
				cout << "Possible\n";
				vector<int> one = go(v);
				one.push_back(u);
				vector<int> two = go(u);
				print(one);
				print(two);
				return 0;
			}
		}
	}
	cout << "Impossible\n";

	return 0;
}