#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

template <typename T, typename L = __int128_t>
struct quot {
    using unit_type = T;
    using large_type = L;
    T n, d;

    quot() : n(0), d(1) {}
    quot(T num) : n(num), d(1) {}
    quot(T num, T den) : n(den >= 0 ? num : -num), d(den >= 0 ? den : -den) {}

    explicit operator bool() const noexcept { return n != 0 && d != 0; }
    explicit operator T() const noexcept { return assert(d != 0), n / d; }
    explicit operator double() const noexcept { return assert(d != 0), double(n) / d; }

    friend int infsign(quot f) { return f.d == 0 ? (f.n > 0) - (f.n < 0) : 0; }
    friend quot abs(quot f) { return quot(abs(f.n), f.d); }
    friend quot inv(quot f) { return quot(f.d, f.n); }
    friend T floor(quot f) { return f.n >= 0 ? f.n / f.d : (f.n - f.d + 1) / f.d; }
    friend T ceil(quot f) { return f.n >= 0 ? (f.n + f.d - 1) / f.d : f.n / f.d; }

    friend bool operator==(quot a, quot b) { return a.n == b.n && a.d == b.d; }
    friend bool operator!=(quot a, quot b) { return a.n != b.n || a.d != b.d; }
    friend bool operator<(quot a, quot b) { return L(a.n) * b.d < L(b.n) * a.d; }
    friend bool operator>(quot a, quot b) { return L(a.n) * b.d > L(b.n) * a.d; }
    friend bool operator<=(quot a, quot b) { return L(a.n) * b.d <= L(b.n) * a.d; }
    friend bool operator>=(quot a, quot b) { return L(a.n) * b.d >= L(b.n) * a.d; }

    friend quot operator+(quot a, quot b) {
        return quot(a.n * b.d + b.n * a.d, a.d * b.d);
    }
    friend quot operator-(quot a, quot b) {
        return quot(a.n * b.d - b.n * a.d, a.d * b.d);
    }
    friend quot operator*(quot a, quot b) { return quot(a.n * b.n, a.d * b.d); }
    friend quot operator/(quot a, quot b) { return quot(a.n * b.d, a.d * b.n); }
    friend quot operator%(quot a, quot b) { return a - T(a / b) * b; }
    friend quot& operator+=(quot& a, quot b) { return a = a + b; }
    friend quot& operator-=(quot& a, quot b) { return a = a - b; }
    friend quot& operator*=(quot& a, quot b) { return a = a * b; }
    friend quot& operator/=(quot& a, quot b) { return a = a / b; }
    friend quot& operator%=(quot& a, quot b) { return a = a % b; }

    friend quot operator-(quot f) { return quot(-f.n, f.d); }
    friend bool operator!(quot f) { return f.n == 0; }

    friend string to_string(quot f) {
        if (f.d == 0) {
            return f.n ? f.n > 0 ? "inf" : "-inf" : "undef";
        } else if (f.d == 1) {
            return to_string(f.n);
        } else {
            return to_string(f.n) + '/' + to_string(f.d);
        }
    }

    friend ostream& operator<<(ostream& out, quot f) { return out << to_string(f); }
};

using Q = quot<int64_t, int64_t>;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }

        int x;
        cin >> x;

        for (int i = 0; i < N; i++) {
            a[i] -= x;
        }

        if (N == 1) {
            cout << 1 << '\n';
            continue;
        }

        int ans = N;
        int latest = -1;

        // Longest prefixes
        vector<pair<int64_t, int>> pref;

        auto insert = [&](int64_t v, int len) {
            while (!pref.empty() && v >= pref.back().first) {
                pref.pop_back();
            }
            pref.push_back({v, len});
        };

        insert(0, 0);
        int64_t sum = a[0];

        for (int i = 1; i < N; i++) {
            sum += a[i];
            pair<int64_t, int> query = {sum, INT_MAX};
            auto it = lower_bound(rbegin(pref), rend(pref), query);
            if (it != rend(pref)) {
                int len = it->second;
                if (latest < len) {
                    latest = i;
                    ans--;
                }
            }
            insert(sum - a[i], i);
        }

        cout << ans << '\n';
    }
    return 0;
}