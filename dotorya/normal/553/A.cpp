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
const ll MOD = 1000000007;
const int INF = 2034567891;
const ll LL_INF = 1234567890123456789ll;

ll comb[1050][1050];
int in[1050];
int main() {
    int i, j, K, sum = 0;
    for (i = 1; i <= 1000; i++) {
        comb[i][0] = comb[i][i] = 1;
        for (j = 1; j < i; j++) comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
    }
    scanf("%d", &K);
    for (i = 1; i <= K; i++) {
        scanf("%d", &in[i]);
        sum += in[i];
    }

    ll ans = 1;
    for (i = K; i > 1; i--) {
        ans = (ans * comb[sum-1][in[i]-1]) % MOD;
        sum -= in[i];
    }
    printf("%I64d", ans);
    return 0;
}
//*/