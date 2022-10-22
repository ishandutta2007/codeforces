#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e6 + 10;

int n, m, k, a[MAXN], b[MAXN], sec[MAXN];

bool cmp(int u, int v){return b[u] < b[v];}

int vec[MAXN];
bool ok(int mid){
	merge(a, a + n, b+m-mid, b+m, vec);
	int sz = n+mid;
	for (int i = 0, w = 0; i < sz; i += k, w++)
		for (int j = i; j < sz && j < i+k; j++)
			if (vec[j] < w)
				return false;
	return true;
}

int aa;
int main(){
	aa = scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		aa = scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < m; i++)
		aa = scanf("%d", &b[i]);
	iota(sec, sec + m, 0);
	sort(sec, sec + m, cmp);
	sort(b, b + m);
	
	int lo = -1, hi = m+1;
	while (hi-lo>1){
		int mid = hi+lo>>1;
		if (ok(mid))
			lo = mid;
		else
			hi = mid;
	}
	if (lo == -1){
		printf("-1\n");
		return 0;
	}

	printf("%d\n", lo);
	for (int i = m-lo; i < m; i++)
		printf("%d ", sec[i]+1);
	printf("\n");
	return 0;
}