#include <bits/stdc++.h>

using namespace std;

const int LIM = 40;

vector<array<double, LIM>> P;
int Parent[500005];

void Remove(int node, int from, int i) {
	if(node == 0 || i >= LIM) return;

	Remove(Parent[node], node, i + 1);
	P[node][i] /= 0.5 * (P[from][i - 1] + 1.0);
}

void Add(int node, int from, int i) {
	if(node == 0 || i >= LIM) return;

	P[node][i] *= 0.5 * (P[from][i - 1] + 1.0);
	Add(Parent[node], node, i + 1);
}

int main() {
	int q, nodes = 1;
	P.push_back(array<double, LIM>());
	P.push_back(array<double, LIM>());
	fill(P.back().begin(), P.back().end(), 1.0);

	cin >> q;
	cout << fixed << setprecision(10);
	
	while(q--) {
		int t, v;
		cin >> t >> v;
		if(t == 1) {
			++nodes;
	
			P.push_back(array<double, LIM>());
			fill(P.back().begin(), P.back().end(), 1.0);

			Parent[nodes] = v;

			Remove(v, nodes, 1);
			Remove(Parent[v], v, 1);

			P[v][0] *= 0.5;

			Add(v, nodes, 1);
			Add(Parent[v], v, 1);
		} else {
			double ans = 0;
			for(int i = 1; i < LIM; ++i)
				ans += i * (P[v][i] - P[v][i-1]);
			cout << ans << '\n';
		}
	}
	return 0;
}