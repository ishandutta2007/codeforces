#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>  

#pragma warning(disable:4996)  
#pragma comment(linker, "/STACK:336777216")  
using namespace std;

#define mp make_pair  
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size())  
#define rep(i, n) for(int i=0;i<n;i++)  
#define all(x) (x).begin(), (x).end()  
#define ldb ldouble  

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

class Node {
public:
	int s;
	int ans;
	int lv;
	int rv;
	int lmx;
	int rmx;
	int tmx;
};
Node indt[600000];
char in[200050];

Node mymerge(Node a, Node b) {
	Node R;
	R.s = a.s + b.s;
	R.lv = max(a.lv, a.s + b.lv);
	R.rv = max(b.rv, -b.s + a.rv);                                  
	R.tmx = max(a.tmx + b.s, -a.s + b.tmx);
	R.lmx = max({ a.lmx, -a.s + b.lmx, a.tmx + b.lv });
	R.rmx = max({ b.rmx, b.s + a.rmx, b.tmx + a.rv });
	R.ans = max({ a.ans, b.ans, a.rv + b.lmx, a.rmx + b.lv });
	return R;
}
Node getsum(int st, int en) {
	Node v1;
	Node v2;
	v1.ans = v2.ans = -INF;
	
	st += IT_MAX - 1;
	en += IT_MAX - 1;
	for (; st <= en; st /= 2, en /= 2) {
		if (st % 2 == 1) {
			if (v1.ans == -INF) v1 = indt[st];
			else v1 = mymerge(v1, indt[st]);
			st++;
		}
		if (en % 2 == 0) {
			if (v2.ans == -INF) v2 = indt[en];
			else v2 = mymerge(indt[en], v2);
			en--;
		}
	}

	if (v1.ans == -INF) return v2;
	else if (v2.ans == -INF) return v1;
	return mymerge(v1, v2);
}


void update(int p) {
	Node u;
	u.s = 1;
	if (in[p] == ')') u.s = -1;
	u.ans = 1;
	u.lv = max(0, u.s);
	u.rv = max(0, -u.s);
	u.lmx = u.rmx = u.tmx = 1;
	indt[p + IT_MAX - 1] = u;

	for (int i = (p + IT_MAX - 1) / 2; i; i /= 2) indt[i] = mymerge(indt[2 * i], indt[2 * i + 1]);
}

int main() {
	int N, Q, i, j;
	scanf("%d %d %s", &N, &Q, in + 1);
	N = 2 * N - 2;

	for (i = 1; i <= N; i++) update(i);
	printf("%d\n", getsum(1, N).ans);

	while (Q--) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		swap(in[t1], in[t2]);
		update(t1);
		update(t2);

		printf("%d\n", getsum(1, N).ans);
	}
	return 0;
}