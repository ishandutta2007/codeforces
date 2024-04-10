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

char u[105];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", u);

		int i, j;
		for (i = 0; u[i] >= 'A' && u[i] <= 'Z'; i++);
		for (; u[i] >= '0' && u[i] <= '9'; i++);
		if (u[i] == 0) {
			int t1 = 0, t2 = 0, c = 0;
			for (i = 0; u[i] >= 'A' && u[i] <= 'Z'; i++) {
				c++;
				t1 = 26 * t1 + u[i] - 'A';
			}
			int p = i;
			for (i = c - 1; i >= 1; i--) {
				int t = 1;
				for (j = 1; j <= i; j++) t *= 26;
				t1 += t;
			}
			for (i = p; u[i] >= '0' && u[i] <= '9'; i++) t2 = 10 * t2 + u[i] - '0';
			printf("R%dC%d\n", t2, t1 + 1);
		}
		else {
			int t1 = 0, t2 = 0;
			for (i = 1; u[i] >= '0' && u[i] <= '9'; i++) t2 = 10 * t2 + u[i] - '0';
			for (i = i + 1; u[i] >= '0' && u[i] <= '9'; i++) t1 = 10 * t1 + u[i] - '0';

			t1--;
			for (i = 1, j = 26; t1 >= j; i++, j *= 26) t1 -= j;
			vector <char> Va;
			for (j = 0; j < i; j++) {
				Va.push_back('A' + t1 % 26);
				t1 /= 26;
			}
			reverse(Va.begin(), Va.end());
			for (auto it : Va) printf("%c", it);
			printf("%d\n", t2);
		}
	}
	return 0;
}