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
#pragma comment(linker, "/STACK:3336777216")  
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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

int bit[26][100050];
void update(int x, int p, int v) {
	for (; p <= 100000; p += p & (-p)) bit[x][p] ^= v;
}
int getsum(int x, int p) {
	int rv = 0;
	for (; p; p -= p & (-p)) rv ^= bit[x][p];
	return rv;
}

char in[100050];
int nxt[100050][26];
int prv[100050][26];

int dpl[100050][26];
int dpr[100050][26];
vector <pii> Vl;
bool mycmp(pii a, pii b) {
	if (a.first != b.first) return a.first > b.first;
	return a.second < b.second;
}
vector <int> Vp[26];

bool grchk[30];
int getgr(int S, int E) {
	memset(grchk, 0, sizeof(grchk));
	int i;
	for (i = 0; i < 26; i++) {
		if (nxt[S][i] > E) continue;

		int p1 = nxt[S][i];
		int p2 = prv[E][i];

		int gr = dpr[S][i] ^ dpl[E][i];
		if (p1 < p2) {
			gr ^= getsum(i, p2 - 1);
			gr ^= getsum(i, p1 - 1);
		}
		grchk[gr] = true;
	}

	for (i = 0;; i++) if (!grchk[i]) return i;
}

int DEBUG = 0;
int main() {
	if(!DEBUG) scanf("%s", in + 1);
	else {
		srand(132132);
		for (int i = 1; i <= 100000; i++) in[i] = rand() % 26 + 'a';
	}
	int N = strlen(in + 1), i, j;

	for (i = 1; i <= N; i++) {
		for (j = 0; j < 26; j++) prv[i][j] = prv[i - 1][j];
		prv[i][in[i] - 'a'] = i;

		for (j = 0; j < 26; j++) {
			if (in[i] - 'a' == j) continue;
			if (prv[i][j] == 0) continue;
			Vl.emplace_back(prv[i][j] + 1, i);
		}
	}
	for (i = 0; i < 26; i++) nxt[N + 1][i] = N + 1;
	for (i = N; i >= 1; i--) {
		for (j = 0; j < 26; j++) nxt[i][j] = nxt[i + 1][j];
		nxt[i][in[i] - 'a'] = i;

		for (j = 0; j < 26; j++) {
			if (in[i] - 'a' == j) continue;
			if (nxt[i][j] == N + 1) continue;
			Vl.emplace_back(i, nxt[i][j] - 1);
		}
	}

	for (i = 1; i <= N; i++) Vp[in[i] - 'a'].push_back(i);
	for (i = 0; i < 26; i++) {
		for (j = 0; j + 1 < Vp[i].size(); j++) {
			int t1 = Vp[i][j], t2 = Vp[i][j + 1];
			if (t1 + 1 != t2) Vl.emplace_back(t1 + 1, t2 - 1);
		}
	}

	sort(all(Vl), mycmp);
	Vl.erase(unique(all(Vl)), Vl.end());

	//printf("Running!\n");
	int cnt = 0;
	for (auto it : Vl) {
		cnt++;
		//if(cnt % 3000 == 0) printf("Running at %d\n", cnt);
		memset(grchk, 0, sizeof(grchk));

		int S = it.first, E = it.second;
		i = getgr(S, E);
		
		if (S != 1 && E != N && in[S - 1] == in[E + 1]) update(in[S - 1] - 'a', S - 1, i);
		
		if (E != N && nxt[S][in[E + 1] - 'a'] == E + 1) dpr[S][in[E + 1] - 'a'] = i;
		if (S != 1 && prv[E][in[S - 1] - 'a'] == S - 1) dpl[E][in[S - 1] - 'a'] = i;
	}

	//printf("Running!\n");
	int Q;
	if(!DEBUG) scanf("%d", &Q);
	else Q = 100000;
	while (Q--) {
		int S, E;
		if(!DEBUG) scanf("%d %d", &S, &E);
		else {
			S = rand() % 100000 + 1;
			E = rand() % 100000 + 1;
			if (S > E) swap(S, E);
		}

		if (!getgr(S, E) && !DEBUG) printf("Bob\n");
		else if(!DEBUG) printf("Alice\n");
	}
	return 0;
}