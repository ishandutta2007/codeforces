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

const int max_p = 33333, inf = 111111111;

long long gcd(long long a, long long b) {
    a = abs(a);
    b = abs(b);
    while (a != 0 && b != 0) {
        long long k = a;
        a = b;
        b = k % b;
    }
    return a + b;
}

long long nok(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

struct drob {
    long long a, b;
    void read() {
        cin >> a >> b;
    }
    void write() {
        cout << a << '/' << b << endl;
    }
    drob() {
        a = b = 0;
    }
    drob(long long x, long long y) {
        a = x;
        b = y;
    }
    drob operator + (drob x) {
        drob ret;
        ret.b = nok(b, x.b);
        ret.a = ret.b / b * a + ret.b / x.b * x.a;
        return ret;
    }
    drob operator - (drob x) {
        drob ret;
        ret.b = nok(b, x.b);
        ret.a = ret.b / b * a - ret.b / x.b * x.a;
        return ret;
    }
    drob operator * (drob x) {
        long long g = gcd(a * x.a, b * x.b);
        return drob((a * x.a) / g, (b * x.b) / g);
    }
    drob operator * (int x) {
        long long g = gcd(a * x, b);
        return drob((a * x) / g, b / g);
    }
    drob operator / (drob x) {
        long long g = gcd(a * x.b, b * x.a);
        return drob((a * x.b) / g, (b * x.a) / g);
    }
};

int t, used[max_p];
vector<int> p;

bool is_prime(int x) {
    for (int i = 0; p[i] * p[i] <= x; ++i) {
        if (x % p[i] == 0) {
            return false;
        }
    }
    return true;
}

drob get_ans(int n) {
    if (is_prime(n + 1)) {
        return drob(1, 2) - drob(1, n + 1);
    }
    long long first, last;
    for (int i = n; i > 0; --i) {
        if (is_prime(i)) {
            first = i;
            break;
        }
    }
    for (int i = n + 1; ; ++i) {
        if (is_prime(i)) {
            last = i;
            break;
        }
    }
    drob d = drob(1, first * last);
    drob ret = drob(1, 2) - drob(1, first) + d * (n - first + 1);
    return ret;
}

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

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_prime();
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int n;
        scanf("%d", &n);
        get_ans(n).write();
    }
    return 0;
}