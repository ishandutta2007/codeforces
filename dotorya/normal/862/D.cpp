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

char out[1050];
void END(int a, int b) {
	printf("! %d %d\n", a + 1, b + 1);
	fflush(stdout);
	exit(0);
}

int main() {
	int N, i, j;
	scanf("%d", &N);
	
	int totc1;
	for (i = 0; i < N; i++) out[i] = '0';
	printf("? %s\n", out);
	fflush(stdout);
	scanf("%d", &totc1);

	int outc = 0;
	int a[2] = { -1, -1 };
	int st = 0, en = N - 1, c = totc1, v = 1;
	while (st <= en) {
		if (c == en - st + 1) a[1] = st;
		if (c == 0) a[0] = st;
		if (c == 0 || c == en - st + 1) break;

		int mi = (st + en) / 2;
		for (i = 0; i < N; i++) out[i] = '0';
		for (i = st; i <= mi; i++) out[i] = '1';
		for (i = mi + 1; i <= en; i++) out[i] = '0';
		printf("? %s\n", out);
		fflush(stdout);
		int ret;
		scanf("%d", &ret);
		ret -= outc;

		int x = (mi - st + 1 + c - ret) / 2;
		if (x == 0) {
			a[0] = st;
			st = mi + 1;
		}
		else if (x == mi - st + 1) {
			a[1] = st;
			st = mi + 1, v = 0;
			outc += x;
			c -= x;
		}
		else {
			en = mi;
			outc += c - x;
			c = x;
		}
	}
	END(a[0], a[1]);
	return 0;
}