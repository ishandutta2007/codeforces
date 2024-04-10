#include<bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define sz(x) int(x.size())
#define cat(x) cerr << #x << " = " << x << endl

using ll = long long;
using namespace std;

const int N = 200200;

int n, a[N], L[N], R[N], go[N], sum[N], e[N];
vector<pair<int, int>> v, nv;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	rep(i, 1, n) L[i] = n + 1;
	rep(i, 1, n) {
		cin >> a[i];
		R[a[i]] = max(R[a[i]], i);
		L[a[i]] = min(L[a[i]], i);
	}
	rep(i, 1, n)
		if (L[i] < R[i]) {
			v.emplace_back(L[i], R[i]);
			e[L[i]] = 1;
			e[R[i]] = 1;
			sum[L[i]]++;
			sum[R[i]]--;
		}
	int res = 0;
	rep(i, 1, n) sum[i] += sum[i - 1];
	rep(i, 1, n) res += sum[i] && !e[i];

	sort(v.begin(), v.end());
	int rmax = -100;
	for (auto [a, b] : v) {
		if (rmax < b) {
			nv.push_back({a, b});
			rmax = b;
		}
		else {
			res += 2;
		}
	}
	v = nv;

	/* cat(res); */
	/* for (auto [a, b] : v) { cat(a); cat(b); } */
	for (int i = 0; i < sz(v);) {
		int j = i + 1;
		while (j < sz(v) && v[j].first < v[j - 1].second)
			j++;

		int cnt = j - i;
		int greedy = 0;

		int k = i;
		while (true) {
			greedy++;
			if (k + 1 == j)
				break;
			int p = k;
			while (p + 1 < sz(v) && v[p + 1].first < v[k].second)
				p++;
			k = p;
		}

		/* cat(cnt); */
		/* cat(greedy); */
		res += greedy - 1 + 2 * (cnt - greedy);
		i = j;
	}
	cout << res << endl;
	return 0;
}