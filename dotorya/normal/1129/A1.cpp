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

int N;
int getdis(int a, int b) {
	if (a <= b) return b - a;
	else return b - a + N;
}
vector <int> Vl[5050];
int val[5050];
int main() {
	int M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		Vl[t1].push_back(t2);
	}

	for (i = 1; i <= N; i++) {
		sort(all(Vl[i]), [&](int a, int b) {
			return getdis(i, a) > getdis(i, b);
		});

		if (Vl[i].size() == 0) val[i] = -INF;
		else val[i] = (Vl[i].size() - 1) * N + getdis(i, Vl[i].back());
	}

	for (i = 1; i <= N; i++) {
		int mx = -INF;
		for (j = 1; j <= N; j++) mx = max(mx, getdis(i, j) + val[j]);
		printf("%d ", mx);
	}
	return !printf("\n");
}