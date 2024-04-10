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

int main() {
	int N, i, j;
	scanf("%d", &N);

	vector <pii> Va;
	if (N <= 56) {
		for (i = 1; i <= 7; i++) {
			if (i % 2 == 1) {
				for (j = 1; j <= 8; j++) {
					Va.emplace_back(i, j);
					if (Va.size() == N - 1) break;
				}
				if (Va.size() == N - 1) break;
			}
			else {
				for (j = 8; j >= 1; j--) {
					Va.emplace_back(i, j);
					if (Va.size() == N - 1) break;
				}
				if (Va.size() == N - 1) break;
			}
		}
		if (Va.back().second == 8) Va.emplace_back(7, 8);
		else Va.emplace_back(8, Va.back().second);
		Va.emplace_back(8, 8);
	}
	else {
		for (i = 1; i <= 7; i++) {
			if (i == 7) {
				for (j = 1; j <= 6; j++) Va.emplace_back(i, j);
				Va.emplace_back(7, 8);
				Va.emplace_back(7, 7);
			}
			else if (i % 2 == 1) {
				for (j = 1; j <= 8; j++) Va.emplace_back(i, j);
			}
			else {
				for (j = 8; j >= 1; j--) Va.emplace_back(i, j);
			}
		}
		for (j = 7; j >= 1; j--) {
			Va.emplace_back(8, j);
			if (Va.size() == N) break;
		}
		Va.emplace_back(8, 8);
	}
	for (auto it : Va) printf("%c%d ", 'a' + it.first - 1, it.second);
	return !printf("\n");
}