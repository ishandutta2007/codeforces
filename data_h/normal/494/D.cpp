#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

const int N = 111111;
const int MOD = 1e9 + 7;
const int LOG = 20;
#define left LEFT
#define right RIGHT

int n;
vector<pair<int, int> > e[N];
int father[N][LOG], size[N], dep[N];
long long dist[N], total[N], all1[N], all2[N], sons2[N];
int left[N], right[N], ind;

void add(long long &a, long long b) {
	a += b % MOD;
	a %= MOD;
	if (a < 0) {
		a += MOD;
	}
}

long long fix(long long x) {
	return (x % MOD + MOD) % MOD;
}

void pre(int x) {
	left[x] = ++ind;
	size[x] = 1;
	sons2[x] = total[x] = 0;
	for(int i = 0; i < (int)e[x].size(); i++) {
		int y = e[x][i].first;
		if (y == father[x][0]) {
			continue;
		} else {
			father[y][0] = x;
			dist[y] = dist[x] + e[x][i].second; //dist[y] %= MOD;
			dep[y] = dep[x] + 1;
			pre(y);
			size[x] += size[y];
			add(total[x], total[y] + 1LL * e[x][i].second * size[y] % MOD);
			//add(sons[x], e[x][i].second);
			add(sons2[x], 1LL * e[x][i].second * e[x][i].second % MOD * size[y] % MOD + sons2[y] + 2LL * e[x][i].second * total[y] % MOD);
		}
	}
	right[x] = ind;
}

void fill(int x, long long v2, long long v1) {
	all2[x] = v2;
	all1[x] = v1;
	for(int i = 0; i < (int)e[x].size(); i++) {
		int y = e[x][i].first;
		if (y == father[x][0]) {
			continue;
		} else {
			long long _v1 = v1, _v2 = v2;
			add(_v1, 1LL * e[x][i].second * (n - size[y] - size[y]));
			add(_v2, 1LL * e[x][i].second * e[x][i].second % MOD * n); // 10 + 5 = 15
			add(_v2, 2LL * e[x][i].second % MOD * fix(v1 - total[y] - 1LL * e[x][i].second * size[y] % MOD)); // 25
			add(_v2, -2LL * e[x][i].second % MOD * fix(total[y] + 1LL * e[x][i].second * size[y] % MOD)); // 
			fill(y, _v2, _v1);
		}
	}
}

int getLCA(int a, int b) {
	if (dep[a] < dep[b]) {
		swap(a, b);
	}
	for(int i = LOG - 1; i >= 0; i--) {
		if (dep[a] - (1 << i) >= dep[b]) {
			a = father[a][i];
		}
	}
	if (a == b) {
		return a;
	}
	for(int i = LOG - 1; i >= 0; i--) {
		if (father[a][i] != father[b][i]) {
			a = father[a][i];
			b = father[b][i];
		}
	}
	return father[a][0];
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		e[a].push_back(make_pair(b, c));
		e[b].push_back(make_pair(a, c));
	}
	pre(1);
	long long preCount2 = 0, preCount1 = 0;
	for(int i = 1; i <= n; i++) {
		add(preCount2, 1LL * (dist[i] % MOD) * (dist[i] % MOD) % MOD);
		add(preCount1, dist[i] % MOD);
	}
	fill(1, preCount2, preCount1);
	for(int i = 0; i < LOG - 1; i++) {
		for(int j = 1; j <= n; j++) {
			father[j][i + 1] = father[father[j][i]][i];
		}
	}
	/*
puts("");
for(int i = 1; i <= n; i++) {
	cout << all1[i] << " " << all2[i] << endl;
}
*/
	int q;
	scanf("%d", &q);
	while(q--) {
		int u, v;
		scanf("%d %d", &u, &v);
		int p = getLCA(u, v);
		long long ds = dist[u] + dist[v] - 2 * dist[p];
		ds %= MOD;
		long long answer = 0;
		if (left[v] <= left[u] && left[u] <= right[v]) {
			answer = all2[u] - 2LL * fix(1LL * ds * ds % MOD * (n - size[v]) % MOD + (all2[v] - sons2[v]) + 2LL * ds % MOD * (all1[v] - total[v]) % MOD);
		} else {
			answer = 2LL * fix(1LL * ds * ds % MOD * size[v] % MOD + 2LL * ds % MOD * total[v] % MOD + sons2[v]) - all2[u];
		}
		printf("%I64d\n", (answer % MOD + MOD) % MOD);
	}
	return 0;
}