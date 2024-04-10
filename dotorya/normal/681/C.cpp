//*
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

int IT_MAX = 4096;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

char in[105];
priority_queue <int, vector<int>, greater<int>> H;

vector <pii> ans;
void print(pii x) {
	if (x.first == 0) printf("insert %d\n", x.second);
	else if (x.first == 1) printf("getMin %d\n", x.second);
	else printf("removeMin\n");
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int t;
		scanf("%s", in);

		if (in[0] == 'i') {
			scanf("%d", &t);
			H.push(t);
			ans.push_back(pii(0, t));
		}
		if (in[0] == 'g') {
			scanf("%d", &t);
			while (!H.empty()) {
				int u = H.top();
				if (t <= u) break;

				ans.push_back(pii(2, 0));
				H.pop();
			}
			if (H.empty()) {
				ans.push_back(pii(0, t));
				ans.push_back(pii(1, t));
				H.push(t);
				continue;
			}

			if (H.top() == t) {
				ans.push_back(pii(1, t));
				continue;
			}
			else {
				ans.push_back(pii(0, t));
				ans.push_back(pii(1, t));
				H.push(t);
				continue;
			}
		}
		if (in[0] == 'r') {
			if (H.empty()) {
				ans.push_back(pii(0, 1));
				ans.push_back(pii(2, 0));
			}
			else {
				ans.push_back(pii(2, 0));
				H.pop();
			}
		}
	}

	printf("%d\n", ans.size());
	for (auto it : ans) print(it);
	return 0;
}