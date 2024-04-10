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

int IT_MAX = 1 << 17;
ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

map <string, int> Mstr;
int ch(string x) {
	if (Mstr.count(x)) return Mstr[x];
	int t = Mstr.size() + 1;
	return Mstr[x] = t;
}
char ustrz[105];
int readString() {
	scanf("%s", ustrz);
	return ch(string(ustrz));
}

class PST {
public:
	int nc;
	int* Ro;
	int* L;
	int* R;
	int* sum;
	int it_max;
	PST() {
		nc = 0;
		Ro = new int[6400000];
		L = new int[6400000];
		R = new int[6400000];
		sum = new int[6400000];
		Ro[0] = 0;
	}
	int update(int p, int S, int E, int n, int v) {
		int nn = ++nc;
		L[nn] = L[n];
		R[nn] = R[n];
		sum[nn] = sum[n];
		if (S == E) {
			sum[nn] += v;
			return nn;
		}

		int M = (S + E) / 2;
		if (p <= M) L[nn] = update(p, S, M, L[n], v);
		else R[nn] = update(p, M + 1, E, R[n], v);
		sum[nn] = sum[L[nn]] + sum[R[nn]];
		return nn;
	}
	ll getsum(int st, int en, int S, int E, int n) {
		if (n == 0) return 0;
		if (en < S || E < st) return 0;
		if (st <= S && E <= en) return sum[n];
		
		int M = (S + E) / 2;
		return getsum(st, en, S, M, L[n]) + getsum(st, en, M + 1, E, R[n]);
	}
};
PST pst[2];

int in[100050][3];
int main() {
	pst[0].it_max = 1 << 17;
	pst[1].it_max = 1 << 30;

	int Q;
	scanf("%d", &Q);
	for (int q = 1; q <= Q; q++) {
		char c[10];
		scanf("%s", c);
		pst[0].Ro[q] = pst[0].Ro[q - 1];
		pst[1].Ro[q] = pst[1].Ro[q - 1];
		if (c[0] == 's' || c[0] == 'r') {
			int t1 = readString(), t2;
			if (c[0] == 'r') t2 = 0;
			else scanf("%d", &t2);

			int cur = pst[0].getsum(t1, t1, 1, pst[0].it_max, pst[0].Ro[q]);
			pst[0].Ro[q] = pst[0].update(t1, 1, pst[0].it_max, pst[0].Ro[q], t2 - cur);

			if(cur) pst[1].Ro[q] = pst[1].update(cur, 1, pst[1].it_max, pst[1].Ro[q], -1);
			if(t2) pst[1].Ro[q] = pst[1].update(t2, 1, pst[1].it_max, pst[1].Ro[q], 1);
		}
		else if (c[0] == 'q') {
			int t1 = readString();
			
			int cur = pst[0].getsum(t1, t1, 1, pst[0].it_max, pst[0].Ro[q]);
			if (!cur) printf("-1\n");
			else printf("%lld\n", pst[1].getsum(1, cur - 1, 1, pst[1].it_max, pst[1].Ro[q]));
			fflush(stdout);
		}
		else {
			int t1;
			scanf("%d", &t1);

			pst[0].Ro[q] = pst[0].Ro[q - 1 - t1];
			pst[1].Ro[q] = pst[1].Ro[q - 1 - t1];
		}
	}
	return 0;
}
//*/