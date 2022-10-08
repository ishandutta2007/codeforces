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

int in[200050];
int main() {
	int N, i;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &in[i]);
		in[i] += i;
	}
	sort(in, in + N);
	for (i = 0; i < N - 1; i++) if (in[i] == in[i + 1]) break;
	if (i < N - 1) {
		printf(":(");
		return 0;
	}
	for (i = 0; i < N; i++) printf("%d ", in[i] - i);
	return 0;
}

//*/