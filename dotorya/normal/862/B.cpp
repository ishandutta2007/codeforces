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

int dep[100050];
vector <int> conn[100050];
bool dchk[100050];
void DFS(int n) {
	dchk[n] = true;
	for (auto it : conn[n]) {
		if (dchk[it]) continue;
		dep[it] = dep[n] + 1;
		DFS(it);
	}
}
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i < N; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
	}
	DFS(1);

	int c1 = 0, c2 = 0;
	for (i = 1; i <= N; i++) {
		if (dep[i] % 2) c1++;
		else c2++;
	}
	
	ll ans = (ll)c1 * c2 - N + 1;
	return !printf("%lld\n", ans);
}