#include <bits/stdc++.h>
using namespace std;

const int N = 110000;
const int M = 7008;

bitset<M> B[N], W[M];

vector<int> d[M];

bool ban[M];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	for (int i = 1; i < M; i++) {
		for (int j = i; j < M; j += i) d[j].push_back(i);
	}
	for (int i = 2; i * i < M; i++) {
		for (int j = i * i; j < M; j += i * i) {
			ban[j] = 1;
		}
	}
	for (int i = 1; i < M; i++) {
		for (int j = 1; i * j < M; j++) {
			if (!ban[j]) W[i][i * j] = 1;
		}
	}
	int n, q; cin >> n >> q;
	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int x, v; cin >> x >> v;
			B[x].reset();
			for (int y : d[v]) B[x][y] = 1;
		} else if (t == 2) {
			int x, y, z; cin >> x >> y >> z;
			B[x] = B[y] ^ B[z];
		} else if (t == 3) {
			int x, y, z; cin >> x >> y >> z;
			B[x] = B[y] & B[z];
		} else {
			int x, v; cin >> x >> v;
			cout << (B[x] & W[v]).count() % 2;
		}
	}
}