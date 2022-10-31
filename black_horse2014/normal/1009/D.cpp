#include <bits/stdc++.h>
using namespace std;

const int N = 110000;
int val[N];
vector<pair<int, int> > ans;
int main() {
	ios::sync_with_stdio(0);
	for (int i = 2; i < N; i++) val[i] = i;
	for (int i = 2; i * i < N; i++) if (val[i] == i) {
		for (int j = i * i; j < N; j += i) val[j] = i;
	}
	int n, m; cin >> n >> m;
	if (m < n - 1) return puts("Impossible"), 0;
	for (int i = 2; i <= n; i++) ans.push_back(make_pair(1, i)), m--;
	int pm = 0;
	for (int i = 2; i <= n; i++) if (val[i] == i) {
		for (int j = 2; j < i && m; j++, m--) ans.push_back(make_pair(j, i));
	}
	for (int i = 2; i <= n; i++) if (val[i] != i) {
		for (int j = 2; j < i && m; j++) if (__gcd(i, j) == 1) ans.push_back(make_pair(j, i)), m--;
	}
	if (m) return puts("Impossible"), 0;
	cout << "Possible\n";
	for (auto e : ans) cout << e.first << " " << e.second << " \n";
	return 0;
}