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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

int in[105][2];
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d %d", &in[i][0], &in[i][1]);

	while (1) {
		int c = 0;
		for (i = 1; i <= N; i++) if (in[i][0] == 0) c++;
		if (c == 1) break;

		int v = 0;
		for (i = 1; i <= N; i++) if (in[i][0] == 0) break;
		v = i;

		int v2 = v;
		while (in[v2][1]) v2 = in[v2][1];
		
		int v3 = 0;
		for (i = 1; i <= N; i++) if (in[i][1] == 0 && i != v2) v3 = i;
		in[v3][1] = v, in[v][0] = v3;
	}
	for (i = 1; i <= N; i++) printf("%d %d\n", in[i][0], in[i][1]);
	return 0;
}