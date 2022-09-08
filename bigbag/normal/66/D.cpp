#include <set>
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

const int max_l = 221;

struct very_long {
    int len;
    int digit[max_l];
    very_long() {
        len = 0;
        memset(digit, 0, sizeof(digit));
    }
    very_long(long long a) {
        memset(digit, 0, sizeof(digit));
        len = 0;
        if (a == 0) {
            len = 1;
            digit[0] = 0;
        }
        while (a != 0) {
            digit[len] = a % 10;
            len++;
            a /= 10;
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
            res.digit[i] = x % 10;
            p = x / 10;
        }
        res.len = l;
        if (p != 0) {
            res.len++;
            res.digit[l] = p;
        }
        return res;
    }
    very_long operator * (const very_long &a) const {
        very_long b, res = 0;
        if (a == 0) {
            return res;
        }
        for (int i = 0; i < len; i++) {
            if (digit[i] != 0) {
                int p = 0;
                for (int j = 0; j < i; j++) {
                    b.digit[j] = 0;
                }
                for (int j = 0; j < a.len; j++) {
                    int x = digit[i] * a.digit[j] + p;
                    b.digit[i + j] = x % 10;
                    p = x / 10;
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
    very_long operator + (const long long a) const {
        return *this + very_long(a);
    }
    very_long operator * (const long long a) const {
        return very_long(a) * *this;
    }
    void write() const {
        for (int i = len - 1; i >= 0; --i) {
            printf("%d", digit[i]);
        }
    }
};

const int max_p = 10000;

int used[max_p];
vector<int> p;

void get_all_prime() {
    for (int i = 2; i < max_p; ++i) {
        if (used[i] == 0) {
            p.push_back(i);
            for (int j = 2; i * j < max_p; ++j) {
                used[i * j] = 1;
            }
        }
    }
}

int n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    if (n == 2) {
        cout << -1 << endl;
        return 0;
    }
    get_all_prime();
    very_long a = 2;
    for (int j = 2; j <= n; ++j) {
        a = a * p[j];
    }
    a.write();
    cout << endl;
    for (int i = 2; i < n; ++i) {
        a = 1;
        for (int j = 2; j < n; ++j) {
            a = a * p[j - 1];
        }
        a = a * p[n];
        a = a * p[n + i];
        a.write();
        cout << endl;
    }
    a = 2;
    for (int i = 1; i < n; ++i) {
        a = a * p[1];
    }
    a.write();
    cout << endl;
    return 0;
}