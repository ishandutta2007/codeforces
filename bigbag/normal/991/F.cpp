#include <bits/stdc++.h>

using namespace std;

const int max_n = 10, inf = 1000111222;

string to_str(long long n) {
    string res = "";
    while (n) {
        res += n % 10 + '0';
        n /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

struct power {
    int a, b;
    long long pw;
    string s;
    power(int a, int b, long long pw): a(a), b(b), pw(pw) {
        s = to_str(a) + "^" + to_str(b);
    }
    bool operator < (const power &p) const {
        return s.length() < p.s.length();
    }
};

long long n, pw[max_n][max_n];
string ans;
vector<power> v;

void update(const string &res) {
    if (res.length() < ans.length()) {
        ans = res;
    }
}

void prec() {
    for (int i = 2; i < max_n; ++i) {
        pw[i][0] = 1;
        for (int j = 1; j < max_n; ++j) {
            pw[i][j] = pw[i][j - 1] * i;
        }
    }
    for (int i = 2; i <= 100000; ++i) {
        long long pw = i;
        for (int j = 2; i * pw <= 10000000000LL; ++j) {
            pw *= i;
            v.push_back(power(i, j, pw));
        }
    }
    sort(v.begin(), v.end());
}

void try_first() {
    for (int a = 2; a < max_n; ++a) {
        for (int b = 2; b < max_n; ++b) {
            for (int a2 = 2; a2 < max_n; ++a2) {
                for (int b2 = 2; b2 < max_n; ++b2) {
                    long long x = pw[a][b], y = pw[a2][b2];
                    if (n % (x * y) == 0) {
                        long long k = n / (x * y);
                        string res;
                        if (k > 1) {
                            res += to_str(k) + "*";
                        }
                        res += to_str(a) + "^" + to_str(b) + "*" + to_str(a2) + "^" + to_str(b2);
                        update(res);
                    }
                    if (n >= x + y && (n - y) % x == 0) {
                        long long k = (n - y) / x;
                        string res;
                        if (k > 1) {
                            res += to_str(k) + "*";
                        }
                        res += to_str(a) + "^" + to_str(b) + "+" + to_str(a2) + "^" + to_str(b2);
                        update(res);
                    }
                    if (n >= x * y) {
                        update(to_str(a) + "^" + to_str(b) + "*" + to_str(a2) + "^" + to_str(b2) + "+" + to_str(n - x * y));
                    }
                }
            }
        }
    }
}

void try_second() {
    for (int i = 0; i < v.size(); ++i) {
        for (int j = i; j < v.size() && v[i].s.length() + v[j].s.length() + 1 < 10; ++j) {
            if (v[i].pw + v[j].pw == n) {
                update(v[i].s + "+" + v[j].s);
            }
        }
    }
}

void try_third() {
    for (int x = 1; x < 1000; ++x) {
        string s = to_str(x);
        for (int i = 0; i < v.size() && s.length() + 3 + v[i].s.length() < 10; ++i) {
            if ((n - x) % v[i].pw == 0) {
                string res = to_str((n - x) / v[i].pw) + "*" + v[i].s + "+" + s;
                update(res);
            }
        }
    }
}

void try_third2() {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].pw <= n) {
            string s = v[i].s;
            if (n - v[i].pw > 0) {
                s += "+" + to_str(n - v[i].pw);
            }
            update(s);
        }
    }
}

void try_fourth() {
    for (int i = 0; i < v.size(); ++i) {
        if (n % v[i].pw == 0) {
            string s = to_str(n / v[i].pw) + "*" + v[i].s;
            update(s);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    prec();
    cin >> n;
    ans = to_str(n);
    try_first();
    try_second();
    try_third();
    try_third2();
    try_fourth();
    cout << ans << endl;
    return 0;
}