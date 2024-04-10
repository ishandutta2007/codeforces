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
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

int cnt[2000050];

int cnt2[2000050];
int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		int N, i, j;
		scanf("%d", &N);
		for (i = 1; i <= N; i++) {
			scanf("%d", &j);
			cnt[j]++;
		}

		vector <int> Vl;
		for (i = 1; i <= N; i++) if (cnt[i]) Vl.push_back(cnt[i]);
		for (auto it : Vl) {
			cnt2[1]++;
			cnt2[it + 1]++;
			for (int s = 2; s <= it; s++) {
				int q = (s - it % s) % s;
				if ((ll)q * (s - 1) <= it) cnt2[s]++;
			}
		}

		int ans = INF;
		for (int s = 1; s <= N + 1; s++) {
			if (cnt2[s] != Vl.size()) continue;

			int c = 0;
			for (auto it : Vl) {
				int q = (s - it % s) % s;
				c += q + (it - q * (s - 1)) / s;
			}
			ans = min(ans, c);
		}

		printf("%d\n", ans);
		for (i = 1; i <= N + 1; i++) {
			cnt[i] = cnt2[i] = 0;
		}
	}
	return 0;
}