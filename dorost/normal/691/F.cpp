/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 3000000, SQ = 1732;
int num[N];
ll ps[N];

int32_t main() {
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		num[x]++;
	}
	for (int i = 1; i < SQ; i++) {
		int x = i;
		int y = i;
		for (int j = i * i; j < N; j += i) {
			if (x == y) {
				ps[j] += (num[x] * (ll)(num[x] - 1));
			} else {
				ps[j] += (num[x] * (ll)num[y] * 2);
			}
			y++;
		}
	}
	for (int i = 1; i < N; i++) {
		ps[i] += ps[i - 1];
	}
	ll wef = n * (ll)(n - 1);
	int m, p;
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &p);
		printf("%lld ", wef - ps[p - 1]);
	}
}