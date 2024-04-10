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

int cnt[10];
int cnt2[10];

char in1[1000050];
char in2[1000050];
int L2;

vector <pair<int, string>> V;

char u[3];
int main() {
	scanf("%s %s", in1, in2);

	int N = strlen(in1), i, j, L;
	L2 = strlen(in2);

	if (N <= 10) L = N - 1;
	else if (N <= 101) L = N - 2;
	else if (N <= 1002) L = N - 3;
	else if (N <= 10003) L = N - 4;
	else if (N <= 100004) L = N - 5;
	else L = N - 6;

	for (i = 0; in1[i] != 0; i++) cnt[in1[i] - '0']++;
	while (L) {
		cnt[L % 10]--;
		L /= 10;
	}
	for (i = 0; in2[i] != 0; i++) cnt[in2[i] - '0']--;

	for (i = 0; i <= 9; i++) {
		u[0] = i + '0';
		for (j = 1; j <= cnt[i]; j++) V.push_back(mp(i,string(u, u + 1)));
	}

	int t = in2[0] - '0';
	for (i = 1; in2[i] != 0; i++) {
		if (in2[0] > in2[i]) {
			t--;
			break;
		}
		if (in2[0] < in2[i]) break;
	}
	V.push_back(mp(t, string(in2, in2 + L2)));
	sort(V.begin(), V.end());
	
	for (i = 0; i < V.size(); i++) if (V[i].second[0] != '0') break;
	if (i == V.size()) return !printf("0\n");
	
	string u1 = string("");
	t = i;
	u1 += V[t].second;
	for (i = 0; i < V.size(); i++) if(i != t) u1 += V[i].second;
	if (t + 1 == V.size()) return !printf("%s\n", u1.c_str());

	string u2 = string("");
	t++;
	u2 += V[t].second;
	for (i = 0; i < V.size(); i++) if(i != t) u2 += V[i].second;

	u1 = min(u1, u2);
	return !printf("%s\n", u1.c_str());
}