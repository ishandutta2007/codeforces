//Timestamp: 2022-12-03 20:18:48
#define DROP
#ifndef LOCAL
#undef _GLIBCXX_DEBUG
#undef _DEBUG
#endif
#include <cassert>
#include <cmath>
#include <cstring>
#include <deque>
#include <fstream>
//#include <ext/pb_ds/assoc_container.hpp>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <tuple>
#include <type_traits>
#include <chrono>
#include <random>
#include <complex>
#include <bitset>
#include <set>
#include <list>
#include <array>
//#include "compiler_hint.cpp"
template <class T, int S>
struct MDVecDef {
  using Type = std::vector<typename MDVecDef<T, S - 1>::Type>;
};
template <class T>
struct MDVecDef<T, 0> {
  using Type = T;
};
template <class T, int S = 1>
using MDVec = typename MDVecDef<T, S>::Type;
#ifndef M_PI
#define M_PI 3.14159265358979323851280895940618620443274267017841L
#endif
#ifndef M_E
#define M_E 2.718281828459045235428168107993940338928950950503355L
#endif
#ifdef LOCAL
#define Assert(x) assert(x)
#define DebugRun(X) X
#define DebugPoint int x = 0; x++;
#else
#define Debug(...) 42
#define DebugFmtln(...) 42
#define Assert(x) 42
#define DebugRun(X)
#define DebugPoint
#endif
#define Line(x) DebugFmtln("Line %d: %s", __LINE__, #x)
template<class T>
inline T DebugRet(T x) {
    Debug(x);
    return x;
}
#define const_ref(T) const T &
#define mut_ref(T) T &
#define let auto
#define var auto
#define Size(T) int((T).size())
#define All(data) data.begin(), data.end()
#define MakeUnique(data) data.resize(std::unique(All(data)) - data.begin())
#define MakeUniqueAndSort(data) Sort(All(data)); MakeUnique(data) 
#define MakeAttribute(struct_name, Type, attr_name)               \
  struct struct_name {                                            \
    using attr_name ## _type = Type;                              \
    Type attr_name;                                               \
    mut_ref(Type) get_##attr_name() { return attr_name; }         \
    const_ref(Type) get_##attr_name() const { return attr_name; } \
  };
#define MakeTemplateAttribute(struct_name, attr_name)          \
  template <class T>                                           \
  struct struct_name {                                         \
    using attr_name##_type = T;                             \
    T attr_name;                                               \
    mut_ref(T) get_##attr_name() { return attr_name; }         \
    const_ref(T) get_##attr_name() const { return attr_name; } \
  };
#define ImplDefaultEq(name)                        \
  bool operator==(const name &a, const name &b) {  \
    return std::memcmp(&a, &b, sizeof(name)) == 0; \
  }                                                \
  bool operator!=(const name &a, const name &b) { return !(a == b); }
#define ImplDefaultComparision(name)                                \
  bool operator>(const name &rhs) const { return rhs < *this; }     \
  bool operator<=(const name &rhs) const { return !(*this > rhs); } \
  bool operator>=(const name &rhs) const { return !(*this < rhs); }
#define ImplArithmeticAssignOperation(name)                                 \
  name &operator+=(const name &rhs) { return *this = (*this) + rhs; } \
  name &operator-=(const name &rhs) { return *this = (*this) - rhs; } \
  name &operator*=(const name &rhs) { return *this = (*this) * rhs; } \
  name &operator/=(const name &rhs) { return *this = (*this) / rhs; }
#define IsType(Type, param, ret_type)                                        \
  template <typename OnlyWhenArg = param>                                    \
  enable_if_t<is_same_v<OnlyWhenArg, param> && is_same_v<OnlyWhenArg, Type>, \
              ret_type>
#define IsBool(param, ret_type)       \
  template <bool OnlyWhenArg = param> \
  enable_if_t<OnlyWhenArg == (param) && OnlyWhenArg, ret_type>
#define IsBoolStatic(param, ret_type) \
  template <bool OnlyWhenArg = param> \
  static enable_if_t<OnlyWhenArg == (param) && OnlyWhenArg, ret_type>
#define MakeAnnotation(name)         \
  template <class T>                 \
  struct is_##name {                 \
    static const bool value = false; \
  };                                 \
  template <class T>                 \
  inline constexpr bool is_##name##_v = is_##name<T>::value;
