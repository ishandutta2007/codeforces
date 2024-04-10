#include <bits/stdc++.h>

using namespace std;

const int N = 20005;
int a[N];
map<long long, bool> H;
int main() {
	
	long long p;
	int k;
	scanf("%lld%d", &p, &k);
	int d = 0;
	while (p) {
		if (H[p]) {
			return puts("-1"), 0;
		}
		H[p] = true;
		a[d] = (p % k + k) % k;
		p -= a[d];
		p /= (-k);
		d++;
	}
	printf("%d\n", d);
	for (int i = 0; i < d; i++) printf("%d%c", a[i], " \n"[i == d - 1]);
	return 0;
}