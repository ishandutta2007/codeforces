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

vector <int> Vu;
set <int> conn[200050];
bool dchk[200050];
void vpush(int n) {
	if (dchk[n]) return;
	dchk[n] = true;
	Vu.push_back(n);
}

int cur = 0;
void addmore(int K) {
	for (; cur < Vu.size(); cur++) {
		int t = Vu[cur];
		while (!conn[t].empty()) {
			int t2 = *conn[t].begin();
			conn[t2].erase(t);
			if (conn[t2].size() < K) vpush(t2);
			conn[t].erase(t2);
		}
	}
}
int in[200050][2];
int ans[200050];

int main() {
	int N, M, K, i, j, k;
	scanf("%d %d %d", &N, &M, &K); 
	for (i = 1; i <= M; i++) {
		scanf("%d %d", &in[i][0], &in[i][1]);
		conn[in[i][0]].insert(in[i][1]);
		conn[in[i][1]].insert(in[i][0]);
	}

	for (i = 1; i <= N; i++) if (conn[i].size() < K) vpush(i);
	addmore(K);

	for (i = M; i >= 1; i--) {
		ans[i] = N - (int)Vu.size();
		int t1 = in[i][0], t2 = in[i][1];
		conn[t1].erase(t2);
		conn[t2].erase(t1);
		if (conn[t1].size() < K) vpush(t1);
		if (conn[t2].size() < K) vpush(t2);
		addmore(K);
	}
	for (i = 1; i <= M; i++) printf("%d\n", ans[i]);
	return 0;
}