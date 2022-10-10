#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define log(msg) clog << __LINE__ << ": " << msg
#else
#define log(msg)
#endif

#define _ << ' ' <<
#define long long long
#define ve vector
#define vi ve<int>
#define sz(v) ((int) v.size())
#define ii pair<int, int>
#define xx first
#define yy second
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()

typedef vi bn;
bn& operator+=(bn& a, bn& b) {
    a.resize(max(a.size(), b.size()) + 1, 0);
    for (int i = 0; i < sz(b); ++i) {
        a[i] += b[i];
    }
    for (int i = 1; i < sz(a); ++i) {
        a[i] += a[i - 1] / 10;
        a[i - 1] %= 10;
    }
    while (a.size() > 0 and a.back() == 0) a.pop_back();
    return a;
}

bn& operator -=(bn& a, bn& b) {
    for (int i = 0; i < sz(b); ++i) a[i] -= b[i];
    for (int i = 1; i < sz(a); ++i) {
        if (a[i - 1] < 0) {
            --a[i];
            a[i - 1] += 10;
        }
    }
    while (a.size() > 0 and a.back() == 0) a.pop_back();
    return a;
}

bn& operator*=(bn& a, int b) {
    a.push_back(0);
    int c = 0;
    for (int i = 0; i < sz(a); ++i) {
        a[i] = a[i] * b + c;
        c = a[i] / 10;
        a[i] %= 10;
    }
    while (a.size() > 0 and a.back() == 0) a.pop_back();
    return a;
}

bn operator* (bn a, bn& b) {
    bn ans(0);
    for (int i = 0; i < sz(b); ++i) {
        bn t(a.bb, a.ee);
        t *= b[i];
        ans += t;
        a *= 10;
    }
    return ans;
}

istream& operator >> (istream& cin, bn& a) {
    string num; cin >> num;
    a.resize(num.size());
    copy(num.rbb, num.ree, a.bb);
    for (auto& t : a) t -= '0';
    return cin;
}

ostream& operator << (ostream& cout, bn& a) {
    for (int i = sz(a) - 1; i >= 0; --i) cout << a[i];
    return cout;
}

bool operator != (bn& a, bn& b) {
    if (a.size() != b.size()) return true;
    for (int i = 0; i < sz(a); ++i) {
        if (a[i] != b[i]) return true;
    }
    return false;
}

bn one(1, 1);
bn two(1, 2);
bn lv, clv, nlv, cur;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    cin >> lv;
    cur.resize(1, 2);
    cout << 2 << endl;
    lv += one;
    nlv = clv = two;

    while (clv != lv) {
        nlv += one;
        bn ans = clv * nlv * nlv;
        ans -= nlv;
        ans += two;
        cout << ans << '\n';
        clv = nlv;
    }

    return 0;
}