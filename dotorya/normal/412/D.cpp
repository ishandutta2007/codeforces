//*
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <map>
#include <set>
#include <time.h>
#include <math.h>
#include <string.h>
#include <limits.h>
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

const int IT_MAX = 32768;
const int MOD = 1000000007;
const int INF = 1234567891;
const ll LL_INF = 1234567890123456789ll;

set <int> S[30050];

int ANS[30050];
int main() {
	int N, M, i, j, t1, t2;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= M; i++) {
		scanf("%d %d", &t1, &t2);
		S[t1].insert(t2);
	}

	ANS[1] = 1;
	for (i = 2; i <= N; i++) {
		ANS[i] = i;
		for (j = i - 1; j >= 1; j--) {
			if (S[ANS[j]].count(ANS[j + 1]) != 0) swap(ANS[j], ANS[j + 1]);
			else break;
		}
	}

	for (i = 1; i <= N; i++) printf("%d ", ANS[i]);
	return 0;
}
//*/