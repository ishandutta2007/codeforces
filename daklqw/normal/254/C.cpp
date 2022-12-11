#include <bits/stdc++.h>

const int MAXN = 100010;
int hav[MAXN], n;
int ndb[MAXN], bak, oh[MAXN];
char buf1[MAXN], buf2[MAXN];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	std::cin >> buf1 >> buf2;
	n = strlen(buf1);
	for (int i = 0; i != n; ++i) {
		++hav[buf1[i] - 'A'], --hav[buf2[i] - 'A'];
		++oh[buf1[i] - 'A'];
	}
	int ans = 0;
	for (int i = 0; i != 26; ++i) {
		if (hav[i] > 0) ans += hav[i];
		if (hav[i] < 0)
			for (int j = 1; j <= -hav[i]; ++j)
				ndb[++bak] = i;
	}
	int cur = 1;
	for (int i = 0; i != n; ++i) {
		const int ch = buf1[i] - 'A';
		if (hav[ch] > 0) {
			if (cur <= bak) {
				if (ch > ndb[cur] || oh[ch] == hav[ch]) {
					--hav[ch];
					buf1[i] = ndb[cur++] + 'A';
				}
			}
		}
		--oh[ch];
	}
	std::cout << ans << '\n' << buf1 << '\n';
	return 0;
}