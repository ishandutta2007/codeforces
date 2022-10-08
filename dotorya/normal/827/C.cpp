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

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()

class bit {
public:
	int it_max;
	int bv[131073];
	bit() {
		it_max = IT_MAX;
		memset(bv, 0, sizeof(bv));
	}
	void update(int p, int v) {
		p++;
		for (; p <= it_max; p += p & (-p)) bv[p] += v;
	}
	int getsum(int p1, int p2) {
		p2++;
		int rv = 0;
		for (; p2; p2 -= p2 & (-p2)) rv += bv[p2];
		for (; p1; p1 -= p1 & (-p1)) rv -= bv[p1];
		return rv;
	}
};
bit tr[11][11][4];

inline int ch(char c) {
	if (c == 'A') return 0;
	if (c == 'C') return 1;
	if (c == 'G') return 2;
	return 3;
}

char in[100050];
char u[15];
int main() {
	scanf("%s", in);
	
	int L = strlen(in), i, j, k, Q;

	for (i = 0; i < L; i++) {
		int x = ch(in[i]);
		for (j = 1; j <= 10; j++) tr[j][i%j][x].update(i, 1);
	}
	
	scanf("%d", &Q);
	while (Q--) {
		int t1, t2, t3;
		scanf("%d %d", &t1, &t2);
		t2--;
		if (t1 == 1) {
			i = t2;
			scanf("%s", u);
			for (j = 1; j <= 10; j++) tr[j][i%j][ch(in[i])].update(i, -1);
			in[i] = u[0];
			for (j = 1; j <= 10; j++) tr[j][i%j][ch(in[i])].update(i, 1);
		}
		else {
			scanf("%d %s", &t3, u);
			t3--;

			int ans = 0;
			int x = strlen(u);
			for (j = 0; j < x; j++) ans += tr[x][(j+t2)%x][ch(u[j])].getsum(t2, t3);
			printf("%d\n", ans);
		}
	}
	return 0;
}