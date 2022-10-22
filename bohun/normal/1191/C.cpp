//vsp
#include<bits/stdc++.h>
#define cat(x) cerr << #x << " = " << x << "\n";
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b) - 1; (a) <= i; i--)
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using ll = long long;
using namespace std;

const int N = 2e5;
ll n, m, k, p[N];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m >> k;
	FOR(i, m)
		cin >> p[i], p[i]--;

	int res = 0;
	for (int i = 0; i < m;) {
		int j = i;
		while (j < m && (p[i] - i) / k == (p[j] - i) / k)
			j++;
		i = j;
		res++;
	}
	cout << res << '\n';

	return 0;
}