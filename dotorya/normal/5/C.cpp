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

int IT_MAX = 1 << 21;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1034567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

int indt[4200000];
void update(int p, int v) {
	p += IT_MAX + 1000000;
	indt[p] = v;
	for (p /= 2; p; p /= 2) indt[p] = max(indt[2 * p], indt[2 * p + 1]);
}
int getmx(int p1, int p2) {
	p1 += IT_MAX + 1000000;
	p2 += IT_MAX + 1000000;

	int rv = 0;
	for (; p1 <= p2; p1 /= 2, p2 /= 2) {
		if (p1 % 2 == 1) rv = max(rv, indt[p1++]);
		if (p2 % 2 == 0) rv = max(rv, indt[p2--]);
	}
	return rv;
}

int pos[2000050];
char in[1000050];
int sum[1000050];
vector <int> Vu[2000050];
int main() {
	scanf("%s", in + 1);

	int N = strlen(in + 1), i, j;

	int ans = 0, cnt = 1;
	pos[1000000] = 1;
	Vu[1000000].push_back(1);
	for (i = 1; i <= N; i++) {
		sum[i] = sum[i - 1];
		if (in[i] == ')') sum[i]--;
		else sum[i]++;

		int t = sum[i] + 1000000;
		if (t == 0) return !printf("0 1\n");

		int sp = pos[t-1] + 1;
		int ap = lower_bound(all(Vu[t]), sp) - Vu[t].begin();
		if (ap < Vu[t].size()) {
//			printf("%d %d\n", Vu[t][ap], i);
			int tans = i - Vu[t][ap] + 1;
			if (ans < tans) {
				ans = tans;
				cnt = 0;
			}
			if (ans == tans) cnt++;
		}
		
		Vu[t].push_back(i + 1);
		pos[t] = i + 1;
	}
	return !printf("%d %d\n", ans, cnt);
}