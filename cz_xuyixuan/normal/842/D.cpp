#include<bits/stdc++.h>
using namespace std;
#define MAXN	6000000
#define MAXLOG	20
int now[MAXLOG], ans;
int root, total, child[MAXN][2], size[MAXN];
void update(int root) {
	size[root] = 0;
	if (child[root][0]) size[root] += size[child[root][0]];
	if (child[root][1]) size[root] += size[child[root][1]];
}
void insert(int root, int pos) {
	if (pos == -1) {
		size[root] = 1;
		return;
	}
	if (!child[root][now[pos]]) child[root][now[pos]] = ++total;
	insert(child[root][now[pos]], pos - 1);
	update(root);
}
void work(int root, int pos) {
	if (pos == 0) {
		if (child[root][now[pos]]) ans++;
		return;
	}
	if (!child[root][now[pos]]) return;
	if (size[child[root][now[pos]]] != 1 << pos) {
		work(child[root][now[pos]], pos - 1);
		return;
	}
	ans += 1 << pos;
	if (!child[root][!now[pos]]) return;
	work(child[root][!now[pos]], pos - 1);
}
int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		for (int j = 0; j < MAXLOG; j++) {
			now[j] = x & 1;
			x >>= 1;
		}
		insert(root, MAXLOG - 1);
	}
	int num = 0;
	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		num ^= x;
		int tmp = num;
		for (int j = 0; j < MAXLOG; j++) {
			now[j] = tmp & 1;
			tmp >>= 1;
		}
		ans = 0;
		work(root, MAXLOG - 1);
		cout << ans << endl;
	}
	return 0;
}