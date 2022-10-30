#include <bits/stdc++.h>
using namespace std;

char s[11000], t[11000];

int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	int q;
	for (scanf("%d", &q); q--; ) {
		int l, r, k; scanf("%d%d%d", &l, &r, &k);
		for (int i = l; i <= r; i++) t[i-l] = s[i];
		int m = r - l + 1;
		for (int i = 0; i <= r-l; i++) {
			int j = ((i - k) % m + m) % m;
			s[i + l] = t[j];
		}
	}
	puts(s + 1);
	return 0;
}