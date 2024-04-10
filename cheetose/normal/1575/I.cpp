#include<bits/stdc++.h>

using namespace std;

const int SZ = 1 << 17;
vector<int> adj[100000];
int node_cnt, num[100000], hld[100000], W[100000], parent[100000], depth[100000], A[100000];
long long tree[2 * SZ];

void dfs(int c)
{
	W[c] = 1;
	for (auto n : adj[c]) if (W[n] == 0) {
		parent[n] = c;
		depth[n] = depth[c] + 1;
		dfs(n);
		W[c] += W[n];
	}
}

void dfs2(int c)
{
	int mx = -1;
	num[c] = node_cnt++;
	tree[SZ + num[c]] = A[c];
	for (auto n : adj[c]) if (W[n] < W[c] && (mx == -1 || W[mx] < W[n])) mx = n;
	if (mx == -1) return;
	hld[mx] = hld[c];
	dfs2(mx);
	for (auto n : adj[c]) if (W[n] < W[c] && mx != n) dfs2(hld[n] = n);
}

void set_tree(int n, int v)
{
	for (tree[n += SZ] = v; n >>= 1;) tree[n] = tree[2 * n] + tree[2 * n + 1];
}

long long get_sum(int s, int e)
{
	long long ret = 0;
	for (s += SZ, e += SZ; s <= e; s >>= 1, e >>= 1) {
		if (s & 1) ret += tree[s++];
		if (~e & 1) ret += tree[e--];
	}
	return ret;
}

long long query(int a, int b)
{
	long long ret = 0;
	while (hld[a] != hld[b]) {
		if (depth[hld[a]] < depth[hld[b]]) swap(a, b);
		ret += get_sum(num[hld[a]], num[a]);
		a = parent[hld[a]];
	}
	if (num[a] > num[b]) swap(a, b);
	return ret + get_sum(num[a], num[b]);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i]; A[i] = abs(A[i]);
	}
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		adj[--a].push_back(--b);
		adj[b].push_back(a);
	}
	dfs(0); dfs2(0);
	for (int i = SZ; --i;) tree[i] = tree[2 * i] + tree[2 * i + 1];
	while (M--) {
		int t, a, b;
		cin >> t >> a >> b; --a;
		if (t == 1) set_tree(num[a], A[a] = abs(b));
		else {
			--b;
			cout << 2 * query(a, b) - A[a] - A[b] << '\n';
		}
	}
	return 0;
}