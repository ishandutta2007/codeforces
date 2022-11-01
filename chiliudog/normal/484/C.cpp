#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1000010;

char s[N], ns[N];
int n, m, S[N], L[N], Z[N], LS[N], tmp[N];

void multi() {
	for (int i = 0; i < n; ++i) tmp[i] = LS[LS[i]];
	for (int i = 0; i < n; ++i) LS[i] = tmp[i];
}
int main() {
	scanf("%s", s), n = strlen(s);
	for (int i = 0; i < n; ++i) {
		L[i] = i? i - 1: n - 1;
	}
	for (scanf("%d", &m); m--; ) {
		int k, d;
		scanf("%d %d", &k, &d);

		for (int i = 0; i < n; ++i) S[i] = i;
		int tot = 0;
		for (int x = 0; x < d; ++x)
			for (int y = x; y < k; y += d) {
				S[y] = tot++;
			}
		for (int i = 0; i < n; ++i) Z[i] = S[i];

		for (int i = 0; i < n; ++i) LS[i] = S[L[i]];
		for (int t = n - k; t; t >>= 1, multi())
			if (t & 1) {
				for (int i = 0; i < n; ++i) Z[i] = LS[Z[i]];
			}

		for (int i = 0; i < n; ++i) ns[Z[i]] = s[i];
		for (int i = 0; i < n; ++i) s[(i + (n - k)) % n] = ns[i];
		printf("%s\n", s);
	}
}