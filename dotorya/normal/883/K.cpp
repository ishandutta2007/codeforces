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
//#include <unordered_map>  
//#include <unordered_set>  
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

//typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple<int, int, int> t3;
#define rep(i, n) for(int i=0;i<n;i++)

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-12;

pii in[200050];
int val[200050];
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d %d", &in[i].first, &in[i].second);
	for (i = 1; i <= N; i++) val[i] = in[i].first + in[i].second;
	for (i = 2; i <= N; i++) val[i] = min(val[i], val[i - 1] + 1);
	for (i = N - 1; i >= 1; i--) val[i] = min(val[i], val[i + 1] + 1);
	for (i = 1; i <= N; i++) if (in[i].first > val[i]) return !printf("-1\n");

	ll ans = 0;
	for (i = 1; i <= N; i++) ans += val[i] - in[i].first;
	printf("%lld\n", ans);
	for (i = 1; i <= N; i++) printf("%d ", val[i]);
	return !printf("\n");
}