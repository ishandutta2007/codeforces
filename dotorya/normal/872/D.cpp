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

int val1[5050]; // (a, 0)
int val2[5050]; // (0, b);

int P[5050];
int B[5050];

int ans[5050];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		printf("? %d 0\n", i);
		fflush(stdout);
		scanf("%d", &val1[i]);
	}
	for (i = 0; i < N; i++) {
		printf("? 0 %d\n", i);
		fflush(stdout);
		scanf("%d", &val2[i]);
	}

	int cnt = 0;
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) P[j] = i ^ val1[j];
		for (j = 0; j < N; j++) if (P[j] >= N) break;
		if (j < N || P[i] != 0) continue;

		for (j = 0; j < N; j++) B[P[j]] = j;
		for (j = 0; j < N; j++) if ((P[0] ^ B[j]) != val2[j]) break;
		if (j >= N) {
			cnt++;
			for (j = 0; j < N; j++) ans[j] = P[j];
		}
	}

	printf("!\n");
	printf("%d\n", cnt);
	for (i = 0; i < N; i++) printf("%d ", ans[i]);
	printf("\n");
	fflush(stdout);
	return 0;
}