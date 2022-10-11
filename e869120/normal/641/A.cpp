#include <bits/stdc++.h>
using namespace std;
int n, a[100009]; string s;
int main() {
	cin >> n >> s;
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	int pos = 0;
	for(int i = 0; i < 1000000; i++) {
		if(s[pos] == '>') pos += a[pos];
		else pos -= a[pos];
		if(pos < 0 || n <= pos) break;
	}
	puts((0 <= pos && pos < n) ? "INFINITE" : "FINITE");
	return 0;
}