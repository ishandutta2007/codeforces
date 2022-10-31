#include <bits/stdc++.h>
using namespace std;
vector<int> g[100010];
char color[100010];
int dfs(int x, int p) {
	int b = (1 << 26) - 1;
	int cnt[26] = {};
	for(int y: g[x]) if(y != p) {
		int t = dfs(y, x);
		for(int i = 0; i < 26; ++i)
			if(~t & (1 << i))
				cnt[i]++;
		b &= t;
	}
	int c1 = -1, c2 = -1;
	for(int i = 0; i < 26; ++i)
		if(cnt[i] > 1) {
			c1 = i - 1;
			break;
		}
		else if(cnt[i] == 0) {
			c2 = i;
		}
	if(c1 == -1) c1 = c2;
	while(cnt[c1]) c1--;
	assert(c1 >= 0 && c1 < 26);
	color[x] = 'A' + c1;
	b |= ((1 << 26) - 1) ^ ((1 << c1) - 1);
	b &= ~(1 << c1);
	return b;
}
int main() {
	int n; scanf("%d", &n);
	for(int i = 0; i < n - 1; ++i) {
		int a, b; scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 0);
	for(int i = 1; i <= n; ++i) printf("%c%c", color[i], " \n"[i == n]);
	return 0;
}