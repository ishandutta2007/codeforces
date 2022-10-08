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

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-8;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

int gcd(int a, int b) {
	return (a == 0) ? b : gcd(b%a, a);
}

int in[200050];
vector <int> Vl[200050];
int val[200050];
vector <int> conn[200050];
bool dchk[200050];
void DFS(int n) {
	dchk[n] = true;
	if (n == 1) {
		val[1] = in[1];
		Vl[1].push_back(0);
		Vl[1].push_back(in[1]);
	}
	for (auto it : conn[n]) {
		if (dchk[it]) continue;
		for (auto it2 : Vl[n]) Vl[it].push_back(gcd(it2, in[it]));
		Vl[it].push_back(val[n]);
		val[it] = gcd(val[n], in[it]);
		sort(all(Vl[it]));
		Vl[it].erase(unique(all(Vl[it])), Vl[it].end());
		DFS(it);
	}
}
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);
	for (i = 1; i < N; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
	}
	DFS(1);
	for (i = 1; i <= N; i++) printf("%d ", Vl[i].back());
	return !printf("\n");
}