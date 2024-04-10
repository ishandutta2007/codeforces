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

struct Hash {
    Hash() {
        Hash(0, 0, 0, 0);
    }
    Hash(ll a, ll b, ll c, ll d) {
        k31 = a;
        k43 = b;
        k59 = c;
        k83 = d;
    }
    ll k31, k43, k59, k83;
    bool operator == (const Hash & l) const {
        return k31 == l.k31 && k43 == l.k43 && k59 == l.k59 && k83 == l.k83;
    }
};
int in1[200050];
int in2[200050];
ll x[200050];
ll y[200050];
int main() {
    int N, W, i, j;
    scanf("%d %d", &N, &W);
    for (i = 0; i < N; i++) scanf("%d", &in1[i]);
    for (i = 0; i < W; i++) scanf("%d", &in2[i]);
    if (W == 1) {
        printf("%d", N);
        return 0;
    }
    if (N < W) {
        printf("0");
        return 0;
    }

    for (i = 0; i < N - 1; i++) x[i] = in1[i + 1] - in1[i];
    for (i = 0; i < W - 1; i++) y[i] = in2[i + 1] - in2[i];
    N--;
    W--;

    ll m31 = 1, m43 = 1, m59 = 1, m83 = 1;
    for (i = 0; i < W; i++) {
        m31 = (m31 * 31) % MOD;
        m43 = (m43 * 43) % MOD;
        m59 = (m59 * 59) % MOD;
        m83 = (m83 * 83) % MOD;
    }

    Hash xh = Hash(0, 0, 0, 0);
    Hash yh = Hash(0, 0, 0, 0);
    for (i = 0; i < W; i++) {
        xh.k31 = (xh.k31 * 31 + x[i] + MOD*10) % MOD;
        xh.k43 = (xh.k43 * 43 + x[i] + MOD * 10) % MOD;
        xh.k59 = (xh.k59 * 59 + x[i] + MOD * 10) % MOD;
        xh.k83 = (xh.k83 * 83 + x[i] + MOD * 10) % MOD;
        yh.k31 = (yh.k31 * 31 + y[i] + MOD * 10) % MOD;
        yh.k43 = (yh.k43 * 43 + y[i] + MOD * 10) % MOD;
        yh.k59 = (yh.k59 * 59 + y[i] + MOD * 10) % MOD;
        yh.k83 = (yh.k83 * 83 + y[i] + MOD * 10) % MOD;
    }

    int ans = 0;
    for (i = W; i < N; i++) {
        if (xh == yh) ans++;
        xh.k31 = (xh.k31 * 31 - (m31*x[i - W]) % MOD + x[i] + MOD) % MOD;
        xh.k43 = (xh.k43 * 43 - (m43*x[i - W]) % MOD + x[i] + MOD) % MOD;
        xh.k59 = (xh.k59 * 59 - (m59*x[i - W]) % MOD + x[i] + MOD) % MOD;
        xh.k83 = (xh.k83 * 83 - (m83*x[i - W]) % MOD + x[i] + MOD) % MOD;
    }
    if (xh == yh) ans++;
    printf("%d", ans);
    return 0;
}
//*/