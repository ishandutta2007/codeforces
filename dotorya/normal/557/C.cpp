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
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;

const int IT_MAX = 131072;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;

int cnt[100050];
int cntsum[100050];
ll val[100050];
ll valsum[100050];
int in[100050][3];
vector <int> list[100050];
vector <pii> sorttmp;
int u[100050];

class data {
public:
	int c, v;
	data() {
		data(0, 0);
	}
	data(int a, int b) {
		c = a, v = b;
	}
	
	data operator + (const data & k) {
		return data(c + k.c, v + k.v);
	}
};

data bit[IT_MAX + 50];
void update(int p, data v) {
	while (p <= IT_MAX) {
		bit[p] = bit[p] + v;
		p += p & (-p);
	}
}

data getsum(int p) {
	data rv = data(0, 0);
	while (p > 0) {
		rv = rv + bit[p];
		p -= p&(-p);
	}
	return rv;
}
int main() {
	int N, i, j, t1, t2;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &in[i][1]);
	for (i = 1; i <= N; i++) {
		scanf("%d", &in[i][2]);
		cnt[in[i][1]]++;
		val[in[i][1]] += in[i][2];
		list[in[i][1]].push_back(i);
		sorttmp.push_back(pii(in[i][2], i));
	}
	sort(sorttmp.begin(), sorttmp.end());
	for (i = 0; i < sorttmp.size(); i++) u[sorttmp[i].second] = i+1;
	for (i = 1; i <= 100000; i++) cntsum[i] = cntsum[i - 1] + cnt[i];
	for (i = 100000; i >= 1; i--) valsum[i] = valsum[i + 1] + val[i];

	ll ans = LL_INF;
	for (i = 1; i <= 100000; i++) {
		t1 = cntsum[i];
		t2 = cnt[i];
		if (t1 != 0 && t1 < t2 * 2) ans = min(ans, valsum[i + 1]);
		else if (t2 != 0) {
			t1 = cntsum[i-1]-t2+1;
			int st = 1, en = N, mi, rv = 0;
			while (st <= en) {
				mi = (st + en)/2;
				data t3 = getsum(mi);
				if (t3.c >= t1) {
					rv = t3.v;
					en = mi - 1;
				}
				else st = mi + 1;
			}
			ans = min(ans, rv + valsum[i + 1]);
		}

		for (j = 0; j < list[i].size(); j++) update(u[list[i][j]], data(1,in[list[i][j]][2]));
	}
	printf("%I64d", ans);
	return 0;
}