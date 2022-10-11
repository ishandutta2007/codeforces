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

const int MAX_N = 228;

int get(int x) {
    printf("%d\n", x);
    fflush(stdout);
    scanf("%d", &x);
    if (!x) exit(0);
    return x;
}

ll m, n;
int arr[MAX_N];

int main() {
#ifdef CH_EGOR
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
#endif

    scanf("%lld%lld", &m, &n);

    for (int i = 0; i < n; ++i) arr[i] = get(1);

    ll l = 1;
    ll r = m + 1;

    int iter = 0;
    while (r - l > 1) {
        ll md = (l + r) >> 1;

        if (arr[iter++ % n] * get(md) > 0) l = md;
        else r = md;
    }

    get(l);
    assert(false);

    return 0;
}