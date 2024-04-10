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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x1f3f3f3f;
const ll LL_INF = 1034567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

multiset <int> Sx;
int in[100050];
int main() {
	int N, K, i, j;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);

	int ans = -1;
	vector <int> Va;
	for (i = 1, j = 1; i <= N; i++) {
		while (j <= N) {
			if (Sx.empty()) {
				Sx.insert(in[j++]);
				continue;
			}
			auto it1 = Sx.begin();
			auto it2 = Sx.end();
			it2--;

			if (abs(in[j] - *it1) > K || abs(in[j] - *it2) > K) break;
			Sx.insert(in[j++]);
		}
		if (ans < j - i) {
			ans = j - i;
			Va.clear();
		}
		if (ans == j - i) Va.push_back(i);

		Sx.erase(Sx.lower_bound(in[i]));
	}
	printf("%d %d\n", ans, (int)Va.size());
	for (auto it : Va) printf("%d %d\n", it, it + ans - 1);
	return 0;
}