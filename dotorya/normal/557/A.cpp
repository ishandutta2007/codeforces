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

int main() {
	int N, mx1, mn1, mx2, mn2, mx3, mn3;
	scanf("%d %d %d %d %d %d %d", &N, &mn1, &mx1, &mn2, &mx2, &mn3, &mx3);

	if (N - mn2 - mn3 < mx1) printf("%d %d %d", N - mn2 - mn3, mn2, mn3);
	else if (N - mx1 - mn3 < mx2) printf("%d %d %d", mx1, N - mx1 - mn3, mn3);
	else printf("%d %d %d", mx1, mx2, N - mx1 - mx2);
	return 0;
}