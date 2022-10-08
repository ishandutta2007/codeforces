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

int IT_MAX = 1 << 18;
const ll MOD = 31991;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

vector <int> Vp[1000050];
int main() {
	int N, A, i, j, t;
	scanf("%d %d", &N, &A);
	for (i = 1; i <= N; i++) {
		scanf("%d", &t);
		Vp[t].push_back(i);
	}
	
	for (i = 1; i <= 1000000; i++) {
		if (A == i) continue;
		for (j = 0; j < Vp[i].size(); j++) {
			int c = lower_bound(all(Vp[A]), Vp[i][j]) - Vp[A].begin();
			if (c > j) break;
		}
		if (j >= Vp[i].size() && Vp[i].size() >= Vp[A].size()) return !printf("%d\n", i);
	}
	return !printf("-1\n");
}