#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_M = 1000 * 1000 + 228;

ll n, m;
ll cnt[MAX_M];

ll get_cnt(ll x) {
    if (x == 0) {
        return n / m;
    } else {
        return n / m + (n % m >= x);
    }
}

int main() {
#ifdef CH_EGOR
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
#endif

    scanf("%lld%lld", &n, &m);

    for (ll i = 0; i < m; ++i) {
        cnt[(i * i) % m] += get_cnt(i);
    }

    ll ans = 0;
    for (ll i = 0; i < m; ++i) {
        ans += cnt[i] * cnt[(m - i) % m];
    }

    printf("%lld\n", ans);

    return 0;
}