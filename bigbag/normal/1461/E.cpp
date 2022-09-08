/**
 *  created: 11/12/2020, 17:09:55
**/

#include <bits/stdc++.h>

using namespace std;

typedef __int128 ll;

ostream& operator << (ostream &os, __int128 x) {
    if (x < 0) {
        os << '-';
        x = -x;
    }
    if (x == 0) {
        os << '0';
    }
    string s;
    while (x) {
        s += '0' + x % 10;
        x /= 10;
    }
    reverse(s.begin(), s.end());
    os << s;
    return os;
}

bool triv(ll k, ll r, ll x, ll y, ll t) {
    while (t--) {
        if (k + y <= r) {
            k += y;
        }
        k -= x;
        if (k < 0) {
            return false;
        }
    }
    return true;
}

const ll inf = 1000111222000111222LL;

const int max_x = 1000111;

bool used[max_x];

bool solve(ll k, ll r, ll x, ll y, ll t) {
    for (int i = 0; i < x; ++i) {
        used[i] = 0;
    }
    while (true) {
        ll days = min({k / x, t,
                      max(ll(0), (k - r + y - 1)) / x});
        /*for (int i = 60; i >= 0; --i) {
            ll days = 1LL << i;
            if (days <= t && k - x * days >= 0 && k - r + y - 1 - x * days >= 0) {
                t -= days;
                k -= x * days;
            }
        }*/
        t -= days;
        k -= x * days;
        if (!t) {
            return true;
        }
        if (k + y > r) {
            k -= x;
            --t;
            if (k < 0) {
                return false;
            }
            if (!t) {
                return true;
            }
        }
        if (k > r - y) {
            return false;
        }
        if (y < x) {
            ll d = x - y;
            return d * t <= k;
        }
        if (used[k % x]) {
            return true;
        }
        used[k % x] = 1;
        k += y;
        k -= x;
        --t;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    /*{
        int mx = 22;
        for (int k = 0; k < mx; ++k) {
            for (int r = k; r < mx; ++r) {
                for (int x = 1; x < mx; ++x) {
                    for (int y = 1; y < mx; ++y) {
                        for (int t = 1; t < mx; ++t) {
                            if (solve(k, r, x, y, t) != triv(k, r, x, y, t)) {
                                cout << "-";
                            }
                        }
                    }
                }
            }
        }
    }*/
    long long k, l, r, t, x, y;
    while (cin >> k >> l >> r >> t >> x >> y) {
        k -= l;
        r -= l;
        l = 0;
        if (solve(k, r, x, y, t)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}