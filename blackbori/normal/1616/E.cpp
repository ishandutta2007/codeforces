#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll inf = 1e18;

vector<int> V[33];
string S, T;
int n; ll a, c;

struct fenwick {
	int T[101010]; int n = 1e5;
	void init() { fill(T, T + n + 1, 0); }
	void add(int i, int v) { for (; i <= n; i += i & -i) T[i] += v; }
	int get(int i) { return i ? get(i - (i & -i)) + T[i] : 0; }
} F;

void tc() {
	int i, j, t;
	cin >> n >> S >> T; F.init();
	for (i = 0; i < 26; i++) {
		V[i].clear();
	}
	for (i = 0; i < n; i++) {
		V[S[i] - 'a'].push_back(i);
	}
	for (i = 0; i < 26; i++) {
		reverse(V[i].begin(), V[i].end());
	}
	a = inf; c = 0;
	for (i = 0; i < n; i++) {
		t = n;
		for (j = 0; j < T[i] - 'a'; j++) {
			if (!V[j].empty() && V[j].back() < t) {
				t = V[j].back();
			}
		}
		if (t < n) a = min(a, c + (t - i) + (i - F.get(t + 1)));

		j = T[i] - 'a';
		if (V[j].empty()) break;
		t = V[j].back(); V[j].pop_back();
		c += (t - i) + (i - F.get(t + 1));
		F.add(t + 1, 1);
	}
	if (a == inf) cout << "-1\n";
	else cout << a << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

	cin >> t;

	for (; t--; ) {
		tc();
	}

	return 0;
}