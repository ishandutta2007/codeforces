#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
typedef vector<int> VI;

template <typename T, typename U>
inline void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template <typename T, typename U>
inline void chkmin(T& x, U y) {
	if (y < x) x = y;
}

const int MAXM = 1111111;
const int MAXN = 2222;

char str[MAXM];
char s[MAXN];

VI next[26][MAXN];
PII last[26][MAXN];
PII st[MAXN];

int a[MAXN], L[MAXN], seen[MAXN];
int n, m;

void update(PII &A, PII B, int c) {
	int id = B.first, pos = B.second + 1;
	if (pos >= L[a[id]]) id++, pos = 0;
	if (id >= m+1) return;
	int u = a[id];
	int npos = next[c][u][pos];
	if (npos == L[u]) {
		id++;
		chkmin(A, last[c][id]);
	} else {
		chkmin(A, PII(id, npos));
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", str), L[i] = strlen(str);
		for (int j = 0; j < 26; j++) seen[j] = L[i], next[j][i].resize(L[i]);
		for (int j = L[i]-1; j >= 0; j--) {
			seen[str[j]-'a'] = j;
			for (int k = 0; k < 26; k++) next[k][i][j] = seen[k];
		}
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
	for (int j = 0; j < 26; j++) last[j][m+1] = PII(m+1, 0);
	for (int i = m; i > 0; i--) {
		int u = a[i];
		for (int j = 0; j < 26; j++) {
			last[j][i] = PII(i, next[j][u][0]);
			if (last[j][i].second == L[u]) last[j][i] = last[j][i+1];
		}
	}
	scanf("%s", s+1);
	st[0] = PII(0, 0);
	for (int i = 1; s[i]; i++) st[i] = PII(m+1, 0);
	int ans = 0;
	for (int i = 1; s[i]; i++) {
		for (int j = ans; j >= 0; j--) update(st[j+1], st[j], s[i]-'a');
		if (st[ans+1].first <= m) ans++;
	}
	cout << ans << endl;
	return 0;
}