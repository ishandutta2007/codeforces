#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int get(int n, int k) {
	int based = n / k;
	int spec = n%k;

	return spec * (based + 1) * (based + 1) + (k - spec) * based * based;

}

int profit(int n, int cur) {
	return get(n, cur) - get(n, cur + 1);
}

main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for (auto &x : v) cin >> x;

	vector<int> dvd(n, 1);
	int ans = 0;

	for (auto x : v) ans += get(x, 1);

	set<pair<int, int> > ms;
	for (int i = 0; i < n; ++i) {
		if (dvd[i] < v[i]) ms.insert(mp(profit(v[i], dvd[i]), i));
	}

	for (int i = 0; i < k-n; ++i) {
		auto it = ms.end();
		it--;

		auto p = (*it);
		ms.erase(it);
		ans -= p.x;

		dvd[p.y]++;
		if (dvd[p.y] < v[p.y]) ms.insert(mp(profit(v[p.y], dvd[p.y]), p.y));
	}

	cout << ans;

}