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

int IT_MAX = 1 << 20;
ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

int cnt[100050];
int u1[20];
int u2[20];
int readInt(int* u) {
	int L = 0;
	ll x;
	scanf("%lld", &x);
	for (int i = 0; i < 20; i++, x /= 10) {
		u[i] = (int)(x % 10);
		if (u[i]) L = i + 1;
	}
	return L;
}
int main() {
	int L1 = readInt(u1);
	int L2 = readInt(u2);

	int i, j, k;
	for (i = 0; i < L1; i++) cnt[u1[i]]++;
	
	if (L1 < L2) {
		sort(u1, u1 + L1, [](int a, int b) {
			return a > b;
		});
		for (i = 0; i < L1; i++) printf("%d", u1[i]);
		return !printf("\n");
	}
	
	for (i = L1 - 1; i >= 0; i--) {
		if (cnt[u2[i]]) {
			cnt[u2[i]]--;
			vector <int> Vu;
			for (j = 0; j < 10; j++) for (k = 0; k < cnt[j]; k++) Vu.push_back(j);
			reverse(all(Vu));

			bool chk = true;
			for (j = i - 1; j >= 0; j--) {
				if (Vu[j] == u2[j]) continue;
				if (Vu[j] > u2[j]) chk = false;
				break;
			}
			if (chk) {
				u1[i] = u2[i];
				continue;
			}
			cnt[u2[i]]++;
		}
		for (j = u2[i] - 1; j >= 0; j--) if (cnt[j]) break;

		u1[i] = j;
		cnt[j]--;
		vector <int> Vu;
		for (j = 0; j < 10; j++) for (k = 0; k < cnt[j]; k++) Vu.push_back(j);
		for (j = 0; j < i; j++) u1[j] = Vu[j];
		break;
	}
	for (i = L1 - 1; i >= 0; i--) printf("%d", u1[i]);
	return !printf("\n");
}
//*/