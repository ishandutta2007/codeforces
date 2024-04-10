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
ll MOD = 1000000007;
//const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first
const int INF = 2e9;

char in[5050];
int main() {
	scanf("%s", in + 1);
	int N = strlen(in + 1), i, j;

	int ans = 0;
	for (i = 1; i <= N; i++) {
		int cnt = 0;
		int c = 0;
		int cur = 0;
		int mn = 0;
		for (j = i; j <= N; j++) {
			if (in[j] == '?') {
				c++;
				mn = cur;
			}
			else if (in[j] == '(') {
				cur++;
				mn = min(mn, cur);
			}
			else {
				cur--;
				mn = min(mn, cur);
			}

			cnt = max(cnt, (c - cur + 1) / 2);
			if (cnt > c) break;

			if (j % 2 == i % 2) continue;

			int x = (c - cur) / 2;
			if (x < 0 || x > c) continue;
			if (x < cnt) continue;
			ans++;
			//printf("%d %d\n", i, j);
		}
	}
	return !printf("%d\n", ans);
}
//*/