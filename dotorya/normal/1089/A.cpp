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
const ll MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

bool dp[205][205][4][4];
pii prv[205][205][4][4];

vector <pii> Vl;
vector <pii> Vl2;
int main() {
	int i, j, k, l, m;
	for (i = 0; i <= 23; i++) {
		Vl.emplace_back(25, i);
		Vl.emplace_back(i, 25);
	}
	for (i = 26; i <= 200; i++) {
		Vl.emplace_back(i, i - 2);
		Vl.emplace_back(i - 2, i);
	}

	for (i = 0; i <= 13; i++) {
		Vl2.emplace_back(15, i);
		Vl2.emplace_back(i, 15);
	}
	for (i = 16; i <= 200; i++) {
		Vl2.emplace_back(i, i - 2);
		Vl2.emplace_back(i - 2, i);
	}

	dp[0][0][0][0] = true;
	for (i = 0; i <= 200; i++) {
		for (j = 0; j <= 200; j++) {
			for (k = 0; k <= 2; k++) {
				for (l = 0; l <= 2; l++) {
					if (!dp[i][j][k][l]) continue;
					
					if (k != 2 || l != 2) {
						for (auto it : Vl) {
							int i2 = i + it.first, j2 = j + it.second, k2 = k, l2 = l;
							if (it.first < it.second) l2++;
							else k2++;

							if (i2 <= 200 && j2 <= 200 && !dp[i2][j2][k2][l2]) {
								dp[i2][j2][k2][l2] = true;
								prv[i2][j2][k2][l2] = it;
							}
						}
					}
					else {
						for (auto it : Vl2) {
							int i2 = i + it.first, j2 = j + it.second, k2 = k, l2 = l;
							if (it.first < it.second) l2++;
							else k2++;

							if (i2 <= 200 && j2 <= 200 && !dp[i2][j2][k2][l2]) {
								dp[i2][j2][k2][l2] = true;
								prv[i2][j2][k2][l2] = it;
							}
						}
					}
				}
			}
		}
	}

	int T;
	scanf("%d", &T);
	while (T--) {
		int s1, s2, a1, a2, i, j;
		scanf("%d %d", &s1, &s2);

		if (dp[s1][s2][3][0]) a1 = 3, a2 = 0;
		else if (dp[s1][s2][3][1]) a1 = 3, a2 = 1;
		else if (dp[s1][s2][3][2]) a1 = 3, a2 = 2;
		else if (dp[s1][s2][2][3]) a1 = 2, a2 = 3;
		else if (dp[s1][s2][1][3]) a1 = 1, a2 = 3;
		else if (dp[s1][s2][0][3]) a1 = 0, a2 = 3;
		else a1 = a2 = -1;

		if (a1 == -1) {
			printf("Impossible\n");
			continue;
		}

		printf("%d:%d\n", a1, a2);
		vector <pii> Va;
		while (a1 || a2) {
			pii u = prv[s1][s2][a1][a2];
			Va.push_back(u);
			if (u.first > u.second) a1--;
			else a2--;
			s1 -= u.first, s2 -= u.second;
		}
		reverse(all(Va));
		for (auto it : Va) printf("%d:%d ", it.first, it.second);
		printf("\n");
	}
	return 0;
}