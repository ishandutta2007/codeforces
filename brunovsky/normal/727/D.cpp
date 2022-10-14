#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

inline namespace impl {

using uint = uint32_t;
using ulong = uint64_t;

struct bigint {
    vector<uint> nums;
    bool sign = 0; // 0=positive, 1=negative

    bigint() = default;
    bigint(int n) : nums(n != 0, abs(n)), sign(n < 0) {}
    bigint(uint n, bool s = 0) : nums(n > 0, n), sign(s) {}
    bigint(const string& s, uint b = 10) {
        assert(2 <= b && b <= 10);
        int i = 0, S = s.size();
        while (i < S && isspace(s[i])) {
            i++;
        }
        if (i == S) {
            return;
        }
        if (s[i] == '-') {
            sign = 1;
        }
        if (!('0' <= s[i] && s[i] <= '9')) {
            i++;
        }
        uint n = 0, tens = 1, threshold = UINT_MAX / (b + 1);
        while (i < S && ('0' <= s[i] && s[i] <= '9')) {
            n = b * n + uint(s[i++] - '0');
            tens *= b;
            if (tens >= threshold) {
                mul_int(*this, tens);
                add_int(*this, n);
                n = 0;
                tens = 1;
            }
        }
        mul_int(*this, tens);
        add_int(*this, n);
    }

    auto& operator[](uint x) { return nums[x]; }
    const auto& operator[](uint x) const { return nums[x]; }
    bool bit(uint x) const { return nums[x / 32] & (1 << (x % 32)); }
    int len() const { return nums.size(); }
    bool zero() const noexcept { return nums.empty(); }
    void clear() { nums.clear(), sign = 0; }
    void flip() { sign = !sign && !zero(); }
    void trim() {
        while (!zero() && nums.back() == 0)
            nums.pop_back();
        sign = sign && !zero();
    }

    explicit operator int() const noexcept {
        return zero() ? 0 : sign ? -nums[0] : nums[0];
    }
    explicit operator bool() const noexcept { return !zero(); }
    explicit operator double() const noexcept {
        double v = 0, e = pow(2, 32);
        for (int i = 0; i < len(); i++)
            v = e * v + nums[i];
        return v;
    }

    friend bool magnitude_cmp(const bigint& u, const bigint& v) {
        int L = u.len(), R = v.len();
        return L != R ? L < R
                      : lexicographical_compare(rbegin(u.nums), rend(u.nums), //
                                                rbegin(v.nums), rend(v.nums));
    }
    friend bool operator<(const bigint& u, const bigint& v) {
        return u.sign != v.sign ? u.sign
               : u.sign         ? magnitude_cmp(v, u)
                                : magnitude_cmp(u, v);
    }
    friend bool operator>(const bigint& u, const bigint& v) { return v < u; }
    friend bool operator<=(const bigint& u, const bigint& v) { return !(u > v); }
    friend bool operator>=(const bigint& u, const bigint& v) { return !(u < v); }
    friend bool operator==(const bigint& u, const bigint& v) {
        return u.sign == v.sign && u.nums == v.nums;
    }
    friend bool operator!=(const bigint& u, const bigint& v) { return !(u == v); }

    friend bigint& operator>>=(bigint& u, uint shift) {
        int s = shift / 32, n = u.len();
        uint lo = shift % 32, hi = 32 - lo;

        if (s >= n) {
            u.clear();
        } else if (lo > 0) {
            for (int i = 0; i < n - s - 1; i++)
                u[i] = (u[i + s] >> lo) | (u[i + s + 1] << hi);
            u[n - s - 1] = u[n - 1] >> lo;
            u.nums.resize(n - s);
            u.trim();
        } else {
            u.nums.erase(begin(u.nums), begin(u.nums) + s);
        }

        return u;
    }
    friend bigint& operator<<=(bigint& u, uint shift) {
        int s = shift / 32, n = u.len();
        uint hi = shift % 32, lo = 32 - hi;

        if (hi > 0) {
            u.nums.resize(n + s + 1, 0);
            for (int i = n + s; i > s; i--)
                u[i] = (u[i - s - 1] >> lo) | (u[i - s] << hi);
            u[s] = u[0] << hi;
            for (int i = s - 1; i >= 0; i--)
                u[i] = 0;
            u.trim();
        } else {
            u.nums.insert(begin(u.nums), s, 0);
        }

        return u;
    }

    friend bigint operator>>(bigint u, uint shift) { return u >>= shift; }
    friend bigint operator<<(bigint u, uint shift) { return u <<= shift; }

    friend bigint& operator&=(bigint& u, const bigint& v) {
        int n = min(u.len(), v.len());
        u.nums.resize(n);
        for (int i = 0; i < n; i++)
            u[i] = u[i] & v[i];
        u.trim();
        return u;
    }
    friend bigint& operator|=(bigint& u, const bigint& v) {
        int n = max(u.len(), v.len());
        u.nums.resize(n, 0);
        for (int i = 0; i < v.len(); i++)
            u[i] = u[i] | v[i];
        return u;
    }
    friend bigint& operator^=(bigint& u, const bigint& v) {
        int n = max(u.len(), v.len());
        u.nums.resize(n, 0);
        for (int i = 0; i < v.len(); i++)
            u[i] = u[i] ^ v[i];
        u.trim();
        return u;
    }
    friend bigint operator~(bigint u) {
        for (int i = 0; i < u.len(); i++)
            u[i] = ~u[i];
        u.trim();
        return u;
    }

    friend bigint operator&(bigint u, const bigint& v) { return u &= v; }
    friend bigint operator|(bigint u, const bigint& v) { return u |= v; }
    friend bigint operator^(bigint u, const bigint& v) { return u ^= v; }

    friend string lsbits(const bigint& u) {
        if (u.zero())
            return "0";
        string s(32 * u.len() + 1, '0');
        s[0] = u.sign ? '-' : '+';
        for (int i = 0; i < 32 * u.len(); i++)
            s[i + 1] = '0' + u.bit(i);
        while (!s.empty() && s.back() == '0')
            s.pop_back();
        return s;
    }
    friend string msbits(const bigint& u) {
        if (u.zero())
            return "0";
        string s(32 * u.len() + 1, '0');
        s[0] = u.sign ? '-' : '+';
        for (int i = 0; i < 32 * u.len(); i++)
            s[32 * u.len() - i] = '0' + u.bit(i);
        s.erase(begin(s) + 1, find(begin(s) + 1, end(s), '1'));
        return s;
    }

    friend void add_int(bigint& u, uint v) {
        for (int i = 0; v && i < u.len(); i++)
            u[i] += v, v = u[i] < v;
        if (v > 0)
            u.nums.push_back(v);
    }
    friend void sub_int(bigint& u, uint v) {
        if (v == 0)
            return;
        if (u.zero()) {
            u.nums = {v}, u.sign = 1;
            return;
        }
        if (u.len() == 1 && u[0] < v) {
            u.nums = {v - u[0]}, u.flip();
            return;
        }
        for (int i = 0; v && i < u.len(); i++) {
            bool carry = v > u[i];
            u[i] -= v;
            v = carry;
        }
        u.trim();
    }
    friend void mul_int(bigint& u, uint v) {
        if (v == 0) {
            u.clear();
            return;
        }
        if (v == 1) {
            return;
        }
        ulong m = v, sum = 0;
        for (int i = 0; i < u.len(); i++) {
            sum += u[i] * m;
            u[i] = sum;
            sum >>= 32;
        }
        if (sum > 0)
            u.nums.push_back(sum);
    }
    friend uint div_int(bigint& u, uint v) {
        constexpr ulong b = 1UL + UINT_MAX;
        assert(v > 0);
        if (v == 1 || u.zero())
            return 0;
        uint r = 0;
        for (int i = u.len() - 1; i >= 0; i--) {
            ulong p = r * b + u[i];
            u[i] = p / v, r = p % v;
        }
        u.trim();
        return r;
    }
    friend void add_vec(bigint& u, const bigint& v) {
        int n = u.len(), m = v.len(), hi = max(n, m), lo = min(n, m);
        u.nums.resize(hi, 0);
        ulong k = 0;
        for (int i = 0; i < lo; i++) {
            k += u[i], k += v[i];
            u[i] = k, k = k > UINT_MAX;
        }
        for (int i = lo; i < m; i++) {
            k += v[i];
            u[i] = k, k = k > UINT_MAX;
        }
        for (int i = m; k && i < hi; i++) {
            u[i]++, k = u[i] == 0;
        }
        if (k)
            u.nums.push_back(k);
    }
    friend void sub_vec(bigint& u, const bigint& v) {
        int n = u.len(), m = v.len();
        assert(n >= m);
        long k = 0;
        for (int i = 0; i < m; i++) {
            long sum = u[i] - k - v[i];
            u[i] = sum + UINT_MAX + 1;
            k = sum < 0;
        }
        for (int i = m; k && i < n; i++) {
            k = u[i] == 0;
            u[i]--;
        }
        assert(k == 0);
        u.trim();
    }
    friend void rev_sub_vec(bigint& u, const bigint& v) {
        int n = u.len(), m = v.len();
        assert(n <= m);
        u.nums.resize(m, 0);
        long k = 0;
        for (int i = 0; i < n; i++) {
            long sum = v[i] - k - u[i];
            u[i] = sum + UINT_MAX + 1;
            k = sum < 0;
        }
        for (int i = n; i < m; i++) {
            u[i] = v[i];
        }
        for (int i = n; k && i < m; i++) {
            k = v[i] == 0;
            u[i]--;
        }
        assert(k == 0);
        u.trim(), u.flip();
    }
    friend void dyn_sub_vec(bigint& u, const bigint& v) {
        int n = u.len(), m = v.len();
        if (n > m) {
            return sub_vec(u, v);
        } else if (n < m) {
            return rev_sub_vec(u, v);
        } else {
            int i = n - 1;
            while (i >= 0 && u[i] == v[i])
                u.nums.pop_back(), i--;
            if (i < 0) {
                u.sign = 0;
                return;
            }
            n = i + 1;
            long k = 0;
            if (u[i] > v[i]) {
                for (i = 0; i < n; i++) {
                    long sum = u[i] - k - v[i];
                    u[i] = sum + UINT_MAX + 1;
                    k = sum < 0;
                }
            } else {
                for (i = 0; i < n; i++) {
                    long sum = v[i] - k - u[i];
                    u[i] = sum + UINT_MAX + 1;
                    k = sum < 0;
                }
                u.flip();
            }
            u.trim();
            assert(k == 0);
        }
    }
    friend bigint mul_vec(const bigint& u, const bigint& v) {
        if (u.zero() || v.zero())
            return 0;
        int n = u.len(), m = v.len();
        bigint c;
        c.nums.resize(n + m, 0);
        c.sign = u.sign ^ v.sign;
        for (int j = 0; j < m; j++) {
            uint k = 0;
            for (int i = 0; i < n; i++) {
                ulong t = ulong(u[i]) * v[j] + c[i + j] + k;
                c[i + j] = t & UINT_MAX;
                k = t >> 32;
            }
            c[n + j] = k;
        }
        c.trim();
        return c;
    }
    friend bigint div_vec(bigint& u, bigint v) {
        constexpr ulong b = 1L + UINT_MAX;
        assert(!v.zero());

        // return the remainder and set u to the quotient, but throughout the algorithm
        // u is the remainder and d is the quotient.
        int n = v.len(), m = u.len() - n;
        uint c = __builtin_clz(v[n - 1]);
        u <<= c, v <<= c;
        if (u.len() == n + m)
            u.nums.push_back(0);
        assert(u.len() == n + m + 1 && v.len() == n && v[n - 1] >= b / 2);

        bigint d;
        d.nums.resize(m + 1, 0);
        d.sign = u.sign ^ v.sign;

        for (int j = m; j >= 0; j--) {
            ulong q = (u[n + j] * b + u[n - 1 + j]) / v[n - 1];
            ulong r = (u[n + j] * b + u[n - 1 + j]) % v[n - 1];

            while (r < b && q * v[n - 2] > r * b + u[n - 2 + j])
                q--, r += v[n - 1];
            if (q == 0)
                continue;

            long k = 0, t;
            for (int i = 0; i < n; i++) {
                ulong p = q * v[i];
                t = u[i + j] - (p & UINT_MAX) - k;
                u[i + j] = t;
                k = (p >> 32) - (t >> 32);
            }
            u[j + n] = t = u[j + n] - k;

            d[j] = q;
            if (t < 0) {
                assert(q > 0 && t == -1);
                d[j]--;
                k = 0;
                for (int i = 0; i < n; i++) {
                    t = u[i + j] + k + v[i];
                    u[i + j] = t;
                    k = t > UINT_MAX;
                }
                u[j + n] = u[j + n] + k;
            }
            assert(u[j + n] == 0);
        }

        u.trim(), u >>= c, d.trim();
        swap(u, d);
        return d;
    }
    friend bigint div_mod(bigint& u, const bigint& v) {
        bigint r;
        if (magnitude_cmp(u, v)) {
            r = move(u);
            u.clear();
        } else if (v.len() == 1) {
            r = bigint(div_int(u, v[0]), u.sign);
            u.sign ^= v.sign, r.sign &= !r.zero();
        } else {
            r = div_vec(u, v);
        }
        return r;
    }

    friend bigint& operator+=(bigint& u, const bigint& v) {
        u.sign == v.sign ? add_vec(u, v) : dyn_sub_vec(u, v);
        return u;
    }
    friend bigint& operator-=(bigint& u, const bigint& v) {
        u.sign != v.sign ? add_vec(u, v) : dyn_sub_vec(u, v);
        return u;
    }
    friend bigint& operator*=(bigint& u, const bigint& v) {
        u = mul_vec(u, v);
        return u;
    }
    friend bigint& operator/=(bigint& u, const bigint& v) {
        div_mod(u, v);
        return u;
    }
    friend bigint& operator%=(bigint& u, const bigint& v) {
        u = div_mod(u, v);
        return u;
    }

    friend bigint& operator+=(bigint& u, uint n) {
        u.sign == 0 ? add_int(u, n) : sub_int(u, n);
        return u;
    }
    friend bigint& operator-=(bigint& u, uint n) {
        u.sign == 1 ? add_int(u, n) : sub_int(u, n);
        return u;
    }
    friend bigint& operator*=(bigint& u, uint n) {
        mul_int(u, n);
        return u;
    }
    friend bigint& operator/=(bigint& u, uint n) {
        div_int(u, n);
        return u;
    }
    friend bigint& operator%=(bigint& u, uint n) {
        u = bigint(div_int(u, n), u.sign);
        return u;
    }

    friend bigint& operator+=(bigint& u, int n) {
        n >= 0 ? u += uint(n) : u -= uint(abs(n));
        return u;
    }
    friend bigint& operator-=(bigint& u, int n) {
        n >= 0 ? u -= uint(n) : u += uint(abs(n));
        return u;
    }
    friend bigint& operator*=(bigint& u, int n) {
        mul_int(u, abs(n)), u.sign ^= n < 0;
        return u;
    }
    friend bigint& operator/=(bigint& u, int n) {
        div_int(u, abs(n)), u.sign ^= n < 0;
        return u;
    }
    friend bigint& operator%=(bigint& u, int n) {
        u = bigint(div_int(u, abs(n)), u.sign);
        return u;
    }

    friend bigint operator+(bigint u, const bigint& v) { return u += v; }
    friend bigint operator+(bigint u, uint n) { return u += n; }
    friend bigint operator+(bigint u, int n) { return u += n; }
    friend bigint operator+(uint n, bigint u) { return u += n; }
    friend bigint operator+(int n, bigint u) { return u += n; }

    friend bigint operator-(bigint u, const bigint& v) { return u -= v; }
    friend bigint operator-(bigint u, uint n) { return u -= n; }
    friend bigint operator-(bigint u, int n) { return u -= n; }

    friend bigint operator*(const bigint& u, const bigint& v) { return mul_vec(u, v); }
    friend bigint operator*(bigint u, uint n) { return u *= n; }
    friend bigint operator*(bigint u, int n) { return u *= n; }
    friend bigint operator*(uint n, bigint u) { return u *= n; }
    friend bigint operator*(int n, bigint u) { return u *= n; }

    friend bigint operator/(bigint u, const bigint& v) { return u /= v; }
    friend bigint operator/(bigint u, uint n) { return u /= n; }
    friend bigint operator/(bigint u, int n) { return u /= n; }

    friend bigint operator%(bigint u, const bigint& v) { return u %= v; }
    friend bigint operator%(bigint u, uint n) { return u %= n; }
    friend bigint operator%(bigint u, int n) { return u %= n; }

    friend bigint operator-(bigint u) { return u.flip(), u; }
    friend bool operator!(const bigint& u) { return u.zero(); }

    friend bigint abs(const bigint& u) { return u.sign ? -u : u; }
    friend bigint gcd(bigint a, bigint b) {
        while (a != 0) {
            b = b % a;
            swap(a, b);
        }
        return abs(b);
    }
    friend bigint sqrt(const bigint& u) {
        assert(u.sign == 0); // no complex fuckery here
        int n = u.len(), m = (n + 1) / 2;
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return uint(std::sqrt(u[0]));
        } else if (n == 2) {
            return uint(std::sqrt(ulong(u[1]) << 32 | u[0]));
        }
        bigint x, y;
        x.nums.resize(m);
        x.nums[m - 1] = std::sqrt(ulong(u[n - 1]) << 32 | u[n - 2]);
        do { // iterate newton until stabilization
            y = move(x), x = (y + u / y) >> 1;
        } while (x != y);
        return x;
    }

    friend string to_string(bigint u, uint b = 10) {
        static auto uint_to_string = [](uint n, uint base) {
            string s;
            while (n > 0) {
                uint m = n / base;
                s += '0' + (n - base * m), n = m;
            }
            reverse(begin(s), end(s));
            return s;
        };

        if (u.zero())
            return "0";
        string s = u.sign ? "-" : "";
        vector<string> rems;
        uint divisor = b, digits = 1;
        while (divisor < UINT_MAX / b) {
            divisor *= b, digits++;
        }
        while (!u.zero()) {
            rems.push_back(uint_to_string(div_int(u, divisor), b));
        }
        for (int i = 0, n = rems.size(); i < n; i++) {
            string pad(i ? digits - rems[n - i - 1].length() : 0, '0');
            s += pad + rems[n - i - 1];
        }
        return s;
    }

    friend ostream& operator<<(ostream& out, const bigint& u) {
        return out << to_string(u);
    }
};

