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

ll in[25];

ll fact_rev(ll x) {
    ll t = MOD - 2;
    ll rv = 1, mul = x;
    while (t > 0) {
        if (t % 2 == 1) rv = (rv*mul) % MOD;
        mul = (mul*mul) % MOD;
        t /= 2;
    }
    return rv;
}
ll H(ll S, int N, ll factn) {
    if (S < 0) return 0;
    if (S == 0) return 1;
    ll rv = 1;
    for (ll i = S + N - 1; i > S; i--) rv = (rv*(i%MOD)) % MOD;
    rv = (rv*fact_rev(factn)) % MOD;
    return rv;
}
int main() {
    int N, i;
    ll S;
    scanf("%d %I64d", &N, &S);
    ll factn = 1;
    for (i = 1; i < N; i++) factn = (factn*i) % MOD;
    for (i = 0; i < N; i++) scanf("%I64d", &in[i]);
    ll ans = 0;
    for (i = 0; i < (1 << N); i++) {
        int cnt = 0, t = i;
        ll x = S;
        for (int j = 0; j < N; j++, t /= 2) {
            if (t % 2 == 1) {
                cnt++;
                x -= in[j] + 1;
            }
        }
        if (cnt % 2 == 0) ans += H(x, N, factn);
        else ans += MOD - H(x, N, factn);
    }
    printf("%I64d", ans%MOD);
    return 0;
}
//*/