#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cstdio>

#define MP 510000
#define MN 55
using namespace std;

int a[MN];
int T[MP], V[MP];
int E[MP], EN;

int main() {
	
	int i, k, n, d;
	
	cin >> n >> d;
	for (i = 0; i < n; i ++) scanf("%d", a + i);
	T[0] = 1;
	int S = 0;
	
	for (i = 0; i < n; i ++) {
		for (k = S; k >= 0; k --) if (T[k]) {
			if (k + a[i] >= MP) continue;
			T[k + a[i]] = 1;
		}
		S += a[i];
	}
	for (i = 0; i <= S; i ++) if (T[i]) {
		E[EN ++] = i;
	}
	memset(V, -1, sizeof(V));
	V[0] = 0;
	
	for (i = 0; i <= S; i ++) if (V[i] != -1) {
		int e = i + d;
		int st = upper_bound(E, E + EN, i) - E;
		int en = upper_bound(E, E + EN, e) - E - 1;
		k = en;
		if (V[E[k]] == -1) V[E[k]] = V[i] + 1;
		if (V[E[k]] > V[i] + 1) V[E[k]] = V[i] + 1;
		
/*		for (k = st; k <= en; k ++) {
			if (V[E[k]] == -1) V[E[k]] = V[i] + 1;
			if (V[E[k]] > V[i] + 1) V[E[k]] = V[i] + 1;
		}*/
	}
	for (i = MP - 1; i >= 0; i --) if (V[i] != -1) break;
	printf("%d %d\n", i, V[i]);
}