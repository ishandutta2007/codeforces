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

int IT_MAX = 1 << 20;
ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

vector <int> conn[505];
int inc[505];
int mn[505];
bool dchk[505];
vector <int> Vu;
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
	}
	for (i = 1; i <= N; i++) {
		memset(inc, 0, sizeof(inc));
		for (j = 1; j <= N; j++) for (auto it : conn[j]) inc[it]++;
		mn[i - 1] = 0;
		mn[i] = 1;
		
		Vu.clear();
		memset(dchk, 0, sizeof(dchk));
		for (j = 1; j <= N; j++) {
			if (inc[j] <= mn[j]) {
				dchk[j] = true;
				Vu.push_back(j);
			}
		}
		for (j = 0; j < Vu.size(); j++) {
			for (auto it : conn[Vu[j]]) {
				inc[it]--;
				if (inc[it] <= mn[it] && !dchk[it]) {
					dchk[it] = true;
					Vu.push_back(it);
				}
			}
		}
		if (Vu.size() == N) return !printf("YES\n");
	}
	return !printf("NO\n");
}
//*/