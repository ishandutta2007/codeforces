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

int r[100050][2];
int root(int x) {
    if (r[r[x][0]][0] == r[x][0]) return r[x][0];

    int n = root(r[x][0]);
    r[x][1] ^= r[r[x][0]][1];
    r[x][0] = n;
    return n;
}
int main() {
    int N, M, i, t1, t2, t3;
    scanf("%d %d", &N, &M);
    for (i = 1; i <= N; i++) {
        r[i][0] = i;
        r[i][1] = 0;
    }

    for (i = 1; i <= M; i++) {
        scanf("%d %d %d", &t1, &t2, &t3);
        int x = root(t1);
        int y = root(t2);
        int z = (1 - t3) ^ r[t1][1] ^ r[t2][1];
        if (x == y) {
            if (z == 1) break;
            continue;
        }
        r[x][0] = y;
        r[x][1] = z;
    }

    if (i <= M) {
        printf("0");
        return 0;
    }
    int cnt = -1;
    for (i = 1; i <= N; i++) {
        if (i == r[i][0]) cnt++;
    }

    ll ans = 1;
    for (i = 1; i <= cnt; i++) {
        ans *= 2;
        ans %= MOD;
    }
    printf("%I64d", ans);
    return 0;
}
//*/