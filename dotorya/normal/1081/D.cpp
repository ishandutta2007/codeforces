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

int IT_MAX = 1 << 19;
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

vector <pair<int, pii>> Ve;

int r[100050];
int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}
int cnt[100050];
int main() {
	int N, M, K, i;
	scanf("%d %d %d", &N, &M, &K);
	for (i = 1; i <= K; i++) {
		int t;
		scanf("%d", &t);
		cnt[t] = 1;
	}
	for (i = 1; i <= N; i++) r[i] = i;
	while (M--) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		Ve.emplace_back(t3, pii(t1, t2));
	}
	
	sort(all(Ve));
	for (auto it : Ve) {
		int t1 = it.second.first, t2 = it.second.second;
		if (root(t1) == root(t2)) continue;

		t1 = root(t1), t2 = root(t2);
		cnt[t2] += cnt[t1];
		r[t1] = t2;

		if (cnt[t2] == K) {
			for (i = 1; i <= K; i++) printf("%d ", it.first);
			return !printf("\n");
		}
	}
	return 0;
}