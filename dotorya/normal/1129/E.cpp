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
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

int qn;
int askquery(vector<int> &V1, vector<int> &V2, int n) {
	qn++;
	if (qn > 11111) {
		printf("OMG\n");
		while (1);
	}

	printf("%d\n", (int)V1.size());
	for (auto it : V1) printf("%d ", it);
	printf("\n");
	printf("%d\n", (int)V2.size());
	for (auto it : V2) printf("%d ", it);
	printf("\n");
	printf("%d\n", n);
	fflush(stdout);

	V1.clear();
	V2.clear();

	int x;
	scanf("%d", &x);
	return x;
}

int sz[505];
int u[505];

int N;

vector <pii> Veu;
set <int> conn[505];

vector <int> son[505];
vector <int> Vl;
bool dchk[505];

void DFS2(int n) {
	dchk[n] = true;
	sz[n] = 1;
	Vl.push_back(n);
	for (auto it : conn[n]) {
		if (dchk[it]) continue;
		dchk[it] = true;
		son[n].push_back(it);
		DFS2(it);
		sz[n] += sz[it];
	}
}

vector <int> Vu;
void DFS1(int n, int nn) {
	DFS2(n);

	int r = n;
	while (!son[r].empty()) {
		int mx = son[r][0];
		for (auto it : son[r]) if (sz[it] > sz[mx]) mx = it;
		if (sz[mx] * 2 <= sz[n]) break;

		r = mx;
	}

	for (auto it : Vl) {
		son[it].clear();
		dchk[it] = false;
		sz[it] = 0;
	}
	Vl.clear();

	Vu.clear();
	for (auto it : conn[r]) Vu.push_back(it);
	random_shuffle(all(Vu));

	int st = 0, en = (int)Vu.size() - 1, mi, rv = (int)Vu.size();
	vector <int> V1, V2;
	while (st <= en) {
		mi = (st + en) / 2;

		V1.push_back(nn);
		for (int i = 0; i <= mi; i++) V2.push_back(Vu[i]);

		int t = askquery(V1, V2, r);
		if (t < mi + 1) {
			rv = mi;
			en = mi - 1;
		}
		else st = mi + 1;
	}
	if (rv == (int)Vu.size()) {
		for (auto it : Veu) {
			conn[it.first].insert(it.second);
			conn[it.second].insert(it.first);
		}
		conn[r].insert(nn);
		conn[nn].insert(r);
		Veu.clear();
		return;
	}

	Veu.emplace_back(r, Vu[rv]);
	conn[r].erase(Vu[rv]);
	conn[Vu[rv]].erase(r);
	DFS1(Vu[rv], nn);
}
int main() {
	srand(time(0));

	scanf("%d", &N);

	vector <int> V1, V2;
	for (int i = 2; i <= N; i++) {
		V1.push_back(1);
		for (int j = 2; j <= N; j++) V2.push_back(j);

		sz[i] = askquery(V1, V2, i);
	}

	for (int i = 2; i <= N; i++) u[i] = i;
	sort(u + 2, u + N + 1, [](int a, int b) {
		return sz[a] > sz[b];
	});

	memset(sz, 0, sizeof(sz));
	for (int i = 2; i <= N; i++) {
		DFS1(1, u[i]);
	}

	printf("ANSWER\n");
	vector <pii> Ve;
	for (int i = 1; i <= N; i++) for (auto it : conn[i]) if (i < it) Ve.emplace_back(i, it);
	for (auto it : Ve) printf("%d %d\n", it.first, it.second);
	return 0;
}