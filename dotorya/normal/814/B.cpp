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

int N;
int A[1050];
int B[1050];

int ans[1050];
bool chk[1050];
void aa(int lvl) {
	if (lvl == N + 1) {
		for (int i = 1; i <= N; i++) chk[i] = false;
		for (int i = 1; i <= N; i++) {
			if (chk[ans[i]]) return;
			chk[ans[i]] = true;
		}
		for (int i = 1; i <= N; i++) printf("%d ", ans[i]);
		printf("\n");
		exit(0);
	}
	if (A[lvl] == B[lvl]) {
		ans[lvl] = A[lvl];
		aa(lvl + 1);
		return;
	}

	ans[lvl] = A[lvl];
	aa(lvl + 1);
	ans[lvl] = B[lvl];
	aa(lvl + 1);
}
int main() {
	scanf("%d", &N);
	int i;
	for (i = 1; i <= N; i++) scanf("%d", A + i);
	for (i = 1; i <= N; i++) scanf("%d", B + i);

	int c = 0;
	for (i = 1; i <= N; i++) if (A[i] == B[i]) c++;
	if (c == N - 1) {
		for (i = 1; i <= N; i++) chk[A[i]] = true;
		for (i = 1; i <= N; i++) if (!chk[i]) break;

		int x = i;
		for (i = 1; i <= N; i++) if (A[i] != B[i]) A[i] = x;
		for (i = 1; i <= N; i++) printf("%d ", A[i]);
		return !printf("\n");
	}
	aa(1);
	return !printf("ERR\n");
}