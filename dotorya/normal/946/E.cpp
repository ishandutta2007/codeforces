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

char u[200050];
int in[200050];
int uin[200050];
int cnt[200050];
int ans[200050];
bool isValid(int N, int mi) {
	vector <int> Vu;
	int i, j;
	for (i = 0; i < 10; i++) cnt[i] = 0;
	for (i = N - 1; i >= N - mi; i--) cnt[in[i]] ^= 1;
	for (i = 0; i < 10; i++) for (j = 1; j <= cnt[i]; j++) Vu.push_back(i);
	while (Vu.size() < N - mi) Vu.push_back(0);
	sort(all(Vu));
	reverse(all(Vu));

	if (Vu.size() > N - mi) return false;
	for (i = N - 1; i >= N - mi; i--) uin[i] = in[i];
	for (i = N - mi - 1; i >= 0; i--) uin[i] = Vu[i];

	for (i = N - 1; i >= 0; i--) {
		if (in[i] == uin[i]) continue;
		if (in[i] > uin[i]) return true;
		return false;
	}
	return true;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", u);
		int N = strlen(u), i, j;
		for (i = 0; i < N; i++) in[i] = u[N - 1 - i] - '0';
		in[0]--;
		for (i = 0; i + 1 < N; i++) {
			if (in[i] < 0) {
				in[i] += 10;
				in[i + 1]--;
			}
		}
		if (in[N-1] == 0) N--;

		if (N % 2 == 1) {
			N--;
			for (i = 0; i < N; i++) in[i] = 9;
		}

		for (i = 0; i <= N - 2; i++) if (in[i] != 0) break;
		if (i > N - 2 && in[N-1] == 1) {
			N -= 2;
			for (i = 0; i < N; i++) in[i] = 9;
		}

		int st = 1, en = N, mi, rv = 0;
		while (st <= en) {
			mi = (st + en) / 2;

			if (isValid(N, mi)) {
				rv = mi;
				st = mi + 1;
			}
			else en = mi - 1;
		}
		if (rv == N) for (i = N - 1; i >= 0; i--) ans[i] = in[i];
		else {
			int p = N - rv - 1;
			for (i = p - 1; i >= 0; i--) in[i] = 9;
			in[p]--;
			while (!isValid(N, rv + 1)) in[p]--;

			vector <int> Vu;
			for (i = 0; i < 10; i++) cnt[i] = 0;
			for (i = N - 1; i >= N - rv - 1; i--) cnt[in[i]] ^= 1;
			for (i = 0; i < 10; i++) for (j = 1; j <= cnt[i]; j++) Vu.push_back(i);

			while (Vu.size() < N - rv - 1) Vu.push_back(9);
			for (i = N - 1; i >= N - rv - 1; i--) ans[i] = in[i];
			for (i = N - rv - 2; i >= 0; i--) ans[i] = Vu[i];
		}
		for (i = N - 1; i >= 0; i--) printf("%d", ans[i]);
		printf("\n");
	}
	return 0;
}