#define AssignAnnotation(cls, annotation) \
  template <>                             \
  struct is_##annotation<cls> {           \
    static const bool value = true;       \
  };
#define AssignAnnotationTemplate(cls, annotation, type) \
  template <type T>                                     \
  struct is_##annotation<cls<T>> {                      \
    static const bool value = true;                     \
  };
#define FunctionAlias(from, to)                       \
  template <typename... Args>                         \
  inline auto to(Args &&...args)                      \
      ->decltype(from(std::forward<Args>(args)...)) { \
    return from(std::forward<Args>(args)...);         \
  }
#define CastToScalar(field, type) \
  operator type() const { return type(field); }
#define CastToAllScalar(field) \
  CastToScalar(field, i8);     \
  CastToScalar(field, u8);     \
  CastToScalar(field, i16);    \
  CastToScalar(field, u16);    \
  CastToScalar(field, i32);    \
  CastToScalar(field, u32);    \
  CastToScalar(field, i64);    \
  CastToScalar(field, u64);    \
  CastToScalar(field, f32);    \
  CastToScalar(field, f64);    \
  CastToScalar(field, f80);
#define COMMA ,
#ifndef LOCAL
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#else
std::mt19937 rng(0);
#endif
template <class T> T random_choice(T l, T r, std::mt19937 &gen = rng) {
  std::uniform_int_distribution<T> random(l, r);
  return random(gen);
}
namespace dalt {
#ifndef LOCAL
struct Timer {explicit Timer(const char* m) {}void stop() const {}};
#else
#endif
}
using i8 = char;
using i16 = short;
using i32 = int;
using i64 = long long;
using u8 = unsigned char;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = unsigned long long;
using usize = size_t;
using f32 = float;
using f64 = double;
// 16 exp, 64 precision
using f80 = long double;
FunctionAlias(std::lower_bound, LowerBound);
FunctionAlias(std::upper_bound, UpperBound);
FunctionAlias(std::unique, Unique);
FunctionAlias(std::swap, Swap);
FunctionAlias(std::min, Min);
FunctionAlias(std::max, Max);
FunctionAlias(std::abs, Abs);
FunctionAlias(std::sin, Sin);
FunctionAlias(std::asin, Asin);
FunctionAlias(std::cos, Cos);
FunctionAlias(std::acos, Acos);
FunctionAlias(std::tan, Tan);
FunctionAlias(std::atan, Atan);
FunctionAlias(std::sort, Sort);
FunctionAlias(std::fill, Fill);
FunctionAlias(std::move, Move);
FunctionAlias(std::reverse, Reverse);
FunctionAlias(std::max_element, MaxElement);
FunctionAlias(std::min_element, MinElement);
FunctionAlias(std::make_tuple, MakeTuple);
FunctionAlias(std::make_pair, MakePair);
FunctionAlias(std::clamp, Clamp);
FunctionAlias(std::shuffle, Shuffle);
FunctionAlias(std::to_string, ToString);
FunctionAlias(std::tie, Tie);
template <typename _Signature>
using Function = std::function<_Signature>;
using Str = std::string;
using String = Str;
using StringStream = std::stringstream;
using IStream = std::istream;
using OStream = std::ostream;
using std::enable_if;
using std::enable_if_t;
using std::is_base_of;
using std::is_base_of_v;
using std::is_floating_point;
using std::is_floating_point_v;
using std::is_integral;
using std::is_integral_v;
using std::is_arithmetic;
using std::is_arithmetic_v;
using std::is_same;
using std::is_same_v;
auto &Stderr = std::cerr;
auto &Stdin = std::cin;
auto &Stdout = std::cout;
template <class T>
using Less = std::less<T>;
template <class T>
using Greater = std::greater<T>;
template <typename _Key, typename _Tp, typename _Compare = Less<_Key>>
using TreeMap = std::map<_Key, _Tp, _Compare>;
template <typename _Key, typename _Compare = Less<_Key>>
using TreeSet = std::set<_Key, _Compare>;
template <typename _Key, typename _Compare = std::less<_Key>,
          typename _Alloc = std::allocator<_Key>>
