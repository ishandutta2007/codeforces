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

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

char in[3050];
int mx[3050];
int dp[3050];
int rev[3050];
bool isVowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool chk[3050];
int main() {
	int N, i, j;
	scanf("%s", in + 1);
	N = strlen(in + 1);

	for (i = 1; i <= N; i++) {
		int c = 0, v = -1;
		for (j = i; j <= N; j++) {
			if (isVowel(in[j])) {
				c = 0, v = -1;
				continue;
			}
			c++;
			if (c == 1) v = in[j];
			else if (v != in[j]) v = -1;
			if (c >= 3 && v == -1) break;
		}
		mx[i] = j - 1;
	}

	for (i = 1; i <= N; i++) {
		dp[i] = INF;
		if (mx[1] >= i) dp[i] = 1;
		for (j = 2; j <= i; j++) {
			if (mx[j] < i) continue;
			if (dp[i] > dp[j] + 1) {
				dp[i] = dp[j] + 1;
				rev[i] = j-1;
			}
		}
	}

	int t = N;
	while (t) {
		t = rev[t];
		chk[t] = true;
	}
	for (i = 1; i <= N; i++) {
		printf("%c", in[i]);
		if (chk[i]) printf(" ");
	}
	return !printf("\n");
}