struct bfrac {
    bigint n, d;

    bfrac() : n(0), d(1) {}
    bfrac(int num) : n(num), d(1) {}
    bfrac(int num, int den) : bfrac(bigint(num), bigint(den)) {}
    bfrac(bigint num) : n(move(num)), d(1) {}
    bfrac(bigint num, bigint den) : n(move(num)), d(move(den)) {
        auto g = gcd(n, d);
        g = ((g < 0) == (d < 0)) ? g : -g;
        n /= g, d /= g;
    }

    explicit operator bool() const noexcept { return n != 0 && d != 0; }
    explicit operator bigint() const noexcept { return assert(d != 0), n / d; }
    explicit operator double() const noexcept {
        return assert(d != 0), double(n) / double(d);
    }

    friend bfrac abs(const bfrac& f) { return bfrac(abs(f.n), f.d); }
    friend bigint floor(const bfrac& f) {
        return f.n >= 0 ? f.n / f.d : (f.n - f.d + 1) / f.d;
    }
    friend bigint ceil(const bfrac& f) {
        return f.n >= 0 ? (f.n + f.d - 1) / f.d : f.n / f.d;
    }
    friend bfrac gcd(const bfrac& a, const bfrac& b) { return a ? gcd(b, a) % a : b; }

    friend bool operator==(const bfrac& a, const bfrac& b) {
        return a.n == b.n && a.d == b.d;
    }
    friend bool operator!=(const bfrac& a, const bfrac& b) {
        return a.n != b.n || a.d != b.d;
    }
    friend bool operator<(const bfrac& a, const bfrac& b) {
        return a.n * b.d < b.n * a.d;
    }
    friend bool operator>(const bfrac& a, const bfrac& b) {
        return a.n * b.d > b.n * a.d;
    }
    friend bool operator<=(const bfrac& a, const bfrac& b) {
        return a.n * b.d <= b.n * a.d;
    }
    friend bool operator>=(const bfrac& a, const bfrac& b) {
        return a.n * b.d >= b.n * a.d;
    }

