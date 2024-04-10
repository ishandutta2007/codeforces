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
const int INF = 2034567891;
const ll LL_INF = 1234567890123456789ll;

int in[6];
int main() {
	int i;
	for (i = 0; i < 6; i++) scanf("%d", &in[i]);
	sort(in, in + 6);
	if (in[0] != in[3] && in[1] != in[4] && in[2] != in[5]) {
		printf("Alien");
		return 0;
	}
	if (in[0] == in[3]) {
		if (in[4] == in[5]) printf("Elephant");
		else printf("Bear");
		return 0;
	}
	if (in[1] == in[4]) printf("Bear");
	else {
		if (in[0] == in[1]) printf("Elephant");
		else printf("Bear");
		return 0;
	}
	return 0;
}
//*/