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
#include <unordered_set>
#include <unordered_map>

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
const int INF = 2034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

class Node {
public:
	int n;
	Node* nxt;
	Node* prv;
	bool chk;

	Node() {
		n = 0;
		chk = false;
		nxt = prv = NULL;
	}
};

vector <int> V;
bool dchk[500050];
char in[500050];
int conn[500050];
Node* u[500050];

char Q[500050];
int main() {
	int N, M, P, i;
	scanf("%d %d %d", &N, &M, &P);

	scanf("%s", in + 1);
	for (i = 1; i <= N; i++) {
		u[i] = new Node();
		u[i]->n = i;
	}
	for (i = 1; i < N; i++) {
		u[i]->nxt = u[i + 1];
		u[i + 1]->prv = u[i];
	}
	for (i = 1; i <= N; i++) {
		if (in[i] == '(') V.push_back(i);
		else {
			conn[V.back()] = i;
			conn[i] = V.back();
			V.pop_back();
		}
	}

	Node* ptr = u[P];
	scanf("%s", Q);
	for (i = 0; i < M; i++) {
		if (Q[i] == 'L') ptr = ptr->prv;
		else if (Q[i] == 'R') ptr = ptr->nxt;
		else if (conn[ptr->n] < ptr->n) {
			Node* n1 = u[conn[ptr->n]]->prv;
			Node* n2 = u[ptr->n]->nxt;
			Node* tmp = u[ptr->n];

			if (n2 != NULL) n2->prv = n1;
			if (n1 != NULL) n1->nxt = n2;
			if (n2 != NULL) ptr = n2;
			else ptr = n1;
			while (tmp != n1) {
				dchk[tmp->n] = true;
				tmp = tmp->prv;
			}
		}
		else {
			Node* n1 = u[ptr->n]->prv;
			Node* n2 = u[conn[ptr->n]]->nxt;
			Node* tmp = u[ptr->n];

			if (n2 != NULL) n2->prv = n1;
			if (n1 != NULL) n1->nxt = n2;
			if (n2 != NULL) ptr = n2;
			else ptr = n1;
			
			while (tmp != n2) {
				dchk[tmp->n] = true;
				tmp = tmp->nxt;
			}
		}
	}

	for (i = 1; i <= N; i++) if (!dchk[i]) printf("%c", in[i]);
	return !printf("\n");
}