using MultiTreeSet = std::multiset<_Key, _Compare, _Alloc>;
template <class T>
using Deque = std::deque<T>;
template <class T>
using Queue = std::queue<T>;
template <class T>
using Vec = std::vector<T>;
template <class T>
using Reducer = Function<T(const T &, const T &)>;
template <class T>
using Comparator = Function<bool(const T &, const T &)>;
template <class T>
using Indexer = Function<T(i32)>;
template <class T>
using Indexer2 = Function<T(i32, i32)>;
template <class A, class B = A, class C = A>
using Adder = Function<C(const A &, const B &)>;
template <class I>
using Checker = Function<bool(const I &)>;
template <class A, class B>
using BiChecker = Function<bool(const A &, const B &)>;
template <class T>
using Consumer = Function<void(const T &)>;
template<class T>
using Supplier = Function<T()>;
template <class FIRST, class SECOND>
using BiConsumer = Function<void(const FIRST &, const SECOND &)>;
template <class F, class T = F>
using Mapper = Function<T(const F &)>;
template <class T>
using MinHeap = std::priority_queue<T, Vec<T>, Greater<T>>;
template <class T>
using MaxHeap = std::priority_queue<T, Vec<T>, Less<T>>;
template <class T, usize S>
using Array = std::array<T, S>;
template <typename... _Elements>
using Tuple = std::tuple<_Elements...>;
template <class T, class = enable_if_t<is_floating_point_v<T>>>
using Complex = std::complex<T>;
template <class A, class B>
using Pair = std::pair<A, B>;
namespace dalt {
template <class T>
IStream& operator>>(IStream& is, Vec<T>& val) {
  for (auto& v : val) {
    is >> v;
  }
  return is;
}
#define VEC_OP(op)                         \
  template <class T>                       \
  Vec<T>& operator op(Vec<T>& data, T x) { \
    for (auto& v : data) {                 \
      v op x;                              \
    }                                      \
    return data;                           \
  }
VEC_OP(+=)
VEC_OP(-=)
VEC_OP(*=)
VEC_OP(/=)
VEC_OP(%=)
VEC_OP(^=)
VEC_OP(&=)
VEC_OP(|=)
VEC_OP(==)
VEC_OP(!=)
template <class T>
int Compare(const Vec<T>& lhs, const Vec<T>& rhs) {
  for(int i = 0; i < Size(lhs) && i < Size(rhs); i++) {
    if(lhs[i] != rhs[i]) {
      return lhs[i] < rhs[i] ? -1 : 1;
    }
  }
  return Size(lhs) < Size(rhs) ? -1 : Size(lhs) > Size(rhs) ? 1 : 0;
}
}  // namespace dalt
//#include "array_adder.cpp"
using namespace dalt;
namespace dalt {
template <class T>
struct Optional {
  using Self = Optional<T>;
 private:
  T val;
  bool show_up;
 public:
  Optional(const T &arg_val) : val(arg_val), show_up(true) {}
  Optional(const T &&arg_val) : val(arg_val), show_up(true) {}
  Optional() : show_up(false) {}
  const T &value() const {
    Assert(show_up);
    return val;
  }
  T &value() {
    Assert(show_up);
    return val;
  }
  T &operator*() { return value(); }
  const T &operator*() const { return value(); }
  bool is_some() const { return show_up; }
  bool is_none() const { return !show_up; }
  const T *operator->() const {
    return &value();
  }
  T *operator->() { return &value(); }
  inline operator T() const { return value(); }
  T or_else(T def) const {
    if (is_some()) {
      return val;
    } else {
      return def;
    }
  }
  template <class E>
  Optional<E> map(const Mapper<T, E> &mapper) const {
    if (is_some()) {
      return mapper(value());
    } else {
      return Optional<E>();
    }
  }
  bool operator==(const Self &b) const {
    return show_up == b.show_up && (!show_up || val == b.val);
  }
};
template <class E>
bool operator!=(const Optional<E> &a, const Optional<E> &b) {
  return !(a == b);
}
template <class E>
OStream &operator<<(OStream &os, const Optional<E> &v) {
  if (v.is_none()) {
    os << "{}";
  } else {
    os << '{' << v.value() << '}';
  }
  return os;
}
}  // namespace dalt
namespace dalt {
template <class T>
inline enable_if_t<is_integral_v<T>, T> Gcd(T a, T b) {
  while (b != 0) {
    a %= b;
    Swap(a, b);
  }
  return a;
}
// ret_value = [x, y, gcd(a,b)] that x * a + y * b = gcd(a, b)
template <class T>
inline enable_if_t<is_integral_v<T>, Array<T, 3>> ExtGcd(T a, T b) {
  if (b == 0) {
    return Array<T, 3>{1, 0, a};
  }
  auto div = a / b;
  auto ans = ExtGcd(b, a - b * div);
  auto x = ans[0];
  auto y = ans[1];
  return Array<T, 3>{y, x - a / b * y, ans[2]};
}
template <class T>
inline enable_if_t<is_integral_v<T>, Optional<T>> PossibleModInverse(
    T a, T modulus) {
  auto res = ExtGcd(a, modulus);
  if (res[2] == 1) {
    auto ans = res[0] % modulus;
    if (ans < 0) {
      ans += modulus;
    }
    return ans;
  }
  return {};
}
}  // namespace dalt
namespace dalt {
template <class T, class E>
T Modular(E val, T mod) {
  val = val % mod;
  if (val < 0) {
    val = val + mod;
  }
  return T(val);
}
template<class T>
inline T MulMod(T a, T b, T modulus) {
  i64 res = i64(a) * i64(b) % modulus;
  return T(res);
}
template<>
inline i64 MulMod<i64>(i64 a, i64 b, i64 modulus) {
  i64 k = roundl((f80)a / modulus * b);
  i64 res = (a * b - k * modulus) % modulus;
  if (res < 0) {
    res += modulus;
  }
  return res;
}
template <class T>
inline enable_if_t<is_integral_v<T>, T> AddMod(T a, T b, T modulus) {
  T res = a + b;
  if (res >= modulus) {
    res -= modulus;
  }
  return res;
}
template <class T, class E>
inline enable_if_t<is_integral_v<T> && is_integral_v<E>, T> PowMod(T x, E exp,
                                                                   T modulus) {
   Assert(exp >= E(0));                                                          
  if (exp == E(0)) {
    return modulus == T(1) ? T(0) : T(1);
  }
  T ans = PowMod(x, exp >> 1, modulus);
  ans = MulMod(ans, ans, modulus);
  if (exp & T(1)) {
    ans = MulMod(ans, x, modulus);
  }
  return ans;
}
template <class T>
inline enable_if_t<is_integral_v<T>, T> SubMod(T a, T b, T modulus) {
  T res = a - b;
  if (res < T(0)) {
    res += modulus;
  }
  return res;
}
}  // namespace dalt
namespace dalt {
template <class T>
inline T& Chmin(T& a, const T& b) {
  if (a > b) {
    a = b;
  }
  return a;
}
template <class T>
inline T& Chmin(T& a, const T& b, const Comparator<T> &comp) {
  if (comp(b, a)) {
    a = b;
  }
  return a;
}
template <class T>
inline T& Chmax(T& a, const T& b) {
  if (a < b) {
    a = b;
  }
  return a;
}
template <class T>
inline T& Chmax(T& a, const T& b, const Comparator<T>& comp) {
  if (comp(a, b)) {
    a = b;
  }
  return a;
}
template <class T>
inline T& AddTo(T& a, const T& b) {
  a = a + b;
  return a;
}
template <class T>
inline T& MulTo(T& a, const T& b) {
  a = a * b;
  return a;
}
template <class T>
inline T& SubFrom(T& a, const T& b) {
  a = a - b;
  return a;
}
template <class T>
inline T& DivFrom(T& a, const T& b) {
  a = a / b;
  return a;
}
template <class T, class E>
constexpr enable_if_t<is_integral_v<E>, T> PowBinaryLift(T x, E n) {
  if (n == E(0)) {
    return T(1);
  }
  auto ans = PowBinaryLift(x, n >> 1);
  ans = ans * ans;
  if (n & 1) {
    ans = ans * x;
  }
  return ans;
}
template <class T>
inline T MulLimit(T a, T b, T max, T def) {
  if (a == T(0) || b == T(0)) {
    return T(0);
  }
  // a * b <= max
  // a <= max / b
  // a <= floor(max / b)
  if (a <= max / b) {
    return a * b;
  } else {
    return def;
  }
}
template <class T>
inline T MulLimit(T a, T b, T max) {
  return MulLimit(a, b, max, max);
}
template <class T>
inline T AddLimit(T a, T b, T max, T def) {
  if (a <= max - b) {
    return a + b;
  } else {
    return def;
  }
}
template <class T>
inline T AddLimit(T a, T b, T max) {
  return AddLimit(a, b, max, max);
}
i64 Round(f32 x) { return roundf(x); }
i64 Round(f64 x) { return round(x); }
i64 Round(f80 x) { return roundl(x); }
//l + ... + r
template<class T>
T SumOfInterval(T l, T r) {
  if(l > r) {
    return T(0);
  }
  return (l + r) * (r - l + 1) / T(2);
}
template<class T>
T Pow2(T x) {
  return x * x;
}
}  // namespace dalt
namespace dalt {
// using Type = T;
// static T modulus;
// static T primitive_root;
MakeAnnotation(modular);
template <class T, i64 M, i64 PR = -1, i64 PHI = M - 1>
struct StaticModular {
  static_assert(is_integral_v<T>);
  const static T modulus = M;
  const static T primitive_root = PR;
  const static T phi = PHI;
  using Type = T;
};
template <class T, i64 M, i64 PR, i64 PHI>
struct is_modular<StaticModular<T, M, PR, PHI>> {
  static const bool value = true;
};
using MOD998244353 =
    StaticModular<i32, 998244353, 3>;
using MOD1000000007 = StaticModular<i32, 1000000007, 5>;
using MOD1000000009 = StaticModular<i32, 1000000009, 13>;
using MOD_BIG = StaticModular<i64, 2305843009213693951, -1>;
// last used: -2
template <class T = i32, i64 CID = 0, i64 ID = 0>
struct DynamicModular {
  static_assert(is_integral_v<T>);
  static T modulus;
  static T primitive_root;
  static T phi;
  static void Register(T _modulus, T _primitive_root = T(), T _phi = T()) {
    modulus = _modulus;
    primitive_root = _primitive_root;
    phi = _phi;
  }
  using Type = T;
};
template <class T, i64 CID, i64 ID>
T DynamicModular<T, CID, ID>::modulus = T();
template <class T, i64 CID, i64 ID>
T DynamicModular<T, CID, ID>::primitive_root = T();
template <class T, i64 CID, i64 ID>
T DynamicModular<T, CID, ID>::phi = T();
template <class T, i64 CID, i64 ID>
struct is_modular<DynamicModular<T, CID, ID>> {
  static const bool value = true;
};
MakeAnnotation(modint);
#define MOD MODULAR::modulus
#define SELF ModInt<MODULAR>
#define TEMPLATE_ARGS template <class MODULAR>
TEMPLATE_ARGS struct ModInt {
  using Modular = MODULAR;
  using Type = typename MODULAR::Type;
  static_assert(is_modular_v<MODULAR>);
  static_assert(is_integral_v<Type>);
  Type value;
  using Self = SELF;
  ModInt() : value(0) {}
  ModInt(const Type &v) {
    value = v;
    if (value < 0 || value >= MOD) {
      value %= MOD;
      if (value < 0) {
        value += MOD;
      }
    }
    Assert(value >= 0);
  }
  static Self nil() {
    Self res;
    res.value = -1;
    return res;
  }
  bool is_nil() {
    return value == -1;
  }
  explicit operator Type() const { return value; }
  static Type modulus() { return MOD; }
  static Type primitive_root() { return Modular::primitive_root; }
  Self operator-() const { return Self(0) - *this; }
  template <class F>
  static enable_if_t<is_integral_v<F>, Self> of(F v) {
    v %= MOD;
    if (v < 0) {
      v += MOD;
    }
    return Self(v);
  }
  Optional<Self> possible_inv() const {
    auto raw_optional_inv = PossibleModInverse(value, MOD);
    if (raw_optional_inv.is_some()) {
      return Self(raw_optional_inv.value());
    } else {
      return {};
    }
  }
  Self operator+(const Self &rhs) const {
    auto res = value + rhs.value;
    if (res >= MOD) {
      res -= MOD;
    }
    return res;
  }
  Self operator-(const Self &rhs) const {
    auto res = value - rhs.value;
    if (res < Type(0)) {
      res += MOD;
    }
    return res;
  }
  Self operator/(const SELF &rhs) const {
    auto inv = Self(rhs.possible_inv().value());
    return (*this) * inv;
  }
  bool operator==(const Self &b) const { return value == b.value; }
  bool operator!=(const Self &b) const { return value != b.value; }
  bool operator<(const Self &b) const { return value < b.value; }
  ImplDefaultComparision(Self);
  ImplArithmeticAssignOperation(Self);
  template <class E>
  enable_if_t<is_integral_v<E>, Self> pow(E n) {
    return PowBinaryLift(*this, n);
  }
  friend inline IStream &operator>>(IStream &is, Self &x) {
    Type val;
    is >> val;
    x = Self(val);
    return is;
  }
  friend inline OStream &operator<<(OStream &os, const Self &x) {
    os << x.value;
    return os;
  }
};
TEMPLATE_ARGS inline enable_if_t<!is_same_v<MODULAR, MOD_BIG>, SELF> operator*(
    const SELF &a, const SELF &b) {
  return SELF(MulMod(a.value, b.value, MOD));
}
TEMPLATE_ARGS inline enable_if_t<is_same_v<MODULAR, MOD_BIG>, SELF> operator*(
    const SELF &x, const SELF &y) {
  static u64 mask = (u64(1) << 32) - 1;
  static u64 mod = MOD_BIG::modulus;
  u64 a = x.value;
  u64 b = y.value;
  u64 l1 = a & mask;
  u64 h1 = (a >> 32) & mask;
  u64 l2 = b & mask;
  u64 h2 = (b >> 32) & mask;
  u64 l = l1 * l2;
  u64 m = l1 * h2 + l2 * h1;
  u64 h = h1 * h2;
  u64 ret = (l & mod) + (l >> 61) + (h << 3) + (m >> 29) + ((m << 35) >> 3) + 1;
  ret = (ret & mod) + (ret >> 61);
  ret = (ret & mod) + (ret >> 61);
  return SELF(ret - 1);
}
TEMPLATE_ARGS struct is_modint<ModInt<MODULAR>> {
  static const bool value = true;
};
#undef TEMPLATE_TYPE
#undef MOD
using ModInt998244353 = ModInt<MOD998244353>;
using ModInt1000000007 = ModInt<MOD1000000007>;
using ModInt1000000009 = ModInt<MOD1000000009>;
}  // namespace dalt
using Mi = ModInt998244353;
#ifndef _builtin_clz
inline i32 _builtin_clz(u32 i) {
  // HD, Count leading 0's
  if (i <= 0) return i == 0 ? 32 : 0;
  int n = 31;
  if (i >= 1 << 16) {
    n -= 16;
    i >>= 16;
  }
  if (i >= 1 << 8) {
    n -= 8;
    i >>= 8;
  }
  if (i >= 1 << 4) {
    n -= 4;
    i >>= 4;
  }
  if (i >= 1 << 2) {
    n -= 2;
    i >>= 2;
  }
  return n - (i >> 1);
}
#endif
#ifndef _builtin_clzll
inline i32 _builtin_clzll(u64 i) {
  u32 x = u32(i >> 32);
  return x == 0 ? 32 + _builtin_clz((int)i) : _builtin_clz(x);
}
#endif
#ifndef _builtin_ctz
inline i32 _builtin_ctz(u32 i) {
  // HD, Figure 5-14
  int y;
  if (i == 0) return 32;
  int n = 31;
  y = i << 16;
  if (y != 0) {
    n = n - 16;
    i = y;
  }
  y = i << 8;
  if (y != 0) {
    n = n - 8;
    i = y;
  }
  y = i << 4;
  if (y != 0) {
    n = n - 4;
    i = y;
  }
  y = i << 2;
  if (y != 0) {
    n = n - 2;
    i = y;
  }
  return n - ((i << 1) >> 31);
}
#endif
#ifndef _builtin_ctzll
inline i32 _builtin_ctzll(u64 i) {
  // HD, Figure 5-14
  int x, y;
  if (i == 0) return 64;
  int n = 63;
  y = (int)i;
  if (y != 0) {
    n = n - 32;
    x = y;
  } else
    x = (int)(i >> 32);
  y = x << 16;
  if (y != 0) {
    n = n - 16;
    x = y;
  }
  y = x << 8;
  if (y != 0) {
    n = n - 8;
    x = y;
  }
  y = x << 4;
  if (y != 0) {
    n = n - 4;
    x = y;
  }
  y = x << 2;
  if (y != 0) {
    n = n - 2;
    x = y;
  }
  return n - ((x << 1) >> 31);
}
#endif
#ifndef _builtin_popcount
inline i32 _builtin_popcount(u32 i) {
  // HD, Figure 5-2
  i = i - ((i >> 1) & 0x55555555);
  i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
  i = (i + (i >> 4)) & 0x0f0f0f0f;
  i = i + (i >> 8);
  i = i + (i >> 16);
  return i & 0x3f;
}
#endif
#ifndef _builtin_popcountll
inline i32 _builtin_popcountll(u64 i) {
  // HD, Figure 5-2
  i = i - ((i >> 1) & 0x5555555555555555ll);
  i = (i & 0x3333333333333333ll) + ((i >> 2) & 0x3333333333333333ll);
  i = (i + (i >> 4)) & 0x0f0f0f0f0f0f0f0fll;
  i = i + (i >> 8);
  i = i + (i >> 16);
  i = i + (i >> 32);
  return (int)i & 0x7f;
}
#endif
namespace dalt {
inline i32 LeadingZeroNumber(u32 x) {
  if (x == 0) return 32;
  return _builtin_clz(x);
}
inline i32 LeadingZeroNumber(i32 x) { return LeadingZeroNumber(u32(x)); }
inline i32 LeadingZeroNumber(u64 x) {
  if (x == 0) return 64;
  return _builtin_clzll(x);
}
inline i32 LeadingZeroNumber(i64 x) { return LeadingZeroNumber(u64(x)); }
inline i32 TrailingZeroNumber(u32 x) {
  if (x == 0) return 32;
  return _builtin_ctz(x);
}
inline i32 TrailingZeroNumber(i32 x) { return TrailingZeroNumber(u32(x)); }
inline i32 TrailingZeroNumber(u64 x) {
  if (x == 0) return 64;
  return _builtin_ctzll(x);
}
inline i32 TrailingZeroNumber(i64 x) { return TrailingZeroNumber(u64(x)); }
inline i32 Log2Ceil(u32 x) {
  if (x == 0) {
    return 0;
  }
  return 32 - LeadingZeroNumber(x - 1);
}
inline i32 Log2Ceil(u64 x) {
  if (x == 0) {
    return 0;
  }
  return 64 - LeadingZeroNumber(x - 1);
}
inline i32 Log2Floor(u32 x) {
  if (x == 0) {
    return -1;
  }
  return 31 - LeadingZeroNumber(x);
}
inline i32 Log2Floor(u64 x) {
  if (x == 0) {
    return -1;
  }
  return 63 - LeadingZeroNumber(x);
}
inline i32 Log2Ceil(i32 x) { return Log2Ceil(u32(x)); }
inline i32 Log2Ceil(i64 x) { return Log2Ceil(u64(x)); }
inline i32 Log2Floor(i32 x) { return Log2Floor(u32(x)); }
inline i32 Log2Floor(i64 x) { return Log2Floor(u64(x)); }
inline i32 CountBit(u32 x) { return _builtin_popcount(x); }
inline i32 CountBit(i32 x) { return CountBit(u32(x)); }
inline i32 CountBit(u64 x) { return _builtin_popcountll(x); }
inline i32 CountBit(i64 x) { return CountBit(u64(x)); }
inline i32 HighestOneBitOffset(u32 x) { return Log2Floor(x); }
inline i32 HighestOneBitOffset(i32 x) { return HighestOneBitOffset(u32(x)); }
inline i32 HighestOneBitOffset(u64 x) { return Log2Floor(x); }
inline i32 HighestOneBitOffset(i64 x) { return HighestOneBitOffset(u64(x)); }
template <class T>
inline enable_if_t<is_integral_v<T>, T> LowestOneBit(T x) {
  return x & -x;
}
template <class T>
inline enable_if_t<is_integral_v<T>, T> HighestOneBit(T x) {
  if (x == 0) {
    return x;
  }
  return T(1) << HighestOneBitOffset(x);
}
template <class T>
inline enable_if_t<is_integral_v<T>, i32> LowestOneBitOffset(T x) {
  if (x == 0) {
    return -1;
  }
  return HighestOneBitOffset(LowestOneBit(x));
}
inline u32 HighestKOnes32(i32 k) {
  if (k == 0) {
    return 0;
  }
  return (~u32()) << (32 - k);
}
inline u64 HighestKOnes64(i32 k) {
  if (k == 0) {
    return 0;
  }
  return (~u64()) << (64 - k);
}
inline u32 LowestKOnes32(i32 k) {
  if (k == 0) {
    return 0;
  }
  return (~u32()) >> (32 - k);
}
inline u64 LowestKOnes64(i32 k) {
  if (k == 0) {
    return 0;
  }
  return (~u64()) >> (64 - k);
}
inline u64 IntervalOnes64(i32 l, i32 r) {
  if (l > r) {
    return 0;
  }
  u64 high = r < 63 ? (u64(-1) << r + 1) : 0;
  u64 low = u64(-1) << l;
  return high ^ low;
}
inline u32 IntervalOnes32(i32 l, i32 r) {
  if (l > r) {
    return 0;
  }
  u32 high = r < 31 ? (u32(-1) << r + 1) : 0;
  u32 low = u32(-1) << l;
  return high ^ low;
}
template <class T>
inline enable_if_t<is_integral_v<T>, i32> KthBit(T x, i32 k) {
  return (x >> k) & 1;
}
template <class T>
inline enable_if_t<is_integral_v<T>, T> SetBit(T x, i32 k) {
  return x | (T(1) << k);
}
template <class T>
inline enable_if_t<is_integral_v<T>, T> ClearBit(T x, i32 k) {
  return x & ~(T(1) << k);
}
}  // namespace dalt
void SolveOne(int test_id, IStream &in, OStream &out) {
  Str s;
  in >> s;
  int N = Size(s);
  MDVec<Mi, 3> dp(N, MDVec<Mi, 2>(1 << 3, Vec<Mi>(1 << 3, Mi::nil())));
  var dfs = [&](var &dfs, int offset, int ok, int ceil) -> Mi {
    if(offset >= N) {
      return ok == 7 ? 1 : 0;
    }
    var &ans = dp[offset][ok][ceil];
    if(ans.is_nil()) {
      ans = 0;
      int bit = s[offset] - '0';
      int c0 = KthBit(ceil, 0);
      int c1 = KthBit(ceil, 1);
      int c2 = KthBit(ceil, 2);
      for(int a = 0; a < 2; a++) {
        if(c0 && a > bit) {
          continue;
        }
        for(int b = 0; b < 2; b++) {
          if(c1 && b > bit) {
            continue;
          }
          for(int c = 0; c < 2; c++) {
            if(c2 && c > bit) {
              continue;
            }
            int next_ok = ok;
            if(b == c && b != a) {
              next_ok |= 1 << 0;
            }
            if (a == c && a != b) {
              next_ok |= 1 << 1;
            }
            if(a == b && a != c) {
              next_ok |= 1 << 2;
            }
            int next_ceil = 0;
            if(c0 && a == bit) {
              next_ceil |= 1 << 0;
            }
            if(c1 && b == bit) {
              next_ceil |= 1 << 1;
            }
            if(c2 && c == bit) {
              next_ceil |= 1 << 2;
            }
            ans += dfs(dfs, offset + 1, next_ok, next_ceil);
          }
        }
      }
      DebugFmtln("dp(%d, %d, %d) = %d", offset, ok, ceil, ans);
    }
    return ans;
  };
  var ans = dfs(dfs, 0, 0, 7);
  out << ans << '\n';
}
void SolveMulti(IStream &in, OStream &out) {
  //std::ifstream input("in");
  int num_of_input = 1;
  //in >> num_of_input;
  for (int i = 0; i < num_of_input; i++) {
    //SolveOne(i + 1, input, out);
	SolveOne(i + 1, in, out);
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  Stdin.tie(0);
  Stdout << std::setiosflags(std::ios::fixed);
  Stdout << std::setprecision(15);
#ifdef STRESS
  stress::Stress();
#else
  SolveMulti(Stdin, Stdout);
#endif
  return 0;
}