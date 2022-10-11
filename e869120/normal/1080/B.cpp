#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

long long query(long long l, long long r) {
	if (l > r) return 0;
	if (l == r) {
		if (l % 2 == 0) return l;
		return -l;
	}
	if (l % 2 == 0) {
		return l + query(l + 1, r);
	}
	else if (r % 2 == 1) {
		return -r + query(l, r - 1);
	}
	else return (r - l + 1LL) / 2LL;
}

int main() {
	long long Q, L, R;
	cin >> Q;
	for (int i = 1; i <= Q; i++) {
		scanf("%lld%lld", &L, &R);
		printf("%lld\n", query(L, R));
	}
	return 0;
}