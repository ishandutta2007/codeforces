#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1111111;
const long long INF = (1LL << 60);
int a[N];
int n;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	a[n + 1] = 0;
	long long m1 = -INF, m2 = -INF;
	long long upper = -INF, lower = INF;
	for(int i = 1; i <= n; i++) {
		upper = max(upper, 1LL * a[i]);
		lower = min(lower, 1LL * a[i]);
		long long temp = max(upper - lower, max(m1 + a[i], m2 - a[i]));
		m1 = max(m1, temp - a[i + 1]);
		m2 = max(m2, temp + a[i + 1]);
		if (i == n) {
			cout << temp << endl;
		}
	}
	return 0;
}