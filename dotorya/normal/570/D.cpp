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

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef pair <char, int> pci;

const int MOD = 9999991;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;

class data {
public:
	int v[26];
	data() {
		for (int i = 0; i < 26; i++) v[i] = 0;
	}
};

int r[500050];
vector <int> son[500050];
int ch[500050];
int dep[500050];
int lr[500050][2];

char in[500050];

vector <pair<int,data>> sum[500050];

int pos = 0;
void DFS(int node, int lvl) {
	dep[node] = lvl;
	lr[node][0] = ++pos;
	ch[pos] = node;
	for (int i = 0; i < son[node].size(); i++) {
		int t = son[node][i];
		DFS(t, lvl+1);
	}
	lr[node][1] = pos;
	return;
}

int getpos(int a, int b) {
	int st = 0, en = sum[b].size() - 1, mi, rv = 0;
	while (st <= en) {
		mi = (st + en) / 2;
		if (sum[b][mi].first <= a) {
			st = mi + 1;
			rv = mi;
		}
		else en = mi - 1;
	}
	return rv;
}
int main() {
	int N, M, i, t1, t2;
	scanf("%d %d", &N, &M);
	for (i = 2; i <= N; i++) {
		scanf("%d", &r[i]);
		son[r[i]].push_back(i);
	}
	scanf("%s", &in[1]);
	DFS(1, 1);

	for (i = 1; i <= N; i++) sum[i].push_back(make_pair(0, data()));
	for (i = 1; i <= N; i++) {
		int t = ch[i];
		int d = dep[t];
		data tmp = sum[d].back().second;
		sum[d].push_back(make_pair(i, tmp));
		sum[d].back().second.v[in[t] - 'a']++;
	}

	for (i = 1; i <= M; i++) {
		scanf("%d %d", &t1, &t2);
		int t3 = lr[t1][0]-1, t4 = lr[t1][1];

		t3 = getpos(t3, t2);
		t4 = getpos(t4, t2);

		int x = 0;
		for (int j = 0; j < 26; j++) if (sum[t2][t4].second.v[j] % 2 != sum[t2][t3].second.v[j] % 2) x++;
		if (x <= 1) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
//*/