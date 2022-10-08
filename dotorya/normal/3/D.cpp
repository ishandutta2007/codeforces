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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

char in[100050];
int mn[100050];
int val[100050][2];
priority_queue <pii, vector<pii>, greater<pii>> Hx;
vector <int> Vu;

int pos[100050];
int main() {
	scanf("%s", in + 1);

	int N = strlen(in + 1), i, c = 0;
	if (N % 2) return !printf("-1\n");
	for (i = 1; i <= N; i++) if (in[i] == '?') c++;
	for (i = 1; i <= c; i++) scanf("%d %d", &val[i][0], &val[i][1]);
	
	int c1 = 0, c2 = 0;
	for (i = 1; i <= N; i++) {
		if (in[i] == '?') {
			c1++;
			pos[c1] = i;
		}
		else if (in[i] == '(') c2++;
		else c2--;

		if (c1 > c2) mn[c1] = max(mn[c1], (c1 - c2 + 1) / 2);
	}

	int x = (c1 - c2) / 2;
	if (x < 0 || x > c) return !printf("-1\n");

	for (i = 0; i <= c; i++) {
		if (i) mn[i] = max(mn[i], mn[i - 1]);
		if (mn[i] > i) return !printf("-1\n");
		if (mn[i] > x) return !printf("-1\n");
	}
	mn[c] = x;
	for (i = 1; i <= c; i++) {
		int t = mn[i] - mn[i - 1];
		while (t--) Vu.push_back(i);
	}

	ll ans = 0;
	for (i = 1; i <= c; i++) ans += val[i][1];
	int p = 0;
	for (auto it : Vu) {
		while (p < it) {
			p++;
			Hx.emplace(val[p][0] - val[p][1], pos[p]);
		}
		in[Hx.top().second] = '(';
		ans += Hx.top().first;
		Hx.pop();
	}
	for (i = 1; i <= N; i++) if (in[i] == '?') in[i] = ')';
	printf("%lld\n", ans);
	printf("%s\n", in + 1);
	return 0;
}