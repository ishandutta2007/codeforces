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

vector <int> conn[100050];
vector <pii> Ve;

int r[100050];
int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}

int G[100050];

vector <int> Vg[100050];
vector <pii> Vu;
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);

	for (i = 1; i <= N; i++) r[i] = i;

	for (i = 1; i <= M; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
		Ve.emplace_back(t1, t2);
	}

	int mn = 1;
	for (i = 2; i <= N; i++) if (conn[i].size() < conn[mn].size()) mn = i;

	sort(all(conn[mn]));
	int p = 0;
	for (i = 1; i <= N; i++) {
		if (p < conn[mn].size() && i == conn[mn][p]) {
			p++;
			continue;
		}

		r[root(mn)] = root(i);
	}

	int gc = 0;
	for (i = 1; i <= N; i++) {
		if (r[i] != i) continue;
		G[i] = ++gc;
	}
	for (i = 1; i <= N; i++) G[i] = G[root(i)];

	for (i = 1; i <= N; i++) Vg[root(i)].push_back(i);


	vector <int> Vl;
	for (i = 1; i <= N; i++) if (r[i] == i) Vl.push_back(i);

	map <pii, int> Mx;
	for (auto it : Ve) {
		int t1 = root(it.first), t2 = root(it.second);
		if (t1 > t2) swap(t1, t2);
		if (t1 != t2) Mx[pii(t1, t2)]++;
	}

	for (i = 0; i < Vl.size(); i++) {
		for (j = i + 1; j < Vl.size(); j++) {
			int t1 = Vl[i], t2 = Vl[j];
			if (Mx[pii(t1, t2)] == (ll)Vg[t1].size() * (ll)Vg[t2].size()) continue;
			r[root(t1)] = root(t2);
		}
	}

	int ans = 0;
	for (i = 1; i <= N; i++) if (r[i] == i) ans++;
	return !printf("%d\n", ans - 1);
}