#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void try_add(int val, int d, queue<int> &Q, vector<int> &dist) {
	if (dist[val] > d) {
		Q.push(val);
		dist[val] = d;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	queue<int> Q;
	const int N = 32768;
	vector<int> dist(N, 2 * N);
	Q.push(0);
	dist[0] = 0;
	while (Q.size()) {
		int f = Q.front();
		Q.pop();
		try_add((f + N - 1) % N, dist[f] + 1, Q, dist);
		if (f % 2 == 0) {
			try_add(f / 2, dist[f] + 1, Q, dist);
			try_add((f / 2) ^ (N / 2), dist[f] + 1, Q, dist);
		}
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		cout << dist[a] << ' ';
	}
}