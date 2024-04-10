#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <map>
#include <cmath>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long n, a[100009], q, l, r, cnt;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) { if (a[i] > a[j])cnt++; }
	}
	cnt %= 2;
	cin >> q;
	for (int i = 1; i <= q; i++) {
		scanf("%lld%lld", &l, &r);
		long long LEN = r - l + 1;
		long long V = LEN*(LEN - 1) / 2;
		if (V % 2 == 1)cnt ^= 1;
		if (cnt == 0)printf("even\n");
		else printf("odd\n");
	}
	return 0;
}