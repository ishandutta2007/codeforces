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

map <pair<int, pii>, vector<int>> Mx;
pair<int, pii> in[105];

int dp[105][2050];
int rev[105][2050];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d %d %d", &in[i].second.first, &in[i].first, &in[i].second.second);
		Mx[in[i]].push_back(i);
	}
	sort(in + 1, in + N + 1);

	for (i = 1; i <= N; i++) {
		for (j = 0; j <= 2000; j++) {
			dp[i][j] = dp[i - 1][j];
			rev[i][j] = j;
		}
		for (j = 0; j + in[i].second.first < in[i].first; j++) {
			int t = j + in[i].second.first;
			if (dp[i][t] < dp[i - 1][j] + in[i].second.second) {
				dp[i][t] = dp[i - 1][j] + in[i].second.second;
				rev[i][t] = j;
			}
		}
	}
	int mx = 0;
	for (i = 1; i <= 2000; i++) if (dp[N][i] > dp[N][mx]) mx = i;

	vector <int> Va;
	printf("%d\n", dp[N][mx]);
	for (i = N; i >= 1; i--) {
		if (rev[i][mx] != mx) {
			auto it = Mx[in[i]];
			Va.push_back(it.back());
			it.pop_back();
			Mx[in[i]] = it;
		}
		mx = rev[i][mx];
	}
	printf("%d\n", (int)Va.size());
	reverse(all(Va));
	for (auto it : Va) printf("%d ", it);
	return !printf("\n");
}