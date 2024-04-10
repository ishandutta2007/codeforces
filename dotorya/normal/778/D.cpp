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

char in[55][55];

char u[55][55];
vector <pii> getans(int N, int M) {
	bool rchk = false;
	int i, j;
	if (N % 2 == 1) {
		for (i = 0; i < M; i++) {
			for (j = 0; j < N; j++) {
				u[i][j] = in[j][i];
				if (u[i][j] == 'U') u[i][j] = 'L';
				else if (u[i][j] == 'L') u[i][j] = 'U';
				else if (u[i][j] == 'D') u[i][j] = 'R';
				else u[i][j] = 'D';
			}
		}
		swap(N, M);
		rchk = true;
	}
	else for (i = 0; i < N; i++) for (j = 0; j < M; j++) u[i][j] = in[i][j];

	vector <pii> rv;
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j += 2) {
			vector <pii> Vu;

			char c = 'U';
			int x = j, y = i;
			while (u[x][y] != c) {
				Vu.emplace_back(x, y);
				if (c == 'U') {
					x++;
					c = 'L';
				}
				else {
					y++;
					c = 'U';
				}
			}
			reverse(Vu.begin(), Vu.end());
			for (auto it : Vu) {
				rv.push_back(it);
				int x = it.first, y = it.second;
				if (u[x][y] == 'L') {
					assert(u[x + 1][y] == 'L' && u[x][y + 1] == 'R' && u[x + 1][y + 1] == 'R');
					u[x][y] = u[x][y+1] = 'U';
					u[x + 1][y] = u[x + 1][y + 1] = 'D';
				}
				else {
					assert(u[x][y] == 'U' && u[x + 1][y] == 'D' && u[x][y + 1] == 'U' && u[x + 1][y + 1] == 'D');
					u[x][y] = u[x + 1][y] = 'L';
					u[x][y + 1] = u[x + 1][y + 1] = 'R';
				}
			}
		}
	}
	if (rchk) for (auto &it : rv) it = pii(it.second, it.first);
	return rv;
}
int main() {
	int N, M, i;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) scanf("%s", in[i]);
	vector <pii> V1 = getans(N, M);
	for (i = 0; i < N; i++) scanf("%s", in[i]);
	vector <pii> V2 = getans(N, M);
	reverse(V2.begin(), V2.end());
	printf("%d\n", (int)V1.size() + (int)V2.size());
	for (auto it : V1) printf("%d %d\n", it.first + 1, it.second + 1);
	for (auto it : V2) printf("%d %d\n", it.first + 1, it.second + 1);
	return 0;
}