#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int main() {
	long long N; scanf("%lld", &N);
	for (int i = 1; i <= N; i++) {
		long long X; scanf("%lld", &X);
		if (X >= 14LL && X % 14LL >= 1LL && X % 14LL <= 6LL) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}