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

int IT_MAX = 1 << 17;
ll MOD = 1000000007;
//const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first
const int INF = 2e9;

vector <int> Vl;
vector <pii> conn[105];
int inc[105];
int dp[105][105][26];

int main() {
	int N, M, i, j, k;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; i++) {
		int t1, t2;
		char c[2];
		scanf("%d %d %s", &t1, &t2, c);
		conn[t1].emplace_back(c[0] - 'a', t2);
		inc[t2]++;
	}

	for (i = 1; i <= N; i++) if (inc[i] == 0) Vl.push_back(i);
	for (i = 0; i < Vl.size(); i++) {
		for (auto it : conn[Vl[i]]) {
			if (--inc[it.second] == 0) Vl.push_back(it.second);
		}
	}

	for (i = N-1; i >= 0; i--) {
		for (j = i; j >= 0; j--) {
			int t1 = Vl[i], t2 = Vl[j];
			for (k = 0; k < 26; k++) {
				int x = 0;
				for (auto it : conn[t1]) {
					if (it.first < k) continue;
					if (!dp[t2][it.second][it.first]) {
						x = 1;
						break;
					}
				}
				dp[t1][t2][k] = x;
			}

			swap(t1, t2);
			for (k = 0; k < 26; k++) {
				int x = 0;
				for (auto it : conn[t1]) {
					if (it.first < k) continue;
					if (!dp[t2][it.second][it.first]) {
						x = 1;
						break;
					}
				}
				dp[t1][t2][k] = x;
			}
		}
	}

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			printf("%c", !dp[i][j][0] + 'A');
		}
		printf("\n");
	}
	return 0;
}
//*/