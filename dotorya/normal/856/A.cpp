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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

int in[105];
bool chk[1000050];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, i, j, k;
		scanf("%d", &N);
		for (i = 1; i <= N; i++) scanf("%d", &in[i]);

		int p = 1;
		printf("YES\n");
		for (i = 1; i <= N; i++) {
			printf("%d ", p);
			for (j = 1; j <= N; j++) {
				for (k = 1; k <= N; k++) {
					int v = p + in[j] - in[k];
					if (v >= 1 && v <= 1000000) chk[v] = true;
				}
			}
			while (chk[p]) p++;
		}
		printf("\n");
		for (i = 1; i <= 1000000; i++) chk[i] = false;
	}
	return 0;
}