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

map <vector<string>, string> Mx;
vector <string> V;

vector <string> Vu;
char u[5];
void aa(char c) {
	int i, j;
	for (i = 0; i < 3; i++) {
		if (V[i][0] == V[i][1] && V[i][0] == V[i][2] && V[i][0] != '.') {
			if (V[i][0] == 'X') Mx[V] = string("the first player won");
			else Mx[V] = string("the second player won");
			return;
		}
		if (V[0][i] == V[1][i] && V[0][i] == V[2][i] && V[0][i] != '.') {
			if (V[0][i] == 'X') Mx[V] = string("the first player won");
			else Mx[V] = string("the second player won");
			return;
		}
	}
	if (V[0][0] == V[1][1] && V[0][0] == V[2][2] && V[0][0] != '.') {
		if (V[0][0] == 'X') Mx[V] = string("the first player won");
		else Mx[V] = string("the second player won");
		return;
	}
	if (V[0][2] == V[1][1] && V[0][2] == V[2][0] && V[0][2] != '.') {
		if (V[0][2] == 'X') Mx[V] = string("the first player won");
		else Mx[V] = string("the second player won");
		return;
	}

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) if (V[i][j] == '.') break;
		if (j < 3) break;
	}
	if (i >= 3) {
		Mx[V] = string("draw");
		return;
	}

	if (c == 'X') Mx[V] = string("first");
	else Mx[V] = string("second");

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (V[i][j] != '.') continue;
			V[i][j] = c;
			aa('0' ^ 'X' ^ c);
			V[i][j] = '.';
		}
	}
}
int main() {
	int i, j;
	for (i = 0; i < 3; i++) V.push_back(string("..."));
	aa('X');

	for (i = 0; i < 3; i++) {
		scanf("%s", u);
		Vu.emplace_back(u);
	}
	if (!Mx.count(Vu)) printf("illegal\n");
	else printf("%s\n", Mx[Vu].c_str());
	return 0;
}