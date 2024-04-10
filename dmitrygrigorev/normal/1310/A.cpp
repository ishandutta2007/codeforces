#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];

	vector<pair<int, int> > men;
	for (int i = 0; i < n; ++i) men.push_back({a[i], b[i]});
	sort(men.begin(), men.end());

	multiset<int> ms;

	ll ans = 0;
	ll sum = 0;

	int cur = men[0].first;
	int u = 0;



	while (u < n || ms.size()) {
		while (u < n && men[u].first == cur) {
			ms.insert(men[u].second);
			sum += men[u].second;
			u++;
		}

		auto it = ms.end();
		it--;
		int p = (*it);
		ms.erase(it);
		sum -= p;
		ans += sum;

		if (ms.size()) cur++;
		else if (u < n) {
			cur = men[u].first;
		} 

	}

	cout << ans;

}