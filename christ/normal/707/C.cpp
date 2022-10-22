#include <bits/stdc++.h>
using namespace std;
const int MN = 1e5 + 5;
int main () {
	int n; scanf ("%d",&n);
	if (n <= 2) printf ("-1\n");
	else {
		if (n % 2 == 1) printf ("%lld %lld\n",((long long)n*n + 1) / 2,((long long)n*n - 1) / 2);
		else {
			printf ("%lld %lld\n",(2 + (long long)n * n / 2) / 2,((long long)n * n / 2 - 2) / 2);
		}
	}
	return 0;
}