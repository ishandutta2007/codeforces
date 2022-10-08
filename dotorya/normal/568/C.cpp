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

const int IT_MAX = 32768;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;

bool prime_chk[10000050];
int palinsum[10000050];
bool palinchk[10000050];
int primesum[10000050];

char in[30];
int nex[30][2]; // [0] : V, [1] : C
char in2[205];

vector <int> conn[405];
vector <int> rconn[405];

int revnum(int x, int N) {
	if (x > N) return x - N;
	else return x + N;
}

int G[405];
bool chk[405];
vector <int> V;
void DFS1(int node) {
	chk[node] = true;
	for (int i = 0; i < conn[node].size(); i++) {
		int t = conn[node][i];
		if (chk[t]) continue;
		DFS1(t);
	}
	V.push_back(node);
	return;
}
void DFS2(int node, int val) {
	G[node] = val;
	for (int i = 0; i < rconn[node].size(); i++) {
		int t = rconn[node][i];
		if (G[t] != 0) continue;
		DFS2(t, val);
	}
	return;
}
bool SCC(int N) {
	for (int i = 1; i <= 2 * N; i++) chk[i] = false;
	for (int i = 1; i <= 2 * N; i++) {
		G[i] = 0;
		if (chk[i]) continue;
		DFS1(i);
	}
	int g = 0;
	while (!V.empty()) {
		int t = V.back();
		V.pop_back();
		if (G[t] != 0) continue;
		DFS2(t, ++g);
	}

	for (int i = 1; i <= N; i++) if (G[i] == G[i + N]) return false;
	return true;
}

void bb(int lvl, int N, int L) {
	if (lvl == N + 1) return;
	int t = 0, i;
	if (nex[0][0] > nex[0][1]) t = 1;
	if (nex[0][t] != L + 1) {
		int t1 = lvl + t*N;
		conn[revnum(t1, N)].push_back(t1);
		rconn[t1].push_back(revnum(t1, N));
		if (SCC(N)) {
			printf("%c", 'a' + nex[0][t] - 1);
			bb(lvl + 1, N, L);
			return;
		}
		conn[revnum(t1, N)].pop_back();
		rconn[t1].pop_back();
	}
	if (nex[0][1 - t] != L + 1) {
		int t1 = lvl + (1 - t)*N;
		conn[revnum(t1, N)].push_back(t1);
		rconn[t1].push_back(revnum(t1, N));
		if (SCC(N)) {
			printf("%c", 'a' + nex[0][1 - t] - 1);
			bb(lvl + 1, N, L);
			return;
		}
		conn[revnum(t1, N)].pop_back();
		rconn[t1].pop_back();
	}

}
bool aa(int lvl, int N, int L) {
	if (lvl == 0) return false;
	int i, j;
	for (i = 1; i < lvl; i++) {
		int t = i;
		if (in[in2[i] - 'a' + 1] == 'C') t += N;
		conn[revnum(t, N)].push_back(t);
		rconn[t].push_back(revnum(t, N));
	}

	int t = 0;
	if (nex[in2[lvl] - 'a' + 1][0] > nex[in2[lvl] - 'a' + 1][1]) t = 1;
	if (nex[in2[lvl] - 'a' + 1][t] != L + 1) {
		int t1 = lvl + t*N;
		conn[revnum(t1, N)].push_back(t1);
		rconn[t1].push_back(revnum(t1, N));
		if (SCC(N)) {
			for (i = 1; i < lvl; i++) printf("%c", in2[i]);
			printf("%c", 'a' + nex[in2[lvl] - 'a' + 1][t] - 1);
			bb(lvl + 1, N, L);
			return true;
		}
		conn[revnum(t1, N)].pop_back();
		rconn[t1].pop_back();
	}
	if (nex[in2[lvl] - 'a' + 1][1 - t] != L + 1) {
		int t1 = lvl + (1 - t)*N;
		conn[revnum(t1, N)].push_back(t1);
		rconn[t1].push_back(revnum(t1, N));
		if (SCC(N)) {
			for (i = 1; i < lvl; i++) printf("%c", in2[i]);
			printf("%c", 'a' + nex[in2[lvl] - 'a' + 1][1 - t] - 1);
			bb(lvl + 1, N, L);
			return true;
		}
		conn[revnum(t1, N)].pop_back();
		rconn[t1].pop_back();
	}
	for (i = 1; i < lvl; i++) {
		int t = i;
		if (in[in2[i] - 'a' + 1] == 'C') t += N;
		conn[revnum(t, N)].pop_back();
		rconn[t].pop_back();
	}
	return aa(lvl - 1, N, L);
}
int main() {
	int N, M, L, i, j, t1, t2;
	char c1[2], c2[2];
	scanf("%s", &in[1]);
	bool cchk = false, vchk = false;
	for (L = 0; in[L + 1] != 0; L++) {
		if (in[L + 1] == 'C') cchk = true;
		else vchk = true;
	}
	
	for (i = 0; i <= L; i++) {
		nex[i][0] = L + 1, nex[i][1] = L + 1;
		for (j = i + 1; j <= L; j++) {
			if (in[j] == 'V') nex[i][0] = min(nex[i][0], j);
			else nex[i][1] = min(nex[i][1], j);
		}
	}
	for (i = L + 1; i <= 26; i++) nex[i][0] = nex[i][1] = L + 1;

	scanf("%d %d", &N, &M);

	if (!cchk) {
		for (i = 1; i <= N; i++) {
			t1 = i;
			conn[revnum(t1, N)].push_back(t1);
			rconn[t1].push_back(revnum(t1, N));
		}
	}
	if (!vchk) {
		for (i = 1; i <= N; i++) {
			t1 = i + N;
			conn[revnum(t1, N)].push_back(t1);
			rconn[t1].push_back(revnum(t1, N));
		}
	}
	for (i = 1; i <= M; i++) {
		scanf("%d %s %d %s", &t1, c1, &t2, c2);
		if (c1[0] == 'C') t1 += N;
		if (c2[0] == 'C') t2 += N;
		conn[t1].push_back(t2);
		conn[revnum(t2, N)].push_back(revnum(t1, N));
		rconn[t2].push_back(t1);
		rconn[revnum(t1, N)].push_back(revnum(t2, N));
	}

	scanf("%s", &in2[1]);
	for (i = N; i >= 1; i--) {
		if (in2[i] != 'a') {
			in2[i]--;
			break;
		}
		else if (i >= 2) {
			in2[i] = 'z';
			continue;
		}
		else in2[i] = 'a' - 1;
	}

	if (in2[1] == 'a' - 1) {
		for (i = 1; i <= N; i++) in2[i] = 'a';
		if (in[1] == 'C') {
			for (i = N + 1; i <= 2 * N; i++) {
				for (j = 0; j < conn[i].size(); j++) if (conn[i][j] <= N) break;
				if (j < conn[i].size()) break;
			}
			if (i > 2 * N) {
				for (i = 1; i <= N; i++) printf("a");
				return 0;
			}
		}
		else {
			for (i = 1; i <= N; i++) {
				for (j = 0; j < conn[i].size(); j++) if (conn[i][j] > N) break;
				if (j < conn[i].size()) break;
			}
			if (i > N) {
				for (i = 1; i <= N; i++) printf("a");
				return 0;
			}
		}
	}

	int st;
	for (st = 1; st < N; st++) if (in2[st] > 'a' + L - 1) break;
	if (!aa(st, N, L)) printf("-1");
	return 0;
}
//*/