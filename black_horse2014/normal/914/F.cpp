#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

bitset<N> a[26], b;
char s[N+10];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%s", s);
	int n = strlen(s);
	for (int i = 0; i < n; i++) a[s[i]-'a'][i] = 1;
	for (int i = 0; i < n; i++) b[i] = 1;
	int q; scanf("%d", &q);
	while (q--) {
		int t; scanf("%d", &t);
		if (t == 1) {
			int i; char c[3]; scanf("%d%s", &i, c), i--;
			a[s[i]-'a'][i] = 0;
			s[i] = c[0];
			a[s[i]-'a'][i] = 1;
		} else {
			int l, r; char c[N+10]; scanf("%d%d%s", &l, &r, c), l--, r--;
			int k = strlen(c);
			r = r - k + 1;
			if (l > r) {
				puts("0");
				continue;
			}
			bitset<N> cur = ((b << (n-r-1) & b) >> (n-r-1)) & ((b >> l) << l);
			for (int j = 0; j < k; j++) {
				cur &= a[c[j]-'a'];
				if (j < k-1) cur <<= 1;
			}
			printf("%d\n", cur.count());
		}
	}
	return 0;
}