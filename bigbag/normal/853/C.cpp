#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 200222, inf = 1011111111;

int n, q, a[max_n], t[max_n];
vector<pair<int, pair<int, int> > > all[2][max_n];
long long ans[max_n];

long long get_c(int n) {
    return (1LL * n * (n - 1)) / 2;
}

void update(int i) {
    for (; i < max_n; i = (i | (i + 1))) {
        ++t[i];
    }
}

int get_sum(int r) {
    int res = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) {
        res += t[r];
    }
    return res;
}

int get_sum(int l, int r) {
    if (l > r) {
        return 0;
    }
    if (l == 0) {
        return get_sum(r);
    }
    return get_sum(r) - get_sum(l - 1);
}

void proc(int tp) {
    memset(t, 0, sizeof(t));
    for (int i = 1; i <= n; ++i) {
        update(a[i]);
        for (int j = 0; j < all[tp][i].size(); ++j) {
            int id = all[tp][i][j].first;
            int l = all[tp][i][j].second.first;
            int r = all[tp][i][j].second.second;
            ans[id] += get_c(get_sum(l, r));
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < q; ++i) {
        int lx, ly, rx, ry;
        scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
        ans[i] = get_c(n) - get_c(lx - 1) - get_c(ly - 1) - get_c(n - rx) - get_c(n - ry);
        all[0][lx - 1].push_back(make_pair(i, make_pair(1, ly - 1)));
        all[0][lx - 1].push_back(make_pair(i, make_pair(ry + 1, n)));
        all[1][n - rx].push_back(make_pair(i, make_pair(1, ly - 1)));
        all[1][n - rx].push_back(make_pair(i, make_pair(ry + 1, n)));
    }
    proc(0);
    reverse(a + 1, a + n + 1);
    proc(1);
    for (int i = 0; i < q; ++i) {
        printf("%I64d\n", ans[i]);
    }
    return 0;
}