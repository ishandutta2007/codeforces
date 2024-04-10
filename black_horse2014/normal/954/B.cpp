#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; char s[110]; scanf("%d%s", &n, s+1);
	int ans = n;
	for (int i = n/2; i > 0; i--) {
		bool flg = 1;
		for (int j = i+1; j <= i+i; j++) {
			if (s[j] != s[j-i]) flg = 0;
		}
		if (flg) {
			ans -= i-1;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}