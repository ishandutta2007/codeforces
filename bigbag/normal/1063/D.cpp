#include <bits/stdc++.h>

using namespace std;

const int max_n = -1;
const long long inf = 1000111222000111222LL;

long long n, l, r, k;
long long cnt;

long long triv(long long n, long long l, long long r, long long k) {
    long long ans = -1;
    for (long long x = 0; x <= n; ++x) {
        long long y = k % (n + x);
        if (cnt <= y && y <= 2 * cnt && x - n + 2 * cnt <= y && y <= x + cnt) {
            ans = max(ans, x);
        }
    }
    return ans;
}

long long triv2(long long n, long long l, long long r, long long k) {
    ++k;
    long long ans = -1;
    for (long long x = 1; x <= n; ++x) {
        long long y = k % (n + x);
        if (1 + cnt <= y && y <= 2 * cnt && x - n + 2 * cnt <= y && y <= x + cnt) {
            ans = max(ans, x);
        }
    }
    return ans;
}

void upd(long long &L, long long &R, long long C) {
    if (L > R) {
        L = 1;
        R = 0;
        return;
    }
    if (C == 0) {
        if (L <= 0 && R >= 0) {
            L = -inf;
            R = inf;
        } else {
            L = 1;
            R = 0;
        }
    } else {
        if (L < 0) {
            L = 0;
        } else {
            L = (L + C - 1) / C;
        }
        if (R < 0) {
            R = -1;
        } else {
            R = R / C;
        }
    }
}

void intersect(long long l1, long long r1, long long l2, long long r2, long long &l, long long &r) {
    if (l1 > r1 || l2 > r2) {
        l = 1;
        r = 0;
        return;
    }
    if (l1 > l2) {
        swap(l1, l2);
        swap(r1, r2);
    }
    if (r1 < l2) {
        l = 1;
        r = 0;
    } else {
        l = l2;
        r = min(r1, r2);
    }
}

long long solve(long long n, long long l, long long r, long long k, long long st) {
    k += st;
    long long lx = st, ans = -1;
    while (lx <= n) {
        long long C = k / (n + lx), rx;
        if (C == 0) {
            rx = n;
        } else {
            rx = k / C - n;
        }
        long long l1, r1, l2, r2;
        l1 = k - C * n - 2 * cnt;
        r1 = k - C * n - cnt;// - st; // #
        if (cnt != 0 && st == 1) {
            --r1;
        }
        l2 = k - C * n - cnt;
        r2 = k - C * n + n - 2 * cnt;
        upd(l1, r1, C);
        upd(l2, r2, C + 1);
        long long okl, okr;
        intersect(lx, rx, l1, r1, okl, okr);
        intersect(okl, okr, l2, r2, okl, okr);
        if (okl <= okr) {
            ans = okr;
        }
        //cout << lx << " " << rx << " " << C << ": " << okl << " " << okr << "    " << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
        lx = rx + 1;
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> l >> r >> k;
    cnt = (r - l + 1) % n;
    if (cnt < 0) {
        cnt += n;
    }
    /*if (cnt == 0) {
        // k : (n + x)
        long long ans = -1;
        for (long long i = 1; i * i <= k; ++i) {
            if (k % i == 0) {
                long long x;
                x = i - n;
                if (0 <= x && x <= n) {
                    ans = max(ans, x);
                }
                x = k / i - n;
                if (0 <= x && x <= n) {
                    ans = max(ans, x);
                }
            }
        }
        cout << ans << "\n";
        return 0;
    }*/
    //cout << triv(n, l, r, k) << endl;
    //cout << triv2(n, l, r, k) << endl;
    long long q = solve(n, l, r, k, 0);
    long long w = solve(n, l, r, k, 1);
    long long ans = max(q, w);
    cout << ans << "\n";
    return 0;
}