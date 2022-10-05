#include<bits/stdc++.h>
using namespace std;

const int maxn = 100005, maxm = 105;
int vis[maxn], q[maxn], e[maxm][maxm], in[maxn], vis2[maxn];
int n, l, r, u, cnt, last;
vector<pair<int,int> > ans;
char s[maxn], t[maxn];

void solve(int x) {
	int tmp = 0;
	l = r = 0; q[r++] = x;
	vis[x] = ++cnt;
	while (l < r) {
		u = q[l++]; tmp++;
		for (int i=1; i<=26; i++)
			if (!vis[i] && (e[u][i] || e[i][u]))
				vis[i] = cnt, q[r++] = i;
	}
	if (tmp == 1) return;
	memset(in, 0, sizeof in);
	for (int i=1; i<=26; i++) if (vis[i] == cnt)
		for (int j=1; j<=26; j++) if (e[i][j]) in[j]++;
	l = r = 0;
	for (int i=1; i<=26; i++)
		if (vis[i] == cnt && !in[i]) q[r++] = i;
	while (l < r) {
		u = q[l++];
		for (int i=1; i<=26; i++)
			if (e[u][i]) {
				in[i]--; if (!in[i]) q[r++] = i;
			}
	}
	if (r == tmp) {
		for (int i=0; i<r-1; i++)
			ans.push_back(make_pair(q[i], q[i+1]));
		return;
	}
	last = 0;
	for (int i=1; i<=26; i++)
		if (vis[i] == cnt) {
			if (last) ans.push_back(make_pair(last, i));
			last = i;
		}
}

int main() {
	scanf("%d%s%s", &n, s+1, t+1);
	for (int i=1; i<=n; i++)
		if (s[i] != t[i]) e[s[i]-'a'+1][t[i]-'a'+1] = 1;
	for (int i=1; i<=26; i++)
		if (!vis[i]) solve(i);
	printf("%d\n", ans.size());
	for (int i=0; i<ans.size(); i++)
		printf("%c %c\n", 'a' + ans[i].first - 1, 'a' + ans[i].second - 1);
	return 0;
}