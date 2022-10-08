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
int IT_MAX = 1 << 12;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

char ch(int c) {
	if (c < 10) return '0' + c;
	else if (c < 36) return 'A' + (c - 10);
	else return 'a' + (c - 36);
}

char in[105][105];
pii ran[105];

char ans[105][105];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int R, C, K, i, j;
		scanf("%d %d %d", &R, &C, &K);

		int cnt = 0;
		for (i = 0; i < R; i++) {
			scanf("%s", in[i]);
			for (j = 0; j < C; j++) if (in[i][j] == 'R') cnt++;
		}

		vector <pii> Vl;
		for (i = 0; i < R; i++) {
			if (i % 2 == 0) for (j = 0; j < C; j++) Vl.emplace_back(i, j);
			else for (j = C - 1; j >= 0; j--) Vl.emplace_back(i, j);
		}
		
		int p = 0;
		int tidx = 0;
		for (i = 0; i < K; i++) {
			int c = cnt / K;
			if (i < cnt % K) c++;

			if (p == Vl.size()) {
				int x1 = ran[tidx].first, x2 = ran[tidx].second;
				while (x1 != x2) tidx++;
				if (in[Vl[x1].first][Vl[x1].second] == 'R') {
					ran[i] = pii(x2, x2);
					ran[tidx].second--;
				}
				else {
					ran[i] = pii(x1, x1);
					ran[tidx].first++;
				}
				continue;
			}

			ran[i].first = p;
			while (1) {
				if (in[Vl[p].first][Vl[p].second] == 'R') c--;
				if (c == 0) break;
				p++;
			}
			ran[i].second = p;
			p++;
			if (i == K - 1) ran[i].second = Vl.size() - 1;
		}

		for (i = 0; i < K; i++) for (j = ran[i].first; j <= ran[i].second; j++) ans[Vl[j].first][Vl[j].second] = ch(i);

		for (i = 0; i < R; i++) {
			for (j = 0; j < C; j++) printf("%c", ans[i][j]);
			printf("\n");
		}
	}
	return 0;
}