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
#pragma comment(linker, "/STACK:1048576")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble
#define rf(x) (x)=0;while(*p<48)p++;while(47<*p)(x)=((x)<<3)+((x)<<1)+(*p++&15);

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple <int, int, int> t3;

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

char in1[1050];
char in2[1050];

multiset <int> Sx;

int main() {
	int N, i;
	scanf("%d", &N);
	scanf("%s %s", in1, in2);

	sort(in1, in1 + N);
	sort(in2, in2 + N);
	
	int a1 = 0, a2 = 0;
	for (i = N - 1; i >= 0; i--) {
		Sx.insert(in2[i]);
		if (Sx.lower_bound(in1[i]) != Sx.end()) Sx.erase(Sx.lower_bound(in1[i]));
		else a1++;
	}
	Sx.clear();
	for (i = N - 1; i >= 0; i--) {
		Sx.insert(in2[i]);
		if (Sx.lower_bound(in1[i] + 1) != Sx.end()) {
			Sx.erase(Sx.lower_bound(in1[i] + 1));
			a2++;
		}
	}
	return !printf("%d\n%d\n", a1, a2);
}