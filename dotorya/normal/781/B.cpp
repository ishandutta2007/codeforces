#include <algorithm>
#include <assert.h>
#include <bitset>
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
#include <unordered_map>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
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

int IT_MAX = 1 << 20;
const ll MOD = 1234567891;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-6;

map <string, int> Mx;
string Mv[2050];
int ch(string x) {
	if (Mx.count(x)) return Mx[x];
	int t = Mx.size() + 1;
	Mx[x] = t;
	Mv[t] = x;
	return t;
}

int ans[2050];

vector <pair<pii, int>> Ve;
bool echk[2050];
bool vchk[2050];

char u1[1050];
char u2[1050];

int r[2050];
int ecnt[2050];
int vcnt[2050];

int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}

vector <int> conn[2050];
int deg[2050];
int in[2050][2];
int cnt[2050];
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%s %s", u1, u2);
		string x1 = string(u1, u1 + 2);
		string x2 = x1;
		x1 += u1[2];
		x2 += u2[0];

		int t1 = ch(x1), t2 = ch(x2);
		in[i][0] = t1, in[i][1] = t2;
		cnt[t1]++;
	}
	for (i = 1; i <= N; i++) {
		int t1 = in[i][0], t2 = in[i][1];
		if (cnt[t1] >= 2 || t1 == t2) {
			if (vchk[t2]) return !printf("NO\n");
			vchk[t2] = true;
			ans[i] = t2;
		}
		else {
			Ve.emplace_back(pii(t1, t2), i);
			deg[t1]++;
			deg[t2]++;
			conn[t1].push_back(t2);
			conn[t2].push_back(t1);
		}
	}
	while (1) {
		for (i = 0; i < Ve.size(); i++) if (!echk[i]) break;
		if (i >= Ve.size()) break;

		bool tc = false;
		for (i = 0; i < Ve.size(); i++) {
			if (echk[i]) continue;
			int t1 = Ve[i].first.first, t2 = Ve[i].first.second;
			if (vchk[t1] && vchk[t2]) return !printf("NO\n");
			if (vchk[t2]) swap(t1, t2);
			if (vchk[t1]) {
				echk[i] = vchk[t2] = tc = true;
				ans[Ve[i].second] = t2;
				for (auto it : conn[t2]) deg[it]--;
			}
		}
		if (tc) continue;
		for (i = 0; i < Ve.size(); i++) {
			if (echk[i]) continue;
			int t1 = Ve[i].first.first, t2 = Ve[i].first.second;
			if (vchk[t1] && vchk[t2]) return !printf("NO\n");
			if (deg[t2] == 1) swap(t1, t2);
			if (deg[t1] == 1 && !vchk[t1]) {
				ans[Ve[i].second] = t1;
				echk[i] = vchk[t1] = tc = true;
				for (auto it : conn[t1]) deg[it]--;
			}
		}
		if (tc) continue;
		for (i = 0; i < Ve.size(); i++) {
			if (echk[i]) continue;
			int t1 = Ve[i].first.first, t2 = Ve[i].first.second;
			if (vchk[t2]) swap(t1, t2);
			if (vchk[t1]) return !printf("NO\n");
			echk[i] = vchk[t1] = true;
			ans[Ve[i].second] = t1;
			for (auto it : conn[t1]) deg[it]--;
			break;
		}
	}
	printf("YES\n");
	for (i = 1; i <= N; i++) printf("%s\n", Mv[ans[i]].c_str());
	return 0;
}