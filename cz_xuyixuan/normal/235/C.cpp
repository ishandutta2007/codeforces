#include<bits/stdc++.h>
using namespace std;
#define MAXN	2000005
struct Suffix_Automaton {
	int child[MAXN][26];
	int father[MAXN], depth[MAXN];
	int cnt[MAXN], visited[MAXN];
	int root, size, last, len;
	int new_node(int dep) {
		depth[size] = dep;
		return size++;
	}
	void init() {
		size = 0;
		root = new_node(0);
	}
	void Extend(int ch) {
		int np = new_node(depth[last] + 1);
		int p = last;
		for (; child[p][ch] == 0; p = father[p])
			child[p][ch] = np;
		if (child[p][ch] == np) last = np;
		else {
			int q = child[p][ch];
			if (depth[p] + 1 == depth[q]) {
				father[np] = q;
				last = np;
			} else {
				int nq = new_node(depth[p] + 1);
				father[nq] = father[q];
				father[q] = father[np] = nq;
				memcpy(child[nq], child[q], sizeof(child[q]));
				for (; child[p][ch] == q; p = father[p])
					child[p][ch] = nq;
				last = np;
			}
		}
	}
	void insert(char *s) {
		len = strlen(s + 1);
		last = 0;
		for (int i = 1; i <= len; i++) {
			Extend(s[i] - 'a');
			cnt[last]++;
		}
	}
	void build() {
		static int sum[MAXN], res[MAXN];
		for (int i = 0; i < size; i++)
			sum[depth[i]]++;
		for (int i = 1; i <= len; i++)
			sum[i] += sum[i - 1];
		for (int i = size - 1; i >= 0; i--)
			res[sum[depth[i]]--] = i;
		for (int i = size; i > 1; i--)
			cnt[father[res[i]]] += cnt[res[i]];
	}
	int getans(char *s, int curri) {
		int ans = 0, now = root, matched = 0;
		int len = strlen(s + 1);
		for (int i = 1; i <= len; i++) {
			int ch = s[i] - 'a';
			while (now && child[now][ch] == 0)
				now = father[now];
			matched = min(matched, depth[now]);
			now = child[now][ch];
			if (now) matched++;
		}
		if (matched >= len && visited[now] != curri) {
			visited[now] = curri;
			ans += cnt[now];
		}
		for (int i = 1; i < len; i++) {
			int ch = s[i] - 'a';
			while (now && child[now][ch] == 0)
				now = father[now];
			matched = min(matched, depth[now]);
			now = child[now][ch];
			if (now) matched++;
			while (depth[father[now]] >= len)
				now = father[now];
			matched = min(matched, depth[now]);
			if (matched >= len && visited[now] != curri) {
				visited[now] = curri;
				ans += cnt[now];
			}
		}
		return ans;
	}
} SAM;
char s[MAXN];
int n, len;
int main() {
	scanf("%s", s + 1);
	SAM.init();
	SAM.insert(s);
	SAM.build();
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		printf("%d\n", SAM.getans(s, i));
	}
	return 0;
}