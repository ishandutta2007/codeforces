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
#pragma comment(linker, "/STACK:1048576")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple <int, int, int> t3;

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const db EPS = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

map <string, int> Mx;
int ch(string x) {
	if (Mx.count(x)) return Mx[x];
	int t = Mx.size() + 1;
	Mx[x] = t;
	return t;
}

char u1[25];
char u2[25];
int r[200050][2];
int root(int x) {
	if (x == r[x][0]) return x;

	int np = r[x][0];
	r[x][0] = root(r[x][0]);
	r[x][1] ^= r[np][1];
	return r[x][0];
}
int main() {
	int N, M, Q, i, j;
	scanf("%d %d %d", &N, &M, &Q);
	for (i = 1; i <= N; i++) {
		scanf("%s", u1);
		j = ch(string(u1));
	}
	for (i = 1; i <= N; i++) r[i][0] = i, r[i][1] = 0;
	for (i = 1; i <= M; i++) {
		int t;
		scanf("%d %s %s", &t, u1, u2);
		int x = ch(string(u1));
		int y = ch(string(u2));
		t--;
		int a = root(x), b = root(y);
		if (a == b) {
			t ^= r[x][1] ^ r[y][1];
			if (t == 0) printf("YES\n");
			else printf("NO\n");
			continue;
		}
		printf("YES\n");
		t ^= r[x][1] ^ r[y][1];
		r[a][0] = b;
		r[a][1] = t;
	}

	for (i = 1; i <= Q; i++) {
		scanf("%s %s", u1, u2);
		int x = ch(string(u1));
		int y = ch(string(u2));

		int a = root(x), b = root(y);
		if (a != b) printf("3\n");
		else printf("%d\n", (r[x][1] ^ r[y][1]) + 1);
	}
	return 0;
}