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

const int max_n = 200222, max_x = 1001111, sz = 555, inf = 1000000007;

int n, a[max_n], q, f[max_x], rv[max_x], res[max_n], lastt[max_x], qq[max_n];
vector<int> v[max_n];
pair<int, pair<int, int> > p[max_n];

int power(int a, int b) {
    if (b == 0) {
        return 1;
    }
    if (b % 2 == 0) {
        return power((1LL * a * a) % inf, b / 2);
    }
    return (1LL * a * power(a, b - 1)) % inf;
}

bool cmp(pair<int, pair<int, int> > p1, pair<int, pair<int, int> > p2) {
    return p1.first / sz < p2.first / sz || p1.first / sz == p2.first / sz && p1.second.first < p2.second.first;
}

const int max_p = 1555;

int used[max_p];
vector<long long> pw;

void get_all_primes() {
    for (int i = 2; i < max_p; ++i) {
        if (used[i] == 0) {
            pw.push_back(i);
            if ((long long) i * i < (long long) max_p) {
                for (int j = i * i; j < max_p; j += i) {
                    used[j] = 1;
                }
            }
        }
    }
}

int get_p(int l, int r) {
    if (l == 0) {
        return qq[r];
    }
    return (1LL * qq[r] * power(qq[l - 1], inf - 2)) % inf;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(rv, -1, sizeof(rv));
    get_all_primes();
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        qq[i] = a[i];
        if (i) {
            qq[i] = (1LL * qq[i - 1] * a[i]) % inf;
        }
        int x = a[i];
        for (int j = 0; j < pw.size() && pw[j] * pw[j] <= x; ++j) {
            if (x % pw[j] == 0) {
                while (x % pw[j] == 0) {
                    x /= pw[j];
                }
                v[i].push_back(pw[j]);
                if (rv[pw[j]] == -1) {
                    rv[pw[j]] = power(pw[j], inf - 2);
                }
                if (rv[pw[j] - 1] == -1) {
                    rv[pw[j] - 1] = power(pw[j] - 1, inf - 2);
                }
            }
        }
        if (x > 1) {
            v[i].push_back(x);
            if (rv[x] == -1) {
                rv[x] = power(x, inf - 2);
            }
            if (rv[x - 1] == -1) {
                rv[x - 1] = power(x - 1, inf - 2);
            }
        }
    }
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        --l;
        --r;
        p[i] = make_pair(l, make_pair(r, i));
        res[i] = get_p(l, r);
    }
    sort(p, p + q, cmp);
    int last = -1, ans;
    for (int i = 0; i < q; ++i) {
        if (last == p[i].first / sz) {
            for (int j = max(p[i].first, p[i - 1].second.first + 1); j <= p[i].second.first; ++j) {
                for (int k = 0; k < v[j].size(); ++k) {
                    int x = v[j][k];
                    if (lastt[x] < last) {
                        f[x] = 0;
                    }
                    lastt[x] = last;
                    if (f[x] == 0) {
                        ans = (1LL * ans * (x - 1)) % inf;
                        ans = (1LL * ans * rv[x]) % inf;
                    }
                    ++f[x];
                }
            }
            if (p[i - 1].first < p[i].first) {
                for (int j = p[i - 1].first; j < min(p[i - 1].second.first + 1, p[i].first); ++j) {
                    for (int k = 0; k < v[j].size(); ++k) {
                        int x = v[j][k];
                        --f[x];
                        if (f[x] == 0) {
                            ans = (1LL * ans * rv[x - 1]) % inf;
                            ans = (1LL * ans * x) % inf;
                        }
                    }
                }
            }
            if (p[i - 1].first > p[i].first) {
                for (int j = p[i].first; j < p[i - 1].first; ++j) {
                    for (int k = 0; k < v[j].size(); ++k) {
                        int x = v[j][k];
                        if (lastt[x] < last) {
                            f[x] = 0;
                        }
                        lastt[x] = last;
                        if (f[x] == 0) {
                            ans = (1LL * ans * (x - 1)) % inf;
                            ans = (1LL * ans * rv[x]) % inf;
                        }
                        ++f[x];
                    }
                }
            }
        } else {
            last = p[i].first / sz;
            ans = 1;
            for (int j = p[i].first; j <= p[i].second.first; ++j) {
                for (int k = 0; k < v[j].size(); ++k) {
                    int x = v[j][k];
                    if (lastt[x] < last) {
                        f[x] = 0;
                    }
                    lastt[x] = last;
                    if (f[x] == 0) {
                        ans = (1LL * ans * (x - 1)) % inf;
                        ans = (1LL * ans * rv[x]) % inf;
                    }
                    ++f[x];
                }
            }
        }
        res[p[i].second.second] = (1LL * res[p[i].second.second] * ans) % inf;
    }
    for (int i = 0; i < q; ++i) {
        printf("%d\n", res[i]);
    }
    return 0;
}