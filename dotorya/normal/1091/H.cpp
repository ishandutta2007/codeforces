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

int IT_MAX = 1 << 19;
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

vector <int> Vp;
vector <int> Vl;
bool pchk[200050];

int gr[200050];

bool dchk[200050];

int gr2[200050];
bitset <200050> bgr[1000];
bitset <200050> bu;

bool tchk[200050];
int main() {
	int i, j;
	for (i = 2; i <= 200000; i++) {
		if (pchk[i]) continue;
		Vp.push_back(i);
		for (j = 2 * i; j <= 200000; j += i) pchk[j] = true;
	}

	for (auto it : Vp) Vl.push_back(it);
	for (int i = 0; i < Vp.size(); i++) {
		for (int j = i; j < Vp.size(); j++) {
			if ((ll)Vp[i] * Vp[j] > 200000) break;
			Vl.push_back(Vp[i] * Vp[j]);
		}
	}

	sort(all(Vl));
	Vl.erase(unique(all(Vl)), Vl.end());
	for (auto it : Vl) tchk[it] = true;

	int N, F;
	scanf("%d %d", &N, &F);
	tchk[F] = false;

	vector <int> Vl[1050];
	Vl[0].push_back(0);
	for (int i = 1; i <= 200000; i++) {
		for (int j = 0;; j++) {
			int k;
			for (k = 0; k < Vl[j].size(); k++) if (tchk[i - Vl[j][k]]) break;
			if (k >= Vl[j].size()) {
				gr[i] = j;
				break;
			}
		}
		Vl[gr[i]].push_back(i);
	}

	int G = 0;
	while (N--) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);

		G ^= gr[t2 - t1 - 1] ^ gr[t3 - t2 - 1];
	}

	if (G) printf("Alice\nBob\n");
	else printf("Bob\nAlice\n");
	return 0;
}