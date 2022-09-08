#include <bits/stdc++.h>

using namespace std;

const int max_n = 1, inf = 1000000000;

unsigned long long n, h;

unsigned long long get_sum(unsigned long long r) {
    return (r * (r + 1)) / 2;
}

unsigned long long get_sum(unsigned long long l, unsigned long long r) {
    return get_sum(r) - get_sum(l - 1);
}

unsigned long long solve(unsigned long long n, unsigned long long h) {
    unsigned long long l = 0, r = 2 * inf;
    while (r - l > 1) {
        unsigned long long mid = (l + r) / 2;
        if (get_sum(mid) < n) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (r <= h) {
        return r;
    }
    l = 0;
    r = 2 * inf;
    while (r - l > 1) {
        unsigned long long mid = (l + r) / 2;
        if (get_sum(h, h + mid) + get_sum(h + mid - 1) < n) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (get_sum(h, h + r) + get_sum(h + r - 1) - h - r >= n) {
        --h;
    }
    return 2 * r + h;
}

int trivial(int n, int h, int cur = -1, int depth = 0) {
    if (depth == 22) {
        return inf;
    }
    if (n == 0) {
        if (cur <= 1) {
            return 0;
        }
        return inf;
    }
    int l = cur - 1, r = cur + 1;
    l = max(l, 0);
    if (cur == -1) {
        l = 0;
        r = h;
    }
    int ans = inf;
    for (int i = l; i <= r && i <= n; ++i) {
        ans = min(ans, trivial(n - i, h, i, depth + 1) + 1);
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    if (0) {
        for (int n = 1; n <= 15; ++n) {
            for (int h = 1; h <= 15; ++h) {
                if (solve(n, h) != trivial(n, h)) {
                    cout << n << " " << h << endl;
                    cout << "WA: " << solve(n, h) << endl;
                    cout << "OK: " << trivial(n, h) << endl;
                    return 0;
                }
                cout << "+";
            }
        }
        cout << "PASSED" << endl;
        return 0;
    }
    cin >> n >> h;
    cout << solve(n, h) << endl;
    //cout << trivial(n, h) << endl;
    return 0;
}