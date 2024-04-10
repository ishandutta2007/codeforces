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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

int askval(int x) {
	printf("%d\n", x);
	fflush(stdout);

	int t;
	scanf("%d", &t);
	if (t == 0) exit(0);

	return t;
}

int val[1050];
int main() {
	int M, N, i, j;
	scanf("%d %d", &M, &N);

	int st = 1, en = M;
	for (i = 1; i <= N; i++) val[i] = askval(1);

	int p = 1;
	while (st <= en) {
		int mi = (st + en) / 2;
		int t = askval(mi) * val[p++];
		if (p == N + 1) p = 1;
		if (t == -1) en = mi - 1;
		else st = mi + 1;
	}
	return 0;
}