    friend bfrac operator+(const bfrac& a, const bfrac& b) {
        return bfrac(a.n * b.d + b.n * a.d, a.d * b.d);
    }
    friend bfrac operator-(const bfrac& a, const bfrac& b) {
        return bfrac(a.n * b.d - b.n * a.d, a.d * b.d);
    }
    friend bfrac operator*(const bfrac& a, const bfrac& b) {
        return bfrac(a.n * b.n, a.d * b.d);
    }
    friend bfrac operator/(const bfrac& a, const bfrac& b) {
        return bfrac(a.n * b.d, a.d * b.n);
    }
    friend bfrac operator%(const bfrac& a, const bfrac& b) {
        return a - bigint(a / b) * b;
    }
    friend bfrac& operator+=(bfrac& a, const bfrac& b) { return a = a + b; }
    friend bfrac& operator-=(bfrac& a, const bfrac& b) { return a = a - b; }
    friend bfrac& operator*=(bfrac& a, const bfrac& b) { return a = a * b; }
    friend bfrac& operator/=(bfrac& a, const bfrac& b) { return a = a / b; }
    friend bfrac& operator%=(bfrac& a, const bfrac& b) { return a = a % b; }

    friend bfrac operator-(const bfrac& f) { return bfrac(-f.n, f.d); }
    friend bool operator!(const bfrac& f) { return f.n == 0; }

