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
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

char in1[1050];
char in2[1050];
bool chk[1050];
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	scanf("%s %s", in1, in2);

	int ans = -1;
	for (i = 0; i <= M - N; i++) {
		int c = 0;
		for (j = 0; j < N; j++) if (in1[j] == in2[i + j]) c++;
		if (ans < c) {
			ans = c;
			for (j = 0; j < N; j++) chk[j] = (in1[j] == in2[i + j]);
		}
	}
	printf("%d\n", N - ans);
	for (i = 0; i < N; i++) if (!chk[i]) printf("%d ", i + 1);
	return !printf("\n");
}