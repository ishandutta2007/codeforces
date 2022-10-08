/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()

int main() {
	int tn = 1;
	// cin >> tn;
	while (tn--) {
		int n, sum = 0;
		cin >> n;
		vector<int> a(n);
		forn(i, n)
			cin >> a[i], sum += a[i];
		int s = sum / 2;
		bitset<2000 * 100 + 1> is;
		is[0] = 1;
		forn(i, n)
			is |= is << a[i];
		if (!is[s] || sum % 2) {
			puts("0");
			continue;
		}
		puts("1");

		int i = 0;
		forn(j, n)
			if (__builtin_ctz(a[i]) > __builtin_ctz(a[j]))
				i = j;
		printf("%d\n", i + 1);
	}
}