    friend string to_string(const bfrac& f) {
        if (f.d == 0) {
            return f.n ? f.n > 0 ? "inf" : "-inf" : "undef";
        } else if (f.d == 1) {
            return to_string(f.n);
        } else {
            return to_string(f.n) + '/' + to_string(f.d);
        }
    }

    friend ostream& operator<<(ostream& out, const bfrac& f) {
        return out << to_string(f);
    }
};

template <typename T>
struct mat {
    using vec = vector<T>;
    int n = 0, m = 0;
    vector<vec> arr;

    mat() = default;
    mat(int n, int m, const T& v = T()) : n(n), m(m), arr(n, vec(m, v)) {}
    mat(vector<vec> v) : n(v.size()), m(n ? v[0].size() : 0), arr(move(v)) {}

    array<int, 2> size() const { return {n, m}; }
    auto& operator[](int x) { return arr[x]; }
    const auto& operator[](int x) const { return arr[x]; }
    auto& operator[](array<int, 2> x) { return arr[x[0]][x[1]]; }
    const auto& operator[](array<int, 2> x) const { return arr[x[0]][x[1]]; }

    bool operator<(const mat& b) const { return tie(n, m, arr) < tie(b.n, b.m, b.arr); }
    bool operator>(const mat& b) const { return b < *this; }
    bool operator<=(const mat& b) const { return !(b < *this); }
    bool operator>=(const mat& b) const { return !(*this < b); }
    bool operator==(const mat& b) const { return n == b.n && m == b.m && arr == b.arr; }
    bool operator!=(const mat& b) const { return !(*this == b); }

