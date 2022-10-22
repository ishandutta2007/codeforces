#include <bits/stdc++.h>

template<unsigned P>
class modint {
  static_assert(1 <= P, "P must be a positive integer");

  using mint = modint<P>;

protected:
  unsigned v;

public:
  constexpr modint() : v() {}

  template<typename T,
           typename std::enable_if<std::is_integral<T>::value &&
                                       std::is_signed<T>::value,
                                   bool>::type = true>
  constexpr modint(T t_v) : v() {
    long long tmp = t_v % static_cast<long long>(P);
    if (tmp < 0) {
      tmp += P;
    }
    v = tmp;
  }

  template<typename T,
           typename std::enable_if<std::is_integral<T>::value &&
                                       std::is_unsigned<T>::value,
                                   bool>::type = true>
  constexpr modint(T t_v) : v() {
    v = t_v % P;
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
    v ? --v : v = P - 1;
    return *this;
  }
  
  constexpr mint operator--(int) {
    mint tmp = *this;
    v ? --v : v = P - 1;
    return tmp;
  }

  constexpr mint operator-() const {
    mint res;
    res.v = v ? P - v : 0;
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

using mint = modint<998244353>;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<std::vector<std::tuple<int, int, int>>> E(n);
    for (int i = 0; i < n - 1; ++i) {
      int u, v, x, y;
      std::cin >> u >> v >> x >> y;
      --u, --v;
      E[u].emplace_back(v, x, y);
      E[v].emplace_back(u, y, x);
    }

    std::vector<int> minp(n + 1);
    std::iota(minp.begin(), minp.end(), 0);
    for (int i = 2; i <= n; ++i) {
      if (minp[i] == i) {
        for (int j = i + i; j <= n; j += i) {
          minp[j] = std::min(minp[j], i);
        }
      }
    }

    std::vector<int> now(n + 1), b(n + 1);
    mint ans = 0;

    auto dfs = [&](auto &self, int u, int fa, mint d) -> void {
      ans += d;
      for (auto [v, x, y] : E[u]) {
        if (v != fa) {
          for (int i = x; i > 1; i /= minp[i]) {
            ++now[minp[i]];
          }
          for (int i = y; i > 1; i /= minp[i]) {
            --now[minp[i]];
          }
          for (int i = x; i > 1; i /= minp[i]) {
            b[minp[i]] = std::max(b[minp[i]], now[minp[i]]);
          }
          self(self, v, u, d * y * mint(x).inv());
          for (int i = x; i > 1; i /= minp[i]) {
            --now[minp[i]];
          }
          for (int i = y; i > 1; i /= minp[i]) {
            ++now[minp[i]];
          }
        }
      }
    };

    dfs(dfs, 0, -1, 1);
    for (int i = 1; i <= n; ++i) {
      ans *= mint(i).pow(b[i]);
    }
    std::cout << ans << "\n";
  }
}