#include <bits/stdc++.h>
using namespace std;

const int N = 330000;

string r[N], tp[N];

int cover(string &s, char x, char y) {
	string c = {x, y};
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < s.length(); i++) ans1 += (s[i] != c[i & 1]), ans2 += (s[i] != c[i & 1 ^ 1]);
	if (ans1 < ans2) {
		for (int i = 0; i < s.length(); i++) s[i] = c[i & 1];
	} else {
		for (int i = 0; i < s.length(); i++) s[i] = c[i & 1 ^ 1];
	}
	return min(ans1, ans2);
}

int solve(int n, int m, string s[]) {
	int ans = n * m + 1;
	char p[11] = "ACGT";
	do {
		if (p[0] > p[1] || p[2] > p[3]) continue;
		for (int i = 0; i < n; i++) tp[i] = s[i];
		int cur = 0;
		for (int i = 0; i < n; i++) {
			char x, y;
			if (i & 1) x = p[2], y = p[3];
			else x = p[0], y = p[1];
			cur += cover(tp[i], x, y);
		}
		if (ans > cur) {
			ans = cur;
			for (int i = 0; i < n; i++) r[i] = tp[i];
		}
	} while (next_permutation(p, p + 4));
	for (int i = 0; i < n; i++) s[i] = r[i];
	return ans;
}

string s[N], t[N];

int main() {
	ios::sync_with_stdio(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) t[j].push_back(s[i][j]);
	int ans1 = solve(n, m, s);
	int ans2 = solve(m, n, t);
	if (ans1 > ans2) {
		for (int i = 0; i < n; i++) s[i].clear();
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) s[j].push_back(t[i][j]);
	}
	for (int i = 0; i < n; i++) cout << s[i] << '\n';
	return 0;
}