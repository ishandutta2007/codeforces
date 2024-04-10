#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

const int N = 1e5 + 7;
const int LOG = 18;
const int MOD = 1e9 + 7;

int n, m;
vector<int> e[N];
vector<pair<int, pair<int, int> > > list;
int father[N][LOG], up[N], down[N];
int upS[N], downS[N], dep[N];


void prepare() {
	for (int i = 0; i < (int)list.size(); i++) {
		int x = list[i].first;
		int a = list[i].second.first, b = list[i].second.second;
		if (father[a][0] == b && x == 1) {
			down[a] = 1;
		} else if (father[b][0] == a && x == 1) {
			up[b] = 1;
		}
	}

	for (int i = 1; i < LOG; i++) {
		for (int j = 1; j <= n; j++) {
			father[j][i] = father[father[j][i - 1]][i - 1];
		}
	}
}

int getLCA(int a, int b) {
	if (dep[a] < dep[b]) {
		swap(a, b);
	}
	for (int i = LOG - 1; i >= 0; i--) {
		if (dep[a] - (1 << i) >= dep[b]) {
			a = father[a][i];
		}
	}
	if (a == b) {
		return a;
	}
	for (int i = LOG - 1; i >= 0; i--) {
		if (father[a][i] != father[b][i]) {
			a = father[a][i];
			b = father[b][i];
		}
	}

	return father[a][0];
}


void solve() {
	int k;
	scanf("%d", &k);
	//k = 1000000;
	for (int i = 1, prev = 1; i <= k; i++) {
		int s;
		scanf("%d", &s);
		int a = prev, b = s;
		int c = getLCA(a, b);
		upS[a]++;
		upS[c]--;
		downS[b]++;
		downS[c]--;
		prev = s;
	}
}

void dfs(int x, int from) {
	father[x][0] = from;
	for (int i = 0; i < (int)e[x].size(); i++) {
		int y = e[x][i];
		if (y == from) {
			continue;
		}
		dep[y] = dep[x] + 1;
		dfs(y, x);
	}
}

int answer = 0;

int power2(int t) {
	if (t == 0) {
		return 1;
	} else {
		int tmp = power2(t / 2);
		if (t & 1) {
			return 1LL * tmp * tmp % MOD * 2 % MOD;
		} else {
			return 1LL * tmp * tmp % MOD;
		}
	}
}

int calc(int times) {
	return (power2(times) - 1 + MOD) % MOD;
}

void collect(int x, int from) {
	for (int i = 0; i < (int)e[x].size(); i++) {
		int y = e[x][i];
		if (y == father[x][0]) {
			continue;
		} else {
			collect(y, x);
			upS[x] += upS[y];
			downS[x] += downS[y];
		}
	}
	if (up[x]) {
		answer += calc(upS[x]);
		//cout << "up " << x << " " << calc(upS[x]) << endl;
		answer %= MOD;
	}
	if (down[x]) {
		answer += calc(downS[x]);
		//cout << "down " << x << " " << calc(downS[x]) << endl;
		answer %= MOD;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b, x;
		scanf("%d %d %d", &a, &b, &x);
		e[a].push_back(b);
		e[b].push_back(a);
		list.push_back(make_pair(x, make_pair(a, b)));
	}

	dep[1] = 0;
	dfs(1, -1);

	prepare();
	solve();
	collect(1, -1);
	printf("%d\n", answer);

	return 0;
}