#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
using namespace std;

const int maxn = 1009;
int x[maxn], y[maxn], res[maxn], del[maxn];
int n, K, l, r, mid, cnt, m, D[maxn*maxn];
vector<int> e[maxn];

int DEL(int x[], int n) {
	int cnt = 1;
	rep (i, 2, n) if (x[i] != x[cnt]) x[++cnt] = x[i];
	return cnt;
}

int dfs(int u, int k) {
	if (u == n + 1) return 1;
	if (del[u] > 0) return dfs(u + 1, k);
	rep (i, 0, e[u].size()-1) {
		k -= (!del[e[u][i]]);
		del[e[u][i]]++;
	}
	if (k >= 0 && dfs(u + 1, k)) return 1;
	del[u] = 1; int t = k;
	rep (i, 0, e[u].size()-1) {
		del[e[u][i]]--;
		k += !del[e[u][i]];
	}
	if ((--k>=0) && k>t && dfs(u + 1, k)) return 1;
	del[u] = 0; 
	return 0;
}

int check(int k, int flag = 0) {
	rep (i, 1, n) {
		e[i].clear(); del[i] = 0;
		rep (j, 1, n) 
			if ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) > k) 
				e[i].push_back(j); 
	}
	if (!flag) return dfs(1, K); dfs(1, K);
	rep (i, 1, n) if (del[i] && K) printf("%d ", i), K--;
	rep (i, 1, n) if (!del[i] && K) printf("%d ", i), K--;
}

int main() {
	scanf("%d%d", &n, &K);
	rep (i, 1, n) scanf("%d%d", &x[i], &y[i]); 
	rep (i, 1, n) rep (j, 1, n)
		D[++m] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
	sort(D+1, D+m+1); m = DEL(D, m);
	l = l; r = m;
	while (l < r) {
		mid = (l + r) >> 1;
		if (check(D[mid])) r = mid;
		else l = mid + 1;
	}
	check(D[l], 1);
	return 0;
}