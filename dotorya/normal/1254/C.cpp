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
int IT_MAX = 1 << 12;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

ll sz[100050];
int main() {
	int N, i, j, k;
	scanf("%d", &N);

	vector <int> Vl[2];
	for (i = 3; i <= N; i++) {
		printf("2 1 2 %d\n", i);
		fflush(stdout);

		int t;
		scanf("%d", &t);
		if (t == -1) Vl[0].push_back(i);
		else Vl[1].push_back(i);
	}

	vector <int> Va;
	for (int q = 0; q < 2; q++) {
		int S = 1, E = 2;
		if (q == 1) swap(S, E);

		Va.push_back(S);
		if (Vl[q].size() <= 1) {
			for (auto it : Vl[q]) Va.push_back(it);
			continue;
		}

		ll mx = -1, mxp = -1;
		for (i = 0; i < Vl[q].size(); i++) {
			printf("1 %d %d %d\n", S, E, Vl[q][i]);
			fflush(stdout);
			
			scanf("%lld", &sz[i]);
			if (mx < sz[i]) {
				mx = sz[i];
				mxp = i;
			}
		}

		vector <int> Vu[2];
		for (i = 0; i < Vl[q].size(); i++) {
			if (i == mxp) continue;

			printf("2 %d %d %d\n", S, Vl[q][mxp], Vl[q][i]);
			fflush(stdout);
			int t;
			scanf("%d", &t);
			if (t == 1) Vu[1].push_back(i);
			else Vu[0].push_back(i);
		}

		sort(all(Vu[0]), [&](int a, int b) {
			return sz[a] < sz[b];
		});
		sort(all(Vu[1]), [&](int a, int b) {
			return sz[a] > sz[b];
		});

		for (auto it : Vu[0]) Va.push_back(Vl[q][it]);
		Va.push_back(Vl[q][mxp]);
		for (auto it : Vu[1]) Va.push_back(Vl[q][it]);
	}

	printf("0 ");
	for (auto it : Va) printf("%d ", it);
	printf("\n");
	fflush(stdout);
	return 0;
}