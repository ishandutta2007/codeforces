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

int main() {
//	printf("%d\n", (0 ^ 1 ^ 2 ^ 3 ^ 4 ^ 11 ^ 13 ^ 14 ^ 19 ^ 21 ^ 22));
	int N, X, i;
	scanf("%d %d", &N, &X);

	if (X == 0) {
		if (N == 2) return !printf("NO\n");
		if (N == 1) return !printf("YES\n0\n");
	}

	printf("YES\n");
	int cur = 1000000;
	if (X == 0) {
		printf("%d %d ", cur - 1, cur - 2);
		cur -= 4;
		N -= 2;
		X = 1;
	}

	while (N > 4) {
		printf("%d %d %d %d ", cur - 1, cur - 2, cur - 3, cur - 4);
		cur -= 4;
		N -= 4;
	}

	if (N == 1) printf("%d ", X);
	else if (N == 2) printf("0 %d ", X);
	else if (N == 3) {
		if (X != 1) printf("0 1 %d ", X ^ 1);
		else printf("0 2 3 ");
	}
	else {
		if (X > 3) printf("0 1 2 %d ", X ^ 3);
		else if (X == 1) printf("1 2 4 6 ");
		else if (X == 2) printf("0 1 4 7 ");
		else printf("0 1 4 6 ");
	}
	return 0;
}