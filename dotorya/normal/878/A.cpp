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
const ll MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)

int v[10];
int main() {
	int N, i, j;
	scanf("%d", &N);

	for (i = 0; i < 10; i++) v[i] = 2;
	while (N--) {
		char c[2];
		int t;
		scanf("%s %d", c, &t);

		if (c[0] == '|') {
			for (i = 0; i < 10; i++) if (t & (1 << i)) v[i] = 1;
		}
		if (c[0] == '&') {
			for (i = 0; i < 10; i++) if (!(t & (1 << i))) v[i] = 0;
		}
		if (c[0] == '^') for (i = 0; i < 10; i++) if(t & (1<<i)) v[i] ^= 1;
	}

	int v1 = 0, v2 = 0, v3 = 0;
	for (i = 0; i < 10; i++) {
		if (v[i] == 0) v1 |= (1 << i);
		if (v[i] == 1) v2 |= (1 << i);
		if (v[i] == 3) v3 |= (1 << i);
	}
	printf("3\n");
	printf("| %d\n", v2);
	printf("& %d\n", 1023 ^ v1);
	printf("^ %d\n", v3);
	return 0;
}