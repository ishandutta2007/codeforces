#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <set>
#include <cmath>
#include <cstdlib>
#include <map>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <stdlib.h>
#include <assert.h>
#include <complex>
#include <cstring>

using namespace std;

typedef long long ll;

typedef complex<double> cd;

const int inf = 1000000000;
const int mod = 1e9 + 7;
const long long longinf = 1000000000000000000;
const double PI = 3.141592653589793;

int N, L, M;
ll dp[200] = {0};
ll dpn[200] = {0};
ll c[200];
ll tr[1000010];
ll A[200][200];
ll tmp[200][200] = {0};
ll res[200][200];

void mult(ll a[200][200], ll b[200][200], int w) {
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < w; ++j) {
            res[i][j] = 0;
            for (int l = 0; l < w; ++l) {
                res[i][j] = (res[i][j] + (a[i][l] * b[l][j]) % mod) % mod;
            }
        }
    }
}

void pwr(int n) {
    for (int i = 0; i < M; ++i)
        tmp[i][i] = 1;

    while (n) {
        if (n & 1) {
            mult(tmp, A, M);
            memcpy(tmp, res, sizeof(tmp));
        }

        n >>= 1;
        mult(A, A, M);
        memcpy(A, res, sizeof(A));
    }
}

void solve() {
    scanf("%d%d%d", &N, &L, &M);

    ll ci;
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &ci);
        if (ci == M)
            ci = 0;
        ++dp[ci];
    }

    for (int i = 0; i < N; ++i) {
        scanf("%lld", &tr[i]);
        if (tr[i] == M)
            tr[i] = 0;
        ++c[tr[i]];
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            A[i][j] = c[(M + i - j) % M];
        }
    }

    pwr(L-2);

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            dpn[i] = (dpn[i] + tmp[i][j] * dp[j]) % mod;
        }
    }

    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        scanf("%lld", &ci);
        ci += tr[i];
        ci %= M;
        ans = (ans + dpn[(M - ci) % M]) % mod;
    }
    printf("%lld", ans);
}

int main() {
    cout.precision(20);
    cin.tie(0);
//    srand(time(0));
    iostream::sync_with_stdio(false);
    solve();
    return 0;
}