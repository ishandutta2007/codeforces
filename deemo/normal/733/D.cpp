#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second

const int MAXN = 3e5 + 10;

int n, a[MAXN];
map<pair<int, int>, pair<int, int>>	mp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		int beg = i*3;
		for (int j = 0; j < 3; j++)
			cin >> a[beg + j];
		sort(a + beg, a + beg + 3);
	}

	pair<int, pair<int, int>>	ans = {-1, {-1, -1}};
	for (int i = 0; i < n; i++){
		if (mp.count({a[3 * i], a[3 * i + 1]}))
			ans = max(ans, {min({a[3 * i], a[3 * i + 1], a[3 * i + 2] + mp[{a[3 * i], a[3 * i + 1]}].first}), {i, mp[{a[3 * i], a[3 * i + 1]}].second}});

		if (mp.count({a[3 * i + 1], a[3 * i + 2]}))
			ans = max(ans, {min({a[3 * i] + mp[{a[3 * i + 1], a[3 * i + 2]}].first, a[3 * i + 1], a[3 * i + 2]}), {i, mp[{a[3 * i+1], a[3 * i + 2]}].second}});

		if (mp.count({a[3 * i], a[3 * i + 2]}))
			ans = max(ans, {min({a[3 * i], a[3 * i + 1] + mp[{a[3 * i], a[3 * i + 2]}].first, a[3 * i + 2]}), {i, mp[{a[3 * i], a[3 * i + 2]}].second}});

		mp[{a[3 * i], a[3 * i + 1]}] = max(mp[{a[3 * i], a[3 * i + 1]}], {a[3 * i + 2], i});

		mp[{a[3 * i], a[3 * i + 2]}] = max(mp[{a[3 * i], a[3 * i + 2]}], {a[3 * i + 1], i});

		mp[{a[3 * i+1], a[3 * i + 2]}] = max(mp[{a[3 * i+1], a[3 * i + 2]}], {a[3 * i], i});
	}

	for (int i = 0; i < n; i++)
		ans = max(ans, {a[3*i], {i, -1}});
	if (ans.S.S >= 0)
		cout << 2 << "\n";
	else
		cout << 1 << "\n";
	cout << ans.S.F+1 << " ";
	if (ans.S.S >= 0)
		cout << ans.S.S+1;
	cout << "\n";
	return 0;
}