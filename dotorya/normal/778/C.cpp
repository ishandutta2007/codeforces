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
const ll MOD = 98765431;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const db ERR = 1E-6;

int son[300050][26];
int par[300050];
int dep[300050];
int cnt[300050];
vector <int> Vu;
vector <int> Vd[300050];
int main() {
	int N, i, j, k;
	char c[2];
	scanf("%d", &N);

	for (i = 1; i < N; i++) {
		int t1, t2;
		scanf("%d %d %s", &t1, &t2, c);
		son[t1][c[0] - 'a'] = t2;
	}

	int mxd = 0;
	dep[1] = 0;
	Vu.push_back(1);
	for (i = 0; i < Vu.size(); i++) {
		mxd = max(mxd, dep[Vu[i]]);
		Vd[dep[Vu[i]]].push_back(Vu[i]);
		for (j = 0; j < 26; j++) {
			if (!son[Vu[i]][j]) continue;
			par[son[Vu[i]][j]] = Vu[i];
			dep[son[Vu[i]][j]] = dep[Vu[i]] + 1;
			Vu.push_back(son[Vu[i]][j]);
		}
	}

	vector <vector<int>> Vu;
	for (i = 1; i <= mxd; i++) {
		vector <vector<int>> Vu2;
		for (auto it : Vu) {
			for (j = 0; j < 26; j++) {
				vector <int> Vu3;
				Vu3.push_back(it[0]);
				for (k = 1; k < it.size(); k++) {
					int it2 = it[k];
					if (son[it2][j]) Vu3.push_back(son[it2][j]);
				}
				if (Vu3.size() >= 3) Vu2.push_back(Vu3);
				Vu3.clear();
			}
		}
		for (auto it : Vd[i - 1]) {
			vector <int> Vu3;
			Vu3.push_back(i);
			for (j = 0; j < 26; j++) if (son[it][j]) Vu3.push_back(son[it][j]);
			if(Vu3.size() >= 3) Vu2.push_back(Vu3);
			Vu3.clear();
		}
		for (auto it : Vu2) cnt[it[0]] += it.size() - 2;
		Vu = Vu2;
	}
	for (i = 1; i <= mxd; i++) {
		for (auto it : Vd[i - 1]) {
			for (j = 0; j < 26; j++) if (son[it][j]) break;
			if (j != 26) cnt[i]++;
		}
	}

	int ans = 1;
	for (i = 2; i <= mxd; i++) if (cnt[i] > cnt[ans]) ans = i;
	return !printf("%d\n%d\n", N - cnt[ans], ans);
}