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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

int in[205][205];
int main() {
	int N, M, K, i, j, k, l;
	scanf("%d %d %d", &N, &M, &K);
	for (i = 1; i <= N; i++) for (j = 1; j <= M; j++) scanf("%d", &in[i][j]);

	int a1 = 0, a2 = 0;
	for (i = 1; i <= M; i++) {
		int mx = 0, p = 0;
		vector <int> Vu;
		for (j = 1; j <= N; j++) if (in[j][i]) Vu.push_back(j);

		for (j = 0; j < Vu.size(); j++) {
			int c = 0;
			for (k = j; k < Vu.size(); k++) if (Vu[k] - Vu[j] < K) c++;
			if (mx < c) {
				mx = c;
				p = j;
			}
		}
		a1 += mx, a2 += p;
	}
	return !printf("%d %d\n", a1, a2);
}