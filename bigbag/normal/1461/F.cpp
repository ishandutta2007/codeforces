/**
 *  created: 11/12/2020, 17:53:06
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int n, a[max_n];
string s;
bool has_plus, has_minus, has_mul;

void write(const string &ans) {
    printf("%d", a[0]);
    for (int i = 1; i < n; ++i) {
        printf("%c%d", ans[i - 1], a[i]);
    }
    puts("");
    exit(0);
}

bool get_bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

string solve(int l, int r) {
    if (r - l + 1 <= 1) {
        return "";
    }
    const int len = r - l + 1;
    int x = 1;
    for (int i = l; i <= r; ++i) {
        x *= a[i];
        if (x > 4 * len) {
            break;
        }
    }
    if (x > 4 * len) {
        int c1 = 0, c2 = 0;
        for (int i = l; a[i] == 1; ++i) {
            ++c1;
        }
        for (int i = r; a[i] == 1; --i) {
            ++c2;
        }
        string res;
        for (int i = 0; i < c1; ++i) {
            res += '+';
        }
        for (int i = 1; i < len - c1 - c2; ++i) {
            res += '*';
        }
        for (int i = 0; i < c2; ++i) {
            res += '+';
        }
        return res;
    }
    vector<int> v;
    if (a[l] != 1) {
        v.push_back(0);
    }
    for (int i = l; i <= r; ) {
        if (a[i] == 1) {
            int start = i;
            while (i <= r && a[i] == 1) {
                ++i;
            }
            v.push_back(i - start);
        } else {
            int start = i, x = 1;
            while (i <= r && a[i] != 1) {
                x *= a[i];
                ++i;
            }
            v.push_back(x);
        }
    }
    if (0) {
        for (int x : v) {
            cout << x << endl;
        }
    }
    int ones = (v.size() + 1) / 2;
    pair<int, int> best(-1, 0);
    for (int mask = 0; mask < (1 << ones); ++mask) {
        int res = 0, last = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (i % 2 == 0) { // ones
                if (get_bit(mask, i / 2)) {
                    res += last + v[i];
                    last = 0;
                } else {
                }
            } else {
                if (!last) {
                    last = 1;
                }
                last *= v[i];
            }
        }
        res += last;
        best = max(best, {res, mask});
    }
    //cout << "#"  << best.first << " " << best.second << endl;
    int mask = best.second;
    ones = 0;
    if (v[0] == 0) {
        ones = 1;
    }
    string s;
    bool first = true;
    char lastc;
    for (int i = l; i <= r; ) {
        if (a[i] == 1) {
            int tp = get_bit(mask, ones);
            char c = "*+"[tp];
            ++ones;
            if (!first) {
                s += c;
            }
            int start = i;
            while (i <= r && a[i] == 1) {
                ++i;
            }
            int len = i - start;
            for (int j = 1; j < len; ++j) {
                s += c;
            }
            lastc = c;
        } else {
            if (!first) {
                s += lastc;
            }
            int start = i;
            while (i <= r && a[i] != 1) {
                ++i;
            }
            int len = i - start;
            for (int j = 1; j < len; ++j) {
                s += '*';
            }
        }
        first = false;
    }
    return s;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    cin >> s;
    if (s.length() == 1) { // "+", "-", "*"
        write(string(n - 1, s[0]));
    }
    has_plus = s.find('+') != -1;
    has_minus = s.find('-') != -1;
    has_mul = s.find('*') != -1;
    if (has_plus && has_minus && !has_mul) { // "+-"
        write(string(n - 1, '+'));
    }
    if (has_minus && has_mul && !has_plus) { // "-*"
        int zero = find(a, a + n, 0) - a;
        string ans;
        for (int i = 0; i + 1 < zero; ++i) {
            ans += '*';
        }
        if (zero != n && zero != 0) {
            ans += '-';
        }
        while (ans.length() + 1 < n) {
            ans += '*';
        }
        write(ans);
    }
    string ans;
    vector<int> zeros{-1};
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            zeros.push_back(i);
        }
    }
    zeros.push_back(n);
    for (int i = 1; i < zeros.size(); ++i) {
        ans += solve(zeros[i - 1] + 1, zeros[i] - 1);
        if (zeros[i] - zeros[i - 1] > 1) {
            ans += '+';
        }
        if (i + 1 != zeros.size()) {
            ans += '+';
        }
    }
    write(ans);
    return 0;
}