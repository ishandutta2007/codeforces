#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <assert.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <queue>
#define forn(i, n) for(int i = 0; i < n; i++)
#define mp(i, j) make_pair(i, j)
#define sz(a) a.size()
#define re  return
#define fi first
#define se second

typedef std::pair<int, int> pii;

using namespace std;

int n, q, x, y;

vector<pii> a[2001];

void my_assert(bool q) {
    if (!q) while(true);
}

int main()
{
    //freopen("point.in", "r", stdin);
    //freopen("point.out", "w", stdout);
    scanf("%d", &n);
    forn (i, 2001)
        a[i].resize(0);

    forn (i, n) {
        scanf("%d%d", &x, &y);
        my_assert(x / 1000 <= 2000);
        assert(y <= 1000000);
        assert(x >= 0);
        assert(y >= 0);
        a[x / 1000].push_back(mp(y, i + 1));
    }

    forn (i, 2001) {
        if (sz(a[i])) sort(a[i].begin(), a[i].end());
        if (i % 2 && sz(a[i])) reverse(a[i].begin(), a[i].end());
        forn (j, sz(a[i]))
            printf("%d ", a[i][j].se);
    }

    return 0;
}