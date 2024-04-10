//Timestamp: 2022-05-04 15:33:04
//#include "all"
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
#define Size(T) int((T).size())
#define All(data) data.begin(), data.end()
#define MakeUnique(data) data.resize(std::unique(All(data)) - data.begin())
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
  enable_if_t<OnlyWhenArg == param && OnlyWhenArg, ret_type>
#define IsBoolStatic(param, ret_type) \
  template <bool OnlyWhenArg = param> \
  static enable_if_t<OnlyWhenArg == param && OnlyWhenArg, ret_type>
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
FunctionAlias(std::acos, Acon);
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
  template <class E>
  friend bool operator==(const Optional<E> &a, const Optional<E> &b);
};
template <class E>
bool operator==(const Optional<E> &a, const Optional<E> &b) {
  return a.show_up == b.show_up && (!a.show_up || a.val == b.val);
}
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
namespace sbt {
template <class S, class U, i64 ID, i64 CID>
struct SelfBalanceTreeBase {
  static S s_nil;
  static U u_nil;
  static Adder<S, S> s_s;
  static Adder<S, U> s_u;
  static Adder<U, U> u_u;
  static void Register(S _s_nil, U _u_nil, const Adder<S, S> &_s_s,
                       const Adder<S, U> &_s_u, const Adder<U, U> &_u_u) {
    s_nil = _s_nil;
    u_nil = _u_nil;
    s_s = _s_s;
    s_u = _s_u;
    u_u = _u_u;
  }
};
template <class S, class U, i64 ID, i64 CID>
S SelfBalanceTreeBase<S, U, ID, CID>::s_nil;
template <class S, class U, i64 ID, i64 CID>
U SelfBalanceTreeBase<S, U, ID, CID>::u_nil;
template <class S, class U, i64 ID, i64 CID>
Adder<S, S> SelfBalanceTreeBase<S, U, ID, CID>::s_s;
template <class S, class U, i64 ID, i64 CID>
Adder<S, U> SelfBalanceTreeBase<S, U, ID, CID>::s_u;
template <class S, class U, i64 ID, i64 CID>
Adder<U, U> SelfBalanceTreeBase<S, U, ID, CID>::u_u;
}  // namespace sbt
}  // namespace dalt
namespace dalt {
namespace sbt {
inline bool SegmentNoIntersection(i32 L, i32 R, i32 l, i32 r) {
  return R < l || r < L;
}
inline bool SegmentCover(i32 L, i32 R, i32 l, i32 r) {
  return L <= l && r <= R;
}
}  // namespace sbt
}  // namespace dalt
namespace dalt {
namespace sbt {
#define CLASS_ID -202202131500
template <class S, class U, bool P = false, bool SPARSE = false, i64 ID = 0,
          i64 CID = 0>
struct SegTree : public SelfBalanceTreeBase<S, U, ID, CLASS_ID> {
  static_assert(int(P) + int(SPARSE) <= 1);
  struct Node {
    using Self = Node;
    Self *left;
    Self *right;
    S sum;
    U upd;
#ifdef DROP
    ~Node() {
      if (this == NIL) {
        return;
      }
      delete left;
      delete right;
    }
#endif
    IsBool(P, Node *) clone() { return new Node(*this); }
    IsBool(!P && !SPARSE, Node *) clone() { return this; }
    IsBool(SPARSE, Node *) clone() {
      if (this == NIL) {
        return new Node(*NIL);
      }
      return this;
    }
    void push_up() { sum = SegTree::s_s(left->sum, right->sum); }
    void push_down() {
      left = left->clone();
      right = right->clone();
      if (upd != SegTree::u_nil) {
        left->modify(upd);
        right->modify(upd);
        upd = SegTree::u_nil;
      }
    }
    void modify(const U &u) {
      sum = SegTree::s_u(sum, u);
      upd = SegTree::SegTree::u_u(upd, u);
    }
  };
  using Self = SegTree<S, U, P, SPARSE, ID, CID>;
  static Node *NIL;
  Node *tree;
  int n;
 private:
  Node *make_node() {
    Node *ans = new Node{
        .left = NIL,
        .right = NIL,
        .sum = SegTree::s_nil,
        .upd = SegTree::u_nil,
    };
    return ans;
  }
  IsBool(P, Node *) make_tree() {
    Node *root = make_node();
    root->left = root->right = root;
    return root;
  }
  IsBool(!P, Node *) make_tree() {
    Node *root = make_node();
    return root;
  }
 public:
  IsBoolStatic(SPARSE, void)
      Register(S _s_nil, U _u_nil, const Adder<S, S> &_s_s,
               const Adder<S, U> &_s_u, const Adder<U, U> &_u_u) {
    SelfBalanceTreeBase<S, U, ID, CLASS_ID>::Register(_s_nil, _u_nil, _s_s,
                                                      _s_u, _u_u);
    NIL = new Node();
    NIL->left = NIL;
    NIL->right = NIL;
    NIL->upd = _u_nil;
    NIL->sum = _s_nil;
  }
  Self clone() const {
    Self ans = *this;
    ans.tree = ans.tree->clone();
    return ans;
  }
  SegTree(
      int _n = 0,
      const Indexer<S> &indexer = [](int index) { return SegTree::s_nil; })
      : n(_n) {
    auto dfs = [&](auto &dfs, int l, int r) -> Node * {
      Node *root = make_tree();
      root->upd = SegTree::u_nil;
      if (l == r) {
        root->sum = indexer(l);
      } else {
        int m = (l + r) / 2;
        root->left = dfs(dfs, l, m);
        root->right = dfs(dfs, m + 1, r);
        root->push_up();
      }
      return root;
    };
    tree = dfs(dfs, 0, n - 1);
  }
  IsBoolStatic(SPARSE, Self) MakeSparseTree(int n) {
    Self res(1);
    res.n = n;
    return res;
  }
  IsBoolStatic(P, Self) MakePersistentTree(int n) {
    Self res(1);
    res.n = n;
    return res;
  }
  S query(int L, int R) {
    auto dfs = [&](auto &dfs, Node *root, int l, int r) {
      if (SegmentNoIntersection(L, R, l, r)) {
        return SegTree::s_nil;
      }
      if (SegmentCover(L, R, l, r)) {
        return root->sum;
      }
      root->push_down();
      int m = (l + r) / 2;
      auto lsum = dfs(dfs, root->left, l, m);
      auto rsum = dfs(dfs, root->right, m + 1, r);
      return SegTree::s_s(lsum, rsum);
    };
    return dfs(dfs, tree, 0, n - 1);
  }
  S query_const(int L, int R) const {
    auto dfs = [&](auto &dfs, Node *root, int l, int r, const U &upd) {
      if (SegmentNoIntersection(L, R, l, r)) {
        return SegTree::s_nil;
      }
      if (SegmentCover(L, R, l, r)) {
        return SegTree::s_u(root->sum, upd);
      }
      U new_upd = SegTree::SegTree::u_u(root->upd, upd);
      int m = (l + r) / 2;
      auto lsum = dfs(dfs, root->left, l, m, new_upd);
      auto rsum = dfs(dfs, root->right, m + 1, r, new_upd);
      return SegTree::s_s(lsum, rsum);
    };
    return dfs(dfs, tree, 0, n - 1, SegTree::u_nil);
  }
  void update(int L, int R, const U &upd) {
    auto dfs = [&](auto &dfs, Node *root, int l, int r) {
      if (SegmentNoIntersection(L, R, l, r)) {
        return;
      }
      if (SegmentCover(L, R, l, r)) {
        root->modify(upd);
        return;
      }
      root->push_down();
      int m = (l + r) / 2;
      dfs(dfs, root->left, l, m);
      dfs(dfs, root->right, m + 1, r);
      root->push_up();
    };
    dfs(dfs, tree, 0, n - 1);
  }
  void travel(const Consumer<S> &consumer) const {
    auto dfs = [&](auto &dfs, Node *root, const U &upd, int l, int r) {
      // is leaf
      if (l == r) {
        consumer(SegTree::s_u(root->sum, upd));
        return;
      }
      int m = (l + r) / 2;
      U new_upd = SegTree::SegTree::u_u(root->upd, upd);
      dfs(dfs, root->left, new_upd, l, m);
      dfs(dfs, root->right, new_upd, m + 1, r);
    };
    dfs(dfs, tree, SegTree::u_nil, 0, n - 1);
  }
  Vec<S> to_vec() const {
    Vec<S> res;
    res.reserve(n);
    travel([&](auto x) { res.push_back(x); });
    return res;
  }
  Optional<Tuple<int, S>> first_true(int L, int R, Checker<S> &checker) {
    S sum = SegTree::s_nil;
    auto dfs = [&](auto &dfs, Node *root, int l, int r) -> Optional<int> {
      if (SegmentNoIntersection(L, R, l, r)) {
        return {};
      }
      if (SegmentCover(L, R, l, r)) {
        S new_sum = SegTree::s_s(sum, root->sum);
        if (!checker(new_sum)) {
          sum = new_sum;
          return {};
        }
        if (l == r) {
          // leaf
          sum = new_sum;
          return l;
        }
      }
      root->push_down();
      int m = (l + r) / 2;
      auto lres = dfs(dfs, root->left, l, m);
      if (lres.is_none()) {
        return dfs(dfs, root->right, m + 1, r);
      }
      return lres;
    };
    auto res = dfs(dfs, tree, 0, n - 1);
    return res.map(
        [&](int x) -> Tuple<int, S> { return Tuple<int, S>(x, sum); });
  }
  Optional<Tuple<int, S>> last_true(int L, int R, const Checker<S> &checker) {
    S sum = SegTree::s_nil;
    auto dfs = [&](auto &dfs, Node *root, int l, int r) -> Optional<int> {
      if (SegmentNoIntersection(L, R, l, r)) {
        return {};
      }
      if (SegmentCover(L, R, l, r)) {
        S new_sum = SegTree::s_s(sum, root->sum);
        if (checker(new_sum)) {
          sum = new_sum;
          return r;
        }
        if (l == r) {
          return {};
        }
      }
      root->push_down();
      int m = (l + r) / 2;
      auto lres = dfs(dfs, root->left, l, m);
      if (lres.s_some() || r < L) {
        auto rres = dfs(dfs, root->right, m + 1, r);
        if (rres.s_some()) {
          return rres;
        }
      }
      return lres;
    };
    auto res = dfs(dfs, tree, 0, n - 1);
    return res.map(
        [&](int x) -> Tuple<int, S> { return Tuple<int, S>(x, sum); });
  }
  Optional<Tuple<int, S>> first_true_const(int L, int R,
                                           Checker<S> &checker) const {
    S sum = SegTree::s_nil;
    auto dfs = [&](auto &dfs, Node *root, const U &upd, int l,
                   int r) -> Optional<int> {
      if (SegmentNoIntersection(L, R, l, r)) {
        return {};
      }
      if (SegmentCover(L, R, l, r)) {
        S new_sum = SegTree::s_s(sum, SegTree::s_u(root->sum, upd));
        if (!checker(new_sum)) {
          sum = new_sum;
          return {};
        }
        if (l == r) {
          // leaf
          sum = new_sum;
          return l;
        }
      }
      U new_upd = SegTree::SegTree::u_u(root->upd, upd);
      int m = (l + r) / 2;
      auto lres = dfs(dfs, root->left, new_upd, l, m);
      if (lres.is_none()) {
        return dfs(dfs, root->right, new_upd, m + 1, r);
      }
      return lres;
    };
    auto res = dfs(dfs, tree, SegTree::u_nil, 0, n - 1);
    return res.map([&](auto x) { return Tuple<int, S>(x, sum); });
  }
  Optional<Tuple<int, S>> last_true_const(int L, int R,
                                          const Checker<S> &checker) const {
    S sum = SegTree::s_nil;
    auto dfs = [&](auto &dfs, Node *root, const U &upd, int l,
                   int r) -> Optional<int> {
      if (SegmentNoIntersection(L, R, l, r)) {
        return {};
      }
      if (SegmentCover(L, R, l, r)) {
        S new_sum = SegTree::s_s(sum, SegTree::s_u(root->sum, upd));
        if (checker(new_sum)) {
          sum = new_sum;
          return r;
        }
        if (l == r) {
          // leaf
          return {};
        }
      }
      U new_upd = SegTree::SegTree::u_u(root->upd, upd);
      int m = (l + r) / 2;
      auto lres = dfs(dfs, root->left, new_upd, l, m);
      if (lres.is_some() || r < L) {
        auto rres = dfs(dfs, root->right, new_upd, m + 1, r);
        if (rres.is_some()) {
          return rres;
        }
      }
      return lres;
    };
    auto res = dfs(dfs, tree, SegTree::u_nil, 0, n - 1);
    return res.map([&](auto x) { return Tuple<int, S>(x, sum); });
  }
  IsBool(!P && !SPARSE, void) destroy() { delete tree; }
  IsBool(P || SPARSE, void) destroy() { }
  IsBoolStatic(SPARSE, Self) merge(Self a, Self b, const Adder<S, S> &adder) {
    assert(a.n == b.n);
    auto dfs = [&](auto &dfs, Node *a, Node *b, int l, int r) -> Node * {
      if (a == NIL) {
        return b;
      }
      if (b == NIL) {
        return a;
      }
      if (l == r) {
        a->sum = adder(a->sum, b->sum);
        return a;
      }
      int m = (l + r) / 2;
      //a->push_down();
      //b->push_down();
      a->left = dfs(dfs, a->left, b->left, l, m);
      a->right = dfs(dfs, a->right, b->right, m + 1, r);
      a->push_up();
      return a;
    };
    a.tree = dfs(dfs, a.tree, b.tree, 0, a.n - 1);
    return a;
  }
#ifdef DROP
  ~SegTree() { destroy(); }
#endif
};
#undef CLASS_ID
template <class S, class U, bool P, bool SPARSE, i64 ID, i64 CID>
typename SegTree<S, U, P, SPARSE, ID, CID>::Node
    *SegTree<S, U, P, SPARSE, ID, CID>::NIL = NULL;
}  // namespace sbt
}  // namespace dalt
using namespace dalt;
void SolveOne(int test_id, IStream &in, OStream &out) {
  int n;
  in >> n;
  Vec<int> colors(n);
  for (int i = 0; i < n; i++) {
    in >> colors[i];
  }
  Vec<Vec<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    in >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  Debug(g);
  Debug(colors);
  using A2 = Array<i64, 2>;
  Vec<A2> ans(n);
  using ST = sbt::SegTree<A2, A2, false, true>;
  ST::Register(
      A2(), A2(),
      [&](const A2 &a, const A2 &b) {
        A2 res{Max(a[0], b[0]), 0};
        if (a[0] == res[0]) {
          res[1] += a[1];
        }
        if (b[0] == res[0]) {
          res[1] += b[1];
        }
        return res;
      },
      [&](const A2 &a, const A2 &b) {
        return A2{a[0] + b[0], Max(a[1], b[1])};
      },
      [&](const A2 &a, const A2 &b) {
        return A2{a[0] + b[0], Max(a[1], b[1])};
      });
  Vec<int> size(n);
  auto dfs = [&](auto &dfs, int root, int fa) -> ST {
    ST st = ST::MakeSparseTree(n + 1);
    for (auto node : g[root]) {
      if (node == fa) {
        continue;
      }
      auto child = dfs(dfs, node, root);
      Debug(st.to_vec());
      Debug(child.to_vec());
      st = ST::merge(st, child, [&](const auto &a, const auto &b) {
        return A2 {a[0] + b[0], Max(a[1], b[1])};
      });
      Debug(st.to_vec());
      size[root] += size[node];
      DebugRun({
        int cnt = 0;
        for (auto a : st.to_vec()) {
          cnt += a[0];
        }
        if(cnt != size[root]) {
          DebugFmtln("root = %d, node = %d", root, node);
          exit(1);
        }
      });
    }
    st.update(colors[root], colors[root], A2{1, colors[root]});
    ans[root] = st.query_const(0, n);
    Debug(root);
    Debug(st.to_vec());
    size[root] += 1;
    return st;
  };
  dfs(dfs, 0, -1);
  for (int i = 0; i < n; i++) {
    out << ans[i][1] << ' ';
  }
}
void SolveMulti(IStream &in, OStream &out) {
   //std::ifstream input("in");
  int num_of_input = 1;
  // in >> num_of_input;
  for (int i = 0; i < num_of_input; i++) {
     SolveOne(i + 1, in, out);
    //SolveOne(i + 1, input, out);
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