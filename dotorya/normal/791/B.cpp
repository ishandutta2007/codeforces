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

int IT_MAX = 1 << 20;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1E-11;

int r[200000];
int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}
int sz1[200000];
int sz2[200000];

int in[200000][2];
int main() {
	int N, M, i;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) r[i] = i;
	for (i = 1; i <= M; i++) {
		scanf("%d %d", &in[i][0], &in[i][1]);
		r[root(in[i][0])] = root(in[i][1]);
	}
	for (i = 1; i <= N; i++) sz1[root(i)]++;
	for (i = 1; i <= M; i++) sz2[root(in[i][0])]++;

	for (i = 1; i <= N; i++) if ((ll)sz1[i] * (sz1[i] - 1) / 2 != sz2[i]) return !printf("NO\n");
	return !printf("YES\n");
}