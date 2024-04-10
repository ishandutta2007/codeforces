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

const int max_n = 111111, max_lev = 20, inf = 111111111;

struct state {
    int x, h, num;
    bool operator < (const state &a) const {
        return x < a.x;
    }
};

int n, ans[max_n], a[max_n], num[max_n];
pair <int, int> maxs[max_lev][max_n];
state s[max_n];

void get_all_maxs(int n, int a[]) {
    for (int i = 0; i < n; ++i) {
        maxs[0][i] = make_pair(a[i], i);
    }
    for (int i = 1; i < max_lev; ++i) {
        for (int j = 0; j < n && j + (1 << (i - 1)) < n; ++j) {
            maxs[i][j] = max(maxs[i - 1][j], maxs[i - 1][j + (1 << (i - 1))]);
        }
    }
    for (int i = 1, x = 0; i <= n; i *= 2, ++x) {
        for (int j = i; j <= n && j < i * 2; ++j) {
            num[j] = x;
        }
    }
}

pair<int, int> get_max(int l, int r) {
    if (l > r) {
        return make_pair(-inf, -inf);
    }
    int lev = num[r - l + 1];
    return max(maxs[lev][l], maxs[lev][r - (1 << lev) + 1]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i].x >> s[i].h;
        s[i].num = i;
    }
    sort(s, s + n);
    for (int i = 0; i < n; ++i) {
        a[i] = s[i].x + s[i].h - 1;
    }
    get_all_maxs(n, a);
    ans[s[n - 1].num] = 1;
    for (int i = n - 2; i >= 0; --i) {
        int h = s[i].x + s[i].h - 1;
        if (h < s[i + 1].x) {
            ans[s[i].num] = 1;
        } else {
            int l = i + 1, r = n;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (s[mid].x <= h) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            pair<int, int> p = get_max(i + 1, l);
            ans[s[i].num] = p.second - i + ans[s[p.second].num];
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}