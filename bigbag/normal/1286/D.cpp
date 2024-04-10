#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 2000111222;
const int mod = 998244353;

int mul(int x, int y) {
    return (1LL * x * y) % mod;
}

int power(int a, int b) {
    if (b == 0) {
        return 1 % mod;
    }
    if (b % 2 == 0) {
        return power(mul(a, a), b / 2);
    }
    return mul(a, power(a, b - 1));
}

int inv(int x) {
    return power(x, mod - 2);
}

struct frac {
    int a, b;

    frac(): a(0), b(1) {
    }

    frac(int a, int b): a(a), b(b) {
    }

    int get_val() const {
        return mul(a, inv(b));
    }

    bool operator < (const frac &f) const {
        return 1LL * a * f.b < 1LL * f.a * b;
    }

    bool operator == (const frac &f) const {
        return 1LL * a * f.b == 1LL * f.a * b;
    }

    bool operator <= (const frac &f) const {
        return 1LL * a * f.b <= 1LL * f.a * b;
    }

    friend ostream& operator << (ostream &os, const frac &f) {
        os << f.a << "/" << f.b;
        return os;
    }
};

vector<pair<int, int>> upd;

struct state {
    vector<int> v[2][2];
    vector<int> diff;
};

const int inv100 = inv(100);

int n, x[max_n], v[max_n], pr[max_n], pl[max_n];
int nums[max_n][2][2];
unsigned long long buf[4 * max_n];
vector<frac> all;

frac get_frac(int pos, int tp2, int tp3) {
    frac upd(inf, 1);
    if (tp2 == 1 && tp3 == 0) {
        upd = {x[pos + 1] - x[pos], v[pos] + v[pos + 1]};
    } else if (tp2 == 0 && tp3 == 0 && v[pos] < v[pos + 1]) {
        upd = {x[pos + 1] - x[pos], v[pos + 1] - v[pos]};
    } else if (tp2 == 1 && tp3 == 1 && v[pos] > v[pos + 1]) {
        upd = {x[pos + 1] - x[pos], v[pos] - v[pos + 1]};
    }
    return upd;
}

state merge(const state &a, const state &b, int pos) {
    state res;
    res.diff.resize(a.diff.size() + b.diff.size());
    merge(a.diff.begin(), a.diff.end(), b.diff.begin(), b.diff.end(), res.diff.begin());
    for (int tp2 = 0; tp2 < 2; ++tp2) {
        for (int tp3 = 0; tp3 < 2; ++tp3) {
            const int nval = nums[pos][tp2][tp3];
            res.diff.insert(lower_bound(res.diff.begin(), res.diff.end(), nval), nval);
        }
    }
    res.diff.erase(unique(res.diff.begin(), res.diff.end()), res.diff.end());
    for (int tp1 = 0; tp1 < 2; ++tp1) {
        for (int tp4 = 0; tp4 < 2; ++tp4) {
            for (int tp2 = 0; tp2 < 2; ++tp2) {
                for (int tp3 = 0; tp3 < 2; ++tp3) {
                    if (a.v[tp1][tp2].empty() || b.v[tp3][tp4].empty()) {
                        continue;
                    }
                    const vector<int> &v1 = a.v[tp1][tp2];
                    const vector<int> &v2 = b.v[tp3][tp4];
                    const int nval = nums[pos][tp2][tp3];
                    int cur = 0;
                    int sump = accumulate(v2.begin(), v2.end(), 0LL) % mod;
                    for (int i = 0; i < a.diff.size(); ++i) {
                        const int val = min(nval, a.diff[i]);
                        while (cur < b.diff.size() && b.diff[cur] < val) {
                            sump += mod - v2[cur];
                            sump %= mod;
                            ++cur;
                        }
                        if (val == nval) {
                            long long sum = accumulate(v1.begin() + i, v1.end(), 0LL) % mod;
                            buf[val] += 1LL * sum * sump;
                            break;
                        }
                        buf[val] += 1LL * v1[i] * sump;
                    }

                    cur = 0;
                    sump = accumulate(v1.begin(), v1.end(), 0LL) % mod;
                    for (int i = 0; i < b.diff.size(); ++i) {
                        const int val = b.diff[i];
                        while (cur < a.diff.size() && min(a.diff[cur], nval) <= val) {
                            sump += mod - v1[cur];
                            sump %= mod;
                            ++cur;
                        }
                        buf[val] += 1LL * v2[i] * sump;
                    }
                }
            }
            for (int x : res.diff) {
                res.v[tp1][tp4].push_back(buf[x] % mod);
                buf[x] = 0;
            }
        }
    }
    return res;
}

state solve(int l, int r) {
    if (l == r) {
        state res;
        res.v[0][0].push_back(pl[l]);
        res.v[1][1].push_back(pr[l]);
        res.diff.push_back(all.size() - 1);
        return res;
    }
    int mid = (l + r) / 2;
    state a = solve(l, mid);
    state b = solve(mid + 1, r);
    return merge(a, b, mid);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &x[i], &v[i], &pr[i]);
    }
    for (int i = 0; i < n; ++i) {
        pr[i] = mul(pr[i], inv100);
        pl[i] = (1 + mod - pr[i]) % mod;
    }
    for (int i = 0; i + 1 < n; ++i) {
        for (int tp2 = 0; tp2 < 2; ++tp2) {
            for (int tp3 = 0; tp3 < 2; ++tp3) {
                all.push_back(get_frac(i, tp2, tp3));
            }
        }
    }
    all.push_back({inf, 1});
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    for (int i = 0; i + 1 < n; ++i) {
        for (int tp2 = 0; tp2 < 2; ++tp2) {
            for (int tp3 = 0; tp3 < 2; ++tp3) {
                nums[i][tp2][tp3] = lower_bound(all.begin(), all.end(), get_frac(i, tp2, tp3)) - all.begin();
            }
        }
    }
    state s = solve(0, n - 1);
    int ans = 0;
    for (int f1 = 0; f1 < 2; ++f1) {
        for (int f2 = 0; f2 < 2; ++f2) {
            for (int i = 0; i < s.diff.size() && i < s.v[f1][f2].size(); ++i) {
                if (all[s.diff[i]] == frac(inf, 1)) {
                    continue;
                }
                ans += mul(all[s.diff[i]].get_val(), s.v[f1][f2][i]);
                ans %= mod;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}