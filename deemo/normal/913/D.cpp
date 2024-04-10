#include<cstdio>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e5 + 10;

int n, lim, a[MAXN], tt[MAXN];
int sec[MAXN];

bool cmp1(int u, int v){return tt[u] < tt[v];}

bool ok(int mid, int t = 0){
	if (t) {
		printf("%d\n", mid);
		printf("%d\n", mid);
	}
	int sm = 0, cur = 0;
	for (int i = 0; cur < mid && i < n; i++)
		if (a[sec[i]] >= mid){
			sm += tt[sec[i]];
			cur++;
			if (t)
				printf("%d ", sec[i]+1);
		}
	if (t)
		printf("\n");
	return sm <= lim && cur == mid;
}

int main(){
	scanf("%d %d", &n, &lim);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &a[i], &tt[i]);
	iota(sec, sec + n, 0);
	sort(sec, sec + n, cmp1);

	int lo = 0, hi = n+1;
	while (hi-lo>1){
		int mid = hi+lo>>1;
		if (ok(mid))
			lo = mid;
		else
			hi = mid;
	}
	ok(lo, 1);
	return 0;
}