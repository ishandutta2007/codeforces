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

const int max_n = 22;
const long long inf = 2400000000LL;

int k, t, a[max_n], b[max_n];
int c[max_n][max_n];
vector<long long> v;

void get_all_c() {
    c[0][0] = 1;
    for (int i = 1; i < max_n; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
}

void gen(int pos, int n, int cnt, int x, long long q) {
    //cout << pos << " " << n << " " << cnt << " " << x << endl;
    if (n - pos + cnt <= t) {
        return;
    }
    if (pos == n) {
        v.push_back(q);
        return;
    }
    int st = 0;
    if (pos == 0) {
        st = 1;
    }
    for (int i = st; i < 16; ++i) {
        a[pos] = i;
        gen(pos + 1, n, cnt + (i == x), x, q * 16 + i);
    }
}

int get_cnt(long long x) {
    return upper_bound(v.begin(), v.end(), x) - v.begin();
}

void write(long long x) {
    vector<int> ans;
    while (x) {
        ans.push_back(x % 16);
        x /= 16;
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        if (ans[i] < 10) {
            printf("%d", ans[i]);
        } else {
            printf("%c", ans[i] + 'a' - 10);
        }
    }
    exit(0);
}

int func(int pos, int len) {
    int res = 1;
    int n = len;
    for (int j = 0; j < pos; ++j) {
        res *= c[n][b[j]];
        n -= b[j];
    }
    return res;
}

int rec(int pos, int sum, int len, int f) {
    if (sum == len) {
        int res = func(pos, len);
        if (b[0] && f) {
            --b[0];
            res -= func(pos, len - 1);
            ++b[0];
        }
        if (0) {
            for (int i = 0; i < 16; ++i) {
                for (int j = 0; j < b[i]; ++j) {
                    if (i < 10) cout << i;
                    else cout << (char) (i - 10 + 'a');
                }
            }
            cout << " res = " << res << "           " << sum << " " << len << endl;
        }
        return res;
    }
    if (pos == 16) {
        return 0;
    }
    int res = 0;
    for (int i = 0; i + sum <= len && i <= a[pos]; ++i) {
        b[pos] = i;
        res += rec(pos + 1, sum + i, len, f);
        b[pos] = 0;
    }
    return res;
}

int cnt(int len, int f) {
    for (int i = 0; i < 16; ++i) {
        if (a[i] < 0) {
            return false;
        }
    }
    return rec(0, 0, len, f);
}

int get(long long x) {
    for (int i = 0; i < 16; ++i) {
        a[i] = t;
    }
    int res = 0;
    vector<int> v;
    while (x) {
        v.push_back(x % 16);
        x /= 16;
    }
    reverse(v.begin(), v.end());
    for (int len = 1; len < v.size(); ++len) {
        res += cnt(len, 1);
    }
    //cout << res << endl;
    for (int i = 0; i < v.size(); ++i) {
        int st = 0;
        if (i == 0) {
            st = 1;
        }
        for (int j = st; j < v[i]; ++j) {
            --a[j];
            res += cnt(v.size() - i - 1, 0);
            //cout << i << " " << j << " " << res << endl;
            ++a[j];
        }
        --a[v[i]];
    }
    int f = 1;
    for (int i = 0; i < 16; ++i) {
        if (a[i] < 0) {
            f = 0;
            break;
        }
    }
    return res + f;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_c();
    cin >> k >> t;
    if (t >= 4) {
        for (int len = t; len <= 8; ++len) {
            for (int j = 0; j < 16; ++j) {
                gen(0, len, 0, j, 0);
            }
        }
        sort(v.begin(), v.end());
        long long l = 0, r = inf;
        while (r - l > 1) {
            long long mid = (l + r) / 2;
            if (mid - get_cnt(mid) >= k) {
                r = mid;
            } else {
                l = mid;
            }
        }
        write(r);
    }
    for (int i = 0; i < 16; ++i) {
        a[i] = 3;
    }
    //cout << "1) " << get(32) << endl;
    //cout << "2) " << get(31) << endl;
    //return 0;
    long long l = 0, r = inf;
    if (t == 1) {
        r = 29000000000LL;
    }
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        //cout << mid << endl;
        if (get(mid) >= k) {
            r = mid;
        } else {
            l = mid;
        }
    }
    //cout << r << endl;
    write(r);
    return 0;
}