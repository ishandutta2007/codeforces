#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

const int N = 1000005;

char str1[N], str2[N];
int n, c1[N], c2[N];
bool vis[N];
set<int> s[2];

void debug_set() {
	for (int i = 0; i < 2; i++) {
		for (auto it = s[i].begin(); it != s[i].end(); it++)
			printf("%d ", *it);
		printf("\n");
	}
}

int main() {
	n = read();
	scanf("%s", str1 + 1); scanf("%s", str2 + 1);
	for (int i = 1; i <= n; i++)
		c1[i] = str1[i] - '0', c2[i] = str2[i] - '0';
	int cnt1 = 0, cnt2 = 0, res = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		if (c1[i] == 0) cnt1++;
		if (c2[i] == 0) cnt2++;
		if (c1[i] != c2[i])
			s[c1[i]].insert(i), res++;
	}
	if (cnt1 != cnt2) { printf("-1\n"); return 0; }
	// for (int i = 1; i <= tp; i++)
		// printf("%d%c", stk[i], " \n" [i == tp]);
	while (res) {
		if (s[0].empty() || s[1].empty()) {
			ans += s[0].size() + s[1].size();
			break;
		}
		int p0 = *s[0].begin(), p1 = *s[1].begin();
		int fr = p0 < p1 ? 0 : 1, pos = min(p0, p1);
		while (pos <= n) {
			s[fr].erase(pos);
			res--, fr ^= 1;
			if (s[fr].empty() || pos >= *s[fr].rbegin()) break;
			pos = *s[fr].upper_bound(pos);
		}
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}