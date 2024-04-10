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

int n, m;
map<int, int> cnt;

bool check(int m) {
    int now = 0;
    for (auto it = cnt.begin(); it != cnt.end(); ++it) {
        now += it->second / m;
    }
    return now >= n;
}

int main() {
#ifdef CH_EGOR
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
#endif

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i) {
        int x;
        scanf("%d", &x);
        ++cnt[x];
    }

    int l = 0;
    int r = INF;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        if (check(m)) l = m;
        else r = m;
    }

    printf("%d\n", l);

    return 0;
}