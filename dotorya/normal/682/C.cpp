#include <stdio.h>  
#include <algorithm>  
#include <assert.h>  
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
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const db ERR = 1E-11;

vector <pll> son[100050];
ll dis[100050];
ll A[100050];
bool chk[100050];

void DFS1(int n, ll v) {
	if (v > A[n]) chk[n] = true;
	for (auto it : son[n]) DFS1(it.second, max(it.first, v + it.first));
}
void DFS2(int n) {
	if (chk[n]) for (auto it : son[n]) chk[it.second] = true;
	for (auto it : son[n]) DFS2(it.second);
}
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%lld", &A[i]);
	for (i = 2; i <= N; i++) {
		ll t1, t2;
		scanf("%lld %lld", &t1, &t2);
		son[t1].emplace_back(t2, i);
	}
	DFS1(1, -LL_INF);
	DFS2(1);

	int ans = 0;
	for (i = 1; i <= N; i++) if (chk[i]) ans++;
	return !printf("%d\n", ans);
}