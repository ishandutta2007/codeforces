#include<bits/stdc++.h>
using namespace std;

const int maxn = 4009, maxlen = 509;
int T[int((maxn*maxlen)*0.8)][26], val[maxn*maxlen], cnt[maxn*maxlen];
int Map[maxn*maxlen], f[maxn][maxn];
int n, K, size = 1, tot;
char s[maxn];

void insert(char s[]) {
	int o = 1;
	for (int i=0; s[i]; i++) {
		if (!T[o][s[i]-'a']) 
			T[o][s[i]-'a'] = ++size, val[size] = 1;
		o = T[o][s[i]-'a'];
	}
	cnt[o]++;
}

void dfs1(int u, int fa, int from) {
	int out = 0, cur;
	for (int i=0; i<26; i++)
		if (T[u][i]) { out++; cur = T[u][i]; }
	if (fa && out == 1 && !cnt[u]) {
		T[fa][from] = cur;
		val[cur] = val[u] + 1;
		dfs1(cur, fa, from);
		return;
	}
	Map[u] = ++tot;
	for (int i=0; i<26; i++)
		if (T[u][i]) dfs1(T[u][i], u, i);
}

void dfs2(int u) {
	for (int i=0; i<=cnt[u]; i++)
		f[Map[u]][i] = val[u] * i * (i - 1) / 2;
	for (int i=0; i<26; i++) {
		if (!T[u][i]) continue;
		dfs2(T[u][i]); cnt[u] += cnt[T[u][i]];
		for (int j=min(cnt[u], K); j>=1; j--)
			for (int k=1; k<=cnt[T[u][i]]&&k<=j; k++)
				f[Map[u]][j] = max(f[Map[u]][j], f[Map[u]][j-k] + f[Map[T[u][i]]][k] + val[u] * (k * (j - k) + k * (k - 1) / 2));
	}
}

int main() {
	scanf("%d%d", &n, &K);
	for (int i=1; i<=n; i++) 
		scanf("%s", s), insert(s);
	dfs1(1, 0, 0); dfs2(1);
	printf("%d\n", f[1][K]);
	return 0;
}