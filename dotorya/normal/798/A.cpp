#include <stdio.h>
#include <algorithm>
#include <assert.h>
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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

char in[20];
int main() {
	bool chk = false;
	
	scanf("%s", in);
	int i, j, k, L = strlen(in);
	for (i = 0; i < L; i++) {
		char oc = in[i];
		for (j = 0; j < 26; j++) {
			if ('a' + j == oc) continue;
			in[i] = 'a' + j;
			for (k = 0; k < L; k++) if (in[k] != in[L - 1 - k]) break;
			if (k >= L) return !printf("YES\n");
		}
		in[i] = oc;
	}
	return !printf("NO\n");
}