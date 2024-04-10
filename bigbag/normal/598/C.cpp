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

const int max_l = 11, mod = 10000, Len_digit = 4;

int Len(int x) {
    if (x == 0) {
        return 1;
    }
    int res = 0;
    while (x != 0) {
        ++res;
        x /= 10;
    }
    return res;
}

struct very_long {
    int len;
    int digit[max_l];
    very_long() {
        len = 0;
        memset(digit, 0, sizeof(digit));
    }
    very_long(const string &s) {
        len = 0;
        for (int i = s.length() - 1; i >= 0; i -= Len_digit) {
            int x = 0;
            for (int j = max(0, i - Len_digit + 1); j <= i; ++j) {
                x = x * 10 + s[j] - '0';
            }
            digit[len] = x;
            ++len;
        }
    }
    very_long(long long a) {
        len = 0;
        if (a == 0) {
            len = 1;
            digit[0] = 0;
        }
        while (a != 0) {
            digit[len] = a % mod;
            len++;
            a /= mod;
        }
    }
    void operator = (const very_long &a) {
        len = a.len;
        for (int i = 0; i < a.len; i++)
            digit[i] = a.digit[i];
    }
    void operator = (const long long &a) {
        *this = very_long(a);
    }
    bool operator == (const very_long &a) const {
        if (len != a.len) return false;
        for (int i = 0; i < len; i++) {
            if (digit[i] != a.digit[i]) return false;
        }
        return true;
    }
    bool operator != (const very_long &a) const {
        return !(*this == a);
    }
    bool operator < (const very_long &a) const {
        if (len < a.len) return true;
        if (len > a.len) return false;
        for (int i = len - 1; i >= 0; i--) {
            if (digit[i] < a.digit[i]) return true;
            if (digit[i] > a.digit[i]) return false;
        }
        return false;
    }
    bool operator <= (const very_long &a) const {
        return *this == a || *this < a;
    }
    bool operator > (const very_long &a) const {
        return !(*this <= a);
    }
    bool operator >= (const very_long &a) const {
        return !(*this < a);
    }
    bool operator == (long long a) const {
        return *this == very_long(a);
    }
    bool operator < (long long a) const {
        return *this < very_long(a);
    }
    bool operator <= (long long a) const {
        return *this <= very_long(a);
    }
    bool operator > (long long a) const {
        return *this > very_long(a);
    }
    bool operator >= (long long a) {
        return *this >= very_long(a);
    }
    very_long operator + (const very_long &a) const {
        int p = 0, l = max(len, a.len);
        very_long res;
        for (int i = 0; i < l; i++) {
            int x = digit[i] + a.digit[i] + p;
            if (len <= i) x -= digit[i];
            if (a.len <= i) x -= a.digit[i];
            res.digit[i] = x % mod;
            p = x / mod;
        }
        res.len = l;
        if (p != 0) {
            res.len++;
            res.digit[l] = p;
        }
        return res;
    }
    very_long operator - (const very_long &q) const {
        very_long a = *this, b = q, res;
        if (a < b) swap(a, b);
        int p = 0;
        for (int i = 0; i < a.len; i++) {
            int x = a.digit[i] - b.digit[i] - p;
            if (b.len <= i) x += b.digit[i];
            p = 0;
            if (x < 0) {
                p = 1;//??????????????
                x += mod;
            }
            res.digit[i] = x;
        }
        res.len = a.len;
        while (res.digit[res.len - 1] == 0 && res.len > 1)
            res.len--;
        return res;
    }
    very_long operator * (const very_long &a) const {
        very_long b, res = 0;
        if (a == 0) {
            return res;
        }
        for (int i = 0; i < len; i++) {
            if (i != 0) {
                b.digit[i - 1] = 0;
            }
            if (digit[i] != 0) {
                int p = 0;
                for (int j = 0; j < a.len; j++) {
                    int x = digit[i] * a.digit[j] + p;
                    b.digit[i + j] = x % mod;
                    p = x / mod;
                }
                b.len = i + a.len;
                if (p != 0) {
                    b.len++;
                    b.digit[i + a.len] = p;
                }
                res = res + b;
            }
        }
        return res;
    }
    very_long operator / (const very_long &a) const {
        very_long res = 0, c = 0;
        for (int ii = len - 1; ii >= -1; --ii) {
            int l = 0, r = 10;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (a * mid <= c) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            res.digit[res.len] = l;
            ++res.len;
            if (ii >= 0) {
                c = c - a * l;
                c = c * 10 + digit[ii];
            }
        }
        reverse(res.digit, res.digit + res.len);
        while (res.len > 1 && res.digit[res.len - 1] == 0) {
            --res.len;
        }
        return res;
    }
    very_long operator + (const long long a) const {
        return *this + very_long(a);
    }
    very_long operator - (const long long a) const {
        return *this - very_long(a);
    }
    very_long operator * (const long long a) const {
        //return very_long(a) * *this;  ?????error
        return *this * very_long(a);//++++
    }
    very_long operator / (int a) const {
        very_long b;
        long long x = 0;
        b.len = len;
        for (int i = len - 1; i >= 0; i--) {
            x = x * mod + digit[i];
            b.digit[i] = x / a;
            x %= a;
        }
        while (b.len > 1 && b.digit[b.len - 1] == 0) {
            b.len--;
        }
        return b;
    }
    long long operator % (long long a) const {
        long long res = 0;
        for (int i = len - 1; i >= 0; i--) {
            res = (res * mod + digit[i]) % a;
        }
        return res;
    }
    void write(string s = "") const {
        for (int i = len - 1; i >= 0; --i) {
            if (i != len - 1) {
                for (int j = 0; j < Len_digit - Len(digit[i]); ++j) {
                    printf("0");
                }
            }
            printf("%d", digit[i]);
        }
        cout << s;
    }
};

