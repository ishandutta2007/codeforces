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

int main() {
    ll N, i;
    scanf("%I64d", &N);
    ll st;
    if (N % 3 == 2) st = 1;
    if (N % 3 == 1) st = 2;
    if (N % 3 == 0) st = 3;
    int ans = 0;
    for (i = st;; i += 3) {
        if (i*(3 * i + 1) / 2 > N) break;
        ans++;
    }
    printf("%d", ans);
    return 0;
}
//*/