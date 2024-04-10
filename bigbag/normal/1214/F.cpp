#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int m, n, used[max_n];
pair<int, int> a[max_n], b[max_n];
int order[max_n];
long long suma[max_n], sumb[max_n];

int dist(int x, int y) {
    int res = abs(x - y);
    //res = min(res, m - res);
    return res;
}

long long get_sum(long long sum[], int l, int r) {
    if (l > r) {
        return 0;
    }
    if (l == 0) {
        return sum[r];
    }
    return sum[r] - sum[l - 1];
}

long long f(int l, int r) {
    long long res = 1LL * l * m - get_sum(sumb, n - l, n - 1) + get_sum(suma, 0, l - 1);
    res += 1LL * m * (n - r - 1) - get_sum(suma, r + 1, n - 1) + get_sum(sumb, 0, n - r - 2);
    const int sd = n - r - 1;
    for (int i = l; i <= r; ++i) {
        res += abs(a[i].first - b[sd + i - l].first);
    }
    return res;
}

int last;

long long f2(int L) {
    int l = l - 2, r = n - 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (f(L, mid) >= f(L, mid + 1)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    last = r;
    return f(L, last);
}

const bool debug = false;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    if (debug) {
        m = 1000000000;
        n = 200000;
        for (int i = 0; i < n; ++i) {
            a[i].first = rand() % m + 1;
        }
    } else {
        scanf("%d%d", &m, &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i].first);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &b[i].first);
        }
    }
    for (int i = 0; i < n; ++i) {
        a[i].second = i;
        b[i].second = i;
    }
    sort(a, a + n);
    sort(b, b + n);
    suma[0] = a[0].first;
    sumb[0] = b[0].first;
    for (int i = 1; i < n; ++i) {
        suma[i] = suma[i - 1] + a[i].first;
        sumb[i] = sumb[i - 1] + b[i].first;
    }
    int l = -1, r = n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (f2(mid) >= f2(mid + 1)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    int L = r;
    long long ans = f2(L);
    int R = last;
    /*int l = 0, r = -1, best_l = 0, best_r = -1;
    long long cur = f(l, r);
    long long ans = cur;
    while (l <= n) {
        while (r + 1 < n) {
            long long ncur = f(l, r + 1);
            if (cur > ncur) {
                ++r;
                cur = ncur;
            } else {
                break;
            }
        }
        if (ans > cur) {
            ans = cur;
            best_l = l;
            best_r = r;
        }
        ++l;
        cur = f(l, r);
    }*/
    /*for (int l = 0; l <= n; ++l) {
        for (int r = l - 1; r < n; ++r) {
            long long res = f(l, r);
            if (ans > res) {
                ans = res;
            }
        }
    }*/
    printf("%I64d\n", ans);
    for (int i = 0; i < L; ++i) {
        order[a[i].second] = b[n - i - 1].second;
    }
    for (int i = R + 1; i < n; ++i) {
        order[a[i].second] = b[n - i - 1].second;
    }
    //cout << L << " " << R << endl;
    const int sd = n - R - 1;
    for (int i = L; i <= R; ++i) {
        order[a[i].second] = b[sd + i - L].second;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", order[i] + 1);
    }
    return 0;
}