#include<bits/stdc++.h>
using namespace std;
#define MAXN	75
map <long long, int> a[MAXN];
int num, mark[MAXN][MAXN];
int get(int value, long long curr) {
	curr &= (1ll << value) - 1;
	if (value == 0) return 0;
	if (a[value].count(curr)) return a[value][curr];
	int now = ++num;
	for (int i = 1; i <= value; i++) {
		long long tmp = 1ll << i - 1;
		if (tmp & curr) continue;
		mark[value][get(value - i, curr | tmp)] = now;
	}
	int ans = 0;
	while (mark[value][ans] == now)
		ans++;
	return a[value][curr] = ans;
}
int main() {
	ios::sync_with_stdio(false);
	int n, ans = 0; cin >> n;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		ans ^= get(x, 0);
	}
	if (ans) cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}