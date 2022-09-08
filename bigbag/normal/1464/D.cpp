/**
 *  created: 21/12/2020, 23:16:10
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, mod = 1000000007, inf = 1000111222;

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

int t, n, p[max_n], cnt[max_n], used[max_n];
int pw[max_n];

void calc_cnt() {
    for (int i = 0; i <= n; ++i) {
        cnt[i] = 0;
        used[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            int pos = i, len = 0;
            do {
                used[pos] = 1;
                pos = p[pos];
                ++len;
            } while (pos != i);
            ++cnt[len];
        }
    }
}

int get_ans1() {
    if (n % 3 == 0) {
        return pw[n / 3];
    }
    if (n % 3 == 1) {
        return mul(pw[n / 3 - 1], 4);
    }
    return mul(pw[n / 3], 2);
}

int rems[3], mx_rem[3], cycles;
int REM0, REM1, REM2, CNT1;

void reserve() {
    REM0 = rems[0];
    REM1 = rems[1];
    REM2 = rems[2];
    CNT1 = cnt[1];
}

void restore() {
    rems[0] = REM0;
    rems[1] = REM1;
    rems[2] = REM2;
    cnt[1] = CNT1;
}

bool check(int c1, int c2, int c3) {
    if (cnt[1] > c1) {
        return false;
    }
    c1 -= cnt[1];

    int d2 = min(c2, rems[2]);
    rems[2] -= d2;
    c2 -= d2;
    if (rems[2] * 2 > c1) {
        return false;
    }
    c1 -= rems[2] * 2;

    if (rems[1] > c1) {
        return false;
    }
    c1 -= rems[1];

    return true;
}

bool check(int c1, int c2, int c3, bool c4) {
    bool res = false;
    reserve();
    if (!c4) {
        res |= check(c1, c2, c3);
        restore();
    } else {
        if (mx_rem[1] >= 4) {
            --rems[1];
            res = check(c1, c2, c3);
            restore();
        } else {
            if (mx_rem[2] >= 8) {
                --rems[2];
                ++rems[1];
                res |= check(c1, c2, c3);
                restore();
            } else if (mx_rem[2] >= 5) {
                --rems[2];
                ++cnt[1];
                res |= check(c1, c2, c3);
                restore();
            }

            if (mx_rem[0] >= 6) {
                --rems[0];
                ++rems[2];
                res |= check(c1, c2, c3);
                restore();
            }
        }
    }
    return res;
}

int solve(int el, int c1, int c2, int c3, bool c4) {
    int res = inf;
    for (int tp3 = 0; tp3 <= c3; ++tp3) {
        int l = -1, r = c3 - tp3 + 1;
        while (r - l > 1) {
            int tp1 = (l + r) / 2;
            int tp2 = c3 - tp3 - tp1;
            if (check(3 * tp1 + tp2 + c1, tp2 + c2, tp3 + c3, c4)) {
                r = tp1;
            } else {
                l = tp1;
            }
        }
        if (r < c3 - tp3 + 1) {
            int tp1 = r;
            int tp2 = c3 - tp3 - tp1;
            int ops = 2 * (3 * tp1 + 2 * tp2 + tp3 + c1 + c2 + c4) - el - cycles;
            //cout << el << " " << c1 << " " << c2 << " " << c3 << " " << c4 << ", tp = " << tp1 << " " << tp2 << " " << tp3 << ", ops = " << ops << endl;
            res = min(res, ops);
        }
    }
    return res;
}

int get_ans2() {
    memset(rems, 0, sizeof(rems));
    memset(mx_rem, 0, sizeof(mx_rem));
    cycles = accumulate(cnt, cnt + n + 1, 0);
    for (int i = 2; i <= n; ++i) {
        rems[i % 3] += cnt[i];
        if (cnt[i]) {
            mx_rem[i % 3] = max(mx_rem[i % 3], i);
        }
    }
    int res = inf;
    if (n % 3 == 0) {
        res = min(res, solve(n / 3, 0, 0, n / 3, 0));
    } else if (n % 3 == 1) {
        res = min(res, solve(n / 3, 0, 0, n / 3 - 1, 1));
        res = min(res, solve(n / 3, 1, 0, n / 3, 0));
        res = min(res, solve(n / 3 + 1, 0, 2, n / 3 - 1, 0));
        res = min(res, solve(n / 3 + 1, 2, 1, n / 3 - 1, 0));
        res = min(res, solve(n / 3 + 1, 4, 0, n / 3 - 1, 0));
    } else {
        res = min(res, solve(n / 3 + 1, 0, 1, n / 3, 0));
        res = min(res, solve(n / 3 + 1, 2, 0, n / 3, 0));
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    pw[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        pw[i] = mul(pw[i - 1], 3);
    }
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &p[i]);
            --p[i];
        }
        calc_cnt();
        printf("%d ", get_ans1());
        printf("%d\n", get_ans2());
    }
    return 0;
}