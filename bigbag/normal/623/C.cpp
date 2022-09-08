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

const int max_n = 111111;
const long long inf = 1111111111111111111LL;

int n;
long long dp[max_n], dp2[max_n];
long long mxa1[max_n], mxa2[max_n];
long long mna1[max_n], mna2[max_n];
long long mnx, mxx, mny, mxy;
pair<int, int> p[max_n];

long long my_abs(long long x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

long long my_sqr(long long x) {
    return x * x;
}

void get_dp() {
    dp[n] = -inf;
    mxa1[n] = -inf;
    mna1[n] = inf;
    for (int i = n - 1; i >= 0; --i) {
        dp[i] = max(dp[i + 1], my_abs(p[i].second));
        mxa1[i] = max(mxa1[i + 1], 1LL * p[i].second);
        mna1[i] = min(mna1[i + 1], 1LL * p[i].second);
    }
    dp2[0] = my_abs(p[0].second);
    mxa2[0] = p[0].second;
    mna2[0] = p[0].second;
    for (int i = 1; i < n; ++i) {
        dp2[i] = max(dp2[i - 1], my_abs(p[i].second));
        mxa2[i] = max(mxa2[i - 1], 1LL * p[i].second);
        mna2[i] = min(mna2[i - 1], 1LL * p[i].second);
    }
}

bool check(long long d) {
    for (int qqq = 0; qqq < 2; ++qqq) {
        //cout << "qqq = " << qqq << endl;
        for (int i = 0; i < n; ++i) {
            if (p[i].first <= 0 && my_sqr(p[i].first) <= d) {
                int l = i, r = n;
                while (r - l > 1) {
                    int mid = (l + r) / 2;
                    if (my_abs(p[i].first) >= my_abs(p[mid].first) && my_sqr(p[mid].first - p[i].first) <= d) {
                        l = mid;
                    } else {
                        r = mid;
                    }
                }
                long long mn = inf;
                long long mx = -inf;
                long long mxx = -inf;
                //cout << i << " " << l << endl;
                if (i) {
                    mn = min(mn, mna2[i - 1]);
                    mx = max(mx, mxa2[i - 1]);
                    mxx = max(mxx, dp2[i - 1]);
                }
                if (l + 1 < n) {
                    mn = min(mn, mna1[l + 1]);
                    mx = max(mx, mxa1[l + 1]);
                    mxx = max(mxx, dp[l + 1]);
                }
                if (i == 0 && l + 1 == n) {
                    mn = mx = mxx = 0;
                }
                long long res = max(my_sqr(mxx) + my_sqr(p[i].first), my_sqr(mx - mn));
                if (res <= d) {
                    return true;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            p[i].first *= -1;
        }
        reverse(p, p + n);
        get_dp();
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    mnx = mny = inf;
    mxx = mxy = -inf;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &p[i].first, &p[i].second);
        mnx = min(mnx, (long long) p[i].first);
        mny = min(mny, (long long) p[i].second);
        mxx = max(mxx, (long long) p[i].first);
        mxy = max(mxy, (long long) p[i].second);
    }
    long long ans = min(mxy - mny, mxx - mnx);
    ans *= ans;
    sort(p, p + n);
    get_dp();
    long long l = -1, r = inf;
    //cout << check(1) << endl;
    //return 0;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << min(ans, r) << endl;
    return 0;
}