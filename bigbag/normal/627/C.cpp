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

const int max_n = 222222, max_lev = 20, inf = 1111111111;

int d, MX, m, n, mins[max_lev][max_n], num[max_n];;
long long ans;
pair<int, int> p[max_n];

void get_all_mins(int n) {
    for (int i = 0; i < n; ++i) {
        mins[0][i] = p[i].second;
    }
    for (int i = 1; i < max_lev; ++i) {
        for (int j = 0; j < n && j + (1 << (i - 1)) < n; ++j) {
            mins[i][j] = min(mins[i - 1][j], mins[i - 1][j + (1 << (i - 1))]);
        }
    }
    for (int i = 1, x = 0; i <= n; i *= 2, ++x) {
        for (int j = i; j <= n && j < i * 2; ++j) {
            num[j] = x;
        }
    }
}

int get_min(int l, int r) {
    if (l > r) {
        return inf;
    }
    int lev = num[r - l + 1];
    return min(mins[lev][l], mins[lev][r - (1 << lev) + 1]);
}

void add(int c, int i) {
    c = min(c, d - p[i].first - m);
    ans += 1LL * c * p[i].second;
    m += c;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &d, &MX, &n);
    m = MX;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &p[i].first, &p[i].second);
    }
    sort(p, p + n);
    get_all_mins(n);
    int last = 0;
    for (int i = 0; i < n; ++i) {
        m -= (p[i].first - last);
        if (m < 0) {
            printf("-1\n");
            return 0;
        }
        last = p[i].first;
        if (last + m >= d) {
            cout << ans << endl;
            return 0;
        }
        int l = i, r = n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (last + m >= p[mid].first) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (i < l && get_min(i + 1, l) <= p[i].second) {
            continue;
        }
        r = n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (get_min(i + 1, mid) < p[i].second) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if (r == n) {
            add(MX - m, i);
        } else {
            int x = p[r].first - p[i].first;
            if (x <= MX) {
                add(x - m, i);
            } else {
                add(MX - m, i);
            }
        }
        if (last + m >= d) {
            cout << ans << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}