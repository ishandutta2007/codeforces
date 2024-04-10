#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> Pi;
const int INF = 9876543;
int a[500005];
int tree[1050000];
Pi Ptree[1050000];
void Pinit(int node, int S, int E) {
	Ptree[node] = { 0,0 };
	if (S == E) return;
	int L = node << 1, R = L | 1, M = S + E >> 1;
	Pinit(L, S, M); Pinit(R, M + 1, E);
}
void Pupd(int node, int S, int E, int i, Pi val) {
	if (S == E) {
		Ptree[node] = max(Ptree[node], val);
		return;
	}
	int L = node << 1, R = L | 1, M = S + E >> 1;
	if (i <= M)Pupd(L, S, M, i, val);
	else Pupd(R, M + 1, E, i, val);
	Ptree[node] = max(Ptree[L], Ptree[R]);
}
Pi Pfind(int node, int S, int E, int i, int j) {
	if (j<S || i>E)return { -INF,-INF };
	if (i <= S && j >= E) return Ptree[node];
	int L = node << 1, R = L | 1, M = S + E >> 1;
	return max(Pfind(L, S, M, i, j), Pfind(R, M + 1, E, i, j));
}

void init(int node, int S, int E) {
	if (S == E) {
		tree[node] = a[S];
		return;
	}
	int L = node << 1, R = L | 1, M = S + E >> 1;
	init(L, S, M); init(R, M + 1, E);
	tree[node] = max(tree[L], tree[R]);
}
int find(int node, int S, int E, int i, int j) {
	if (j<S || i>E)return -INF;
	if (i <= S && j >= E) return tree[node];
	int L = node << 1, R = L | 1, M = S + E >> 1;
	return max(find(L, S, M, i, j), find(R, M + 1, E, i, j));
}
int d[500005];
void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)scanf("%d", a + i);
	Pinit(1, 0, n);
	init(1, 0, n);
	for (int i = 1; i <= n; i++) {
		d[i] = 0;
		int x = a[i];
		if (a[i] >= a[i - 1])d[i] = d[i - 1] + 1;
		Pi P = Pfind(1, 0, n, 0, x);
		P.Y = -P.Y;
		if (find(1, 0, n, P.Y + 1, i - 1) > x)d[i] = max(d[i], d[P.Y] + 2);
		else d[i] = max(d[i], d[P.Y] + 1);
		if (i > 1)Pupd(1, 0, n, a[i - 1], { d[i - 1],-i + 1 });
	}
	printf("%d\n", *max_element(d + 1, d + n + 1));
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--)solve();
}