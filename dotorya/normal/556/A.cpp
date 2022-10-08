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

char in[200050];
int main() {
	int cnt0 = 0, cnt1 = 0, i, L;
	scanf("%d", &L);
	scanf("%s", in);
	for (i = 0; in[i] != 0; i++) {
		if (in[i] == '0') cnt0++;
		else cnt1++;
	}
	printf("%d", abs(cnt1 - cnt0));
	return 0;
}