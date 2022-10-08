//*
#include <algorithm>
#include <iostream>
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
#include <string>
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
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;

const int IT_MAX = 131072;
const int MOD = 1000000007;
const int INF = 2034567891;
const ll LL_INF = 1234567890123456789ll;

ll in[100050];
pli sor[100050];
int ch[100050];
int dp[100050];
int rev[100050];

pii it[2 * IT_MAX + 50];
vector <int> ANS;
void update(int pos, pii val) {
	it[pos] = val;
	while (pos > 1) {
		pos /= 2;
		it[pos] = max(it[pos*2], it[pos*2+1]);
	}
}

pii getmx(int p1, int p2) {
	if (p1 > p2) return pii(0,0);
	pii t = pii(0,0);
	if (p1 == p2) return it[p1];
	if (p1 % 2 == 1) {
		t = it[p1];
		p1++;
	}
	if (p1 == p2) return max(t,it[p1]);
	if (p2 % 2 == 0) {
		t = max(t,it[p2]);
		p2--;
	}
	return max(t, getmx(p1 / 2, p2 / 2));
}
int main() {
	int N, i;
	ll D;
	scanf("%d %I64d", &N, &D);
	for (i = 1; i <= N; i++) {
		scanf("%I64d", &in[i]);
		sor[i] = pli(in[i], i);
	}
	sort(sor + 1, sor + N + 1);
	for (i = 1; i <= N; i++) ch[sor[i].second] = i;
	for (i = 1; i <= N; i++) {
		int st = 1, en = N, mi, rv = 0;
		while (st <= en) {
			mi = (st + en) / 2;
			if (sor[mi].first <= in[i] - D) {
				rv = mi;
				st = mi + 1;
			}
			else en = mi - 1;
		}
		pii ans = getmx(IT_MAX, IT_MAX + rv - 1);
		st = 1, en = N, mi, rv = N+1;
		while (st <= en) {
			mi = (st + en) / 2;
			if (sor[mi].first >= in[i] + D) {
				rv = mi;
				en = mi - 1;
			}
			else st = mi + 1;
		}
		ans = max(ans, getmx(IT_MAX + rv - 1, IT_MAX + N - 1));
		dp[i] = ans.first + 1;
		rev[i] = ans.second;
		update(IT_MAX + ch[i] - 1, pii(dp[i], i));
	}

	int p = 1;
	for (i = 2; i <= N; i++) if (dp[p] < dp[i]) p = i;
	printf("%d\n", dp[p]);
	while (p != 0) {
		ANS.push_back(p);
		p = rev[p];
	}
	for (i = ANS.size() - 1; i >= 0; i--) printf("%d ", ANS[i]);
	return 0;
}
//*/