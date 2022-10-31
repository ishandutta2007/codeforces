#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fst first
#define snd second
#define mp(a,b) make_pair(a, b)

#define RD(x) scanf("%d", &x)
#define RDD(x, y) scanf("%d%d", &x, &y)
#define FOR(i, n) for(int i = 0; i < n; ++i)
#define CLR(A, V) memset(A, V, sizeof A)

pii ans[5010];
int main() {
	int n, m; RDD(n, m);
	FOR(i, n) {
		int t; RD(t);
		ans[i].fst = ans[i].snd = t;
	}
	FOR(i, n) {
		if(ans[i].fst != ans[i].snd) continue;
		FOR(j, n) {
			if(i == j) continue;
			if(ans[i].fst != ans[j].fst && ans[i].fst != ans[j].snd) { swap(ans[i].fst, ans[j].fst); break ; }
		}
	}
	int nans = 0;
	FOR(i, n) if(ans[i].fst != ans[i].snd) nans++;
	printf("%d\n", nans);
	FOR(i, n) printf("%d %d\n", ans[i].fst, ans[i].snd);
	return 0;
}