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

int in[105][105];
int main() {
	int N, M, i, j, k;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; i++) for (j = 1; j <= N; j++) scanf("%d", &in[i][j]);

	vector <int> Va;
	int ans = M;
	for (i = 1; i <= M; i++) Va.push_back(i);

	for (i = 1; i < N; i++) {
		int s = 0;
		vector <pii> Vl;
		for (j = 1; j <= M; j++) {
			int t = in[j][N] - in[j][i];
			s += t;
			Vl.emplace_back(t, j);
		}
		sort(all(Vl));
		reverse(all(Vl));

		vector <int> Vu;
		for (j = 0; j < M; j++) {
			if (s <= 0) break;
			Vu.push_back(Vl[j].second);
			s -= Vl[j].first;
		}

		if (ans > Vu.size()) {
			ans = Vu.size();
			Va = Vu;
		}
	}
	printf("%d\n", ans);
	for (auto it : Va) printf("%d ", it);
	return !printf("\n");
}