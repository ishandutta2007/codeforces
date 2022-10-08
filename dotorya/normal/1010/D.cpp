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

int son[1000050][2];
string in[1000050];
char u[1050];

int val[1000050];
int chk[1000050][2];

void DFS(int n) {
	if (in[n] == string("IN")) {
		val[n] = son[n][0];
		return;
	}
	if (in[n] == string("AND")) {
		DFS(son[n][0]);
		DFS(son[n][1]);
		int v0 = val[son[n][0]], v1 = val[son[n][1]];
		val[n] = v0 & v1;
		if (((!v0) & v1) != val[n]) chk[n][0] = true;
		if (((!v1) & v0) != val[n]) chk[n][1] = true;
	}
	if (in[n] == string("OR")) {
		DFS(son[n][0]);
		DFS(son[n][1]);
		int v0 = val[son[n][0]], v1 = val[son[n][1]];
		val[n] = v0 | v1;
		if (((!v0) | v1) != val[n]) chk[n][0] = true;
		if (((!v1) | v0) != val[n]) chk[n][1] = true;
	}
	if (in[n] == string("XOR")) {
		DFS(son[n][0]);
		DFS(son[n][1]);
		int v0 = val[son[n][0]], v1 = val[son[n][1]];
		val[n] = v0 ^ v1;
		if (((!v0) ^ v1) != val[n]) chk[n][0] = true;
		if (((!v1) ^ v0) != val[n]) chk[n][1] = true;
	}
	if (in[n] == string("NOT")) {
		DFS(son[n][0]);
		int v0 = val[son[n][0]];
		val[n] = !v0;
		chk[n][0] = true;
	}
}

int ans[1000050];
void DFS2(int n) {
	if (in[n] == string("IN")) {
		ans[n] = !ans[n];
		return;
	}

	if (chk[n][0]) DFS2(son[n][0]);
	if (chk[n][1]) DFS2(son[n][1]);
}
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%s", u);
		in[i] = string(u);
		if (in[i] == string("IN") || in[i] == string("NOT")) scanf("%d", &son[i][0]);
		else scanf("%d %d", &son[i][0], &son[i][1]);
	}
	DFS(1);
	for (i = 1; i <= N; i++) ans[i] = val[1];
	DFS2(1);

	for (i = 1; i <= N; i++) if (in[i] == string("IN")) printf("%d", ans[i]);
	return !printf("\n");
}