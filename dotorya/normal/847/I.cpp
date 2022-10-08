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

char in[255][255];
ll ans[255][255];

int dis[255][255];
int main() {
	int N, M, Q, P, i, j, k, l;
	scanf("%d %d %d %d", &N, &M, &Q, &P);
	for (i = 0; i < N; i++) scanf("%s", in[i]);
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (in[i][j] < 'A' || in[i][j] > 'Z') continue;
			ll v = Q * (in[i][j] - 'A' + 1);

			vector <pii> Vu;
			Vu.emplace_back(i, j);
			dis[i][j] = v;
			for (k = 0; k < Vu.size(); k++) {
				int d = dis[Vu[k].first][Vu[k].second];
				if (d == 1) continue;
				for (l = 0; l < 4; l++) {
					int x = Vu[k].first + "1102"[l] - '1';
					int y = Vu[k].second + "0211"[l] - '1';
					if (x < 0 || x >= N || y < 0 || y >= M) continue;
					if (in[x][y] == '*' || dis[x][y]) continue;
					dis[x][y] = d / 2;
					Vu.emplace_back(x, y);
				}
			}
			for (auto it : Vu) {
				ans[it.first][it.second] += dis[it.first][it.second];
				dis[it.first][it.second] = 0;
			}
		}
	}

	int A = 0;
	for (i = 0; i < N; i++) for (j = 0; j < M; j++) if (ans[i][j] > P) A++;
	return !printf("%d\n", A);
}