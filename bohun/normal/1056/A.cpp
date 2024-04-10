//vsp
#include <bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; (a) <= i; i--)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

int n, cnt[101];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	FOR(q, n) {
		int m;
		cin >> m;

		while (m--) {
			int x;
			cin >> x;
			cnt[x]++;
		}
	}

	int mx = *max_element(cnt, cnt + 101);
	FOR(i, 101)
		if (cnt[i] == mx)
			cout << i << ' ';

	return 0;
}