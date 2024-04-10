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

int in[15];
int main() {
    int N, L, R, X, i, j, ans = 0;
    scanf("%d %d %d %d", &N, &L, &R, &X);
    for (i = 0; i < N; i++) scanf("%d", &in[i]);
    for (i = 3; i < (1 << N); i++) {
        int t = i;
        int mx = 0, mn = INF, cnt = 0, sum = 0;
        for (j = 0; j < N; j++) {
            if (t % 2 == 1) {
                mx = max(mx, in[j]);
                mn = min(mn, in[j]);
                cnt++;
                sum += in[j];
            }
            t /= 2;
        }
        if (cnt == 1) continue;
        if (mx - mn < X) continue;
        if (sum > R || sum < L) continue;
        ans++;
    }
    printf("%d", ans);
    return 0;
}
//*/