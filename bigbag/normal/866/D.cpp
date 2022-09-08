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

const int max_n = 300333, inf = 1011111111;

int n, a[max_n];
long long ans;
set<pair<int, int> > q1, q2, ok;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = n - 1; i >= 0; --i) {
        pair<int, int> best1 = {-inf, inf};
        pair<int, int> best2 = {-inf, inf};
        if (q1.size()) {
            pair<int, int> p = *q1.rbegin();
            if (a[i] < p.first) {
                best1 = {p.first - a[i], p.second};
            }
        }
        if (ok.size()) {
            pair<int, int> p = *ok.rbegin();
            if (a[i] < p.first) {
                best2 = {p.first - a[i], p.second};
            }
        }
        int mx = max(best1.first, best2.first);
        if (mx > 0) {
            ans += mx;
            if (best1.first >= best2.first) {
                q1.erase({a[best1.second], best1.second});
                q1.insert({a[i], i});
                ok.insert({a[best1.second], best1.second});
            } else {
                ok.erase({a[best2.second], best2.second});
                q1.insert({a[i], i});
            }
        } else {
            ok.insert({a[i], i});
        }
    }
    printf("%I64d\n", ans);
    return 0;
}