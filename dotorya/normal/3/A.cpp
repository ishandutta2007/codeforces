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

int IT_MAX = 4096;
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

char in1[10];
char in2[10];
int main() {
	scanf("%s %s", in1, in2);

	printf("%d\n", (int)max(abs(in1[0] - in2[0]), abs(in1[1] - in2[1])));
	while (in1[0] != in2[0] || in1[1] != in2[1]) {
		if (in1[0] < in2[0]) {
			in1[0]++;
			printf("R");
		}
		if (in1[0] > in2[0]) {
			in1[0]--;
			printf("L");
		}
		if (in1[1] > in2[1]) {
			in1[1]--;
			printf("D");
		}
		if (in1[1] < in2[1]) {
			in1[1]++;
			printf("U");
		}
		printf("\n");
	}
	return 0;
}