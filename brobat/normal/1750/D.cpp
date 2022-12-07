#include <bits/stdc++.h>
using namespace std;

const int N = 200100;
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

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector <int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }
        vector <int> fac;
        for(int i = 1; i <= sqrt(v[0]); i++) {
            if(v[0] % i == 0) {
                fac.push_back(i);
                if(i * i != v[0]) {
                    fac.push_back(v[0] / i);
                }
            }
        }
        sort(fac.begin(), fac.end(), greater<int>());
        Mint ans = 1;
        for(int i = 1; i < n; i++) {
            if(v[i] > v[i - 1] || v[i - 1] % v[i] != 0) {
                ans = 0;
                break;
            }
            if(v[i] == v[i - 1]) {
                int x = m/v[i];
                ans *= Mint(x);
            } else {
                // find answer in O(log n).
                vector <int> f;
                for(auto j : fac) if(v[i - 1] % j == 0) f.push_back(j);
                int s = f.size();
                map<int, int> dp;
                for(auto j : f) {
                    dp[j] = m/j;
                }
                for(auto j : f) {
                    for(auto k : f) {
                        if(k < j && j % k == 0) {
                            dp[k] -= dp[j];
                        }
                    }
                }
                // for(auto j : f) cout << j << ',' << dp[j] << ';'; cout << '\n';
                ans *= Mint(dp[v[i]]);
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}