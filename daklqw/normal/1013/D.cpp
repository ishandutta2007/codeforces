#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define MAXN 200010
int n, m, Q, xs[MAXN], ys[MAXN], a[MAXN], b[MAXN], ans = 0, fa[MAXN << 1];
bool ux[MAXN], uy[MAXN], uz[MAXN << 1];
vector<int> v1[MAXN], v2[MAXN];
set<pair<int, int> >S;
int findx(int x) {return x == xs[x] ? x : xs[x] = findx(xs[x]);}
int findy(int x) {return x == ys[x] ? x : ys[x] = findy(ys[x]);}
int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
int main() {
	scanf("%d%d%d", &n, &m, &Q);
	for (int i = 1; i <= n; ++i) xs[i] = i;
	for (int i = 1; i <= m; ++i) ys[i] = i;
	for (int i = 1; i <= n + m; ++i) fa[i] = i;
	for (int i = 1; i <= Q; ++i) {
		scanf("%d%d", &a[i], &b[i]);
		v1[a[i]].push_back(b[i]);
		v2[b[i]].push_back(a[i]);
	}
	for (int i = 1; i <= Q; ++i) {
		if (v1[a[i]].size() <= 1 || v2[b[i]].size() <= 1) continue;
		for (int j = 1; j != v1[a[i]].size(); ++j)
			ys[v1[a[i]][j]] = findy(v1[a[i]][0]);
		for (int j = 1; j != v2[b[i]].size(); ++j)
			xs[v2[b[i]][j]] = findx(v2[b[i]][0]);
		v1[a[i]].clear(); v2[b[i]].clear();
	}
	for (int i = 1; i <= Q; ++i)
		fa[find(findx(a[i]))] = find(findy(b[i]) + n);
	for (int i = 1; i <= n; ++i) {
		if (!uz[find(findx(i))]) {
			++ans;
			uz[find(findx(i))] = true;
		}
		//cout << find(findx(i)) << " ";
	}
	for (int i = 1; i <= m; ++i) {
		if (!uz[find(findy(i) + n)]) {
			++ans;
			uz[find(findy(i) + n)] = true;
		}
		//cout << find(findy(i) + n) << " ";
	}
	printf("%d\n", ans - 1);
	return 0;
}