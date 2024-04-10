#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

const int mod = 1000000007;
const int inf = 1000000000;

int f[(1 << 24) + 10], g[(1 << 24) + 10], n, k, a[300], b[300], c[300], s[(1 << 24) + 10];

inline int good(int x) {
	for(int i = 1; i <= k; i++)
		if (x == b[i])
			return 0;
	return 1;
}

inline int lowbit(const int &x) {
	return x & (-x);
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		g[1 << i] = a[i];
	}
	scanf("%d", &k);
	for(int i = 1; i <= k; i++) {
		scanf("%d", &b[i]);
	}
	int tot = 0;
	for(int i = 0; i < n; i++) {
		tot += a[i];
		if (tot > inf)
			tot = inf + 1;
	}
	if (!good(tot)) {
		printf("0\n");
		return 0;
	}
	
	long long ans = 0;
	f[0] = 1; s[0] = 0;
	for(int i = 1; i < (1 << n); i++) {
		int sum = 0, t, len = 0;
		int p = lowbit(i);
		s[i] = s[i - p] + g[p];
		if (s[i] > inf) s[i] = inf + 1;
		if (!good(s[i]))
			continue;
		p = i; int c;
		while(p) {
			c = lowbit(p);
			f[i] += f[i - c]; 
			if (f[i] >= mod) f[i] -= mod;
			p -= c;
		}
	}
	cout << f[(1 << n) - 1] << endl;
	return 0;
}