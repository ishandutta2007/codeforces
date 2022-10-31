#include <bits/stdc++.h>
using namespace std;

int n;
char s[110];
int chk[110];

int main() {
	scanf("%d%s", &n, s+1);
	int ans = 0;
	for (int i = 2; i <= n; i++) {
		if (!chk[i-1] && s[i-1] != s[i]) {
			chk[i] = 1;
			ans++;
		}
	}
	cout << n - ans << endl;
	return 0;
}