    static mat identity(int n) {
        mat a(n, n);
        for (int i = 0; i < n; i++)
            a[i][i] = T(1);
        return a;
    }

    friend mat transpose(const mat& a) {
        mat b(a.m, a.n);
        for (int i = 0; i < a.m; i++)
            for (int j = 0; j < a.n; j++)
                b[i][j] = a[j][i];
        return b;
    }

    friend mat operator-(mat a) {
        for (int i = 0; i < a.n; i++)
            for (int j = 0; j < a.m; j++)
                a[i][j] = -a[i][j];
        return a;
    }

    friend mat& operator+=(mat& a, const mat& b) {
        assert(a.n == b.n && a.m == b.m);
        for (int i = 0; i < a.n; i++)
            for (int j = 0; j < a.m; j++)
                a[i][j] += b[i][j];
        return a;
    }

    friend mat& operator-=(mat& a, const mat& b) {
        assert(a.n == b.n && a.m == b.m);
        for (int i = 0; i < a.n; i++)
            for (int j = 0; j < a.m; j++)
                a[i][j] -= b[i][j];
        return a;
    }

    friend mat operator+(mat a, const mat& b) { return a += b; }
    friend mat operator-(mat a, const mat& b) { return a -= b; }

    friend mat operator*(const mat& a, const mat& b) {
        assert(a.m == b.n && "Different matrix mul operand dimensions");
        mat c(a.n, b.m);
        for (int i = 0; i < a.n; i++)
            for (int j = 0; j < b.m; j++)
                for (int k = 0; k < a.m; k++)
                    c[i][j] += a[i][k] * b[k][j];
        return c;
    }

