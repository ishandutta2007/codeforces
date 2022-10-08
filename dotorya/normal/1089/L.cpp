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

ll A[100050];
ll B[100050];

vector <ll> Vl[100050];
int main() {
	int N, K, i, j;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) scanf("%lld", &A[i]);
	for (i = 1; i <= N; i++) scanf("%lld", &B[i]);

	for (i = 1; i <= N; i++) Vl[A[i]].push_back(B[i]);

	priority_queue <int, vector<int>, greater<int>> Hx;
	int c = 0;
	for (i = 1; i <= K; i++) {
		sort(all(Vl[i]));
		reverse(all(Vl[i]));
		if (Vl[i].empty()) c++;
		else {
			for (j = 1; j < Vl[i].size(); j++) Hx.push(Vl[i][j]);
		}
	}

	ll s = 0;
	while (c) {
		s += Hx.top();
		Hx.pop();
		c--;
	}
	return !printf("%lld\n", s);
}