#include <bits/stdc++.h>

using namespace std;


template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}

template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;

  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }

  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }

  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }

  Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
  Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
  template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
  template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) { Modular result(*this); *this += 1; return result; }
  Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
  Modular operator-() const { return Modular(-value); }

  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
#ifdef _WIN32
    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
    asm(
      "divl %4; \n\t"
      : "=a" (d), "=d" (m)
      : "d" (xh), "a" (xl), "r" (mod())
    );
    value = m;
#else
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type& operator*=(const Modular& rhs) {
    int64_t q = static_cast<int64_t>(static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }

  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename U>
  friend std::istream& operator>>(std::istream& stream, Modular<U>& number);

 private:
  Type value;
};

template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }

template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }

template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }

template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }

template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }

template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}


template <typename T>
std::ostream& operator<<(std::ostream& stream, const Modular<T>& number) {
  return stream << number();
}

template <typename T>
std::istream& operator>>(std::istream& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, int64_t>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}

constexpr int md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

const int N = (int) 5e5 + 7;
int n, q, dig[N], cnt[100], c4[4 * N];

struct T {
  int l;
  int r;
  Mint dp1;
  Mint dp2;
  Mint dp3;
  Mint dp4;
};

int f(int x, int y) {
  if (x != 1) {
    return 0;
  } else {
    return cnt[10 * x + y];
  }
}

T et;

T operator + (T a, T b) {
  if (a.l == -1) {
    return b;
  }
  if (b.l == -1) {
    return a;
  }
  int l = a.l;
  int r = b.r;
  Mint dp1;
  Mint dp2;
  Mint dp3;
  Mint dp4;
  if (r - l + 1 == 2) {
    int x = dig[l];
    int y = dig[r];
    dp1 = f(x, y) + cnt[x] * cnt[y];
    dp2 = cnt[x];
    dp3 = cnt[y];
    dp4 = 1;
  }
  if (r - l + 1 == 3) {
    int x = dig[l];
    int y = dig[l + 1];
    int z = dig[l + 2];
    dp1 = cnt[x] * cnt[y] * cnt[z] + f(x, y) * cnt[z] + cnt[x] * f(y, z);
    dp2 = f(x, y) + cnt[x] * cnt[y];
    dp3 = f(y, z) + cnt[y] * cnt[z];
    dp4 = cnt[y];
  }
  if (r - l + 1 > 3) {
    int middle = f(dig[a.r], dig[b.l]);
    dp1 = a.dp1 * b.dp1 + a.dp2 * middle * b.dp3;
    dp2 = a.dp1 * b.dp2 + a.dp2 * middle * b.dp4;
    dp3 = a.dp3 * b.dp1 + a.dp4 * middle * b.dp3;
    dp4 = a.dp3 * b.dp2 + a.dp4 * middle * b.dp4;
  }
  return {l, r, dp1, dp2, dp3, dp4};
}

T t[4 * N];

void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = {tl, tr, cnt[dig[tl]], 1, 1, 1};
    c4[v] = (dig[tl] == 0);
    return;
  }
  int tm = (tl + tr) / 2;
  build(2 * v, tl, tm);
  build(2 * v + 1, tm + 1, tr);
  t[v] = t[2 * v] + t[2 * v + 1];
  c4[v] = c4[2 * v] + c4[2 * v + 1];
}

void upd(int v, int tl, int tr, int i) {
  if (tr < i || i < tl) {
    return;
  }
  if (tl == tr) {
    t[v] = {tl, tr, cnt[dig[tl]], 1, 1, 1};
    c4[v] = (dig[tl] == 0);
    return;
  }
  int tm = (tl + tr) / 2;
  upd(2 * v, tl, tm, i);
  upd(2 * v + 1, tm + 1, tr, i);
  t[v] = t[2 * v] + t[2 * v + 1];
  c4[v] = c4[2 * v] + c4[2 * v + 1];
}

void build() {
  build(1, 1, n);
}

void upd(int i, int x) {
  dig[i] = x;
  upd(1, 1, n, i);
}

T get(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) {
    return et;
  }
  if (l <= tl && tr <= r) {
    return t[v];
  }
  int tm = (tl + tr) / 2;
  T a = get(2 * v, tl, tm, l, r);
  T b = get(2 * v + 1, tm + 1, tr, l, r);
  return a + b;
}

Mint get(int l, int r) {
  return get(1, 1, n, l, r).dp1;
}

int fffpos(int v, int tl, int tr) {
  if (c4[v] == 0) {
    return tl;
  }
  if (c4[v] == tr - tl + 1) {
    return -1;
  }
  int tm = (tl + tr) / 2;
  int sol = fffpos(2 * v, tl, tm);
  if (sol == -1) {
    sol = fffpos(2 * v + 1, tm + 1, tr);
  }
  return sol;
}

Mint get() {
  int j = fffpos(1, 1, n);
  if (j == -1) {
    return 1;
  }
  return get(j, n);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i <= 9; i++) {
    for (int j = 0; j <= 9; j++) {
      cnt[i + j]++;
    }
  }
  et.l = -1;
  string str;
  cin >> n >> q >> str;
  for (int i = 1; i <= n; i++) {
    dig[i] = str[i - 1] - '0';
  }
  build();
  for (int it = 1; it <= q; it++) {
    int i, x;
    cin >> i >> x;
    upd(i, x);
    cout << get() << "\n";
  }
  return 0;
}