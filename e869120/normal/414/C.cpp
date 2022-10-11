#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#pragma warning(disable: 4996)

long long n, q, a[1 << 20], p[1 << 20], FF[21], ret; bool used[21];
void dfs(int l, int r, int dep) {
	if (dep == 0)return;
	vector<int>Z1, Z2; int mid = (l + r) / 2;
	for (int i = l; i < mid; i++)Z1.push_back(a[i]);
	for (int i = mid; i < r; i++)Z2.push_back(a[i]);
	dfs(l, mid, dep - 1); dfs(mid, r, dep - 1);

	sort(Z1.begin(), Z1.end());
	sort(Z2.begin(), Z2.end());

	int F = 0; long long c = 0, d = 0;
	for (int i = 0; i < Z1.size(); i++) {
		while (F < Z2.size() && Z1[i] > Z2[F])F++;
		while (d < Z2.size() && Z1[i] >= Z2[d])d++;
		c += F; FF[dep] += Z2.size() - (d - F);
	}
	p[dep] += c; ret += c;
}
int main() {
	cin >> n; for (int i = 0; i < (1 << n); i++)scanf("%lld", &a[i]);
	dfs(0, (1 << n), n);
	cin >> q;
	for (int i = 0; i < q; i++) {
		int b; scanf("%d", &b);
		for (int j = 0; j <= b; j++) {
			if (used[j] == false)ret += (FF[j] - p[j]) - p[j];
			if (used[j] == true)ret -= (FF[j] - p[j]) - p[j];
			used[j] ^= true;
		}
		printf("%lld\n", ret);
	}
	return 0;
}