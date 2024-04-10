//*
#include <algorithm>
#include <ctype.h>
#include <functional>
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

int IT_MAX;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;

vector <int> V[100050];
vector <int> Vt;
vector <int> chk[4]; // LL, LR, RL, RR

set <int> S[2];
int c[100050];
char in[100050];
int main() {
	int i, j, L;
	scanf("%s", in);
	for (L = 0; in[L] != 0; L++) {
		if (in[L] == 'L') S[0].insert(L);
		else S[1].insert(L);
	}

	int gcnt;
	for (gcnt = 0; !S[0].empty() || !S[1].empty(); gcnt++) {
		int p, mn;
		if (S[0].empty()) p = 1;
		else if (S[1].empty()) p = 0;
		else if (*(S[0].begin()) < *(S[1].begin())) p = 0;
		else p = 1;

		mn = *(S[p].begin());
		Vt.push_back(mn+1);
		S[p].erase(mn);

		int t = p * 2;
		while (!S[1 - p].empty()) {
			auto it = S[1 - p].lower_bound(mn);
			if (it == S[1 - p].end()) break;
			Vt.push_back(*it+1);
			mn = *it;
			S[1 - p].erase(it);
			p = 1 - p;
		}
		t += p;
		V[gcnt] = Vt;
		chk[t].push_back(gcnt);
		Vt.clear();
	}

	printf("%d\n", gcnt - 1);
	if (chk[0].size() > chk[3].size()) {
		for (i = 0; i < chk[1].size(); i++) for (j = 0; j < V[chk[1][i]].size(); j++) printf("%d ", V[chk[1][i]][j]);
		for (i = 0; i < chk[3].size(); i++) {
			for (j = 0; j < V[chk[0][i]].size(); j++) printf("%d ", V[chk[0][i]][j]);
			for (j = 0; j < V[chk[3][i]].size(); j++) printf("%d ", V[chk[3][i]][j]);
		}
		for (j = 0; j < V[chk[0].back()].size(); j++) printf("%d ", V[chk[0].back()][j]);
		for (i = 0; i < chk[2].size(); i++) for (j = 0; j < V[chk[2][i]].size(); j++) printf("%d ", V[chk[2][i]][j]);
		return 0;
	}

	if (chk[0].size() < chk[3].size()) {
		for (i = 0; i < chk[2].size(); i++) for (j = 0; j < V[chk[2][i]].size(); j++) printf("%d ", V[chk[2][i]][j]);
		for (i = 0; i < chk[0].size(); i++) {
			for (j = 0; j < V[chk[3][i]].size(); j++) printf("%d ", V[chk[3][i]][j]);
			for (j = 0; j < V[chk[0][i]].size(); j++) printf("%d ", V[chk[0][i]][j]);
		}
		for (j = 0; j < V[chk[3].back()].size(); j++) printf("%d ", V[chk[3].back()][j]);
		
		for (i = 0; i < chk[1].size(); i++) for (j = 0; j < V[chk[1][i]].size(); j++) printf("%d ", V[chk[1][i]][j]);
		return 0;
	}

	for (i = 0; i < chk[0].size(); i++) {
		for (j = 0; j < V[chk[0][i]].size(); j++) V[gcnt].push_back(V[chk[0][i]][j]);
		for (j = 0; j < V[chk[3][i]].size(); j++) V[gcnt].push_back(V[chk[3][i]][j]);
	}
	for (i = 0; i < chk[1].size(); i++) for (j = 0; j < V[chk[1][i]].size(); j++) V[gcnt].push_back(V[chk[1][i]][j]);
	for (i = 0; i < chk[2].size(); i++) for (j = 0; j < V[chk[2][i]].size(); j++) V[gcnt + 1].push_back(V[chk[2][i]][j]);

	if (V[gcnt].empty()) {
		for (i = 0; i < V[gcnt + 1].size(); i++) printf("%d ", V[gcnt + 1][i]);
		return 0;
	}
	if (V[gcnt + 1].empty()) {
		for (i = 0; i < V[gcnt].size(); i++) printf("%d ", V[gcnt][i]);
		return 0;
	}

	if (V[gcnt][0] > V[gcnt + 1][0]) {
		printf("%d ", V[gcnt + 1][0]);
		for (i = 0; i < V[gcnt].size(); i++) printf("%d ", V[gcnt][i]);
		for (i = 1; i < V[gcnt + 1].size(); i++) printf("%d ", V[gcnt + 1][i]);
		return 0;
	}
	
	else {
		printf("%d ", V[gcnt][0]);
		for (i = 0; i < V[gcnt + 1].size(); i++) printf("%d ", V[gcnt + 1][i]);
		for (i = 1; i < V[gcnt].size(); i++) printf("%d ", V[gcnt][i]);
		return 0;
	}
	return 0;
}
//*/