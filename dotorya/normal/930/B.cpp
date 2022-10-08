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
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define Se second
#define Fi first

char in[5050];
vector <int> Vl[5050];

int cnt[26];
int main() {
	scanf("%s", in);

	int N = strlen(in), i, j, k;
	for (i = 0; i < N; i++) Vl[in[i] - 'a'].push_back(i);
	
	int ans = 0;
	for (i = 0; i < 26; i++) {
		if (Vl[i].empty()) continue;

		int mx = 0;
		for (j = 1; j < N; j++) {
			memset(cnt, 0, sizeof(cnt));
			for (auto it : Vl[i]) cnt[in[(it + j) % N] - 'a']++;
			
			int c = 0;
			for (k = 0; k < 26; k++) if (cnt[k] == 1) c++;
			mx = max(mx, c);
		}
		ans += mx;
	}
	return !printf("%.20lf\n", (db)ans / N);
}