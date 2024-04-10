#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, a, b, c;
	cin >> t;
	while(t--) {
		scanf("%d%d%d", &a, &b, &c);
		int cnt = 0;
		while(a <= c && b <= c) {
			if(a < b) a += b;
			else b += a;
			++cnt;
		}
		printf("%d\n", cnt);
	}
	return 0;
}