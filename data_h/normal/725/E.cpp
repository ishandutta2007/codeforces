#include <iostream>
#include <set>
#include <cassert>
#include <algorithm>
using namespace std;

const int N = 2e5 + 7;

int c, n;
int x[N];
int remain[N];
bool ok[N];
int visit[N];
long long sum[N];

bool solve(int rem, int pos = -2) {
	//printf("%d %d\n", rem, pos);
	if (pos == -1) {
		return rem > 0;
	}
	if (rem == 0) {
		return false;
	}
	if (x[0] > rem) {
		return true;
	}
	bool spe = (pos == -2);
	if (spe) {
		if (visit[rem]) {
			return ok[rem];
		} else {
			visit[rem] = 1;
		}
	}
	int l = 0, r = (spe ? n : pos);
	while (l < r) {
		int mid = (l + r + 1) / 2;
		if (x[mid] <= rem) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	int i = l;
	l = 0, r = i;
	while (l < r) {
		int mid = (l + r) / 2;
		if (sum[i] - (mid == 0 ? 0 : sum[mid - 1]) > rem) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	int new_rem = rem - (sum[i] - (l == 0 ? 0 : sum[l - 1]));
	if (l == 0) {
		if (spe) {
			return ok[rem] = (new_rem > 0);
		} else {
			return new_rem > 0;
		}
	}
	assert(new_rem < x[l - 1]);
	if (spe) {
		return ok[rem] = solve(new_rem);
	} else {
		return solve(new_rem);
	}
}

int main() {
	scanf("%d", &c);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}
	sort(x, x + n);
	sum[0] = x[0];
	for (int i = 0; i < n; i++) {
		sum[i + 1] = sum[i] + x[i + 1];
	}
	int cc = c;
	remain[n] = c;
	x[n] = c + 1;
	for (int i = n - 1; i >= 0; i--) {
		if (cc >= x[i]) {
			cc -= x[i];
		}
		remain[i] = cc;
	}
	fill(visit, visit + c + 1, 0);
	for (int i = 1; i <= c; i++) {
		int l = 0, r = n;
		while (l < r) {
			int mid = (l + r) / 2;
			if (i > x[mid]) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		int rem = remain[l];
		if (rem >= i && solve(rem - i, l - 1)) {
			cout << i << endl;
			return 0;
		}
	}
	puts("Greed is good");
	return 0;
}