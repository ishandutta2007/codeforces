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

vector <pair<int, pii>> Va;
set <int> conn[200050];
bool dchk[200050];
int par[200050];
vector <int> Vu;
void DFS(int n) {
	dchk[n] = true;
	for (auto it : conn[n]) {
		if (dchk[it]) continue;
		par[it] = n;
		DFS(it);
	}
	Vu.push_back(n);
}
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		conn[t1].insert(t2);
		conn[t2].insert(t1);
	}

	for (i = 1; i <= N; i++) {
		if (dchk[i]) continue;
		DFS(i);
		for (auto n : Vu) {
			while (conn[n].size() >= 2) {
				int t1 = *(conn[n].begin());
				if (t1 == par[n]) {
					auto it = conn[n].end();
					it--;
					t1 = *it;
				}
				conn[n].erase(t1);

				int t2 = *(conn[n].begin());
				if (t2 == par[n] && conn[n].size() != 1) {
					auto it = conn[n].end();
					it--;
					t2 = *it;
				}
				conn[n].erase(t2);

				conn[t2].erase(n);
				conn[t1].erase(n);
				Va.emplace_back(t1, pii(n, t2));
			}
		}
		Vu.clear();
	}
	
	printf("%d\n", (int)Va.size());
	for (auto it : Va) printf("%d %d %d\n", it.first, it.second.first, it.second.second);
	return 0;
}