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
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-9;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

string in[5550];
vector <int> Vl[5550];
char u[5550];

int cnt[26];
int cnt2[26];
int main() {
	int K, N, i, j, k, l;
	scanf("%d %d", &K, &N);
	for (i = 0; i < K; i++) {
		scanf("%s", u);
		in[i] = string(u);
	}
	for (i = 0; i < N; i++) cnt[in[0][i] - 'a']++;
	for (i = 1; i < K; i++) {
		for (j = 0; j < 26; j++) cnt2[j] = 0;
		for (j = 0; j < N; j++) cnt2[in[i][j] - 'a']++;
		for (j = 0; j < 26; j++) if (cnt[j] != cnt2[j]) return !printf("-1\n");
	}

	bool chk2 = false;
	for (i = 0; i < 26; i++) if (cnt[i] >= 2) chk2 = true;

	for (i = 1; i < K; i++) {
		for (j = 0; j < N; j++) if (in[0][j] != in[i][j]) Vl[i].push_back(j);
		if (Vl[i].size() > 4) return !printf("-1\n");
	}

	for (i = 0; i < N; i++) {
		for (j = i + 1; j < N; j++) {
			swap(in[0][i], in[0][j]);
			for (k = 1; k < K; k++) {
				int c = 0;
				if (in[0][i] != in[k][i]) c++;
				if (in[0][j] != in[k][j]) c++;
				for (auto it : Vl[k]) if (it != i && it != j && in[0][it] != in[k][it]) c++;
				if (c > 2) break;
				if (c == 0 && !chk2) break;
			}
			if (k >= K) return !printf("%s\n", in[0].c_str());
			swap(in[0][i], in[0][j]);
		}
	}
	return !printf("-1\n");
}