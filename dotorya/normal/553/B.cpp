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

ll F[55];
void aa(int lvl, int N, ll K) {
    if (lvl > N) return;
    if (lvl == N) {
        printf("%d ", lvl);
        return;
    }
    int n = N + 1 - lvl;
    if (F[n - 1] > K) {
        printf("%d ", lvl);
        aa(lvl + 1, N, K);
    }
    else {
        printf("%d %d ", lvl + 1, lvl);
        aa(lvl + 2, N, K - F[n - 1]);
    }
}
int main() {
    int N, i;
    F[1] = 1, F[2] = 2;
    for (i = 3; i <= 50; i++) F[i] = F[i - 1] + F[i - 2];
    ll K;
    scanf("%d %I64d", &N, &K);
    K--;
    aa(1, N, K);
    return 0;
}
//*/