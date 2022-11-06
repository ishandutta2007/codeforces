#include<bits/stdc++.h>
using namespace std;
int f[1005],g[1005];
int find1(int x) {
	return x == f[x] ? x : f[x] = find1(f[x]);
}
int find2(int x) {
	return x == g[x] ? x : g[x] = find2(g[x]);
}
void join1(int u, int v) {
	int f1 = find1(u), f2 = find1(v);
	if (f1 != f2)f[f1] = f2;
}
void join2(int u, int v) {
	int f1 = find2(u), f2 = find2(v);
	if (f1 != f2)g[f1] = f2;
}
int A[1005], B[1005];
int main() {
	int n, m1, m2,i,j,k,u,v,ans=0;
	scanf("%d%d%d", &n, &m1, &m2);
	for (i = 1; i <= n; ++i)f[i] = g[i]=i;
	for (i = 1; i <= m1; ++i) {
		scanf("%d%d", &u, &v);
		join1(u, v);
	}
	for (i = 1; i <= m2; ++i) {
		scanf("%d%d", &u, &v);
		join2(u, v);
	}
	for (i = 1; i <= n; ++i) {
		for (j = i + 1; j <= n; ++j) {
			if (find1(i) != find1(j) && find2(i) != find2(j)) {
				++ans;
				A[ans] = i; B[ans] = j;
				f[find1(i)] = find1(j);
				g[find2(i)] = find2(j);
			}
		}
	}
	printf("%d\n", ans);
	for (i = 1; i <= ans; ++i)printf("%d %d\n", A[i], B[i]);
	return 0;
}