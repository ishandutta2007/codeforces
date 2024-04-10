#include <algorithm>
#include <assert.h>
#include <complex>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <locale.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
//#include <unordered_set>
//#include <unordered_map>

#pragma warning(disable:4996)
using namespace std;

#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <ldb, ldb> pdd;

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-13;

class Node {
public:
	int val;
	bool chk;
	Node* fail;
	Node* nxt[26];
	Node() {
		for (int i = 0; i < 26; i++) nxt[i] = NULL;
		fail = NULL;
		chk = false;
		val = 0;
	}
	void insert(char* str, int v) {
		if (str[0] == 0) {
			chk = true;
			val += v;
			return;
		}
		if (nxt[str[0] - 'a'] == NULL) nxt[str[0] - 'a'] = new Node();
		nxt[str[0] - 'a']->insert(str + 1, v);
	}
};

int msz;
int Mat[205][205];
class Trie {
public:
	Node* root;
	Trie() {
		root = new Node();
	}
	void insert(char* str, int val) {
		root->insert(str, val);
	}
	void buildFailureLink() {
		vector <Node*> V;
		int i, j;
		V.push_back(root);
		root->fail = root;
		for (i = 0; i < V.size(); i++) {
			Node* u = V[i];
			for (j = 0; j < 26; j++) {
				if (u->nxt[j] == NULL) continue;
				Node* tmp = u;
				while (1) {
					if (tmp == root) {
						u->nxt[j]->fail = root;
						break;
					}
					tmp = tmp->fail;
					if (tmp->nxt[j] != NULL) {
						u->nxt[j]->fail = tmp->nxt[j];
						break;
					}
				}
				V.push_back(u->nxt[j]);
				u->nxt[j]->val += u->nxt[j]->fail->val;
			}
		}
		V.clear();
	}
	void buildMatrix() {
		vector <Node*> V;
		map <Node*, int> Mx;
		int i, j;
		V.push_back(root);
		Mx[root] = 1;

		for (i = 0; i < V.size(); i++) {
			for (j = 0; j < 26; j++) {
				if (V[i]->nxt[j] == NULL) continue;
				V.push_back(V[i]->nxt[j]);

				int t = Mx.size() + 1;
				Mx[V[i]->nxt[j]] = t;
			}
		}
		msz = Mx.size();
		for (i = 1; i <= msz; i++) for (j = 1; j <= msz; j++) Mat[i][j] = -INF;
		for (i = 0; i < V.size(); i++) {
			for (j = 0; j < 26; j++) {
				Node* u = V[i];
				Node* u2 = NULL;
				while (u->nxt[j] == NULL) {
					if (u == root) {
						u2 = root;
						break;
					}
					u = u->fail;
				}
				if (u->nxt[j] != NULL) u2 = u->nxt[j];
				u = V[i];
				Mat[Mx[u]][Mx[u2]] = max(Mat[Mx[u]][Mx[u2]], u2->val);
			}
		}
		Mx.clear();
		V.clear();
	}
};

ll mul[205][205];
ll rv[205][205];
ll utmp[205][205];

int A[205];
char in[205];
int main() {
	int N, i, j, k;
	ll L;
	scanf("%d %lld", &N, &L);
	for (i = 1; i <= N; i++) scanf("%d", &A[i]);
	
	Trie T;
	for (i = 1; i <= N; i++) {
		scanf("%s", in);
		T.insert(in, A[i]);
	}
	T.buildFailureLink();
	T.buildMatrix();

	for (i = 1; i <= msz; i++) for (j = 1; j <= msz; j++) mul[i][j] = Mat[i][j];
	for (i = 1; i <= msz; i++) for (j = 1; j <= msz; j++) if(i != j) rv[i][j] = -INF;

	while (L) {
		if (L % 2) {
			for (i = 1; i <= msz; i++) {
				for (j = 1; j <= msz; j++) {
					utmp[i][j] = -INF;
					for (k = 1; k <= msz; k++) utmp[i][j] = max(mul[i][k] + rv[k][j], utmp[i][j]);
				}
			}
			for (i = 1; i <= msz; i++) for (j = 1; j <= msz; j++) rv[i][j] = utmp[i][j];
		}
		for (i = 1; i <= msz; i++) {
			for (j = 1; j <= msz; j++) {
				utmp[i][j] = -INF;
				for (k = 1; k <= msz; k++) utmp[i][j] = max(mul[i][k] + mul[k][j], utmp[i][j]);
			}
		}
		for (i = 1; i <= msz; i++) for (j = 1; j <= msz; j++) mul[i][j] = utmp[i][j];
		L /= 2;
	}

	ll ans = 0;
	for (i = 1; i <= msz; i++) ans = max(ans, rv[1][i]);
	return !printf("%lld\n", ans);
}