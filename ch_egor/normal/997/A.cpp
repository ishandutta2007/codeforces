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

const int MAX_N = 300 * 1000 + 228;

int n;
ll x, y;
char st[MAX_N];

int main() {
#ifdef CH_EGOR
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
#endif

    scanf("%d%lld%lld", &n, &x, &y);
    scanf("%s", st);

    ll cnt = (st[0] == '0');
    for (int i = 1; i < n; ++i) if (st[i] == '0' && st[i - 1] == '1') ++cnt;

    if (cnt) printf("%lld\n", y + (cnt - 1) * min(x, y));
    else printf("0\n");

    return 0;
}