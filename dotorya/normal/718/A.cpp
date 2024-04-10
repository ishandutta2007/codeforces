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
#include <string>
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

int IT_MAX = 262144;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-11;

vector <int> V1;
vector <int> V2;

void printans() {
	for (auto it : V1) printf("%d", it);
	if (V2.empty()) {
		printf("\n");
		exit(0);
	}
	printf(".");
	for (auto it : V2) printf("%d", it);
	printf("\n");
	exit(0);
}

char in[500050];
int main() {
	int N, T, i, j;
	scanf("%d %d %s", &N, &T, in);
	for (i = 0; in[i] != '.'; i++) V1.push_back(in[i] - '0');
	for (i = i + 1; in[i] != 0; i++) V2.push_back(in[i] - '0');

	for (i = 0; i < V2.size(); i++) if (V2[i] >= 5) break;
	if (i >= V2.size()) printans();

	while (V2.size() != i) V2.pop_back();
	bool c = true;
	while (!V2.empty() && c) {
		V2.back()++;
		if (V2.back() != 10) {
			c = false;
			break;
		}
		V2.pop_back();
	}
	if (c) {
		V1.back()++;
		for (i = V1.size() - 1; i >= 1; i--) {
			if (V1[i] != 10) break;
			V1[i - 1]++;
			V1[i] = 0;
		}
		printans();
	}

	T--;
	while (T--) {
		if (V2.back() < 5) printans();
		V2.pop_back();
		c = true;
		while (!V2.empty() && c) {
			V2.back()++;
			if (V2.back() != 10) {
				c = false;
				break;
			}
			V2.pop_back();
		}
		if (c) {
			V1.back()++;
			for (i = V1.size() - 1; i >= 1; i--) {
				if (V1[i] != 10) break;
				V1[i - 1]++;
				V1[i] = 0;
			}
			printans();
		}
	}
	printans();
}