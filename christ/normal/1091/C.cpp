#include <bits/stdc++.h>
using namespace std;
const int MN = 1e5 + 5;
int main () {
	int n; scanf ("%d",&n);
	set<long long> ret;
	auto go = [&] (int x) {
		int cnt = n / x;
		//x + 2x + 3x + ... + (cnt-1)x
		ret.insert((long long)cnt * (cnt-1) / 2 * x + cnt);
	};
	for (int i = 1; i * i <= n; i++) if (n % i == 0) {
		go(i);
		if (i * i != n) go(n/i);
	}
	for (long long i : ret) printf ("%lld ",i);
	printf ("\n");
	return 0;
}
//0 + x + ... + n