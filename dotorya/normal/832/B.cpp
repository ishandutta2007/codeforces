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
#pragma comment(linker, "/STACK:1048576")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple <int, int, int> t3;

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

bool good[26];
char pat[100050];
char u[100050];
int main() {
	int i, j, k;
	scanf("%s", u);
	for (i = 0; u[i] != 0; i++) good[u[i] - 'a'] = true;
	scanf("%s", pat);

	int Q;
	scanf("%d", &Q);
	while (Q--) {
		scanf("%s", u);
		int L = (int)strlen(u) - (int)strlen(pat) + 1;
		if (L < 0) {
			printf("NO\n");
			continue;
		}
		for (i = 0, j = 0; u[i] != 0 && pat[j] != 0;) {
			if (pat[j] >= 'a' && pat[j] <= 'z') {
				if (u[i] != pat[j]) break;
				i++, j++;
				continue;
			}
			if (pat[j] == '?') {
				if (!good[u[i] - 'a']) break;
				i++, j++;
				continue;
			}
			for (k = i; k < i + L; k++) if (good[u[k] - 'a']) break;
			if (k < i + L) break;
			i += L, j++;
		}
		if (u[i] == 0 && (pat[j] == 0 || pat[j] == '*')) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}