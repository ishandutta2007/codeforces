#include <bits/stdc++.h>
using namespace std;

const int N = 110000;

int a[N];
long long ans[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, c; cin >> n >> c;
	set<pair<int, int> > S;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		S.insert(make_pair(a[i], i));
		if (i > c) S.erase(make_pair(a[i - c], i - c));
		ans[i] = ans[i - 1];
		if (i >= c) ans[i] = max(ans[i], ans[i - c] + (S.begin()->first));
	}
	long long ret = 0;
	for (int i = 1; i <= n; i++) ret += a[i];
	cout << ret - ans[n] << endl;
	return 0;
}