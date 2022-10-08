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

int main() {
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        ll N, K, d1, d2, i, j;
        scanf("%I64d %I64d %I64d %I64d", &N, &K, &d1, &d2);
        if (N % 3 != 0) {
            printf("no\n");
            continue;
        }
        for (i = -1; i <= 1; i += 2) {
            for (j = -1; j <= 1; j += 2) {
                ll t1 = d1*i, t2 = d2*j;
                ll x1, x2, x3;
                if ((K - t1 - 2 * t2) % 3 != 0 || (K - t1 - 2 * t2) < 0) continue;
                x3 = (K - t1 - 2 * t2) / 3;
                x2 = x3 + t2;
                x1 = x2 + t1;
                if (max(max(x1, x2), x3) <= N / 3 && min(min(x1, x2), x3) >= 0) break;
            }
            if (j <= 1) break;
        }
        if (i <= 1) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
//*/