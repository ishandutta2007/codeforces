//*
#include <algorithm>
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
#include <unordered_set>
#include <unordered_map>


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
typedef pair <ldb, int> pdi;
typedef pair <ldb, ll> pdl;

int IT_MAX;
const int MOD = 500500507;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;

class Trie {
public:
	int v;
	char c;
	vector <Trie*> son;
	int sz;
	Trie() {
		*this = Trie('?');
	}
	Trie(char C) {
		v = 0;
		c = C;
		son.clear();
		sz = 1;
	}
};



int in[300050];
char str[300050];
vector <int> conn[300050];

bool dchk[300050];
Trie* ptr[300050] = { NULL, };

void DFS(int n, Trie* tr) {
	dchk[n] = true;
	ptr[n] = tr;
	tr->v = in[n];
	for (auto it : conn[n]) {
		if (dchk[it]) continue;
		Trie* x = new Trie(str[it]);
		DFS(it, x);
		tr->son.push_back(x);
		tr->sz += x->sz;
	}
}

Trie* add_trie(Trie* x, Trie* y) {
	Trie* rv = new Trie(x->c);
	int p1 = 0, p2 = 0;
	for (char i = 'a'; i <= 'z'; i++) {
		if (p1 == x->son.size() || x->son[p1]->c != i) {
			if (p2 == y->son.size() || y->son[p2]->c != i) continue;
			rv->son.push_back(y->son[p2]);
			rv->sz += y->son[p2]->sz;
			p2++;
		}
		else {
			if (p2 == y->son.size() || y->son[p2]->c != i) {
				rv->son.push_back(x->son[p1]);
				rv->sz += x->son[p1]->sz;
				p1++;
			}
			else {
				Trie* u = add_trie(x->son[p1], y->son[p2]);
				rv->son.push_back(u);
				rv->sz += u->sz;
				p1++;
				p2++;
			}
		}
	}
	return rv;
}

bool cmp(const Trie* t1, const Trie* t2) {
	return t1->c < t2->c;
}

int mx;
int cnt;
void DFS2(Trie* tr) {
	sort(tr->son.begin(), tr->son.end(), cmp);
	for (auto it : tr->son) DFS2(it);
	for (int i = 1; i < tr->son.size(); i++) {
		if (tr->son[i - 1]->c == tr->son[i]->c) {
			tr->son[i] = add_trie(tr->son[i - 1], tr->son[i]);
		}
	}

	vector <Trie*> V;
	tr->sz = 1;
	for (int i = 0; i < tr->son.size(); i++) {
		if (i + 1 != tr->son.size() && tr->son[i]->c == tr->son[i + 1]->c) continue;
		tr->sz += tr->son[i]->sz;
		V.push_back(tr->son[i]);
	}
	tr->son = V;

	int rv = tr->v + tr->sz;
	if (rv > mx) {
		mx = rv;
		cnt = 1;
	}
	else if (rv == mx) cnt++;
}

int main() {
	int N, i, t1, t2;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);
	scanf("%s", &str[1]);
	for (i = 1; i < N; i++) {
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
		conn[t2].push_back(t1);
	}

	Trie* root = new Trie(str[1]);
	DFS(1, root);

	DFS2(root);
	printf("%d\n%d\n", mx, cnt);
	return 0;
}