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
typedef pair <char, int> pci;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX;
const int MOD = 9901;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;

int in[200050];
ll sum[200050];

vector <pil> V1;
vector <pil> V2;
int main() {
	int N, i;
	scanf("%d", &N);
	if (N == 1) return printf("0"), 0;
	for (i = 1; i <= N; i++) {
		scanf("%d", &in[i]);
		sum[i] = sum[i - 1] + in[i];
	}

	V1.push_back(pil(0, 0));
	for (i = 1; i <= N; i++) {
		pil tmp = pil(i, sum[i]);
		while (V1.size() > 1) {
			ll x1 = V1[V1.size() - 2].first, y1 = V1[V1.size() - 2].second;
			ll x2 = V1.back().first, y2 = V1.back().second;
			ll x3 = tmp.first, y3 = tmp.second;
			if (y1*(x3 - x1) + (y3 - y1)*(x2 - x1) > y2*(x3 - x1)) break;
			V1.pop_back();
		}
		V1.push_back(tmp);
	}

	V2.push_back(pil(0, 0));
	for (i = 1; i <= N; i++) {
		pil tmp = pil(i, sum[i]);
		while (V2.size() > 1) {
			ll x1 = V2[V2.size() - 2].first, y1 = V2[V2.size() - 2].second;
			ll x2 = V2.back().first, y2 = V2.back().second;
			ll x3 = tmp.first, y3 = tmp.second;
			if (y1*(x3 - x1) + (y3 - y1)*(x2 - x1) < y2*(x3 - x1)) break;
			V2.pop_back();
		}
		V2.push_back(tmp);
	}

	db ans = LL_INF;
	for (i = 0; i + 1 < V1.size(); i++) {
		db x1 = V1[i].first, y1 = V1[i].second;
		db x2 = V1[i + 1].first, y2 = V1[i + 1].second;
		db t = 1.0 * (y1 - y2) / (x2 - x1);

		int st = 0, en = V2.size() - 2, mi, rv = -1;
		while (st <= en) {
			mi = (st + en) / 2;
			if (t * V2[mi].first + V2[mi].second < t * V2[mi + 1].first + V2[mi + 1].second) {
				rv = mi;
				st = mi + 1;
			}
			else en = mi - 1;
		}

		ans = min(ans, V2[rv + 1].first * t + V2[rv + 1].second - (x1*t + y1));
	}

	for (i = 0; i + 1 < V2.size(); i++) {
		db x1 = V2[i].first, y1 = V2[i].second;
		db x2 = V2[i + 1].first, y2 = V2[i + 1].second;
		db t = 1.0 * (y1 - y2) / (x2 - x1);

		int st = 0, en = V1.size() - 2, mi, rv = -1;
		while (st <= en) {
			mi = (st + en) / 2;
			if (t * V1[mi].first + V1[mi].second > t * V1[mi + 1].first + V1[mi + 1].second) {
				rv = mi;
				st = mi + 1;
			}
			else en = mi - 1;
		}

		ans = min(ans, -(V1[rv + 1].first * t + V1[rv + 1].second) + (x1*t + y1));
	}

	printf("%.20lf", ans);
	return 0;
}
//*/