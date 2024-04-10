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

int n, k;
string st, gst;
int ans;

int main() {
#ifdef CH_EGOR
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
#endif

    scanf("%d%d", &n, &k);
    cin >> st;
    sort(st.begin(), st.end());
    gst.push_back(st[0]);
    for (int i = 1; i < n; ++i) {
        if (st[i] - gst.back() > 1) gst.push_back(st[i]);
    }

    if (gst.size() < k) return 0 * printf("-1\n");
    else {
        for (int i = 0; i < k; ++i) ans += gst[i] - 'a' + 1;
        printf("%d\n", ans);
    }

    return 0;
}