    friend vec operator*(const mat& a, const vec& b) {
        assert(a.m == int(b.size()) && "Matrix and column have unequal dimensions");
        vec c(a.n);
        for (int i = 0; i < a.n; i++)
            for (int j = 0; j < a.m; j++)
                c[i] += a[i][j] * b[j];
        return c;
    }

    friend mat operator^(mat a, int e) {
        assert(a.n == a.m && "Matrix exp operand is not square");
        mat c = identity(a.n);
        while (e > 0) {
            if (e & 1)
                c = c * a;
            if (e >>= 1)
                a = a * a;
        }
        return c;
    }

    void resize(int N, int M, T&& val = T()) {
        if (n != N)
            arr.resize(N, vec(M, val));
        if (m != M)
            for (auto& row : arr)
                row.resize(M, val);
        n = N, m = M;
    }

    void assign(int N, int M, T&& val = T()) { n = N, m = M, arr.assign(N, vec(M, val)); }

    void set_row(int i, T&& val = T()) {
        for (int j = 0; j < m; j++)
            arr[i][j] = val;
    }

    void set_col(int j, T&& val = T()) {
        for (int i = 0; i < n; i++)
            arr[i][j] = val;
    }

    void add_row(int i, T&& add) {
        for (int j = 0; j < m; j++)
            arr[i][j] += add;
    }

    void add_col(int j, T&& add) {
        for (int i = 0; i < n; i++)
            arr[i][j] += add;
    }

    void mul_row(int i, T&& mul) {
        for (int j = 0; j < m; j++)
            arr[i][j] *= mul;
    }

    void mul_col(int j, T&& mul) {
        for (int i = 0; i < n; i++)
            arr[i][j] *= mul;
    }

    void div_row(int i, T&& div) {
        for (int j = 0; j < m; j++)
            arr[i][j] /= div;
    }

    void div_col(int j, T&& div) {
        for (int i = 0; i < n; i++)
            arr[i][j] /= div;
    }

    void mul_add_row(int i, int src, T&& mul) {
        for (int j = 0; j < m; j++)
            arr[i][j] += mul * arr[src][j];
    }

    void mul_add_col(int j, int src, T&& mul) {
        for (int i = 0; i < n; i++)
            arr[i][j] += mul * arr[i][src];
    }
};

enum LPState { LP_FEASIBLE = 0, LP_OPTIMAL = 1, LP_UNBOUNDED = 2, LP_IMPOSSIBLE = 3 };
enum LPConstraintType { LP_LESS = 0, LP_EQUAL = 1, LP_GREATER = 2 };

#define LP_TSW(type, le, eq, ge) (type == LP_EQUAL ? (eq) : type == LP_LESS ? (le) : (ge))

template <typename F>
struct lp_constraint {
    vector<F> v;
    F b;
    LPConstraintType type;
};

template <typename F>
struct simplex {
    using constraint_t = lp_constraint<F>;
    static inline const F inf = F(1, 0);

    int N = 0, M = 0; // num variables / num constraints
    vector<F> z;
    vector<constraint_t> C;

    simplex() = default;
    simplex(int N) : N(N), z(N, 1) {}

    void set_objective(vector<F> f) {
        assert(!N || N == int(f.size()));
        z = move(f), N = z.size();
    }

