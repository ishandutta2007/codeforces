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
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

string in1[1050];
int in2[1050];
char u[1050];

map <string, int> Mx;
set <string> Sx;
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%s %d", u, &in2[i]);
		in1[i] = string(u);
		Mx[in1[i]] += in2[i];
	}

	int mx = 0;
	for (auto it : Mx) mx = max(mx, it.second);
	for (auto it : Mx) if (it.second == mx) Sx.insert(it.first);
	Mx.clear();
	for (i = 1; i <= N; i++) {
		Mx[in1[i]] += in2[i];
		if (Mx[in1[i]] >= mx && Sx.count(in1[i])) return !printf("%s\n", in1[i].c_str());
	}
	return 0;
}