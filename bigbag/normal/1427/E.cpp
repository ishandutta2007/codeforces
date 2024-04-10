#include <bits/stdc++.h>

using namespace std;

struct op {
    long long a, b;
    char c;

    op(long long a, long long b, char c): a(a), b(b), c(c) {
    }

    void write() {
        if (0) {
            long long y = a + b;
            if (c == '^') {
                y = a ^ b;
            }
            cout << a << " " << c << " " << b << " = " << y << "\n";
        } else {
            cout << a << " " << c << " " << b << "\n";
        }
    }
};

bool can_add(long long x, vector<long long> &v) {
    for (long long y : v) {
        if ((x ^ y) < x) {
            x ^= y;
        }
    }
    return x;
}

vector<op> ans;

bool add(long long x, vector<long long> &v) {
    for (long long y : v) {
        if ((x ^ y) < x) {
            ans.push_back({x, y, '^'});
            x ^= y;
        }
    }
    if (!x) {
        return false;
    }
    for (long long &y : v) {
        if ((x ^ y) < y) {
            ans.push_back({x, y, '^'});
            y ^= x;
        }
    }
    v.push_back(x);
    return true;
}

void create(int a, int x) {
    if (a == 1) {
        return;
    }
    int h = a / 2;
    create(h, x);
    ans.push_back({1LL * h * x, 1LL * h * x, '+'});
    if (a % 2) {
        ans.push_back({2LL * h * x, x, '+'});
    }
}

void solve(int x) {
    ans.clear();
    int t = 2;
    if (x == 3) {
        t = 3;
    }
    vector<long long> basis{x};
    for (int a = 2; a <= t * x; ++a) {
        if (can_add(1LL * a * x, basis)) {
            //cout << "$" << a << endl;
            create(a, x);
            add(1LL * a * x, basis);
        }
    }
    assert(*min_element(basis.begin(), basis.end()) == 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    /*for (int x = 5; x < 1111; x += 2) {
        int mn = inf;
        vector<int> basis;
        int mx = 10;
        for (int a = 1; a <= 2 * x; ++a) {
            add(a * x, basis);
        }
        for (int y : basis) {
            mn = min(mn, y);
        }
        assert(mn == 1);
    }*/
    int x;
    scanf("%d", &x);
    solve(x);
    cout << ans.size() << "\n";
    for (auto a : ans) {
        a.write();
    }
    return 0;
}