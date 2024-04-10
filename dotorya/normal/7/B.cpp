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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1034567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

int in[105];
vector <int> Vu;
char u[105];
bool chk[105];
int main() {
	int n = 0, Q, M, i, j;
	scanf("%d %d", &Q, &M);
	while (Q--) {
		scanf("%s", u);
		if (u[0] == 'a') {
			int t;
			scanf("%d", &t);
			for (i = 1; i + t - 1 <= M; i++) {
				for (j = 0; j < t; j++) if (in[i+j]) break;
				if (j == t) break;
			}
			if (i + t - 1 <= M) {
				n++;
				chk[n] = true;
				printf("%d\n", n);
				for (j = i; j <= i + t - 1; j++) in[j] = n;
			}
			else printf("NULL\n");
		}
		if (u[0] == 'd') {
			for (i = 1; i <= M; i++) if (in[i]) Vu.push_back(in[i]);
			for (i = 1; i <= M; i++) in[i] = 0;
			for (i = 0; i < Vu.size(); i++) in[i + 1] = Vu[i];
			Vu.clear();
		}
		if (u[0] == 'e') {
			scanf("%d", &j);
			if (j < 0 || j > 100 || !chk[j]) {
				printf("ILLEGAL_ERASE_ARGUMENT\n");
				continue;
			}
			for (i = 1; i <= M; i++) if (in[i] == j) in[i] = 0;
			chk[j] = false;
		}
	}
	return 0;
}