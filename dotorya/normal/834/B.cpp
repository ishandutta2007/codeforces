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

int IT_MAX = 1 << 17;
const ll MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db EPS = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

int lr[26][2];
char in[1000050];

vector <pii> Vu;
int main() {
	int N, K, i;
	scanf("%d %d %s", &N, &K, in + 1);
	
	for (i = 0; i < 26; i++) lr[i][0] = INF, lr[i][1] = -INF;
	for (i = 1; i <= N; i++) {
		int t = in[i] - 'A';
		lr[t][0] = min(lr[t][0], i);
		lr[t][1] = max(lr[t][1], i);
	}
	for (i = 0; i < 26; i++) {
		if (lr[i][0] == INF) continue;
		Vu.emplace_back(lr[i][0], -1);
		Vu.emplace_back(lr[i][1], 1);
	}

	sort(all(Vu));
	int s = 0;
	for (auto it : Vu) {
		s -= it.second;
		if (s > K) return !printf("YES\n");
	}
	return !printf("NO\n");
}