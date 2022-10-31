#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int ncase;
	for (cin >> ncase; ncase--; ) {
		int n; string s; cin >> n >> s;
		if (n >= 3) {
			puts("YES\n2");
			string a(s.begin(), s.begin() + 1), b(s.begin() + 1, s.end());
			printf("%s %s\n", a.c_str(), b.c_str());
		} else {
			if (n == 1) {
				puts("NO");
			} else {
				if (s[0] >= s[1]) {
					puts("NO");
				} else {
					puts("YES\n2");
					printf("%c %c\n", s[0], s[1]);
				}
			}
		}
	}
	return 0;
}