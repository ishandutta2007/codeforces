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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

int nc = 0;
int son[1000050][26];
int par[1000050];
int fail[1000050];
int dep[1000050];
char u[1000050];

bool chk[1000050];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, i, j;
		scanf("%d", &N);

		nc = 1;
		while (N--) {
			scanf("%s", u);
			for (i = 0, j = 1; u[i] != 0; i++) {
				int t = u[i] - 'a';
				if (!son[j][t]) son[j][t] = ++nc;
				j = son[j][t];
			}
		}

		vector <int> Vu;
		Vu.push_back(1);
		fail[1] = 1;
		for (i = 0; i < Vu.size(); i++) {
			int t = Vu[i];
			for (j = 0; j < 26; j++) {
				if (son[t][j]) {
					dep[son[t][j]] = dep[t] + 1;
					par[son[t][j]] = t;
					Vu.push_back(son[t][j]);
				}
			}
			if (!i) continue;

			int p = par[t];
			int x = 0;
			for (x = 0; x < 26; x++) if (son[p][x] == t) break;
			while (1) {
				if (p == 1) {
					fail[t] = 1;
					break;
				}
				p = fail[p];
				if (son[p][x]) {
					fail[t] = son[p][x];
					break;
				}
			}
		}

		sort(all(Vu), [](int a, int b) {
			return dep[a] > dep[b];
		});

		int ans = 0;
		for (auto it : Vu) {
			if (it == 1) continue;
			if (chk[it]) continue;
			ans++;
			if (dep[fail[it]] + 1 == dep[it]) chk[fail[it]] = true;
		}
		printf("%d\n", ans);

		Vu.clear();
		for (i = 1; i <= nc; i++) {
			for (j = 0; j < 26; j++) son[i][j] = 0;
			dep[i] = par[i] = fail[i] = 0;
			chk[i] = false;
		}
	}
	return 0;
}