const int max_n = 111111, inf = 1111111111;

int n;
pair<int, pair<int, int> > p[max_n];

int get_num(pair<int, pair<int, int> > p) {
    if (p.first >= 0) {
        if (p.second.first >= 0) {
            return 1;
        }
        return 4;
    }
    if (p.second.first >= 0) {
        return 2;
    }
    return 3;
}

bool cmp(pair<int, pair<int, int> > p1, pair<int, pair<int, int> > p2) {
    int n1 = get_num(p1);
    int n2 = get_num(p2);
    if (n1 != n2) {
        return n1 < n2;
    }
    return p1.second.first * p2.first < p2.second.first * p1.first;
}

bool cmp2(pair<long long, pair<long long, pair<long long, int> > > p1, pair<long long, pair<long long, pair<long long, int> > > p2) {
    int z1 = 0;
    if (p1.first < 0) {
        z1 = 1;
        p1.first *= -1;
    }
    int z2 = 0;
    if (p2.first < 0) {
        z2 = 1;
        p2.first *= -1;
    }
    very_long a1 = p1.first;
    very_long b1 = p1.second.first;
    very_long c1 = p1.second.second.first;
    very_long a2 = p2.first;
    very_long b2 = p2.second.first;
    very_long c2 = p2.second.second.first;
    //a1.write(" = a1\n");
    //a2.write(" = a2\n");
    if (z1 == 1) {
        if (z2 == 0) return true;
        return a1 * a1 * b2 * c2 > a2 * a2 * b1 * c1;
    }
    if (z2 == 1) {
        return false;
    }
    //(a1 * a1 * b2 * c2).write("\n");
    //(a2 * a2 * b1 * c1).write("\n");
    return a1 * a1 * b2 * c2 < a2 * a2 * b1 * c1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &p[i].first, &p[i].second.first);
        p[i].second.second = i + 1;
    }
    sort(p, p + n, cmp);
    int num1 = 1, num2 = 2, ii;
    pair<long long, pair<long long, pair<long long, int> > > last;
    for (int i = 0; i < n; ++i) {
        long long x = p[i].first, y = p[i].second.first;
        long long xx = p[(i + 1) % n].first, yy = p[(i + 1) % n].second.first;
        pair<long long, pair<long long, pair<long long, int> > > p;
        p = make_pair((x * xx + y * yy), make_pair(x * x + y * y, make_pair(xx * xx + yy * yy, i)));
        //cout << p.first << " " << p.second.first << " " << p.second.second.first << endl;
        if (i == 0) {
            ii = 0;
            last = p;
        } else if (cmp2(last, p)){
            ii = i;
            last = p;
        }
    }
    num1 = p[ii].second.second;
    num2 = p[(ii + 1) % n].second.second;
    cout << num1 << " " << num2 << endl;
    return 0;
}