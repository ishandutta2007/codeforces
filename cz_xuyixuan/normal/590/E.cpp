#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1505;
const int MAXM = 1e7 + 5;
typedef long long ll;
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
namespace NetworkFlow {
	const int INF  = 1e9 + 7;
	const int MAXP = 2e3 + 5;
	struct edge {
		int dest, flow;
		unsigned pos;
	}; vector <edge> a[MAXP];
	int tot, s, t, dist[MAXP];
	unsigned curr[MAXP];
	void addedge(int x, int y, int z) {
		a[x].push_back((edge) {y, z, a[y].size()});
		a[y].push_back((edge) {x, 0, a[x].size() - 1});
	}
	int dinic(int pos, int limit) {
		if (pos == t) return limit;
		int used = 0, tmp;
		for (unsigned &i = curr[pos]; i < a[pos].size(); i++)
			if (a[pos][i].flow != 0 && dist[pos] + 1 == dist[a[pos][i].dest] && (tmp = dinic(a[pos][i].dest, min(limit - used, a[pos][i].flow)))) {
				used += tmp;
				a[pos][i].flow -= tmp;
				a[a[pos][i].dest][a[pos][i].pos].flow += tmp;
				if (used == limit) return used;
			}
		return used;
	}
	bool bfs() {
		static int q[MAXP];
		int l = 0, r = 0;
		memset(dist, 0, sizeof(dist));
		dist[s] = 1, q[0] = s;
		while (l <= r) {
			int tmp = q[l];
			for (unsigned i = 0; i < a[tmp].size(); i++)
				if (dist[a[tmp][i].dest] == 0 && a[tmp][i].flow != 0) {
					q[++r] = a[tmp][i].dest;
					dist[q[r]] = dist[tmp] + 1;
				}
			l++;
		}
		return dist[t] != 0;
	}
	int flow() {
		int ans = 0;
		while (bfs()) {
			memset(curr, 0, sizeof(curr));
			ans += dinic(s, INF);
		}
		return ans;
	}
}
bitset <MAXN> mp[MAXN];
namespace ACAutomaton {
	struct Node {
		int child[2];
		int fail, father, home, last;
	} a[MAXM];
	int root, size;
	void init() {
		root = size = 0;
	}
	void insert(char *s, int x) {
		int now = root, len = strlen(s + 1);
		for (int i = 1; i <= len; i++) {
			int tmp = s[i] - 'a';
			if (a[now].child[tmp] == 0) {
				a[now].child[tmp] = ++size;
				a[size].father = now;
			}
			now = a[now].child[tmp];
		}
		a[now].home = x;
	}
	void build() {
		static int q[MAXM];
		int l = 0, r = -1;
		for (int i = 0; i <= 1; i++)
			if (a[root].child[i]) q[++r] = a[root].child[i];
		while (l <= r) {
			int tmp = q[l++];
			if (a[tmp].home) a[tmp].last = a[tmp].home;
			else a[tmp].last = a[a[tmp].fail].last;
			for (int i = 0; i <= 1; i++)
				if (a[tmp].child[i]) {
					a[a[tmp].child[i]].fail = a[a[tmp].fail].child[i];
					q[++r] = a[tmp].child[i];
				} else a[tmp].child[i] = a[a[tmp].fail].child[i];
		}
		for (int i = 1; i <= size; i++)
			if (a[i].home) {
				int tmp = a[i].father;
				if (a[a[i].fail].last) mp[a[i].home][a[a[i].fail].last] = 1;
				while (tmp != root) {
					if (a[tmp].last) mp[a[i].home][a[tmp].last] = 1;
					tmp = a[tmp].father;
				}
			}
	}
}
char s[MAXM]; bool vis[MAXN];
int n, len[MAXN], pos[MAXN], match[MAXN];
void debug() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			printf("%d", mp[i][j] == 1);
		puts("");
	}
}
void work(int pos) {
	vis[pos] = true;
	if (pos <= n) {
		for (int i = 1; i <= n; i++)
			if (mp[pos][i] && !vis[i + n]) work(i + n);
	} else if (!vis[match[pos]]) work(match[pos]);
}
int main() {
	read(n), ACAutomaton :: init();
	for (int i = 1; i <= n; i++) {
		scanf("\n%s", s + 1);
		pos[i] = i, len[i] = strlen(s + 1);
		ACAutomaton :: insert(s, i);
	}
	ACAutomaton :: build();
	sort(pos + 1, pos + n + 1, [&] (int x, int y) {return len[x] < len[y];} );
	for (int i = 1; i <= n; i++) {
		int now = pos[i];
		for (int j = 1; j <= n; j++)
			if (mp[now][j]) mp[now] |= mp[j];
	}
	using namespace NetworkFlow;
	NetworkFlow :: s = 2 * n + 1;
	NetworkFlow :: t = 2 * n + 2;
	for (int i = 1; i <= n; i++) {
		addedge(2 * n + 1, i, 1);
		addedge(i + n, 2 * n + 2, 1);
	}
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		if (mp[i][j]) addedge(i, j + n, 1);
	cout << n - flow() << endl;
	for (int i = n + 1; i <= 2 * n; i++)
	for (auto x : a[i])
		if (x.dest <= n && x.flow == 1) {
			match[i] = x.dest;
			match[x.dest] = i;
		}
	for (int i = 1; i <= n; i++)
		if (match[i] == 0 && !vis[i]) work(i);
	for (int i = 1; i <= n; i++)
		if (vis[i] && !vis[i + n]) printf("%d ", i);
	return 0;
}