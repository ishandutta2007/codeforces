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
const int max_lev = 18;

int maxs[max_lev][max_n], num[max_n];

void get_all_maxs(int n, int a[]) {
    for (int i = 0; i < n; ++i) {
        maxs[0][i] = a[i];
    }
    for (int i = 1; i < max_lev; ++i) {
        for (int j = 0; j < n && j + (1 << (i - 1)) < n; ++j) {
            maxs[i][j] = maxs[i - 1][j] | maxs[i - 1][j + (1 << (i - 1))];
        }
    }
    for (int i = 1, x = 0; i <= n; i *= 2, ++x) {
        for (int j = i; j <= n && j < i * 2; ++j) {
            num[j] = x;
        }
    }
}

int get_xor(int l, int r) {
    if (l > r) {
        return -inf;
    }
    int lev = num[r - l + 1];
    return maxs[lev][l] | maxs[lev][r - (1 << lev) + 1];
}

int n, a[max_n];
long long ans;
vector<pair<int, int> > v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    get_all_maxs(n, a);
    for (int i = n - 1; i >= 0; --i) {
        while (v.size() && a[i] >= -v.back().first) {
            v.pop_back();
        }
        v.push_back({-a[i], i});
        int st = i;
        while (st != n) {
            int cur = get_xor(i, st);
            int l = st, r = n;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (cur == get_xor(i, mid)) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            vector<pair<int, int> >::iterator it = upper_bound(v.begin(), v.end(), make_pair(-cur, inf));
            if (it == v.begin()) {
                ans += r - st;
            } else {
                --it;
                ans += min(it->second, r) - st;
            }
            st = r;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}