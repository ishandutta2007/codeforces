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
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()

char in[105];
int getans(int N) {
	int rv = 0, i;
	for (i = 0; i + 1 < N; i++) {
		if (in[i] == 'V' && in[i + 1] == 'K') {
			rv++;
			i++;
		}
	}
	return rv;
}
int main() {
	int N, i, j;
	scanf("%s", in);
	N = strlen(in);

	int ans = getans(N);
	for (i = 0; i < N; i++) {
		in[i] = 'V' ^ 'K' ^ in[i];
		ans = max(ans, getans(N));
		in[i] = 'V' ^ 'K' ^ in[i];
	}
	return !printf("%d\n", ans);
}