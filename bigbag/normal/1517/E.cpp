/**
 *  created: 23/04/2021, 18:23:33
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, mod = 998244353;

int t, n, a[max_n];

bool get_bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

bool ok(const string &s) {
    vector<int> c, p;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'C') {
            c.push_back(i);
        } else {
            p.push_back(i);
        }
    }
    for (int i = 1; i + 1 < c.size(); ++i) {
        if (c[i] - c[i - 1] > c[i + 1] - c[i]) {
            return 0;
        }
    }
    for (int i = 1; i + 1 < p.size(); ++i) {
        if (p[i] - p[i - 1] < p[i + 1] - p[i]) {
            return 0;
        }
    }
    return true;
}

vector<string> gen_all(int n) {
    vector<string> res;
    for (int mask = 0; mask < (1 << n); ++mask) {
        string s;
        for (int i = 0; i < n; ++i) {
            s += "PC"[get_bit(mask, i)];
        }
        if (ok(s)) {
            res.push_back(s);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int triv() {
    long long tot = accumulate(a, a + n, 0LL), res = 0;
    for (auto s : gen_all(n)) {
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'C') {
                sum += a[i];
            }
        }
        res += 2 * sum < tot;
    }
    return res % mod;
}

long long tot;

bool oks(long long sum) {
    return 2 * sum < tot;
}

long long solve1() { // CCCCCCPCPCPCPCPPPPPPPPPPPP
    long long res = 0;
    for (int start = 0; start < 2; ++start) {
        long long cur_sum = 0, add = 0;
        if (start) {
            cur_sum = a[0];
        }
        int pos = start;
        while (pos + 1 < n && oks(cur_sum + add + a[pos + 1])) {
            add += a[pos + 1];
            pos += 2;
        }
        for (int c = start; c <= n && oks(cur_sum); c += 2) {
            //cout << start << " " << c << " " << pos << "   += " << (pos - c) / 2 + 1 << endl;
            res += (pos - c) / 2 + 1;

            cur_sum += a[c];
            cur_sum += a[c + 1];
            if (!oks(cur_sum)) {
                break;
            }
            add -= a[c + 1];
            while (!oks(cur_sum + add)) {
                pos -= 2;
                add -= a[pos + 1];
            }
        }
    }
    return res;
}

long long solve2() { // PCCCCCCCCCCCCCCPCPCPCPCPPPPPPPPPPPPPP
    if (n < 3) {
        return 0;
    }
    long long res = 0;
    for (int start = 3; start <= 4 && start <= n; ++start) {
        long long cur_sum = a[1] + a[2], add = 0;
        if (start == 4) {
            cur_sum += a[3];
        }
        int pos = start;
        while (pos + 1 < n && oks(cur_sum + add + a[pos + 1])) {
            add += a[pos + 1];
            pos += 2;
        }
        for (int c = start; c <= n && oks(cur_sum); c += 2) {
            res += (pos - c) / 2 + 1;
            cur_sum += a[c];
            cur_sum += a[c + 1];
            if (!oks(cur_sum)) {
                break;
            }
            add -= a[c + 1];
            while (!oks(cur_sum + add)) {
                pos -= 2;
                add -= a[pos + 1];
            }
        }
    }
    return res;
}

long long solve3() { // PCPPPPPPPPPC
    if (n >= 5 && oks(a[1] + a[n - 1])) {
        return 1;
    }
    return 0;
}

long long solve4() { // PPPPPCCCCCCCC
    long long res = 0;
    long long cur_sum = 0;
    for (int i = n - 1; i >= 2; --i) {
        cur_sum += a[i];
        if (!oks(cur_sum)) {
            break;
        }
        if (i != n - 1) {
            ++res;
        }
    }
    return res;
}


long long solve5() { // CCCCCCPCPCPCPCPPPPPPPPPPPPC
    if (n < 3) {
        return 0;
    }
    long long res = 0;
    for (int start = 0; start < 2; ++start) {
        long long cur_sum = 0, add = 0;
        if (start) {
            cur_sum = a[0];
        }
        cur_sum += a[n - 1];
        n -= 3;
        int pos = start;
        while (pos + 1 < n && oks(cur_sum + add + a[pos + 1])) {
            add += a[pos + 1];
            pos += 2;
        }
        for (int c = start; c <= n && oks(cur_sum); c += 2) {
            //cout << start << " " << c << " " << pos << "   += " << (pos - c) / 2 + 1 << endl;
            res += (pos - c) / 2 + 1;
            if (!c) {
                //--res;
            }

            cur_sum += a[c];
            cur_sum += a[c + 1];
            if (!oks(cur_sum)) {
                break;
            }
            add -= a[c + 1];
            while (!oks(cur_sum + add)) {
                pos -= 2;
                add -= a[pos + 1];
            }
        }
        n += 3;
    }
    return res;
}

long long solve6() { // PCCCCCCCCCCCCCCPCPCPCPCPPPPPPPPPPPPPP
    if (n < 6) {
        return 0;
    }
    long long res = 0;
    for (int start = 3; start <= 4 && start <= n; ++start) {
        long long cur_sum = a[1] + a[2], add = 0;
        if (start == 4) {
            cur_sum += a[3];
        }
        cur_sum += a[n - 1];
        n -= 3;
        int pos = start;
        while (pos + 1 < n && oks(cur_sum + add + a[pos + 1])) {
            add += a[pos + 1];
            pos += 2;
        }
        for (int c = start; c <= n && oks(cur_sum); c += 2) {
            res += (pos - c) / 2 + 1;
            cur_sum += a[c];
            cur_sum += a[c + 1];
            if (!oks(cur_sum)) {
                break;
            }
            add -= a[c + 1];
            while (!oks(cur_sum + add)) {
                pos -= 2;
                add -= a[pos + 1];
            }
        }
        n += 3;
    }
    return res;
}

int solve() {
    tot = accumulate(a, a + n, 0LL);
    //cout << solve5() << endl;
    //cout << solve1() << " " << solve2() << " " << solve3() << " " << solve4() << " " << solve5() << " " << solve6() << endl;
    long long res = 0;
    res += solve1();
    res += solve2();
    //res += solve3();
    res += solve4();
    res += solve5();
    res += solve6();
    res %= mod;
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        /*for (auto s : gen_all(n)) {
            cout << s << " ";
        }
        cout << endl;*/
        int ans = solve();
        printf("%d\n", ans);
    }
    return 0;
}