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

int IT_MAX = 1024;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 3234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-10;

map <int, int> Mx;
int pos[200050];
int dis[200050];
pii in[100050];

vector <int> V[200050];
vector <int> V2;

ll ans[100050];
int main() {
	int N, K, i, j;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) {
		scanf("%d %d", &in[i].first, &in[i].second);
		Mx[in[i].first] = 0;
		Mx[in[i].first + K] = 0;
	}
	sort(in + 1, in + N + 1, [](pii a, pii b) {
		return a.second < b.second;
	});
	i = 0;
	for (auto &it : Mx) {
		it.second = ++i;
		pos[i] = it.first;
	}
	for (i = 1; i < Mx.size(); i++) dis[i] = pos[i + 1] - pos[i];

	for (i = 1; i <= N; i++) for (j = Mx[in[i].first]; j < Mx[in[i].first + K]; j++) V[j].push_back(in[i].second);

	for (i = 1; i < Mx.size(); i++) {
		int p1 = 0, p2 = 0;
		for (auto it : V[i]) V2.push_back(it + K);

		int c = 0;
		while (p2 != V2.size()) {
			if (p1 != V[i].size() && V[i][p1] < V2[p2]) {
				c++;
				if(p1 + 1 == V[i].size()) ans[c] += (ll)(V2[p2] - V[i][p1]) * dis[i];
				else ans[c] += (ll)(min(V2[p2], V[i][p1 + 1]) - V[i][p1]) * dis[i];
				p1++;
			}
			else {	
				c--;
				p2++;
				if (p2 == V2.size()) break;

				if (p1 == V[i].size()) ans[c] += (ll)(V2[p2] - V2[p2-1]) * dis[i];
				else ans[c] += (ll)(min(V2[p2], V[i][p1]) - V2[p2-1]) * dis[i];
			}
		}
		V2.clear();
	}
	for (i = 1; i <= N; i++) printf("%lld ", ans[i]);
	return !printf("\n");
}