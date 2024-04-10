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

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

bool chk[26];

char u1[100050];
char u2[100050];
int main() {
	int N, i, j;
	scanf("%d", &N);
	
	int tot = 0;
	int cur = 0;
	for (i = 1; i < N; i++) {
		scanf("%s %s", u1, u2);

		bool cus = false;
		int c = 0;
		for (j = 0; j < 26; j++) if (chk[j]) c++;
		if (c < 25) cus = true;

		int v = 0;
		for (j = 0; u2[j] != 0; j++) v |= 1 << ((int)(u2[j] - 'a'));
		if (u1[0] == '.') {
			for (j = 0; j < 26; j++) if (v & (1 << j)) chk[j] = true;
		}
		else if(u1[0] == '!') {
			tot++;
			for (j = 0; j < 26; j++) if (!(v & (1 << j))) chk[j] = true;
		}
		else if (u1[0] == '?') {
			tot++;
			chk[u2[0] - 'a'] = true;
		}

		if (cus) cur = tot;
	}
	return !printf("%d\n", tot - cur);
}