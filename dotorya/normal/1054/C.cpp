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

int ans[1050];
int in[1050][2];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &in[i][0]);
	for (i = 1; i <= N; i++) scanf("%d", &in[i][1]);

	for (j = N;; j--) {
		for (i = 1; i <= N; i++) if (!ans[i]) break;
		if (i > N) break;

		vector <int> Vl;
		for (i = 1; i <= N; i++) {
			if (ans[i]) continue;
			if (in[i][0] == 0 && in[i][1] == 0) Vl.push_back(i);
		}
		if (Vl.empty()) return !printf("NO\n");

		for (auto it : Vl) ans[it] = j;
		for (i = 1; i <= N; i++) {
			if (ans[i]) continue;
			for (auto it : Vl) {
				if (it < i) in[i][0]--;
				else in[i][1]--;
			}
			if (in[i][0] < 0 || in[i][1] < 0) return !printf("NO\n");
		}
	}
	printf("YES\n");
	for (i = 1; i <= N; i++) printf("%d ", ans[i]);
	return !printf("\n");
}