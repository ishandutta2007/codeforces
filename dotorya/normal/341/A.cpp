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

const int IT_MAX = 32768;
const int MOD = 1000000007;
const int INF = 2034567891;
const ll LL_INF = 1234567890123456789ll;

ll in[100050];
ll gcd(ll a, ll b) {
    return (a == 0) ? b : gcd(b%a, a);
}
int main() {
    ll N, i;
    scanf("%I64d", &N);
    //N = 100000;
    for (i = 1; i <= N; i++) {
        scanf("%I64d", &in[i]);
        //if (i % 2 == 1) in[i] = 1;
    //  else in[i] = 10000000;
    }
    sort(in + 1, in + N + 1);

    ll ans = 0;
    for (i = 1; i <= N; i++) {
        ans += (4*i-2*N-1)*in[i];
    //  ans += 2 * (i - 1)*(i - 1)*in[i];
    //  ans += (i - 1) * in[i];
    //  ans -= (N - i) * in[i];
    //  ans -= 2 * (N - i)*(N - i - 1) * in[i];
    }

    ll ans2 = N;
    ll g = gcd(ans, ans2);
    printf("%I64d %I64d", ans / g, ans2 / g);
    return 0;
}
//*/