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
            b >>= 1;
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

vector<int> z_function(string& b, string& a) {
    // Match the string a with characters of b
    string s = b + '#' + a;
    int n = s.length();
    vector <int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    int an = a.length();
    int bn = b.length();
    vector <int> v(an);
    for(int i = 0; i < an; i++) {
        v[i] = z[i + bn + 1];
    }
    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string a, l, r;
    cin >> a >> l >> r;
    int n = a.length();
    int ln = l.length();
    int rn = r.length();
    auto lz = z_function(l, a);
    auto rz = z_function(r, a);
    // for(auto i : lz) cerr << i << ' '; cerr << '\n';
    // for(auto i : rz) cerr << i << ' '; cerr << '\n';
    vector <int> lc(n); // lc[i] = 1 if the substring of length ln starting from i is >= l, else 0
    for(int i = 0; i < n; i++) {
        if(lz[i] == ln) lc[i] = 1;
        else if(l[lz[i]] <= a[i + lz[i]]) lc[i] = 1;
        else lc[i] = 0;
    }
    vector <int> rc(n); // rc[i] = 1 if the substring of length rn starting from i is <= r, else 0
    for(int i = 0; i < n; i++) {
        if(rz[i] == rn) rc[i] = 1;
        else if(r[rz[i]] >= a[i + rz[i]]) rc[i] = 1;
        else rc[i] = 0;
        if(rn > 1 && a[i] == '0') rc[i] = 0;
    }
    // for(auto i : lc) cerr << i << ' '; cerr << '\n';
    // for(auto i : rc) cerr << i << ' '; cerr << '\n';
    vector <Mint> dp(n, 0); // dp[i] --> The number of beautiful substrings ending at position i.
    // dp[-1] = 1.
    Mint between_sum = 0;
    for(int i = 0; i < n; i++) {
        if(ln == rn) {
            if(i - ln + 1 >= 0) {
                if(lc[i - ln + 1] && rc[i - rn + 1]) {
                    dp[i] += (i - ln == -1 ? 1 : dp[i - ln]);
                }
            }
        } else {
            if(i - ln + 1 >= 0) {
                if(lc[i - ln + 1]) {
                    dp[i] += (i - ln == -1 ? 1 : dp[i - ln]);
                    // cerr << 'L';
                }
            }
            if(i - rn + 1 >= 0) {
                if(rc[i - rn + 1]) {
                    dp[i] += (i - rn == -1 ? 1 : dp[i - rn]);
                    // cerr << 'R';
                }
            }
            if(rn > ln + 1) {
                if(i - ln >= 0) {
                    if(a[i - ln] != '0') {
                        between_sum += (i - ln - 1 == -1 ? 1 : dp[i - ln - 1]);
                    }
                }
                if(i - rn + 1 >= 0) {
                    if(a[i - rn + 1] != '0') {
                        between_sum -= (i - rn == -1 ? 1 : dp[i - rn]);
                    }
                }
                dp[i] += between_sum;
            }
        }
        // cerr << dp[i] << ',' << between_sum << ' ';
    }
    // cerr << '\n';
    cout << dp[n - 1] << '\n';

    return 0;
}