    void add_constraint(constraint_t constraint) {
        assert(!N || int(constraint.v.size()) == N);
        C.push_back(move(constraint)), M++, N = N ? N : constraint.v.size();
    }

    void add_constraints(const vector<constraint_t>& constraints) {
        for (const auto& constraint : constraints)
            add_constraint(constraint);
    }

    void clear() {
        N = M = S = A = 0, z.clear(), C.clear();
        var_to_row.clear(), row_to_var.clear();
    }

    int S = 0, A = 0; // slack and artificial variable count
    mat<F> tab;
    vector<int> var_to_row, row_to_var;

    int slackvar(int i) const { return --i, LP_TSW(C[i].type, 1, 0, -1); }
    int artifvar(int i) const {
        return --i, LP_TSW(C[i].type, -(C[i].b < 0), C[i].b >= 0 ? 1 : -1, C[i].b > 0);
    }
    void make_basic(int r, int c) {
        var_to_row[row_to_var[r]] = 0, var_to_row[c] = r, row_to_var[r] = c;
    }

    void pivot(int r, int c) {
        make_basic(r, c);
        tab.mul_row(r, 1 / tab[r][c]);
        for (int i = 0; i <= M; i++) {
            if (i != r) {
                tab.mul_add_row(i, r, -tab[i][c]);
            }
        }
    }

    LPState optimize() {
        int iterations = 0;
        do {
            int r = 0, c = min_element(begin(tab[0]) + 1, end(tab[0])) - begin(tab[0]);
            if (tab[0][c] >= 0) {
                return LP_OPTIMAL;
            }
            int bland = INT_MAX;
            F best = inf;
            for (int i = 1; i <= M; i++) {
                if (int j = row_to_var[i]; tab[i][c] > 0) {
                    auto ratio = tab[i][0] / tab[i][c];
                    if (0 <= ratio && (ratio < best || (ratio == best && j < bland))) {
                        best = ratio, r = i, bland = j;
                    }
                }
            }
            if (r == 0) {
                return LP_UNBOUNDED;
            }
            pivot(r, c);
        } while (++iterations < 100 * N * M);

        throw runtime_error("oops: simplex::optimize took too many iterations\n");
    }

    pair<LPState, F> compute() {
        S = A = 0;
        for (int i = 1; i <= M; i++) {
            S += slackvar(i) != 0, A += artifvar(i) != 0;
        }

        tab = mat<F>(M + 1, N + S + A + 1, 0);
        var_to_row.assign(N + S + A + 1, 0);
        row_to_var.assign(M + 1, 0);

        for (int i = 1, s = 1 + N, a = 1 + N + S; i <= M; i++) {
            const auto& [v, b, type] = C[i - 1];
            tab[i][0] = b;
            for (int j = 1; j <= N; j++) {
                tab[i][j] = v[j - 1];
            }
            if (int c = slackvar(i); c != 0) {
                make_basic(i, s);
                tab[i][s++] = F(c);
            }
            if (int c = artifvar(i); c != 0) {
                make_basic(i, a);
                tab.mul_add_row(0, i, -F(c));
                tab[i][a++] = F(c);
            }
            if (int j = row_to_var[i]; j != 0 && tab[i][j] != 1) {
                tab.mul_row(i, 1 / tab[i][j]);
            }
        }

        if (A > 0) {
            auto res = optimize();
            if (res != LP_OPTIMAL || tab[0][0] != 0) {
                assert(res == LP_OPTIMAL && tab[0][0] < 0);
                return {LP_IMPOSSIBLE, tab[0][0]};
            }

            for (int a = 1 + N + S; a <= N + S + A; a++) {
                row_to_var[var_to_row[a]] = 0;
            }
            tab.resize(M + 1, N + S + 1);
            for (int i = 1; i <= M; i++) {
                if (row_to_var[i])
                    continue;
                for (int j = 1; j <= N + S; j++) {
                    if (!var_to_row[j] && tab[i][j] != 0 && tab[i][0] / tab[i][j] >= 0) {
                        pivot(i, j);
                        break;
                    }
                }
            }
            tab.set_row(0, 0);
        }

        for (int j = 1; j <= N; j++) {
            tab[0][j] = -z[j - 1];
        }
        for (int j = 1; j <= N; j++) {
            if (int i = var_to_row[j]; i != 0) {
                tab.mul_add_row(0, i, -tab[0][j] * tab[i][j]);
            }
        }

        auto res = optimize();
        return {res, tab[0][0]};
    }

    vector<F> extract() const {
        vector<F> x(N, 0);
        for (int j = 1; j <= N; j++) {
            if (int r = var_to_row[j]; r != 0) {
                x[j - 1] = tab[r][0] / tab[r][j];
            }
        }
        return x;
    }
};

} // namespace impl

#define SZ 6
string names[SZ] = {"S", "M", "L", "XL", "XXL", "XXXL"};

