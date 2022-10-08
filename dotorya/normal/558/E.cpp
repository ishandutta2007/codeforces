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

const int IT_MAX = 131072;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;

class data {
public:
	int cnt[26];
	char u;
	data() {
		for (int i = 0; i < 26; i++) cnt[i] = 0;
		u = 0;
	}
	data(char c) {
		for (int i = 0; i < 26; i++) cnt[i] = 0;
		cnt[c - 'a'] = 1;
		u = 0;
	}
};

data it[IT_MAX * 2 + 50];
class segtree {
public:
	segtree() {
		for (int i = 0; i < IT_MAX * 2; i++) it[i] = data();
	}
	void update(int S, int E, int st, int en, char c, int pos) {
		if (st > en) return;
		if (S == st && E == en) {
			for (int i = 0; i < 26; i++) it[pos].cnt[i] = 0;
			it[pos].cnt[c - 'a'] = E - S + 1;
			it[pos].u = c;
			return;
		}
		if (it[pos].u != 0) {
			it[2 * pos].u = it[pos].u;
			for (int i = 0; i < 26; i++) it[2 * pos].cnt[i] = 0;
			it[2 * pos].cnt[it[pos].u - 'a'] = (E - S + 1) / 2;
			it[2 * pos + 1].u = it[pos].u;
			for (int i = 0; i < 26; i++) it[2 * pos+1].cnt[i] = 0;
			it[2 * pos+1].cnt[it[pos].u - 'a'] = (E - S + 1) / 2;
			it[pos].u = 0;
		}
		int M = (S + E) / 2;
		if (st >= M + 1) update(M + 1, E, st, en, c, pos * 2 + 1);
		else if (en <= M) update(S, M, st, en, c, pos * 2);
		else {
			update(S, M, st, M, c, pos * 2);
			update(M + 1, E, M + 1, en, c, pos * 2 + 1);
		}
		
		for (int i = 0; i < 26; i++) it[pos].cnt[i] = it[2 * pos].cnt[i] + it[2 * pos + 1].cnt[i];
	}

	int* getcnt(int S, int E, int st, int en, int pos) {
		int* rv = new int[26];
		for (int i = 0; i < 26; i++) rv[i] = 0;
		if (st > en) return rv;
		if (S == st && E == en) {
			for (int i = 0; i < 26; i++) rv[i] = it[pos].cnt[i];
			return rv;
		}
		if (it[pos].u != 0) {
			it[2 * pos].u = it[pos].u;
			for (int i = 0; i < 26; i++) it[2 * pos].cnt[i] = 0;
			it[2 * pos].cnt[it[pos].u - 'a'] = (E - S + 1) / 2;
			it[2 * pos + 1].u = it[pos].u;
			for (int i = 0; i < 26; i++) it[2 * pos + 1].cnt[i] = 0;
			it[2 * pos + 1].cnt[it[pos].u - 'a'] = (E - S + 1) / 2;
			it[pos].u = 0;
		}
		int M = (S + E) / 2;
		if (st >= M + 1) return getcnt(M + 1, E, st, en, pos * 2 + 1);
		else if (en <= M) return getcnt(S, M, st, en, pos * 2);
		else {
			int* rv1 = getcnt(S, M, st, M, pos * 2);
			int* rv2 = getcnt(M + 1, E, M + 1, en, pos * 2 + 1);

			for (int i = 0; i < 26; i++) rv[i] = rv1[i] + rv2[i];
			free(rv1);
			free(rv2);
			return rv;
		}
	}
};

char in[100050];
segtree Se;
int main() {
	int N, Q, i, j;
	scanf("%d %d", &N, &Q);
	scanf("%s", in);
	Se = segtree();
	for (i = 0; in[i] != 0; i++) {
		Se.update(1, IT_MAX, i + 1, i + 1, in[i], 1);
	}

	for (i = 1; i <= Q; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);

		int* rv = Se.getcnt(1, IT_MAX, t1, t2, 1);
		int p = t1;
		if (t3 == 1) {
			for (j = 0; j < 26; j++) {
				Se.update(1, IT_MAX, p, p + rv[j] - 1, 'a' + j, 1);
				p += rv[j];
			}
		}
		else {
			for (j = 25; j >= 0; j--) {
				Se.update(1, IT_MAX, p, p + rv[j] - 1, 'a' + j, 1);
				p += rv[j];
			}
		}
		free(rv);
	}

	for (i = 1; i <= N; i++) {
		int* rv = Se.getcnt(1, IT_MAX, i, i, 1);
		for (j = 0; j < 26; j++) if (rv[j] != 0) break;
		printf("%c", 'a' + j);
		free(rv);
	}
	return 0;
}