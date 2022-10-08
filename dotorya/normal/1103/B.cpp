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

int IT_MAX = 1 << 20;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

char myask(int a, int b) {
	printf("? %d %d\n", a, b);
	fflush(stdout);

	char c[2];
	scanf("%s", c);
	return c[0];
}
char u[105];
int main() {
	while (1) {
		scanf("%s", u);
		if (u[0] == 'm') while (1);
		if (u[0] == 'e') break;

		int v = myask(0, 1);
		if (v == 'x') {
			printf("! 1\n");
			fflush(stdout);
			continue;
		}

		int i;
		for (i = 0; i <= 28; i++) {
			int v = myask(1 << i, 1 << (i + 1));
			if (v == 'x') break;
		}

		int st = 0, en = (1 << i) - 1, mi, rv = (1<<i);
		while (st <= en) {
			mi = (st + en) / 2;
			int v = myask(mi, 1 << (i + 1));
			if (v == 'x') {
				rv = mi;
				en = mi - 1;
			}
			else st = mi + 1;
		}
		printf("! %d\n", (1 << (i + 1)) - rv);
		fflush(stdout);
	}
	return 0;
}