auto solve() {
    int sizes[SZ], N;
    for (int i = 0; i < SZ; i++) {
        cin >> sizes[i];
    }
    cin >> N;
    int kind[11] = {}, each[5][2] = {};
    vector<int> ids(N);
    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        auto j = line.find(',');
        if (j == string::npos) {
            ids[i] = find(names, names + SZ, line) - names;
        } else {
            string a = line.substr(0, j);
            string b = line.substr(j + 1);
            int ai = find(names, names + SZ, a) - names;
            int bi = find(names, names + SZ, b) - names;
            assert(ai + 1 == bi);
            ids[i] = 6 + ai;
        }
        kind[ids[i]]++;
    }

    using lpb = lp_constraint<bfrac>;
    simplex<bfrac> smp;
    smp.set_objective({1, 1, 1, 1, 1, 1, 01, 1, 1, 1, 1, 01, 1, 1, 1, 1});
    smp.add_constraints({{
        lpb{{1, 0, 0, 0, 0, 0, 01, 0, 0, 0, 0, 00, 0, 0, 0, 0}, sizes[0], LP_LESS},
        lpb{{0, 1, 0, 0, 0, 0, 00, 1, 0, 0, 0, 01, 0, 0, 0, 0}, sizes[1], LP_LESS},
        lpb{{0, 0, 1, 0, 0, 0, 00, 0, 1, 0, 0, 00, 1, 0, 0, 0}, sizes[2], LP_LESS},
        lpb{{0, 0, 0, 1, 0, 0, 00, 0, 0, 1, 0, 00, 0, 1, 0, 0}, sizes[3], LP_LESS},
        lpb{{0, 0, 0, 0, 1, 0, 00, 0, 0, 0, 1, 00, 0, 0, 1, 0}, sizes[4], LP_LESS},
        lpb{{0, 0, 0, 0, 0, 1, 00, 0, 0, 0, 0, 00, 0, 0, 0, 1}, sizes[5], LP_LESS},
        lpb{{1, 0, 0, 0, 0, 0, 00, 0, 0, 0, 0, 00, 0, 0, 0, 0}, kind[0], LP_EQUAL},
        lpb{{0, 1, 0, 0, 0, 0, 00, 0, 0, 0, 0, 00, 0, 0, 0, 0}, kind[1], LP_EQUAL},
        lpb{{0, 0, 1, 0, 0, 0, 00, 0, 0, 0, 0, 00, 0, 0, 0, 0}, kind[2], LP_EQUAL},
        lpb{{0, 0, 0, 1, 0, 0, 00, 0, 0, 0, 0, 00, 0, 0, 0, 0}, kind[3], LP_EQUAL},
        lpb{{0, 0, 0, 0, 1, 0, 00, 0, 0, 0, 0, 00, 0, 0, 0, 0}, kind[4], LP_EQUAL},
        lpb{{0, 0, 0, 0, 0, 1, 00, 0, 0, 0, 0, 00, 0, 0, 0, 0}, kind[5], LP_EQUAL},
        lpb{{0, 0, 0, 0, 0, 0, 01, 0, 0, 0, 0, 01, 0, 0, 0, 0}, kind[6], LP_EQUAL},
        lpb{{0, 0, 0, 0, 0, 0, 00, 1, 0, 0, 0, 00, 1, 0, 0, 0}, kind[7], LP_EQUAL},
        lpb{{0, 0, 0, 0, 0, 0, 00, 0, 1, 0, 0, 00, 0, 1, 0, 0}, kind[8], LP_EQUAL},
        lpb{{0, 0, 0, 0, 0, 0, 00, 0, 0, 1, 0, 00, 0, 0, 1, 0}, kind[9], LP_EQUAL},
        lpb{{0, 0, 0, 0, 0, 0, 00, 0, 0, 0, 1, 00, 0, 0, 0, 1}, kind[10], LP_EQUAL},
    }});
    auto [res, optimum] = smp.compute();
    if (res != LP_OPTIMAL || optimum != N) {
        cout << "NO" << endl;
        return;
    }

    auto x = smp.extract();
    for (int i = 0; i < SZ; i++)
        kind[i] = int(bigint(x[i]));
    for (int i = 0; i < SZ - 1; i++) {
        for (int j : {0, 1})
            each[i][j] = int(bigint(x[6 + i + 5 * j]));
    }

    cout << "YES" << endl;
    for (int i = 0; i < N; i++) {
        if (ids[i] < 6) {
            cout << names[ids[i]] << endl;
        } else {
            int a = ids[i] - 6, b = a + 1;
            if (each[a][0]) {
                each[a][0]--;
                cout << names[a] << endl;
            } else {
                each[a][1]--;
                cout << names[b] << endl;
            }
        }
    }
}

// *****

int main() {
    solve();
    return 0;
}