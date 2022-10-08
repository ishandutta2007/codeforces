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

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

bool pchk[500050];
vector <int> Vp;

int in[500050];
int main() {
	int N, i, j;

	for (i = 2; i <= 500000; i++) {
		if (pchk[i]) continue;
		Vp.push_back(i);
		for (j = 2 * i; j <= 500000; j += i) pchk[j] = true;
	}

	scanf("%d", &N);
	int c[3] = { 0,0,0 };
	for (i = 1; i <= N; i++) {
		int t;
		scanf("%d", &t);
		c[t]++;
	}

	if (c[1] == 0 || c[2] == 0) {
		for (i = 1; i <= c[1]; i++) printf("1 ");
		for (i = 1; i <= c[2]; i++) printf("2 ");
		return !printf("\n");
	}

	printf("2 1 ");
	for (i = 1; i < c[2]; i++) printf("2 ");
	for (i = 1; i < c[1]; i++) printf("1 ");
	
	return !printf("\n");
}