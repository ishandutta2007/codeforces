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

int IT_MAX = 131072;
const ll MOD = 1000000009;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-10;

class Node {
public:
	Node* nxt[26];
	int v;
	Node() {
		for (int i = 0; i < 26; i++) nxt[i] = NULL;
		v = -1;
	}
	void insert(char* c, int x) {
		if (c[0] == 0) {
			v = x;
			return;
		}
		if (c[0] >= 'A' && c[0] <= 'Z') c[0] = c[0] - 'A' + 'a';
		if (nxt[c[0] - 'a'] == NULL) nxt[c[0] - 'a'] = new Node();
		nxt[c[0] - 'a']->insert(c + 1, x);
	}
};

const int LMX = 10000 + 50;
const int MMX = 100000 + 50;
char in[LMX];
char u[LMX];
string tmp[MMX];

bool dp[LMX];
pii rev[LMX];
vector <int> ans;
int main() {
	int N, M, i, j;
	Node* root = new Node();

	scanf("%d %s", &N, in + 1);
	scanf("%d", &M);
	for (i = 1; i <= M; i++) {
		scanf("%s", u);
		tmp[i] = string(u);
		root->insert(u, i);
	}

	dp[0] = true;
	for (i = 1; i <= N; i++) {
		Node* pos = root;
		for (j = i; j >= 1 && pos != NULL; j--) {
			pos = pos->nxt[in[j] - 'a'];
			if (pos != NULL && pos->v != -1 && dp[j - 1]) {
				dp[i] = true;
				rev[i] = pii(j - 1, pos->v);
			}
		}
	}

	assert(dp[N]);
	i = N;
	while (i) {
		ans.push_back(rev[i].second);
		i = rev[i].first;
	}
	reverse(ans.begin(), ans.end());
	for (auto it : ans) printf("%s ", tmp[it].c_str());
	printf("\n");
	return 0;
}