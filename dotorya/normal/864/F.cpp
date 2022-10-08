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

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

vector <int> conn[3050];
vector <int> rconn[3050];

vector <int> tconn[3050];
bool valid[3050];
bool dchk[3050][3050];
int nxt[3050][3050];
short nxt2[9][3050][3050];

int chk[3050];
int u[3050];
int main() {
	int N, M, Q, i, j, k;
	scanf("%d %d %d", &N, &M, &Q);
	for (i = 1; i <= M; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
		rconn[t2].push_back(t1);
	}
	for (i = 1; i <= N; i++) sort(all(conn[i]));
	for (i = 1; i <= N; i++) {
		dchk[i][i] = true;
		nxt[i][i] = i;
		vector<int> Vu;
		Vu.push_back(i);
		for (j = 0; j < Vu.size(); j++) {
			for (auto it : rconn[Vu[j]]) {
				if (dchk[i][it]) continue;
				dchk[i][it] = true;
				Vu.push_back(it);
			}
		}
		for (j = 1; j <= N; j++) {
			if (i == j) continue;
			for (auto it : conn[j]) {
				if (dchk[i][it]) {
					nxt[i][j] = it;
					break;
				}
			}
		}
		for (j = 1; j <= N; j++) nxt2[0][i][j] = nxt[i][j];
		for (int x = 1; x <= 8; x++) {
			for (j = 1; j <= N; j++) nxt2[x][i][j] = nxt2[x - 1][i][nxt2[x - 1][i][j]];
		}
	}

	for(int q = 1; q <= Q; q++) {
		int s, e, K;
		scanf("%d %d %d", &s, &e, &K);

		for (i = 1, j = s; i <= 15; i++) j = nxt2[8][e][j];
		if (j != e) {
			printf("-1\n");
			continue;
		}

		K--;
		while (K) {
			if (K > 256) {
				s = nxt2[8][e][s];
				K -= 256;
			}
			else if (K > 16) {
				s = nxt2[4][e][s];
				K -= 16;
			}
			else {
				s = nxt[e][s];
				K--;
			}
			if (K == 0) break;
			if (s == e) {
				printf("-1\n");
				break;
			}
		}
		if (!K) printf("%d\n", s);
	}
	return 0;
}