#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
using namespace std;

const int maxn = 1009;
bitset<maxn> key[2][maxn], val[2][maxn];
int u[maxn], v[maxn], pa[2][maxn];
map<string,int> Map; string s;
int n, m, K, a, b, c, d, cnt;

inline int getpa(int pa[maxn], int x) {
	return pa[x] == x ? x : pa[x] = getpa(pa, pa[x]);
}

void solve(bitset<maxn> key[maxn], bitset<maxn> val[maxn], int pa[maxn]) {
	rep (i, 1, K) {
		cin >> s;
		if (Map.count(s)) a = Map[s];
		else Map[s] = a = ++cnt;
		scanf("%d%d", &b, &c);
		val[b][a] = 1; 
		while (c--) {
			scanf("%d", &d);
			key[b][d] = 1;
		}
	}
	rep (i, 1, n) pa[i] = i;
	rep (j, 1, n-1) rep (i, 1, m)
		if (getpa(pa, u[i]) != getpa(pa, v[i]) && (key[getpa(pa, u[i])][i] || key[getpa(pa, v[i])][i])) {
			key[getpa(pa, v[i])] |= key[getpa(pa, u[i])];
			val[getpa(pa, v[i])] |= val[getpa(pa, u[i])];
			pa[getpa(pa, u[i])] = v[i];
		}
}

int main() {
	scanf("%d%d%d", &n, &m, &K);
	rep (i, 1, m) scanf("%d%d", &u[i], &v[i]);
	solve(key[0], val[0], pa[0]);
	solve(key[1], val[1], pa[1]);
	rep (i, 1, n) 
		if ((key[0][getpa(pa[0], i)] != key[1][getpa(pa[1], i)])
		 || (val[1][getpa(pa[1], i)] != val[0][getpa(pa[0], i)])){
			 puts("NO"); return 0;
		 }
	puts("YES");
	return 0;
}