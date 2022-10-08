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
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

vector <int> Vq;

vector <int> Vl[6050];
int in[6050][2];
int ans[6050];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, i, j;
		scanf("%d", &N);
		for (i = 1; i <= N; i++) {
			int t1, t2;
			scanf("%d %d", &t1, &t2);
			in[i][0] = t1, in[i][1] = t2;
			Vl[t1].push_back(i);
		}

		int st = 0;
		for (i = 1; i <= 6002; i++) {
			for (auto it : Vl[i]) Vq.push_back(it);
			while (st < Vq.size()) {
				if (in[Vq[st]][1] >= i) break;
				st++;
			}
			if (st < Vq.size()) {
				ans[Vq[st]] = i;
				st++;
			}
		}
		for (i = 1; i <= N; i++) printf("%d ", ans[i]);
		printf("\n");

		for (i = 1; i <= N; i++) ans[i] = 0;
		Vq.clear();
		for (i = 1; i <= 5000; i++) Vl[i].clear();
	}
	return 0;
}
//*/