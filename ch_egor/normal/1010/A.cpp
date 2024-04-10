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

const int MAX_N = 100 * 1000 + 228;

int n;
ll m;
ll a[MAX_N];
ll b[MAX_N];

int main() {
#ifdef CH_EGOR
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
#endif

    scanf("%d%lld", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
        if (a[i] == 1) return 0 * printf("-1\n");
    }
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &b[i]);
        if (b[i] == 1) return 0 * printf("-1\n");
    }

    ld ans = m + (ld)m / (b[0] - 1);
    for (int i = n - 1; i > -1; --i) {
        ans += ans / (a[i] - 1);
        if (i) ans += ans / (b[i] - 1);
    }

    cout << fixed << setprecision(20);
    cout << ans - m << "\n";

    return 0;
}