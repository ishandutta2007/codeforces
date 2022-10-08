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

ll pow2(ll x, ll mod) {
    ll ans = 1, t = 2;
    while (x != 0) {
        if (x % 2 == 1) {
            ans *= t;
            ans %= mod;
        }
        t = (t*t) % mod;
        x /= 2;
    }
    return ans;
}

ll mat[2][2];
struct matrix {
    ll val[2][2];
    matrix() {
        for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) val[i][j] = mat[i][j];
    }
    matrix mul(matrix X, ll mod) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                mat[i][j] = 0;
                for (int k = 0; k < 2; k++) mat[i][j] += val[i][k] * X.val[k][j];
                mat[i][j] %= mod;
            }
        }
        return matrix();
    }
};

ll fib(ll x, ll mod) {
    mat[0][0] = 1, mat[0][1] = 1, mat[1][0] = 1, mat[1][1] = 0;
    matrix M = matrix();
    mat[0][0] = 1, mat[0][1] = 0, mat[1][0] = 0, mat[1][1] = 1;
    matrix A = matrix();
    while (x != 0) {
        if (x % 2 == 1) A = A.mul(M, mod);
        M = M.mul(M, mod);
        x /= 2;
    }
    return A.val[1][0];
}
int main() {
    ll n, k, m;
    int l, lk;
    scanf("%lld %lld %d %lld", &n, &k, &l, &m);
    if (m == 1) {
        printf("0");
        return 0;
    }
    if (l == 0) {
        if (k == 0) printf("1");
        else printf("0");
        return 0;
    }
    
    for (lk = 0; k >= (1LL << lk); lk++);
    if (lk > l) {
        printf("0");
        return 0;
    }
    int cnt1 = 0;
    while (k != 0) {
        if (k % 2 == 1) cnt1++;
        k /= 2;
    }

    ll val0 = fib(n + 2, m);
    ll val1 = (pow2(n, m) - fib(n + 2, m) + m) % m;

    ll ans = 1;
    for (int i = 1; i <= cnt1; i++) ans = (ans*val1) % m;
    for (int i = cnt1 + 1; i <= l; i++) ans = (ans*val0) % m;
    printf("%lld", ans);
    return 0;
}
//*/