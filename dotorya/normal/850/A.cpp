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

int IT_MAX = 1 << 15;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

int in[1050][5];

bool chk[243];
int main() {
	int N, i, j, k, l;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) for (j = 0; j < 5; j++) scanf("%d", &in[i][j]);

	if (N >= 300) return !printf("0\n");
	vector <int> Va;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			for (k = j + 1; k <= N; k++) {
				if (i == j || i == k) continue;

				ll s = 0;
				for (l = 0; l < 5; l++) s += (in[j][l] - in[i][l]) * (in[k][l] - in[i][l]);
				if (s > 0) break;
			}
			if (k <= N) break;
		}
		if (j > N) Va.push_back(i);
	}
	printf("%d\n", (int)Va.size());
	for (auto it : Va) printf("%d ", it);
	return !printf("\n");
}