//Timestamp: 2022-12-03 21:21:14
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
enable_if_t<is_integral_v<T>, Optional<T>> FirstTrue(
    T l, T r, const Checker<T> &checker) {
  if (!checker(r)) {
    return {};
  }
  while (l < r) {
    T m = DivFloor<T>(l + r, 2);
    if (checker(m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  return l;
}
template <class T>
enable_if_t<is_integral_v<T>, Optional<T>> LastTrue(T l, T r,
                                                    const Checker<T> &checker) {
  if (!checker(l)) {
    return {};
  }
  while (l < r) {
    T m = DivCeil<T>(l + r, 2);
    if (checker(m)) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  return l;
}
template <class T>
enable_if_t<is_floating_point_v<T>, Optional<T>> FirstTrue(
    T l, T r, const Checker<T> &checker, Function<bool()> stopper) {
  if (!checker(r)) {
    return {};
  }
  while (!stopper()) {
    T m = (l + r) / 2;
    if (checker(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  return l;
}
template <class T>
enable_if_t<is_floating_point_v<T>, Optional<T>> FirstTrue(
    T l, T r, const Checker<T> &checker, i32 max_round) {
  return FirstTrue<T>(
      l, r, checker,[&]() { return max_round-- <= 0; });
}
}  // namespace dalt
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
template <class T> struct SparseTable {
private:
  Vec<Vec<T>> table;
  Reducer<T> reducer;
public:
  using Self = SparseTable<T>;
  SparseTable(int n, const Indexer<T> &data, Reducer<T> f) : reducer(f) {
    i32 m = Log2Floor(u32(n));
    table = Vec<Vec<T>>(m + 1, Vec<T>(n));
    for(int i = 0; i < n; i++){
      table[0][i] = data(i);
    }
    for (i32 i = 0; i < m; i++) {
      i32 step = 1 << i;
      for (i32 j = 0; j < n; j++) {
        if (j + step < n) {
          table[i + 1][j] = reducer(table[i][j], table[i][j + step]);
        } else {
          table[i + 1][j] = table[i][j];
        }
      }
    }
  }
  T query(i32 l, i32 r) const {
    int len = r - l + 1;
    int log_floor = Log2Floor(u32(len));
    return reducer(table[log_floor][l],
                   table[log_floor][r + 1 - (1 << log_floor)]);
  }
};
} // namespace dalt
namespace dalt {
const i32 SHIFT = 5;
const i32 BLOCK_SIZE = 1 << SHIFT;
const i32 AND_MASK = BLOCK_SIZE - 1;
struct StaticRMQ {
private:
  Vec<i32> to_left;
  Comparator<i32> comparator;
  SparseTable<i32> *st;
  i32 minor_one(i32 a, i32 b) { return !comparator(b, a) ? a : b; }
public:
  using Self = StaticRMQ;
  StaticRMQ(int n, Comparator<i32> arg_comparator)
      : comparator(arg_comparator) {
    int consider_part = ((n - 1) >> SHIFT) + 1;
    Vec<i32> min_indices = Vec<i32>(consider_part, -1);
    to_left = Vec<i32>(n);
    for (int i = 0; i < n; i++) {
      int to = i >> SHIFT;
      if (min_indices[to] == -1 || comparator(i, min_indices[to])) {
        min_indices[to] = i;
      }
    }
    st = new SparseTable<i32>(consider_part, MakeIndexer<i32>(min_indices),
                              [&](int a, int b) {
                                return minor_one(a, b);
                              });
    int mask = 0;
    for (int i = 0; i < n; i++) {
      if ((i & AND_MASK) == 0) {
        mask = 0;
      }
      int b = i >> SHIFT;
      while (mask != 0) {
        int head = HighestOneBitOffset(mask);
        if (!comparator((b << SHIFT) | head, i)) {
          mask = ClearBit(mask, head);
        } else {
          break;
        }
      }
      mask = SetBit(mask, i & AND_MASK);
      to_left[i] = mask;
    }
  }
  i32 query(int l, int r) {
    Assert(l <= r);
    int bl = l >> SHIFT;
    int br = r >> SHIFT;
    int tl = l & AND_MASK;
    //        int tr = r & AND_MASK;
    if (bl == br) {
      return TrailingZeroNumber(to_left[r] & HighestKOnes32(32 - tl)) |
             (bl << SHIFT);
    }
    int res1 = TrailingZeroNumber(to_left[(bl << SHIFT) | AND_MASK] &
                                  HighestKOnes32(32 - tl)) |
               (bl << SHIFT);
    int res2 = TrailingZeroNumber(to_left[r]) | (br << SHIFT);
    int best = minor_one(res1, res2);
    if (bl + 1 < br) {
      best = minor_one(best, st->query(bl + 1, br - 1));
    }
    return best;
  }
#ifdef DROP
  ~StaticRMQ() { delete st; }
#endif
};
} // namespace dalt
void SolveOne(int test_id, IStream &in, OStream &out) {
  int N, M;
  in >> N >> M;
  Vec<Pair<i64, i64>> Qs(N);
  Vec<i64> discrete;
  for(int i = 0; i < N; i++) {
    in >> Qs[i].first >> Qs[i].second;
    discrete.push_back(Qs[i].first);
  }
  MakeUniqueAndSort(discrete);
  int K = Size(discrete);
  Vec<i64> A(K);
  Vec<i64> B(K);
  var update = [&](Vec<i64> &data, int l, int r, i64 x) {
    l = Max(l, 0);
    if(l > r) {
      return;
    }
    if(l < Size(data)) {
      data[l] += x;
    }
    if(r + 1 < Size(data)) {
      data[r + 1] -= x;
    }
  }; 
  Line(parse query);
  for(var &q : Qs) {
    i64 pos = q.first;
    i64 weight = q.second;
    int index = LowerBound(All(discrete), pos) - discrete.begin();
    int l_bound = LowerBound(All(discrete), pos - weight) - discrete.begin();
    int r_bound = UpperBound(All(discrete), pos + weight) - discrete.begin() - 1;
    update(A, l_bound, index - 1, 1);
    update(B, l_bound, index - 1, weight - pos);
    update(A, index, r_bound, -1);
    update(B, index, r_bound, weight + pos);
  }
  for(int i = 1; i < K; i++) {
    A[i] += A[i - 1];
    B[i] += B[i - 1];
  }
  Vec<i64> final_heights(K);
  for(int i = 0; i < K; i++) {
    final_heights[i] = A[i] * discrete[i] + B[i];
  }
  Vec<i64> left_atleast(K), right_atleast(K);
  for(int i = 0; i < K; i++) {
    // virtual_val - (weight - pos) <= m
    left_atleast[i] = (-discrete[i] + final_heights[i]) - M;
    right_atleast[i] = (discrete[i] + final_heights[i]) - M;
  }
  Line(make rmq);
  StaticRMQ rmq_heights(K, [&](int a, int b) {
    return final_heights[a] > final_heights[b];
  });
  StaticRMQ rmq_left_atleast(
      K, [&](int a, int b) { return left_atleast[a] > left_atleast[b]; });
  StaticRMQ rmq_right_atleast(
      K, [&](int a, int b) { return right_atleast[a] > right_atleast[b]; });
  Line(solve query);
  for(var &q : Qs) {
    i64 pos = q.first;
    i64 weight = q.second;
    int index = LowerBound(All(discrete), pos) - discrete.begin();
    int l_bound = LowerBound(All(discrete), pos - weight) - discrete.begin();
    int r_bound =
        UpperBound(All(discrete), pos + weight) - discrete.begin() - 1;
    l_bound = Max(l_bound, 0);
    r_bound = Min(r_bound, K - 1);
    bool ok = true;
    if(l_bound > 0 && final_heights[rmq_heights.query(0, l_bound - 1)] > M) {
      ok = false;
    }
    if(r_bound < K - 1 && final_heights[rmq_heights.query(r_bound + 1, K - 1)] > M) {
      ok = false;
    }
    int left_index = rmq_left_atleast.query(l_bound, index);
    int right_index = rmq_right_atleast.query(index, r_bound);
    if ((weight - pos) < left_atleast[left_index]) {
      ok = false;
    }
    if((weight + pos) < right_atleast[right_index]) {
      ok = false;
    }
    out << (ok ? 1 : 0);
  }
  out << '\n';
}
void SolveMulti(IStream &in, OStream &out) {
  //std::ifstream input("in");
  int num_of_input = 1;
  in >> num_of_input;
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