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

char str[500050];
int sa[19][600050];
int u1[500050];
int u2[500050];
int pos[500050];
int lcp(int a, int b) {
	int rv = 0;
	for (int i = 18; i >= 0; i--) {
		if (sa[i][a] == sa[i][b]) {
			rv += 1 << i;
			a += 1 << i;
			b += 1 << i;
		}
	}
	return rv;
}

char in1[300050];
char in2[300050];

int dp[300050][35];
int main() {
	int N, M, X, i, j, k;
	scanf("%d %s %d %s %d", &N, in1, &M, in2, &X);

	int L = N + M + 1;
	for (i = 0; i < N; i++) str[i] = in1[i];
	str[N] = '#';
	for (i = 0; i < M; i++) str[i + N + 1] = in2[i];
	
	for (i = 0; i < L; i++) u1[i] = i;
	sort(u1, u1 + L, [](int a, int b) {
		return str[a] < str[b];
	});
	for (i = 0, j = 0; i < L; i++) {
		if (i == 0 || str[u1[i]] != str[u1[i - 1]]) j++;
		sa[0][u1[i]] = j;
	}
	for (i = 0; i < 18; i++) {
		for (j = 0; j <= L; j++) pos[j] = 0;
		for (j = 0; j < L; j++) pos[sa[i][j + (1 << i)]]++;
		for (j = 1; j <= L; j++) pos[j] += pos[j - 1];
		for (j = L - 1; j >= 0; j--) u1[--pos[sa[i][j + (1 << i)]]] = j;

		for (j = 0; j <= L; j++) pos[j] = 0;
		for (j = 0; j < L; j++) pos[sa[i][j]]++;
		for (j = 1; j <= L; j++) pos[j] += pos[j - 1];
		for (j = L - 1; j >= 0; j--) u2[--pos[sa[i][u1[j]]]] = u1[j];

		for (j = 0, k = 0; j < L; j++) {
			if (j == 0 || sa[i][u2[j]] != sa[i][u2[j - 1]]
				|| sa[i][u2[j] + (1 << i)] != sa[i][u2[j - 1] + (1 << i)]) k++;
			sa[i+1][u2[j]] = k;
		}
	}
	
	for (i = 0; i < N; i++) {
		if(i != 0) for (j = 0; j <= X; j++) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		for (j = 0; j < X; j++) {
			int t1 = i, t2 = dp[i][j];
			int s = lcp(t1, N + 1 + t2);
			dp[i + s][j + 1] = max(dp[i + s][j + 1], dp[i][j] + s);
			if (dp[i + s][j + 1] == M) return !printf("YES\n");
		}
	}
	return !printf("NO\n");
}