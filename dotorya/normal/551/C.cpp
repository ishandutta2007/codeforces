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

ll in[100050];
ll t[100050];
int main() {
    int N, M, i, j;
    ll st = 1, en = 1E+16, mi, ans = 1E+14;
    scanf("%d %d", &N, &M);
    for (i = 1; i <= N; i++) scanf("%lld", &in[i]);
    while (in[N] == 0) N--;
    while (st <= en) {
        mi = (st + en) / 2;
        int c = 1;
        for (i = 1; i <= N; i++) t[i] = in[i];
        
        for (i = 1; i <= M; i++) {
            ll tmp = mi - c;
            while(c <= N) {
                if (tmp >= t[c]) {
                    tmp -= t[c] + 1;
                    t[c] = 0;
                    c++;
                    if (tmp <= 0) break;
                    continue;
                }
                else {
                    t[c] -= tmp;
                    tmp = 0;
                    break;
                }
            }
            if (c > N) break;
        }
        if (c <= N) st = mi + 1;
        else {
            ans = mi;
            en = mi - 1;
        }
    }
    printf("%lld", ans);
    return 0;
}
//*/