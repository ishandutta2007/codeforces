#include <bits/stdc++.h>
using namespace std;

int n, pc[12], prime = 0;
long long a[12], ans = 0, tree[12]={};

long long dfs(int x, int tsz, int rt, int num) {
	if(x == n) {
		return num + (rt > 1) + n - prime;
	}
	long long best = LLONG_MAX;
	for(int i = 0; i < tsz; ++i) if(tree[i] % a[x] == 0) {
		tree[i] /= a[x];
		tree[tsz] = a[x];
		best = min(best, dfs(x + 1, tsz + 1, rt + (i == 0), num + (i == 0 ? pc[x] : 0)));
		tree[i] *= a[x];
	}
	return best;
}

int main() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n, greater<long long>());
	for(int i = 0; i < n; ++i) {
		long long t = a[i];
		int cnt = 0;
		for(long long i = 2; i * i <= t; ++i) {
			while(t % i == 0) {
				cnt++;
				t /= i;
			}
		}
		if(t > 1) cnt++;
		pc[i] = cnt;
		prime += cnt == 1;
	}
	cout << dfs(0, 1, 0, 0) << endl;;
	return 0;
}