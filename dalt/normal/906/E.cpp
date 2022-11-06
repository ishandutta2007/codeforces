//Timestamp: 2022-09-18 17:23:24
#define DROP
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
template <class T, i64 M, i64 PR, i64 PHI = M - 1>
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
namespace dalt {
namespace hash {
// https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
inline u64 Shuffle(u64 x) {
  static const uint64_t C = uint64_t(2e18 * M_PI) + 71;  // large odd number
  static const int RANDOM = rng();
  return __builtin_bswap64((x ^ RANDOM) * C);
}
i64 SafeHash(const void *ptr, usize size) {
  using Mi1 = ModInt1000000007;
  using Mi2 = ModInt1000000009;
  static const Mi1 X1 = Mi1(random_choice<i32>(1, Mi1::modulus() - 1));
  static const Mi2 X2 = Mi2(random_choice<i32>(1, Mi2::modulus() - 1));
  Mi1 ans1 = Mi1(size);
  Mi2 ans2 = Mi2(size);
  const char *cur = (const char *)ptr;
  int offset = 0;
  while (size - offset >= 4) {
    i32 v = *(i32 *)(cur + offset);
    ans1 = ans1 * X1 + Mi1(v);
    ans2 = ans2 * X2 + Mi2(v);
    offset += 4;
  }
  if (size - offset >= 2) {
    i32 v = *(i16 *)(cur + offset);
    ans1 = ans1 * X1 + Mi1(v);
    ans2 = ans2 * X2 + Mi2(v);
    offset += 2;
  }
  if (size - offset >= 1) {
    i32 v = *(i8 *)(cur + offset);
    ans1 = ans1 * X1 + Mi1(v);
    ans2 = ans2 * X2 + Mi2(v);
    offset += 1;
  }
  return (i64(ans1.value) << 32) | ans2.value;
}
i64 FastHash(const void *ptr, usize size) {
  static const i64 X = random_choice<i64>(std::numeric_limits<i64>::min(),
                                          std::numeric_limits<i64>::max());
  const char *cur = (const char *)ptr;
  int offset = 0;
  i64 ans = size;
  while (size - offset >= 8) {
    i64 v = *((i64 *)(cur + offset));
    ans = ans * X + v;
    offset += 8;
  }
  if (size - offset >= 4) {
    i64 v = *((i32 *)(cur + offset));
    ans = ans * X + v;
    offset += 4;
  }
  if (size - offset >= 2) {
    i64 v = *((i16 *)(cur + offset));
    ans = ans * X + v;
    offset += 2;
  }
  if (size - offset >= 1) {
    i64 v = *((u8 *)(cur + offset));
    ans = ans * X + v;
    offset += 1;
  }
  return ans;
}
template <class T>
inline i64 Hash(const T &val) {
  return SafeHash(&val, sizeof(T));
}
template <>
inline i64 Hash<i64>(const i64 &val) {
  return val;
}
template <>
inline i64 Hash<i32>(const i32 &val) {
  return val;
}
}  // namespace hash
}  // namespace dalt
namespace dalt {
template <class T> enable_if_t<is_integral_v<T>, T> DivFloor(T a, T b) {
  Assert(b > 0);
  auto ans = a / b;
  if (ans * b > a) {
    ans = ans - 1;
  }
  return ans;
}
template <class T> enable_if_t<is_integral_v<T>, T> DivCeil(T a, T b) {
  Assert(b > 0);
  auto ans = a / b;
  if (ans * b < a) {
    ans = ans + 1;
  }
  return ans;
}
template <class T>
enable_if_t<is_floating_point_v<T>, T> DivFloor(T a, T b) {
  return a / b;
}
template <class T>
enable_if_t<is_floating_point_v<T>, T> DivCeil(T a, T b) {
  return a / b;
}
template <class T>
enable_if_t<is_integral_v<T>, T> SmallerValue(T val) {
  return val - 1;
}
template <class T>
enable_if_t<is_integral_v<T>, T> LargerValue(T val) {
  return val + 1;
}
template <class T>
enable_if_t<is_floating_point_v<T>, T> SmallerValue(T val) {
  return val;
}
template <class T>
enable_if_t<is_floating_point_v<T>, T> LargerValue(T val) {
  return val;
}
} // namespace dalt
namespace dalt {
template <class T>
bool InRange(T l, T r, T x) {
  return l <= x && x <= r;
}
template <class T>
bool InRangeRotate(T l, T r, T x) {
  if (l <= r) {
    return InRange(l, r, x);
  } else {
    return !InRange(LargerValue(r), SmallerValue(l), x);
  }
}
}  // namespace dalt
namespace dalt {
struct Nil {};
Nil operator+(const Nil &a, const Nil &b) { return Nil(); }
Nil operator-(const Nil &a, const Nil &b) { return Nil(); }
Nil operator*(const Nil &a, const Nil &b) { return Nil(); }
Nil operator/(const Nil &a, const Nil &b) { return Nil(); }
bool operator==(const Nil &a, const Nil &b) { return true; }
bool operator!=(const Nil &a, const Nil &b) { return false; }
OStream &operator<<(OStream &os, const Nil &b) {
  os << "{}";
  return os;
}
} // namespace dalt
namespace dalt {
namespace hash {
template <class K, class V = Nil>
struct HashMap {
  using Self = HashMap<K, V>;
 private:
  static const i32 NON_EXIST = 0;
  Vec<Pair<K, V>> entries;
  Vec<i32> hash_val;
  i32 mask;
  i32 size;
  int index_of(const K& key, i32 h) const {
    i32 index = h & mask;
    while (hash_val[index] != NON_EXIST) {
      if (hash_val[index] == h && entries[index].first == key) {
        return index;
      }
      index = (index + 1) & mask;
    }
    return index;
  }
 public:
  struct CIter
      : public std::iterator<std::bidirectional_iterator_tag, Pair<K, V>> {
    const HashMap<K, V>* hm;
    i32 index;
    const Pair<K, V>& operator*() {
      Assert(index < Size(hm->entries));
      Assert(hm->hash_val[index] != NON_EXIST);
      return hm->entries[index];
    }
    const Pair<K, V>* operator->() const {
      return &hm->entries[index];
    }
    CIter& operator++() {
      index++;
      while (index < Size(hm->entries) && hm->hash_val[index] == NON_EXIST) {
        index++;
      }
      return *this;
    }
    CIter operator++(int) {
      auto ans = *this;
      ++(*this);
      return ans;
    }
    CIter& operator--() {
      index--;
      while (index >= 0 && hm->hash_val[index] == NON_EXIST) {
        index--;
      }
      return *this;
    }
    CIter operator--(int) {
      Iter ans = *this;
      --(*this);
    }
    bool operator<(const CIter& rhs) const { return index < rhs.index; }
    bool operator>(const CIter& rhs) const { return index > rhs.index; }
    bool operator==(const CIter& rhs) const { return index == rhs.index; }
    bool operator!=(const CIter& rhs) const { return index != rhs.index; }
  };
  struct Iter
      : public std::iterator<std::bidirectional_iterator_tag, Pair<K, V>> {
    HashMap<K, V>* hm;
    i32 index;
    Pair<K, V>& operator*() {
      Assert(index < Size(hm->entries));
      Assert(hm->hash_val[index] != NON_EXIST);
      return hm->entries[index];
    }
    const Pair<K, V>& operator*() const {
      Assert(index < Size(hm->entries));
      Assert(hm->hash_val[index] != NON_EXIST);
      return hm->entries[index];
    }
    Pair<K, V>* operator->() { return &hm->entries[index]; }
    Iter& operator++() {
      index++;
      while (index < Size(hm->entries) && hm->hash_val[index] == NON_EXIST) {
        index++;
      }
      return *this;
    }
    Iter operator++(int) {
      auto ans = *this;
      ++(*this);
      return ans;
    }
    Iter& operator--() {
      index--;
      while (index >= 0 && hm->hash_val[index] == NON_EXIST) {
        index--;
      }
      return *this;
    }
    Iter operator--(int) {
      Iter ans = *this;
      --(*this);
    }
    bool operator<(const Iter& rhs) { return index < rhs.index; }
    bool operator>(const Iter& rhs) { return index > rhs.index; }
    bool operator==(const Iter& rhs) { return index == rhs.index; }
    bool operator!=(const Iter& rhs) { return index != rhs.index; }
  };
  void recap(i32 cap) {
    cap = Max(cap, 2);
    decltype(entries) old_entry(cap);
    decltype(hash_val) old_hash_val(cap);
    entries.swap(old_entry);
    hash_val.swap(old_hash_val);
    mask = cap - 1;
    size = 0;
    for (int i = 0; i < Size(old_entry); i++) {
      if (old_hash_val[i] != NON_EXIST) {
        put(Move(old_entry[i]), old_hash_val[i]);
      }
    }
  }
  bool contain(const K& key) const {
    return find(key) != end();
  }
  i32 get_hash(i64 hash) const {
    hash = Shuffle(hash);
    if (hash == NON_EXIST) {
      hash = -1;
    }
    return hash;
  }
  bool check_health() {
    if (size * 2 > Size(entries)) {
      recap(Size(entries) * 2);
      return true;
    }
    return false;
  }
  void put(Pair<K, V> kv, i32 hash) {
    auto& key = kv.first;
    i32 pos = index_of(kv.first, hash);
    if (hash_val[pos] == NON_EXIST) {
      size++;
    }
    entries[pos] = Move(kv);
    hash_val[pos] = hash;
    check_health();
  }
 public:
  HashMap(i32 cap = 1) : size(0) {
    cap = 1 << Log2Ceil(cap);
    recap(cap * 2);
  }
  void put(Pair<K, V> kv) { put(Move(kv), get_hash(Hash(kv.first))); }
  void put(K key, V value) { put(Pair<K, V>(Move(key), Move(value))); }
  Iter find(const K& key) {
    i32 hash = get_hash(Hash(key));
    i32 pos = index_of(key, hash);
    if (hash_val[pos] != NON_EXIST) {
      return Iter{
          .hm = this,
          .index = pos,
      };
    }
    return end();
  }
  CIter find(const K& key) const {
    i32 hash = get_hash(Hash(key));
    i32 pos = index_of(key, hash);
    if (hash_val[pos] != NON_EXIST) {
      return CIter{
          .hm = this,
          .index = pos,
      };
    }
    return end();
    return end();
  }
  V& operator[](const K& key) {
    i32 hash = get_hash(Hash(key));
    i32 pos = index_of(key, hash);
    if (hash_val[pos] != NON_EXIST) {
      return entries[pos].second;
    }
    entries[pos] = Pair<K, V>(key, V());
    hash_val[pos] = hash;
    size++;
    if (check_health()) {
      return (*this)[key];
    }
    return entries[pos].second;
  }
  void remove(const K& key) {
    i32 hash = get_hash(Hash(key));
    i32 h = index_of(key, hash);
    if (hash_val[h] == NON_EXIST) {
      return;
    }
    size--;
    hash_val[h] = NON_EXIST;
    int iter = (h + 1) & mask;
    while (hash_val[iter] != NON_EXIST) {
      i32 insert_pos = hash_val[iter] & mask;
      if (InRangeRotate(iter + 1, h, insert_pos)) {
        Swap(entries[h], entries[iter]);
        Swap(hash_val[h], hash_val[iter]);
        h = iter;
      }
      iter = (iter + 1) & mask;
    }
  }
  CIter end() const {
    return CIter{
        .hm = this,
        .index = Size(hash_val),
    };
  }
  CIter rbegin() const {
    return --CIter{
        .hm = this,
        .index = Size(hash_val),
    };
  }
  CIter rend() const {
    return CIter{
        .hm = this,
        .index = -1,
    };
  }
  CIter begin() const {
    return ++CIter{
        .hm = this,
        .index = -1,
    };
  }
  Iter begin() {
    return ++Iter{
        .hm = this,
        .index = -1,
    };
  }
  Iter end() {
    return Iter{
        .hm = this,
        .index = Size(hash_val),
    };
  }
  Iter rbegin() {
    return --Iter{
        .hm = this,
        .index = Size(hash_val),
    };
  }
  Iter rend() {
    return Iter{
        .hm = this,
        .index = -1,
    };
  }
  Vec<Pair<K, V>> to_vec() const {
    Vec<Pair<K, V>> res;
    for (auto& kv : *this) {
      res.push_back(kv);
    }
    return res;
  }
};
}  // namespace hash
}  // namespace dalt
namespace dalt {
namespace seq {
// verified by:
//  - https://loj.ac/p/141
struct Eertree {
  struct Node {
    int id;
    Node *fail;
    int len;
    int depth;
  };
  Node *odd;
  Node *even;
  hash::HashMap<u64, Node *> hm;
  Vec<i32> data;
  int zero;
  int front_size;
  int back_size;
  Node *front_build_last;
  Node *back_build_last;
  Vec<Node *> all;
  i64 palindrome_substring_cnt;
  Node *newNode() {
    auto ans = new Node();
    ans->id = Size(all);
    all.push_back(ans);
    return ans;
  }
  Node *GetChild(Node *node, int index) {
    var iter = hm.find(IdOf(node, index));
    return iter == hm.end() ? NULL : iter->second;
  }
  void SetChild(Node *node, int index, Node *item) {
    hm[IdOf(node, index)] = item;
  }
  u64 IdOf(Node *node, int index) { return u64(node->id) << 32 | index; }
  Eertree(int back_addition, int front_addition = 0)
      : palindrome_substring_cnt(0) {
    int cap = front_addition + back_addition;
    all.resize(2 + cap);
    data.resize(cap);
    zero = front_addition;
    front_size = zero - 1;
    back_size = zero;
    odd = newNode();
    odd->len = -1;
    odd->depth = 0;
    odd->id = -1;
    even = newNode();
    even->fail = odd;
    even->len = 0;
    even->depth = 0;
    even->id = -2;
    all.clear();
    back_build_last = front_build_last = odd;
    hm = decltype(hm)(cap);
  }
  void push_front(i32 c) {
    data[front_size--] = c;
    int index = c;
    auto trace = front_build_last;
    while (front_size + 2 + trace->len >= back_size) {
      trace = trace->fail;
    }
    while (data[front_size + trace->len + 2] != c) {
      trace = trace->fail;
    }
    var next_index_iter = hm.find(IdOf(trace, index));
    if (next_index_iter != hm.end()) {
      front_build_last = next_index_iter->second;
    } else {
      auto now = newNode();
      now->len = trace->len + 2;
      hm[IdOf(trace, index)] = now;
      if (now->len == 1) {
        now->fail = even;
      } else {
        trace = trace->fail;
        while (data[front_size + trace->len + 2] != c) {
          trace = trace->fail;
        }
        now->fail = hm[IdOf(trace, index)];
      }
      now->depth = now->fail->depth + 1;
      front_build_last = now;
    }
    if (front_build_last->len == back_size - front_size - 1) {
      back_build_last = front_build_last;
    }
    palindrome_substring_cnt += front_build_last->depth;
  }
  void push_back(i32 c) {
    data[back_size++] = c;
    int index = c;
    auto trace = back_build_last;
    while (back_size - 2 - trace->len <= front_size) {
      trace = trace->fail;
    }
    while (data[back_size - trace->len - 2] != c) {
      trace = trace->fail;
    }
    var next_index_iter = hm.find(IdOf(trace, index));
    if (next_index_iter != hm.end()) {
      back_build_last = next_index_iter->second;
    } else {
      auto now = newNode();
      now->len = trace->len + 2;
      hm[IdOf(trace, index)] = now;
      if (now->len == 1) {
        now->fail = even;
      } else {
        trace = trace->fail;
        while (data[back_size - trace->len - 2] != c) {
          trace = trace->fail;
        }
        now->fail = hm[IdOf(trace, index)];
      }
      now->depth = now->fail->depth + 1;
      back_build_last = now;
    }
    if (back_build_last->len == back_size - front_size - 1) {
      front_build_last = back_build_last;
    }
    palindrome_substring_cnt += back_build_last->depth;
  }
  void visit(Consumer<Node *> consumer) {
    for (int i = Size(all) - 1; i >= 0; i--) {
      consumer(all[i]);
    }
  }
  i64 get_palindrome_substring_cnt() const { return palindrome_substring_cnt; }
  int get_distinct_palindrome_substring() const { return Size(all); }
#ifdef DROP
  ~Eertree() {
    delete odd;
    delete even;
    for (var item : all) {
      delete item;
    }
  }
#endif
};
}  // namespace seq
}  // namespace dalt
/// @brief credited to https://arxiv.org/pdf/1506.04862.pdf
/// @param N length of s
/// @param s string
/// @return ret[i] is the minimum factorization number of pre(s, i + 1)
Vec<Pair<int, int>> FactorizePalindrome(int N, const Indexer<int> &s) {
  seq::Eertree tree(N);
  using Node = seq::Eertree::Node;
  Vec<Node *> max_suf;
  max_suf.reserve(N);
  for (int i = 0; i < N; i++) {
    tree.push_back(s(i));
    max_suf.push_back(tree.back_build_last);
  }
  var &all = tree.all;
  Vec<int> diff(Size(all));
  Vec<Node *> series_link(Size(all));
  for (int i = 0; i < Size(all); i++) {
    var &node = all[i];
    diff[i] = node->len;
    diff[i] -= node->fail->len;
    series_link[i] = node->fail;
    if (node->fail->id >= 0 && diff[i] == diff[node->fail->id]) {
      series_link[i] = series_link[node->fail->id];
    }
  }
  int inf = (int)2e9;
  Vec<Pair<int, int>> dp(N);
  Vec<Pair<int, int>> ans(N, MakePair(inf, -1));
  int n;
  var get_min = [&](Node *v) {
    int index = n - (series_link[v->id]->len + diff[v->id]);
    dp[v->id] = MakePair(index < 0 ? 0 : ans[index].first, index);
    if (v->fail->id >= 0 && diff[v->id] == diff[v->fail->id]) {
      Chmin(dp[v->id], dp[v->fail->id]); 
    }
    return MakePair(dp[v->id].first + 1, dp[v->id].second);
  };
  for (n = 0; n < N; n++) {
    var best = MakePair(inf, -1);
    if(n >= 1 && s(n) == s(n - 1)) {
      Chmin(best, MakePair(n >= 2 ? ans[n - 2].first : 0, n - 2));
    }
    for (var node = max_suf[n]; node->id >= 0; node = series_link[node->id]) {
      best = Min(best, get_min(node));
    }
    if(n % 2) {
      ans[n] = best;
    }
  }
  Debug(ans);
  return ans;
}
namespace dalt {
template <class T, class C>
Indexer<T> MakeIndexer(const C &data) {
  return [&](auto i) -> T { return data[i]; };
}
template <class T, class C>
Indexer<T> MakeReverseIndexer(const C &data) {
  return [&](auto i) -> T { return data[Size(data) - 1 - i]; };
}
template <class T>
Vec<T> ExpandIndexer(int n, const Indexer<T> &indexer) {
  Vec<T> ans;
  ans.reserve(n);
  for (int i = 0; i < n; i++) {
    ans.push_back(indexer(i));
  }
  return ans;
}
Indexer<i32> SelfIndexer() {
  return [](auto i) { return i; };
}
template <class T>
Indexer<T> ConstantIndexer(const T &val) {
  return [=](auto i) { return val; };
}
template <class A, class B>
Mapper<A, B> ConstructorMapper() {
  return [&](auto a) { return B(a); };
}
template <class T>
Adder<T> NaturalAdder() {
  return [](auto a, auto b) { return a + b; };
}
template <class A, class B, class C>
constexpr Adder<A, B, C> EmptyAdder() {
  return [](auto a, auto b) { return C(); };
}
template <class A, class B = A>
constexpr Adder<A, B, A> ReturnLeftAdder() {
  return [](auto a, auto b) { return a; };
}
template <class A, class B = A>
constexpr Adder<A, B, B> ReturnRightAdder() {
  return [](auto a, auto b) { return b; };
}
template <class T>
Indexer<int> BinaryIndexer(const T& val) {
  return [=](int i) {return int((val >> i) & 1);};
}
template <class T>
Indexer<int> ReverseIndexer(int n, Indexer<T> indexer) {
  return [=](int i) {return indexer(n - 1 - i);};
}
}  // namespace dalt
void SolveOne(int test_id, IStream &in, OStream &out) {
  Str a, b;
  in >> a >> b;
  Vec<int> data;
  data.reserve(2 * Size(a));
  for(int i = 0; i < Size(a); i++) {
    data.push_back(a[i]);
    data.push_back(b[i]);
  }
  Debug(data);
  var ans = FactorizePalindrome(Size(data), MakeIndexer<int>(data));
  if(ans.back().first >= 1e9) {
    out << -1;
    return;
  }
  Vec<Pair<int, int>> reverse_range;
  for(int i = Size(ans) - 1; i >= 0; i = ans[i].second) {
    int last = ans[i].second;
    if(i - last == 2 && data[i] == data[i - 1]) {
      //same
    } else {
      reverse_range.push_back(MakePair(last + 1, i));
    }
  }
  out << Size(reverse_range) << '\n';
  Reverse(All(reverse_range));
  for(var &range : reverse_range) {
    out << range.first / 2 + 1 << ' ' << range.second / 2 + 1 << '\n';
  }
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