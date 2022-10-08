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

char in[100050];
int readnexttok(int &p) {
	int rv = 0;
	while (in[p] >= '0' && in[p] <= '9') {
		rv = rv * 10 + in[p] - '0';
		p++;
	}
	return rv;
}

vector <vector<int>> Vl[1050];
int sz[1050][1050];

vector <int> son[1050];
bool dchk[1050];
void DFS(int n, int p) {
	dchk[n] = true;
	for (auto it : Vl[n]) {
		int i;
		for (i = 0; i < it.size(); i++) if (it[i] == p) break;
		if (i < it.size()) continue;

		int mn = INF, a = 0;
		for (auto it2 : it) {
			if (mn > sz[it2][n]) {
				mn = sz[it2][n];
				a = it2;
			}
		}
		if (dchk[a]) {
			printf("-1\n");
			exit(0);
		}
		son[n].push_back(a);
		DFS(a, n);
	}
}

vector <int> conn[1050];
int dchk2[1050];
vector <int> Vx[1050];
int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%s", in);
		int p = 0;

		while (in[p]) {
			vector <int> Vu;
			int sz = readnexttok(p);
			p++;
			for (j = 1; j <= sz; j++) {
				Vu.push_back(readnexttok(p));
				if (j != sz) p++;
			}
			sort(all(Vu));
			Vl[i].push_back(Vu);
			if (!in[p]) break;
			p++;
		}
	}

	for (i = 1; i <= N; i++) {
		sort(all(Vl[i]));
		for (auto it : Vl[i]) {
			for (auto it2 : it) sz[i][it2] = it.size();
		}
	}

	DFS(1, 0);
	for (i = 1; i <= N; i++) {
		for (auto it : son[i]) {
			conn[i].push_back(it);
			conn[it].push_back(i);
		}
	}
	for (i = 1; i <= N; i++) {
		vector <int> Vu;
		for (j = 1; j <= N; j++) dchk2[j] = 0;
		for (auto it : conn[i]) {
			Vu.push_back(it);
			dchk2[it] = it;
		}
		dchk2[i] = i;
		for (j = 0; j < Vu.size(); j++) {
			for (auto it : conn[Vu[j]]) {
				if (dchk2[it]) continue;
				dchk2[it] = dchk2[Vu[j]];
				Vu.push_back(it);
			}
		}
		vector <vector<int>> Vl2;
		for (j = 1; j <= N; j++) if (j != i) Vx[dchk2[j]].push_back(j);
		for (j = 1; j <= N; j++) if (j != i && !Vx[j].empty()) Vl2.push_back(Vx[j]);
		sort(all(Vl2));
		if (Vl[i] != Vl2) return !printf("-1\n");

		for (j = 1; j <= N; j++) Vx[j].clear();
	}

	printf("%d\n", N - 1);
	for (i = 1; i <= N; i++) for (auto it : son[i]) printf("%d %d\n", i, it);
	return 0;
}