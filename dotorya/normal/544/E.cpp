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

char in[25][25];
ll dp[1200000];
ll val[25][25];
ll same_val[25][25];
int same_bit[25][25];

int main() {
    int N, M, i, j, k;
    scanf("%d %d", &N, &M);
    for (i = 0; i < N; i++) scanf("%s", in[i]);
    for (i = 0; i < N; i++) for (j = 0; j < M; j++) scanf("%lld", &val[i][j]);
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            ll sum = 0, mx = 0;
            for (k = 0; k < N; k++) {
                if (in[i][j] == in[k][j]) {
                    same_bit[i][j] += (1 << k);
                    sum += val[k][j];
                    mx = max(mx, val[k][j]);
                }
            }
            same_val[i][j] = sum - mx;
        }
    }

    dp[0] = 0;
    for (i = 1; i < (1 << N); i++) dp[i] = LL_INF;
    for (i = 1; i < (1<<N); i++) {
        int t = i, lb;
        for (lb = 0;;lb++, t /= 2) if (t % 2 == 1) break;

        t = i & (~(1 << lb));
        for (j = 0; j < M; j++) {
            dp[i] = min(dp[i], dp[t] + val[lb][j]);
        }

        for (j = 0; j < M; j++) {
            t = i & (~same_bit[lb][j]);
            dp[i] = min(dp[i], dp[t] + same_val[lb][j]);
        }
    }
    printf("%lld", dp[(1 << N) - 1]);
    return 0;
}
//*/