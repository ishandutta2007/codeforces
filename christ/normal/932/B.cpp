#include <bits/stdc++.h>
using namespace std;
const int MN = 1e6 + 5;
int psa[10][MN], gg[MN], ff[MN];
int f (int x) {
	if (~ff[x]) return ff[x];
	int prod = 1;
	while (x) {
		int cur = x % 10;
		x /= 10;
		if (cur) prod *= cur;
	}
	return ff[x] = prod;
}
int g (int x) {
	if (~gg[x]) return gg[x];
	if (x < 10) return gg[x] = x;
	return gg[x] = g(f(x));
}
int main () {
	memset(gg,-1,sizeof gg); memset(ff,-1,sizeof ff);
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < MN; j++) {
			psa[i][j] = psa[i][j-1] + (g(j) == i);
		}
	}
	int q; scanf ("%d",&q);
	while (q--) {
		int l,r,k;
		scanf ("%d %d %d",&l,&r,&k);
		printf ("%d\n",psa[k][r] - psa[k][l-1]);
	}
	return 0;
}