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

int in[105][105];
int A[105];
int B[105];
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) for (j = 1; j <= M; j++) scanf("%d", &in[i][j]);

	for (i = 2; i <= N; i++) A[i] = in[i][1] - in[1][1];
	for (i = 2; i <= M; i++) B[i] = in[1][i] - in[1][1];

	for (i = 1; i <= N; i++) for (j = 1; j <= M; j++) if (A[i] + B[j] != in[i][j] - in[1][1]) return !printf("-1\n");

	int mna = 0, mnb = 0;
	for (i = 1; i <= N; i++) mna = max(mna, -A[i]);
	for (i = 1; i <= M; i++) mnb = max(mnb, -B[i]);
	if (mna + mnb > in[1][1]) return !printf("-1\n");

	if (N <= M) mna = in[1][1] - mnb;
	else mnb = in[1][1] - mna;
	for (i = 1; i <= N; i++) A[i] += mna;
	for (i = 1; i <= M; i++) B[i] += mnb;

	int ans = 0;
	for (i = 1; i <= N; i++) ans += A[i];
	for (i = 1; i <= M; i++) ans += B[i];
	printf("%d\n", ans);
	for (i = 1; i <= N; i++) for (j = 1; j <= A[i]; j++) printf("row %d\n", i);
	for (i = 1; i <= M; i++) for (j = 1; j <= B[i]; j++) printf("col %d\n", i);
	return 0;
}