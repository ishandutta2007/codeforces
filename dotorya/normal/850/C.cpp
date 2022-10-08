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

int IT_MAX = 1 << 15;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

map <int, int> Mx;
int ch(int x) {
	if (Mx.count(x)) return Mx[x];
	int t = Mx.size() + 1;
	return Mx[x] = t;
}

vector <int> Vin[10500];

int gr[65536];
int getgr(int x) {
	if (x < 65536) return gr[x];

	bool tchk[45] = { false, };
	for (int j = 0;; j++) {
		int t1 = x >> j, t2 = x & ((1 << j) - 1);
		int y = (t1 / 2) | t2;
		if (y == x) break;
		tchk[getgr(y)] = true;
	}
	for (int j = 0;; j++) if (!tchk[j]) return j;
}

bool chk[45];
int main() {
	int N, i, j, t;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &t);
		for (j = 2; j * j <= t; j++) {
			if (t % j) continue;

			int c = 0;
			while (t % j == 0) {
				t /= j;
				c++;
			}
			Vin[ch(j)].push_back(c);
		}
		if (t != 1) Vin[ch(t)].push_back(1);
	}

	gr[0] = 0;
	for (i = 1; i <= 65535; i++) {
		memset(chk, 0, sizeof(chk));
		for (j = 0;; j++) {
			int t1 = i >> j, t2 = i & ((1 << j) - 1);
			int x = (t1 / 2) | t2;
			if (x == i) break;
			chk[gr[x]] = true;
		}
		for (j = 0;; j++) if (!chk[j]) break;
		gr[i] = j;
	}

	int G = 0;
	for (i = 1; i <= Mx.size(); i++) {
		int x = 0;
		for (auto it : Vin[i]) x |= 1 << (it - 1);
		G ^= getgr(x);
	}
	if (G) printf("Mojtaba\n");
	else printf("Arpa\n");
	return 0;
}