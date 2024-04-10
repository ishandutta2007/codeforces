#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 111;

int n, a[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i]--;
	}
	long long ans = 1;
	for (int i = 0; i < n; i++) {
		static int visit[N];
		fill(visit, visit + n, 0);
		int x = i, cnt = 0;
		while (visit[x] == 0) {
			cnt++;
			visit[x] = 1;
			x = a[x];
		}
		if (cnt % 2 == 0) {
			cnt /= 2;
		}
		if (cnt == 0) cnt = 1;
		if (x != i) {
			ans = -1;
		} else if (ans != -1 && ans % cnt != 0) {
			ans = ans * cnt / __gcd(ans, 0LL + cnt);
		}
	}
	cout << ans << endl;
	return 0;
}