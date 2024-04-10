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
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

vector <int> conn[105];
vector <int> son[105];
map <pii, int> Mx;

db ans[105];
int in[105][2];
bool dchk[105];
void DFS(int n, db prv) {
	dchk[n] = true;

	prv += 1;
	for (auto it : conn[n]) {
		if (dchk[it]) continue;
		prv += 2.0 / (int)conn[n].size();

		int x = Mx[pii(n, it)];
		db a = prv;
		if (in[x][0] != n) a += 1;
		ans[x] = a;
		DFS(it, prv);
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
		Mx[pii(t1, t2)] = i;
		Mx[pii(t2, t1)] = i;
		in[i][0] = t1, in[i][1] = t2;
	}
	DFS(1, 2.0/3);

	printf("%d\n", N - 1);
	for (i = 1; i < N; i++) {
		int v = (int) (ans[i] / 2);
		ans[i] -= 2 * v;
		
		printf("1 %d ", i);
		if (ans[i] < 1) printf("%d %d %.20lf\n", in[i][0], in[i][1], ans[i]);
		else printf("%d %d %.20lf\n", in[i][1], in[i][0], ans[i] - 1);
	}
	return 0;
}