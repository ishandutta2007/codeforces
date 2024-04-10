//*
#include <algorithm>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>

#define pow10 pasiodfiopsdjviozjxciovjxcviozj
#define pow2 qpowdskopjkcoizxnzoicn

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef pair <char, int> pci;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef pair <db, int> pdi;

int IT_MAX;
const int MOD = 1000000;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;

vector <pii> V;
vector <int> V2;
int main() {
	int N, i, j, t;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &t);
		if (V.empty() || t != V.back().first) V.push_back(pii(t, 1));
		else V.back().second++;
	}

	if (V.size() == 1) {
		printf("0\n");
		for (i = 1; i <= N; i++) printf("%d ", V[0].first);
		return 0;
	}

	V2.push_back(0);
	int st = 0;
	int ans = 0;
	for (i = 1; i < V.size()-1; i++) {
		if (V[i].second >= 2) {
			ans = max(ans, (i - st) / 2);
			st = i;
		}
	}
	ans = max(ans, ((int)V.size() - st - 1) / 2);

	printf("%d\n", ans);
	
	st = 0;
	for (i = 0; i < V[0].second; i++) printf("%d ", V[0].first);
	for (i = 1; i < V.size(); i++) {
		if (V[i].second >= 2 || i == V.size() - 1) {
			if (V[i].first == V[st].first) for (j = 1; j < i - st; j++) printf("%d ", V[i].first);
			else {
				for (j = 1; j <= (i - st) / 2; j++) printf("%d ", V[st].first);
				for (j = 1; j <= (i - st) / 2; j++) printf("%d ", V[i].first);
			}
			st = i;
			for (j = 0; j < V[st].second; j++) printf("%d ", V[st].first);
		}
	}
	return 0;
}
//*/