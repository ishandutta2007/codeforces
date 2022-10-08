#include <algorithm>
#include <assert.h>
#include <complex>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <locale.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <cmath>
#include <vector>
#include <deque>
//#include <unordered_set>
//#include <unordered_map>

#pragma warning(disable:4996)
using namespace std;

#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <ldb, ldb> pdd;

int IT_MAX = 1<<19;
const int MOD = 100000000;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-10;

int in[200050];

int cnt[200050];

multiset <int> Sx;
bool chk[200050];
int main() {
	int N, S, i;
	int ans = 0;
	scanf("%d %d", &N, &S);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);
	if (in[S] != 0) {
		ans++;
		in[S] = 0;
	}

	sort(in + 1, in + N + 1);
	for (i = 0; i < N; i++) Sx.insert(i);
	for (i = 1; i <= N; i++) Sx.erase(in[i]);
	
	bool c0 = false;
	for (i = 1; i <= N; i++) {
		if (in[i] != 0) continue;
		if (!c0) c0 = true;
		else {
			auto it = Sx.begin();
			in[i] = *it;
			Sx.erase(it);
			ans++;
		}
	}
	Sx.clear();
	for (i = 1; i <= N; i++) Sx.insert(in[i]);
	for (i = 1; i <= N; i++) cnt[in[i]]++;

	int c = 0;
	while (1) {
		while (cnt[c]) c++;

		auto it = Sx.end();
		it--;
		if (*it <= c) break;
		ans++;
		cnt[*it]--;
		cnt[c]++;
		Sx.erase(it);
		Sx.insert(c);
	}
	return !printf("%d\n", ans);
}