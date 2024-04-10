#include <bits/stdc++.h>
using namespace std;

const int N = 110000;
int a[N], b[N], chk[N];
vector<int> vec[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	int n, k; cin >> n >> k;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i], chk[a[i]]++;
		vec[a[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= k; i++) {
		if (!chk[i]) cnt++;
	}
	vector<int> V;
	for (int i = 1; i <= k; i++) {
		vector<int> tmp;
		for (int x : vec[i]) {
			tmp.push_back(b[x]);
		}
		if (!tmp.size()) continue;
		sort(tmp.begin(), tmp.end());
		tmp.pop_back();
		V.insert(V.end(), tmp.begin(), tmp.end());
	}
	sort(V.begin(), V.end());
	long long ans = 0;
	assert(V.size() >= cnt);
	for (int i = 0; i < cnt; i++) {
		ans += V[i];
	}
	cout << ans << endl;
	return 0;
}