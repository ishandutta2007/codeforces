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
#define all(x) (x).begin(), (x).end()  
#define ldb ldouble

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple <int, int, int> t3;

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)

int r[100050];
int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}

vector <int> conn[100050];
vector <int> Vl[100050];
vector <pii> Ve;
int cnt[100050];

int ans[100050];

int dep[100050];
bool dchk[100050];
vector <int> son[100050];
int par[100050];
void DFS(int n) {
	dchk[n] = true;
	for (auto it : conn[n]) {
		if (dchk[it]) continue;
		son[n].push_back(it);
		par[it] = n;
		dep[it] = dep[n] + 1;
		DFS(it);
	}
}

void getans(int r, vector<int> &Vu2, int a, int b, int c) {
	ans[r] = a * b * c;
	int i, j;
	for (i = 1, j = Vu2[0]; i < a; i++) {
		ans[j] = (a - i)*b*c;
		if (i + 1 != a) j = son[j][0];
	}
	for (i = 1, j = Vu2[1]; i < b; i++) {
		ans[j] = a * (b - i) * c;
		if (i + 1 != b) j = son[j][0];
	}
	for (i = 1, j = Vu2[2]; i < c; i++) {
		ans[j] = a * b * (c - i);
		if (i + 1 != c) j = son[j][0];
	}
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, M, i, j, k;
		scanf("%d %d", &N, &M);
		for (i = 1; i <= N; i++) r[i] = i;
		for (i = 1; i <= N; i++) cnt[i] = 0;
		for (i = 1; i <= M; i++) {
			int t1, t2;
			scanf("%d %d", &t1, &t2);
			conn[t1].push_back(t2);
			conn[t2].push_back(t1);
			r[root(t1)] = root(t2);
			Ve.emplace_back(t1, t2);
		}
		for (i = 1; i <= N; i++) Vl[root(i)].push_back(i);
		for (auto it : Ve) cnt[root(it.first)]++;

		for (i = 1; i <= N; i++) {
			if (root(i) != i) continue;

			int V = Vl[i].size(), E = cnt[i];
			if (V <= E) {
				for (j = 1; j <= N; j++) ans[j] = 0;
				for (auto it : Vl[i]) ans[it] = 1;
				printf("YES\n");
				for (j = 1; j <= N; j++) printf("%d ", ans[j]);
				printf("\n");
				break;
			}

			int c = 0;
			for (auto it : Vl[i]) if (conn[it].size() == 1) c++;
			if (c >= 4) {
				for (j = 1; j <= N; j++) ans[j] = 0;
				for (auto it : Vl[i]) {
					if (conn[it].size() == 1) ans[it] = 1;
					else ans[it] = 2;
				}
				printf("YES\n");
				for (j = 1; j <= N; j++) printf("%d ", ans[j]);
				printf("\n");
				break;
			}
			if (c <= 2) continue;

			int r = 0;
			for (auto it : Vl[i]) if (conn[it].size() == 3) r = it;
			dep[r] = 1;
			DFS(r);

			vector <int> Vu;
			vector <int> Vu2;
			for (auto it : Vl[i]) if (conn[it].size() == 1) Vu.push_back(it);
			sort(all(Vu), [](int a, int b) {
				return dep[a] < dep[b];
			});
			for (auto it : Vu) {
				int t = it;
				while (par[t] != r) t = par[t];
				Vu2.push_back(t);
			}

			for (j = 1; j <= N; j++) ans[j] = 0;
			if (dep[Vu[0]] >= 3) {
				getans(r, Vu2, 3, 3, 3);
				printf("YES\n");
				for (j = 1; j <= N; j++) printf("%d ", ans[j]);
				printf("\n");
				break;
			}

			if ((ll)(dep[Vu[1]] - 2) * (dep[Vu[2]] - 2) < 4) continue;
			if (dep[Vu[1]] == 3) getans(r, Vu2, 2, 3, 6);
			else getans(r, Vu2, 2, 4, 4);
			printf("YES\n");
			for (j = 1; j <= N; j++) printf("%d ", ans[j]);
			printf("\n");
			break;
		}
		if (i > N) printf("NO\n");

		for (i = 1; i <= N; i++) {
			conn[i].clear();
			son[i].clear();
			Vl[i].clear();
			Ve.clear();
			dep[i] = dchk[i] = 0;
		}
	}
	return 0;
}