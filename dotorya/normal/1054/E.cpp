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
const ll MOD = 1000000009;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

queue<char> in1[305][305];
queue<char> in2[305][305];
char u[100050];

queue<char> Qu;
queue<char> getstr(bool chk) {
	while (!Qu.empty()) Qu.pop();
	scanf("%s", u);
	int L = strlen(u);
	if (chk) reverse(u, u + L);
	for (int i = L - 1; i >= 0; i--) Qu.push(u[i]);
	return Qu;
}

vector <pair<pii, pii>> Vr;

queue<char> in[305][305];
void movepos(int x1, int y1, int x2, int y2) {
	in[x2][y2].push(in[x1][y1].front());
	in[x1][y1].pop();
	Vr.emplace_back(pii(x1, y1), pii(x2, y2));
}
vector <pair<pii, pii>> getans(int N, int M) {
	Vr.clear();
	while (!in[1][1].empty()) {
		char c = in[1][1].front();
		if (c == '0') movepos(1, 1, 1, M);
		else movepos(1, 1, N, 1);
	}
	while (!in[N][M].empty()) {
		char c = in[N][M].front();
		if (c == '0') movepos(N, M, 1, M);
		else movepos(N, M, N, 1);
	}

	for (int q = 0; q < 2; q++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (i == 1 && j == 1) continue;
				if (i == N && j == M) continue;
				while (!in[i][j].empty()) {
					char c = in[i][j].front();
					int x = i, y = j;
					if (c == '0') {
						if (y != 1) {
							movepos(x, y, x, 1);
							y = 1;
							continue;
						}
						if (x != 1) movepos(x, y, 1, y);
					}
					else {
						if (y != M) {
							movepos(x, y, x, M);
							y = M;
							continue;
						}
						if (x != N) movepos(x, y, N, y);
					}
				}
			}
		}
	}
	return Vr;
}

int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) for (j = 1; j <= M; j++) in1[i][j] = getstr(false);
	for (i = 1; i <= N; i++) for (j = 1; j <= M; j++) in2[i][j] = getstr(true);

	for (i = 1; i <= N; i++) for (j = 1; j <= M; j++) in[i][j] = in1[i][j];
	vector <pair<pii, pii>> Vl1 = getans(N, M);
	for (i = 1; i <= N; i++) for (j = 1; j <= M; j++) in[i][j] = in2[i][j];
	vector <pair<pii, pii>> Vl2 = getans(N, M);

	reverse(all(Vl2));

	printf("%d\n", (int)Vl1.size() + (int)Vl2.size());
	for (auto it : Vl1) printf("%d %d %d %d\n", it.first.first, it.first.second, it.second.first, it.second.second);
	for (auto it : Vl2) printf("%d %d %d %d\n", it.second.first, it.second.second, it.first.first, it.first.second);
	return 0;
}