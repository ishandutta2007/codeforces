#include <bits/stdc++.h>
using namespace std;

int e, f;
char s[222];

int main() {
	ios::sync_with_stdio(0);
	int n; cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == '8') e++;
		else f++;
	}
	int dap = 0;
	for (int i = 1; i <= e; i++) if (n - i >= 10 * i) dap = i;
	printf("%d\n", dap);
	return 0;
}