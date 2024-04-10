#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<list>
#include<bitset>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(int i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define AIN(A, B, C) assert(IN(A, B, C))

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;

VP V;
VP P;
map<int, int> Mcnt;
map<PII, int> Mat;

#define MAXN 100005
int root[MAXN];
struct Node {
	int l, r;
	int cnt;
} node[22 * MAXN];
int nnode = 0;
int n, k;

int insert(int prev, int x, int l, int r) {
	int at = nnode++;
	node[at].l = node[prev].l;
	node[at].r = node[prev].r;
	node[at].cnt = node[prev].cnt + 1;
	if (l == r) return at;
	int m = (l + r) / 2;
	if (x <= m) node[at].l = insert(node[at].l, x, l, m);
	else node[at].r = insert(node[at].r, x, m + 1, r);
	return at;
}

int query(int at, int L, int R, int l, int r) {
	if (l <= L && R <= r) return node[at].cnt;
	if (r < L || R < l) return 0;
	int M = (L + R) / 2;
	return query(node[at].l, L, M, l, r) + query(node[at].r, M + 1, R, l, r);
}

int query(int l, int r) {
	int id = std::upper_bound(ALL(V), PII(l, 0 )) - V.begin() - 1;
	if (id >= 0) id = root[id];
	else id = 0;

	return query(id, 1, n, l, r);
}

int build(int l, int r) {
	int at = nnode++;
	node[at].cnt = 0;
	node[at].l = node[at].r = -1;
	if (l == r) return at;
	int m = (l + r) / 2;
	node[at].l = build(l, m);
	node[at].r = build(m + 1, r);
	return at;
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif
	scanf("%d%d", &n,&k);
	for (int i = 1; i <= n; i++) {
		int color;
		scanf("%d", &color);
		int pos = i;
		Mcnt[color]++;
		int serial = Mcnt[color];
		Mat[{color, serial}] = i;
		int prev = 0;
		if (serial > k) prev = Mat[{color, serial - k}];

		V.push_back({ prev, pos });
		P.push_back({ pos, prev });
	}

	build(1, n);

	sort(ALL(V));
	for (int i = 0; i < SZ(V); i++) {
		int id = V[i].second;
		root[i] = insert(i == 0 ? 0 : root[i - 1], id, 1, n);
	}

	int last = 0,q;
	scanf("%d", &q);
	while (q--) {
		int a, b;
		scanf("%d %d", &a, &b);
		a = (a + last) % n + 1;
		b = (b + last) % n + 1;
		if (a > b) swap(a, b);
		int ans = query(a, b);
		last = ans;
		printf("%d\n", ans);
	}


	return 0;
}