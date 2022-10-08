//*
#include <algorithm>
#include <ctype.h>
#include <functional>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

const int IT_MAX = 32768;
const int MOD = 1000000000;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;

bool prime_chk[20000050];
int palinsum[20000050];
bool palinchk[20000050];
int primesum[20000050];

vector <int> V;
bool isPalindrome(int x) {
	V.clear();
	while (x != 0) {
		V.push_back(x % 10);
		x /= 10;
	}
	for (int i = 0; i < V.size(); i++) if (V[i] != V[V.size() - 1 - i]) return false;
	return true;
}
int main() {
	int i, j;
	for (i = 2; i <= 20000000; i++) {
		primesum[i] = primesum[i - 1];
		if (prime_chk[i]) continue;
		primesum[i]++;
		for (j = 2 * i; j <= 20000000; j += i) prime_chk[j] = true;
	}

	palinsum[1] = 1;
	for (i = 2; i <= 20000000; i++) {
		palinsum[i] = palinsum[i - 1];
		if (isPalindrome(i)) palinsum[i]++;
	}

	int P, Q, ans = 1;
	scanf("%d %d", &P, &Q);
	for (i = 2; i <= 20000000; i++) if ((ll)primesum[i] * Q <= (ll)palinsum[i] * P) ans = i;
	printf("%d", ans);
	return 0;
}
//*/