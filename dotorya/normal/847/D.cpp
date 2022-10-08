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

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

int bit[300000];
void update(int p, int v) {
	for (; p <= IT_MAX; p += p & (-p)) bit[p] += v;
}
int getsum(int p) {
	int rv = 0;
	for (; p; p -= p & (-p)) rv += bit[p];
	return rv;
}

ll in[200050];
int main() {
	int N;
	ll T, i;
	scanf("%d %lld", &N, &T);
	for (i = 1; i <= N; i++) {
		scanf("%lld", &in[i]);
		in[i] = max(in[i], i);
	}

	vector <pll> Vq;
	for (i = 1; i <= N; i++) Vq.emplace_back(T - 1 + i - in[i], i);
	sort(all(Vq));
	reverse(all(Vq));

	int ans = 0, p = 0;
	for (i = N; i >= 1; i--) {
		while (p < Vq.size()) {
			if (Vq[p].first < i) break;
			update(Vq[p].second, 1);
			p++;
		}

		ans = max(ans, getsum(i));
	}
	return !printf("%d\n", ans);
}