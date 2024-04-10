#include <bits/stdc++.h>
 
using i64 = long long;
 
constexpr int P = 998244353;
using i64 = long long;
// assume -P <= x < 2P
int norm(int x) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}
template<class T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    Z(i64 x) : x(norm(x % P)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(P - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = i64(x) * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Z &a) {
        i64 v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Z &a) {
        return os << a.val();
    }
};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<i64> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        a[i] += a[i - 1];
    }
    
    int c = 0;
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && a[j] - a[i] < a[n] / 2) {
            j++;
        }
        if (j < n && (a[j] - a[i]) * 2 == a[n]) {
            c++;
        }
    }
    
    const int N = std::max(n, m);
    
    std::vector<Z> fac(N + 1), invfac(N + 1);
    fac[0] = 1;
    for (int i = 1; i <= N; i++) {
        fac[i] = fac[i - 1] * i;
    }
    invfac[N] = fac[N].inv();
    for (int i = N; i; i--) {
        invfac[i - 1] = invfac[i] * i;
    }
    
    Z ans = 0;
    for (int k = 0; k <= c && k <= m; k++) {
        ans += fac[c] * invfac[k] * invfac[c - k] * fac[m] * invfac[m - k] * power(Z(m - k) * (m - k - 1), c - k) * power(Z(m - k), n - 2 * c);
    }
    std::cout << ans << "\n";
    
    return 0;
}