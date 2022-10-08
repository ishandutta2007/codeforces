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

bool prime_chk[5000050];
vector <int> prime_list;

ll cnt[5000050];
ll sum[5000050];
int main() {
    int i, j, T, A, B;
    for (i = 1; i <= 5000000; i++) cnt[i] = 0;
    for (i = 2; i <= 5000000; i++) {
        if (prime_chk[i]) continue;
        for (j = 2 * i; j <= 5000000; j += i) prime_chk[j] = true;
        ll t = i;
        while (t <= 5000000) {
            for (j = t; j <= 5000000; j+=t) cnt[j]++;
            t *= i;
        }
    }
    for (i = 1; i <= 5000000; i++) sum[i] = sum[i - 1] + cnt[i];
    
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        scanf("%d %d", &A, &B);
        printf("%lld\n", sum[A] - sum[B]);
    }
    return 0;
}
//*/