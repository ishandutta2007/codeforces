#include <bits/stdc++.h>

template<unsigned P>
class modint {
  static_assert(1 <= P);

  using mint = modint<P>;

protected:
  unsigned v;

public:
  constexpr modint() : v() {}

  template<typename T, 
           typename std::enable_if<
                    std::is_signed<T>::value
                    && std::is_integral<T>::value,
                    bool>::type = true>
  constexpr modint(T _v) : v() {
    long long tmp = _v % static_cast<long long>(P);
    if (tmp < 0) {
      tmp += P;
    }
    v = tmp;
  }

  template<typename T, 
           typename std::enable_if<
                    std::is_unsigned<T>::value
                    && std::is_integral<T>::value,
                    bool>::type = true>
  constexpr modint(T _v) : v() {
    v = _v % P;
  }

  constexpr unsigned val() const {
    return v;
  }

  static constexpr unsigned mod() {
    return P;
  }

  static constexpr mint raw(unsigned v) {
    mint res;
    res.v = v;
    return res;
  }

  constexpr mint &operator+=(const mint &rhs) {
    v < P - rhs.v ? v += rhs.v : v -= P - rhs.v;
    return *this;
  }

  constexpr mint &operator++() {
    v + 1 < P ? ++v : v = 0;
    return *this;
  }

  constexpr mint operator++(int) {
    mint tmp = *this;
    v + 1 < P ? ++v : v = 0;
    return tmp;
  }

  constexpr mint &operator-=(const mint &rhs) {
    v < rhs.v ? v += P - rhs.v : v -= rhs.v;
    return *this;
  }

  constexpr mint &operator--() {
    v == 0 ? v = P - 1 : --v;
    return *this;
  }

  constexpr mint operator--(int) {
    mint tmp = *this;
    v == 0 ? v = P - 1 : --v;
    return tmp;
  }

  constexpr mint operator-() const {
    mint res;
    res.v = v == 0 ? 0 : P - v;
    return res;
  }

  constexpr mint &operator*=(const mint &rhs) {
    v = static_cast<unsigned long long>(v) * rhs.v % P;
    return *this;
  }

  constexpr mint pow(unsigned long long b) const {
    mint a(*this), s(1);
    for (; b; b >>= 1) {
      if (b & 1) {
        s *= a;
      }
      a *= a;
    }
    return s;
  }

  constexpr mint inv() const {
    return pow(P - 2);
  }

  constexpr friend mint operator+(const mint &lhs, const mint &rhs) {
    return mint(lhs) += rhs;
  }

  constexpr friend mint operator-(const mint &lhs, const mint &rhs) {
    return mint(lhs) -= rhs;
  }

  constexpr friend mint operator*(const mint &lhs, const mint &rhs) {
    return mint(lhs) *= rhs;
  }

  constexpr friend bool operator==(const mint &lhs, const mint &rhs) {
    return lhs.v == rhs.v;
  }

  constexpr friend bool operator!=(const mint &lhs, const mint &rhs) {
    return lhs.v != rhs.v;
  }

  friend std::istream &operator>>(std::istream &in, mint &x) {
    return in >> x.v;
  }

  friend std::ostream &operator<<(std::ostream &out, const mint &x) {
    return out << x.v;
  }
};

template<typename Val, 
         typename VV = std::plus<Val>>
class fenwick_tree {
public:
  typedef std::size_t size_type;

protected:
  const Val E;

  size_type n;
  std::vector<Val> val;

  VV fun;

public:
  fenwick_tree() : fenwick_tree(0) {}

  fenwick_tree(size_type _n)
  : E(), n(_n), val(n + 1, E) {}

  fenwick_tree(size_type _n, const Val &_E)
  : E(_E), n(_n), val(n + 1, E) {}

  size_type size() const {
    return n;
  }

  void modify(size_type x, const Val &v) {
    for (++x; x <= n; x += x & -x) {
      val[x] = fun(val[x], v);
    }
  }

  Val query(size_type x) {
    Val s = E;
    for (; x; x ^= x & -x) {
      s = fun(s, val[x]);
    }
    return s;
  }
};

using mint = modint<1000000007>;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    std::vector<int> v(a);
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < n; ++i) {
      a[i] = std::lower_bound(v.begin(), v.end(), a[i]) - v.begin();
    }

    std::vector<int> suf(a);
    for (int i = n - 2; i >= 0; --i) {
      suf[i] = std::max(suf[i + 1], suf[i]);
    }
    std::vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
      pos[i] = std::lower_bound(suf.begin(), suf.end(), a[i],
                                std::greater<int>()) - suf.begin() - 1;
      pos[i] = std::max(pos[i], i);
    }

    fenwick_tree<mint> T(v.size());

    auto DP = [&](std::vector<int> id, bool op) {
      int n = id.size();
      std::vector<mint> f(n);
      mint sum = 0;
      for (int i = n - 1; i >= 0; --i) {
        f[i] = sum - T.query(a[id[i]] + 1) + (op || i == n - 1);
        T.modify(a[id[i]], f[i]);
        sum += f[i];
      }
      for (int i = 0; i < n; ++i) {
        T.modify(a[id[i]], -f[i]);
      }
      return f;
    };

    std::vector<std::vector<int>> r(n);
    for (int i = 0; i < n; ++i) {
      r[pos[i]].push_back(i);
    }
    std::vector<mint> f(n);
    for (int i = 0; i < n; ++i) {
      auto tmp = DP(r[i], false);
      for (int j = 0; j < (int)r[i].size(); ++j) {
        f[r[i][j]] = tmp[j];
      }
    }
    std::vector<int> id(n);
    std::iota(id.begin(), id.end(), 0);
    auto g = DP(id, true);
    for (int i = 0; i < n; ++i) {
      a[i] = (int)v.size() - 1 - a[i];
    }
    std::reverse(id.begin(), id.end());
    auto h = DP(id, true);
    std::reverse(h.begin(), h.end());
    mint ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += h[i] * (g[i] - f[i]);
    }
    std::cout << ans << "\n";
  }
}