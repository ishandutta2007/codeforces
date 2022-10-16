#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <deque>

using namespace std;

void dfs(int v, int p, vector<int>& a, vector<int>& visited, vector<int>& from) {
	from[v] = p;
	visited[v] = 1;

	if (visited[a[v]] == 0)
		dfs(a[v], v, a, visited, from);
	if (visited[a[v] == 1])
	{
		if (from[a[v]] == -1)
			from[a[v]] = v;
	}
	if (visited[a[v]] == 2) {
		from[a[v]] = v;
	}

	visited[v] = 2;
}

void solve() {
	int n; cin >> n;

	vector<int> a(n); for (int i = 0; i < n; ++i) { cin >> a[i]; --a[i]; }

	vector<int> visited(n), from(n, -1);
	for (int i = 0; i < n; ++i) if (visited[i] == 0) {
		dfs(i, -1, a, visited, from);
	}

	vector<int> b(n, -2);
	for (int i = 0; i < n; ++i) if (from[i] != -1) {
		b[from[i]] = i;
	}

	for (int i = 0; i < n; ++i)
		cerr << b[i] << ' ';
	cerr << endl;

	int result = 0;
	vector<int> head(n, 1), tail(n, 1);
	for (int i = 0; i < n; ++i) {
		if (b[i] != -2) {
			head[b[i]] = 0, tail[i] = 0;
			++result;
		}
	}

	vector<int> heads, tails, both;
	for (int i = 0; i < n; ++i) {
		if (head[i] and tail[i]) {
			both.push_back(i); 
			continue;
		};
		if (head[i]) heads.push_back(i);
		if (tail[i]) tails.push_back(i);
	}

	for (int i = 0; i + 1 < both.size(); ++i) {
		b[both[i]] = both[i + 1];
	}
	if (both.size()) {
		heads.push_back(both[0]);
		tails.push_back(both.back());
	}
	reverse(heads.begin(), heads.end());

	for (int i = 0; i < heads.size(); ++i)
		b[tails[i]] = heads[i];

	cout << result << endl;
	for (int i = 0; i < n; ++i)
		cout << b[i] + 1 << ' ';
	cout << endl;
}

int main() {
	cin.sync_with_stdio(false);
	int t; cin >> t;
	while (t-- > 0)
		solve();
	return 0;
}