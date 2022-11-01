#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 55;

int n, a[N];
long long m;

int main() {
	cin >> n >> m;
	int l = 0, r = n + 1;
	for(int i = 1; i <= n - 1; i++) {
		if (m > (1 << (n - 1 - i))) {
			a[--r] = i;
			m -= (1 << (n - 1 - i));
		} else {
			a[++l] = i;
		}
	}
	a[++l] = n;
	for(int i = 1; i <= n; i++) {
		printf("%d%c", a[i], i == n ? '\n' : ' ');
	}
}