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

int in[100050];

int val[100050];

int u[100050];
int ans[100050];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 0; i <= 2 * N - 2; i += 2) scanf("%d", &in[i]);
	in[2 * N] = in[0];

	for (i = 1; i <= 2 * N - 1; i += 2) val[i] = (N - in[i - 1]) - in[i + 1];

	for (i = 0; i < N; i++) u[i] = i * 2 + 1;
	sort(u, u + N, [](int a, int b) {
		return val[a] < val[b];
	});

	for (i = 0; i < N; i++) ans[u[i]] = N-1-i;
	for (i = 1; i <= 2 * N - 1; i += 2) printf("%d ", ans[i]);
	return !printf("\n");
}