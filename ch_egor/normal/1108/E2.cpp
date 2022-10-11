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

int n, m;
int arr[MAX_N];
int mx[4 * MAX_N];
int mn[4 * MAX_N];
int add[4 * MAX_N];
vector<pair<int, int>> lk[MAX_N];
vector<pair<int, int>> rk[MAX_N];

void build(int v, int l, int r) {
    if (r - l == 1) {
        mx[v] = arr[l];
        mn[v] = arr[l];
        add[v] = 0;
    } else {
        int m = (l + r) >> 1;

        build(2 * v + 1, l, m);
        build(2 * v + 2, m, r);

        mn[v] = min(mn[2 * v + 1], mn[2 * v + 2]);
        mx[v] = max(mx[2 * v + 1], mx[2 * v + 2]);
        add[v] = 0;
    }
}

void add_val(int v, int x) {
    mx[v] += x;
    mn[v] += x;
    add[v] += x;
}

void push(int v) {
    add_val(2 * v + 1, add[v]);
    add_val(2 * v + 2, add[v]);
    add[v] = 0;
}

void add_rg(int v, int l, int r, int x, int y, int val) {
    if (r <= x || y <= l) {
        return;
    } else if (x <= l && r <= y) {
        add_val(v, val);
    } else {
        push(v);
        int m = (l + r) >> 1;

        add_rg(2 * v + 1, l, m, x, y, val);
        add_rg(2 * v + 2, m, r, x, y, val);

        mn[v] = min(mn[2 * v + 1], mn[2 * v + 2]);
        mx[v] = max(mx[2 * v + 1], mx[2 * v + 2]);
    }
}

pair<int, vector<int>> solve(vector<pair<int, int>> at[MAX_N]) {
    build(0, 0, n);

    pair<int, int> ans = {mx[0] - mn[0], -1};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (int)at[i].size(); ++j) {
            add_rg(0, 0, n, at[i][j].first, i + 1, -1);
        }
        ans = max(ans, {mx[0] - mn[0], i});
    }

    pair<int, vector<int>> ret = {ans.first, {}};
    for (int i = 0; i <= ans.second; ++i) {
        for (int j = 0; j < (int)at[i].size(); ++j) {
            ret.second.push_back(at[i][j].second);
        }
    }
    sort(ret.second.begin(), ret.second.end());

    return ret;
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
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        --l; --r;
        lk[n - l - 1].push_back({n - r - 1, i});
        rk[r].push_back({l, i});
    }

    auto ans = solve(rk);
    reverse(arr, arr + n);
    ans = max(ans, solve(lk));

    printf("%d\n", ans.first);
    printf("%d\n", (int)ans.second.size());
    for (int i = 0; i < (int)ans.second.size(); ++i) {
        printf("%d%c", ans.second[i] + 1, " \n"[i == (int)ans.second.size() - 1]);
    }

    return 0;
}