#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int sy, a, b, n, q, l[max_n], r[max_n];
long long sum[max_n];

long long get_sum(int l, int r) {
    if (l == 0) {
        return sum[r];
    }
    return sum[r] - sum[l - 1];
}

long double getx(int x, int y, int l) {
    long double res = 1LL * (l - x) * (y - sy);
    res /= y;
    res += x;
    return res;
}

long double add(int x, int y, int l, int r) {
    long double from = getx(x, y, l);
    long double to = getx(x, y, r);
    if (to < a) {
        return 0;
    }
    if (from > b) {
        return 0;
    }
    from = max(from, (long double) a);
    to = min(to, (long double) b);
    return to - from;
}

double solve(int x, int y) {
    int L = -1, R = n;
    while (R - L > 1) {
        int mid = (L + R) / 2;
        if (1LL * a * y <= 1LL * x * y + 1LL * (l[mid] - x) * (y - sy)) {
            R = mid;
        } else {
            L = mid;
        }
    }
    int first = R;
    L = -1, R = n;
    while (R - L > 1) {
        int mid = (L + R) / 2;
        if (1LL * x * y + 1LL * (r[mid] - x) * (y - sy) <= 1LL * b * y) {
            L = mid;
        } else {
            R = mid;
        }
    }
    int last = L;
    long double ans = 0;
    if (first <= last) {
        long double pl = 1LL * get_sum(first, last) * (y - sy);
        pl /= y;
        ans += pl;
    }
    //cout << first << " " << last << endl;
    if (first - 1 >= 0) {
        ans += add(x, y, l[first - 1], r[first - 1]);
    }
    if (last + 1 < n && last + 1 != first - 1) {
        ans += add(x, y, l[last + 1], r[last + 1]);
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d", &sy, &a, &b, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &l[i], &r[i]);
        sum[i] = r[i] - l[i];
        if (i) {
            sum[i] += sum[i - 1];
        }
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%.10f\n", solve(x, y));
    }
    return 0;
}