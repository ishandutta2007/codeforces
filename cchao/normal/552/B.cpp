#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	long long ans = 0;
	for(int i = 1; i <= n; i *= 10) {
		ans += n - i + 1;
		if(i == 1000000000) break;
	}
	cout << ans << endl;
	return 0;
}