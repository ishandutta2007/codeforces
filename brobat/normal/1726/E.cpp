#include <bits/stdc++.h>
using namespace std;

const int N = 300100;
const int MOD = 998244353;
class Mint {
public:
    long long x;
    Mint(long long v = 0) {
        if(v < 0) v = v % MOD + MOD;
        if(v >= MOD) v = v % MOD;
        x = v;
    }

    Mint(int v) : Mint((long long)v) {}

    Mint pow(long long b) const {
        if(b < 0) return inv().pow(-b);
        Mint a = *this;
        Mint res = 1;
        while(b > 0) {
            if(b & 1) res *= a;
            a *= a;
            b >>= 1ll;
        }
        return res;
    }

    Mint inv() const { return pow(MOD - 2); }

    explicit operator int() const { return x; }
    explicit operator long long() const { return x; }
    explicit operator bool() const { return x; }

    Mint& operator+= (const Mint& other) {
        x += other.x;
        if(x >= MOD) x -= MOD;
        return *this;
    }

    Mint& operator-= (const Mint& other) {
        x -= other.x;
        if(x < 0) x += MOD;
        return *this;
    }

    Mint& operator*= (const Mint& other) {
        x *= other.x;
        x %= MOD;
        return *this;
    }

    Mint& operator/= (const Mint& other) {
        return *this *= other.inv();
    }

    Mint& operator++() {
        return *this += 1;
    }

    Mint& operator--() {
        return *this -= 1;
    }

    // https://www.cs.odu.edu/~zeil/cs333/f13/Public/faq/faq-htmlsu23.html
    Mint operator++(int) {
        Mint before = *this;
        ++*this;
        return before;
    }

    Mint operator--(int) {
        Mint before = *this;
        --*this;
        return before;
    }

    Mint operator-() const {
        return x == 0 ? 0 : MOD - x;
    }

    friend Mint operator+ (const Mint& a, const Mint& b) {
        return Mint(a) += b;
        // why not just a += b?
    }

    friend Mint operator- (const Mint& a, const Mint& b) { return Mint(a) -= b; }
    friend Mint operator* (const Mint& a, const Mint& b) { return Mint(a) *= b; }
    friend Mint operator/ (const Mint& a, const Mint& b) { return Mint(a) /= b; }

    friend bool operator== (const Mint& a, const Mint& b) { return a.x == b.x; }
    friend bool operator!= (const Mint& a, const Mint& b) { return a.x != b.x; }
    friend bool operator< (const Mint& a, const Mint& b) { return a.x < b.x; }
    friend bool operator> (const Mint& a, const Mint& b) { return a.x > b.x; }
    friend bool operator<= (const Mint& a, const Mint& b) { return a.x <= b.x; }
    friend bool operator>= (const Mint& a, const Mint& b) { return a.x >= b.x; }

    friend ostream& operator<<(ostream& os, const Mint& m) { return os << m.x; }
    friend istream& operator>>(istream& is, Mint& m) { return is >> m.x; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector <Mint> f(N), inv(N);
    f[0] = 1;
    inv[0] = 1;
    for(int i = 1; i < N; i++) {
        f[i] = f[i - 1] * i;
        inv[i] = f[i].inv();
    }
 
    auto COMB = [&](int n, int r) -> Mint {
        if(n < r) return 0;
        return f[n] * inv[r] * inv[n - r];
    };

    vector<Mint> dp(N);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i < N; i++) {
        dp[i] = (i - 1)*dp[i - 2] + dp[i - 1];
    }

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        Mint ans = 0;
        for(int x = 0; x < n; x++) {
            if(n - 4*x < 0) break;
            ans += COMB(n - 2*x, n - 4*x) * f[2*x] / f[x] * dp[n - 4*x];
        }
        cout << ans << '\n';
    }

    return 0;
}