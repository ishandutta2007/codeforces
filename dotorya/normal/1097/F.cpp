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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

bitset <7050> bs[100050];

bitset <7050> val[7050];
bool dchk[7050];

bitset <7050> val2[7050];
int main() {
	int i, j;
	for (i = 1; i <= 7000; i++) {
		for (j = 2; j <= 100; j++) if (i % (j*j) == 0) dchk[i] = true;
	}

	for (i = 1; i <= 7000; i++) {
		for (j = i; j <= 7000; j += i) val[j][i] = 1;
		for (j = i; j <= 7000; j += i) if (!dchk[j / i]) val2[i][j] = 1;
	}

	bitset <7050> u;
	int N, Q;
	scanf("%d %d", &N, &Q);
	while (Q--) {
		int t1, t2, t3, t4;
		scanf("%d %d %d", &t1, &t2, &t3);
		if (t1 == 2 || t1 == 3) scanf("%d", &t4);

		if (t1 == 1) bs[t2] = val[t3];
		if (t1 == 2) bs[t2] = bs[t3] ^ bs[t4];
		if (t1 == 3) bs[t2] = bs[t3] & bs[t4];
		if (t1 == 4) {
			u = val2[t3] & bs[t2];
			printf("%d", u.count() % 2);
		}
	}
	return !printf("\n");
}