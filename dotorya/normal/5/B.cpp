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

vector <string> Vu;
char u[100050];
int main() {
	int L = 0;
	while (fgets(u, 100050, stdin) != NULL) {
		int tl = strlen(u);
		if (u[tl - 1] == '\n') u[--tl] = 0;

		L = max(L, tl);
		Vu.emplace_back(u);
	}

	bool c = false;
	for (int i = 1; i <= L + 2; i++) printf("*");
	printf("\n");
	for (auto it : Vu) {
		printf("*");
		
		int x = L - it.size();
		int x1 = x / 2, x2 = x - x / 2;
		if (x1 != x2) {
			if (c) swap(x1, x2);
			c = !c;
		}
		for (int i = 1; i <= x1; i++) printf(" ");
		printf("%s", it.c_str());
		for (int i = 1; i <= x2; i++) printf(" ");
		printf("*\n");
	}
	for (int i = 1; i <= L + 2; i++) printf("*");
	return !printf("\n");
}