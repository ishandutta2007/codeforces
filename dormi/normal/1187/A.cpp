#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int test;
	cin >> test;
	while (test--) {
		int n, s, t;
		cin >> n >> s >> t;
		printf("%d\n", max(s, t) - ((s + t) - n) + 1);
	}
	return 0;
}