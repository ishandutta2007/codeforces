#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cstring>
#include <cmath>
#include <complex>
#include <cstdio>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>
#include <type_traits>
#include <tuple>
 
 
#define GET_4TH_ARG(arg1, arg2, arg3, arg4, ...) arg4
#define F0(f) [=]() -> decltype(auto) { return (f); }
#define F1(_, f) [=](auto&& _) -> decltype(auto) { (void)_; return (f); }
#define F2(_1, _2, f) [=](auto&& _1, auto&& _2) -> decltype(auto) { (void)_1; (void)_2; return (f); }
#define FV_macro_chooser(...) GET_4TH_ARG(__VA_ARGS__, F2, F1, F0)
#define FV(...) FV_macro_chooser(__VA_ARGS__)(__VA_ARGS__)
#define G0(f) [&]() -> decltype(auto) { return (f); }
#define G1(_, f) [&](auto&& _) -> decltype(auto) { (void)_; return (f); }
#define G2(_1, _2, f) [&](auto&& _1, auto&& _2) -> decltype(auto) { (void)_1; (void)_2; return (f); }
#define FR_macro_chooser(...) GET_4TH_ARG(__VA_ARGS__, G2, G1, G0)
#define FR(...) FR_macro_chooser(__VA_ARGS__)(__VA_ARGS__)
 
 
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <type_traits>
#include <tuple>
 
 
#ifndef GET_4TH_ARG
    #define GET_4TH_ARG(arg1, arg2, arg3, arg4, ...) arg4
#endif
#define GET_7TH_ARG(arg1, arg2, arg3, arg4, arg5, arg6, arg7, ...) arg7
#define template_for_iterable_3(T, I, V) template<typename T, typename I = typename T::iterator, typename V = typename T::value_type>
#define template_for_iterable_2(T, I) template_for_iterable_3(T, I, )
#define template_for_iterable_1(T) template_for_iterable_2(T, I)
#define template_for_iterable_macro_chooser(...) GET_4TH_ARG(__VA_ARGS__, template_for_iterable_3, template_for_iterable_2, template_for_iterable_1)
#define template_for_iterable(...) template_for_iterable_macro_chooser(__VA_ARGS__)(__VA_ARGS__)
#define iterator_macro(extra, neq, incr, val)               \
    struct Iterator {                                       \
        extra                                               \
        bool operator != (const Iterator& other) const {    \
            (void)other;                                    \
            return neq;                                     \
        }                                                   \
        void operator ++ () incr                            \
        decltype(auto) operator * () const {                      \
            return val;                                     \
        }                                                   \
    };
#define def_iterator_manip_iter(name, templ, args, args_, extra, it_begin, it_end, extra_it, neq_it, incr_it, val_it) \
    def_iterator_manip(name, templ, args, args_, extra, { iterator_macro(extra extra_it mutable I it;, neq_it, incr_it, val_it); return iterable_wrapper(it_begin, it_end); })                                                                                                           
#define def_iterator_manip_2(name, code)        \
    constexpr struct {                          \
        using is_composable_ = void;         \
        template_for_iterable(T, I, V)          \
        decltype(auto) operator() (const T& v) const code      \
    } name;                                     
#define def_iterator_manip_6(name, templ, args, args_, extra, code)     \
    templ                                                               \
    struct name##_ {                                                    \
        using is_composable_ = void;                                 \
        extra                                                           \
        template_for_iterable(T, I, V)                                  \
        decltype(auto) operator () (const T& v) const code              \
    };                                                                  \
    templ                                                               \
    constexpr decltype(auto) name args {                                          \
        return name##_ args_;                                           \
    }
#define def_iterator_manip_iter_chooser(...) GET_7TH_ARG(__VA_ARGS__, def_iterator_manip_6, , , , def_iterator_manip_2)
#define def_iterator_manip(...) def_iterator_manip_iter_chooser(__VA_ARGS__)(__VA_ARGS__)
#define def_template_lambda(templ, name, args, code)    \
    constexpr struct {                                  \
        using is_composable_ = void;                 \
        templ                                           \
        decltype(auto) operator() args const code       \
    } name;
 
 
// Is-iterable type trait
template<typename T, typename = void>
struct is_iterable : public std::false_type { };
 
template<typename T>
struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>())), decltype(std::end(std::declval<T>()))>> : public std::true_type { };
 
template<typename T>
constexpr bool is_iterable_v = is_iterable<T>::value;
 
 
// Is-iterator-manip type trait
template<typename T, typename = void>
struct is_composable : public std::false_type { };
 
template<typename T>
struct is_composable<T, std::void_t<typename T::is_composable_>> : public std::true_type { };
 
template<typename T>
constexpr bool is_composable_v = is_composable<T>::value;
 
 
// Iterable wrapper
template<typename I>
constexpr auto iterable_wrapper(const I& b, const I& e) {
    struct Wrapper {
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
        using is_iterable_wrapper = void;
        using iterator = I;
        using value_type = std::decay_t<decltype(*std::declval<I>())>;
#pragma GCC diagnostic pop
        I b, e;
        auto begin() const {
            return b;
        }
        auto end() const {
            return e;
        }
    };
    return Wrapper{b, e};
}
 
template_for_iterable(T, I)
constexpr auto iter(const T& iterable) {
    return iterable_wrapper(std::begin(iterable), std::end(iterable));
}
 
 
// Container-carrying iterator wrapper
template<typename C>
struct container_carrying_iterator {
    std::shared_ptr<C> p;
    typename C::iterator it;
    bool operator != (const container_carrying_iterator& other) const {
        return it != other.it;
    }
    void operator ++ () {
        ++it;
    }
    decltype(auto) operator * () const {
        return *it;
    }
};
template<typename C>
constexpr auto iterc(C&& v) {
    using D = std::decay_t<C>;
    std::shared_ptr<D> p(new D(v));
    return iterable_wrapper(container_carrying_iterator<D>{ p, std::begin(*p) }, container_carrying_iterator<D>{ p, std::end(*p) });
}
 
template<typename T>
constexpr auto iter(std::initializer_list<T> l) {
    return iterc(std::vector<T>(l));
}
 
 
// Composing functions
 
template<typename T, typename F, typename = std::invoke_result_t<F, T>>
decltype(auto) operator > (T&& v, const F& f) {
    return f(std::forward<T>(v));
}
 
template<typename M1, typename M2>
struct composed {
    using is_composable_ = void;
    const M1 m1;
    const M2 m2;
    template<typename T>
    decltype(auto) operator () (const T& v) const {
        return v > m2 > m1;
    }
};
 
template<typename M1, typename M2, typename = std::enable_if_t<is_composable_v<M1> or is_composable_v<M2>>>
constexpr auto operator < (const M1& m1, const M2& m2) {
    return composed<M1, M2>{m1, m2};
}
 
 
// To-container iterator
#define to_container_macro(T, ins)                               \
    def_iterator_manip(                                     \
    to_##T, {                                            \
        std:: T <V> s;                                   \
        for(auto&& x : v) {                                 \
            s.ins(std::forward<decltype(x)>(x));      \
        }                                                   \
        return s;                                           \
    })
to_container_macro(vector, push_back)
to_container_macro(set, insert)
to_container_macro(unordered_set, insert)
 
 
// Is-nil
def_iterator_manip(
is_nil, {
    return not (std::begin(v) != std::end(v));
});
 
 
// Apply iterator
def_iterator_manip_iter(
    apply,
    template<typename F>,
    (F f),
    <F>{f},
    F f;,
    (Iterator{f, std::begin(v)}),
    (Iterator{f, std::end(v)}),
    ,
    it != other.it,
    { ++it; },
    f(*it)
)
 
 
// Take iterator
def_iterator_manip_iter(
    take,
    ,
    (size_t n),
    {n},
    size_t n;,
    (Iterator{n, std::begin(v)}),
    (Iterator{0, std::end(v)}),
    ,
    n != other.n,
    { --n; if(n > 0) { ++it; } },
    *it
)
 
 
// Take-while iterator
def_iterator_manip_iter(
    take_while,
    template<typename F>,
    (F f),
    <F>{f},
    F f;,
    (Iterator{f, not (std::begin(v) != std::end(v) and f(*std::begin(v))), std::begin(v)}),
    (Iterator{f, true, std::end(v)}),
    bool is_end;,
    is_end xor other.is_end,
    { ++it; if(not f(*it)) { is_end = true; }},
    *it
)
 
 
// Drop iterator
def_iterator_manip_iter(
    drop,
    ,
    (size_t n),
    {n},
    mutable size_t n;,
    (Iterator{n, std::end(v), std::begin(v)}),
    (Iterator{0, std::end(v), std::end(v)}),
    const I end_it;
    inline void advance() const {
        while(n > 0) {
            if(not (it != end_it)) {
                n = 0;
                break;
            }
            --n;
            ++it;
        }
    },
    (advance(), other.advance(), it != other.it),
    { advance(); ++it; },
    (advance(), *it)
)
 
 
// Drop-while iterator
def_iterator_manip_iter(
    drop_while,
    template<typename F>,
    (F f),
    <F>{f},
    F f;,
    (Iterator{f, std::end(v), false, std::begin(v)}),
    (Iterator{f, std::end(v), true, std::end(v)}),
    const I end_it;
    mutable bool has_advanced;
    inline void advance() const {
        if(not has_advanced) {
            while(it != end_it and f(*it)) {
                ++it;
            }
            has_advanced = true;
        }
    },
    (advance(), other.advance(), it != other.it),
    { advance(); ++it; },
    (advance(), *it)
)
 
 
// Head iterator
def_iterator_manip(
head, {
    return *std::begin(v);
})
 
 
// Tail iterator
constexpr auto tail = drop(1);
 
 
// Length iterator
def_iterator_manip(
length, {
    auto b = std::begin(v);
    auto e = std::end(v);
    size_t n = 0;
    while(b != e) {
        ++n;
        ++b;
    }
    return n;
})
 
 
// At iterator
constexpr auto at(size_t n) {
    return head < drop(n);
}
 
 
// Cons iterator
def_iterator_manip_iter(
    cons,
    template<typename S>,
    (S s),
    <S>{s},
    S s;,
    (Iterator{ s, true, std::begin(v) }),
    (Iterator{ s, false, std::end(v) }),
    bool is_s;,
    is_s != other.is_s or it != other.it,
    { if(is_s) { is_s = false; } else { ++it; } },
    (is_s) ? (s) : (*it)
)
    
 
 
// Snoc iterator
def_iterator_manip(
snoc, {
    return tuple(v > head, v > tail);
})
 
 
// Fold iterator (cannot use macro because of commas)
template<typename F, typename S>
struct fold_ {
    using is_composable_ = void;
    F f;
    S s;
    template_for_iterable(T)
    decltype(auto) operator () (const T& v) const {
        auto x = s;
        for(auto y : v) {
            x = f(x, y);
        }
        return x;
    }
};
 
template<typename F, typename S>
constexpr auto fold(F f, const S& s) {
    return fold_<F, S>{f, s};
}
 
 
def_iterator_manip(fold1, template<typename F>, (F f), <F>{f}, F f;, { return v > tail > fold(f, v > head);})
 
 
// Sum iterator
def_iterator_manip(
sum, {
    return v > fold(std::plus<V>(), V());
})
 
 
// Product iterator
def_iterator_manip(
product, {
    return v > fold(std::multiplies<V>(), V(1));
})
 
 
// Maximum iterator
def_iterator_manip(maximum_by, template<typename F>, (F f), <F>{f}, F f;, { return v > fold1(FR(x, y, (f(x, y)) ? (y) : (x))); })
def_iterator_manip(
maximum, {
    return v > maximum_by(std::less<V>());
})
def_iterator_manip(maximum_on, template<typename F>, (F f), <F>{f}, F f;, { return v > fold1(FR(x, y, (f(x) < f(y)) ? (y) : (x))); })
 
 
// Minimum iterator
def_iterator_manip(minimum_by, template<typename F>, (F f), <F>{f}, F f;, { return v > fold1(FR(x, y, (f(y, x)) ? (y) : (x))); })
def_iterator_manip(
minimum, {
    return v > maximum_by(std::less<V>());
})
def_iterator_manip(minimum_on, template<typename F>, (F f), <F>{f}, F f;, { return v > fold1(FR(x, y, (f(y) < f(x)) ? (y) : (x))); })
 
 
// Scan iterator
def_iterator_manip_iter(
    scan1,
    template<typename F>,
    (F f),
    <F>{f},
    F f;,
    (Iterator{ f, *std::begin(v), true, std::begin(v) }),
    (Iterator{ f, *std::begin(v), true, std::end(v) }),
    mutable V s; mutable bool has_updated;,
    it != other.it,
    { if(not has_updated) { s = f(s, *it); }; has_updated = false; ++it; },
    (has_updated) ? (s) : (has_updated = true, s = f(s, *it))
)
 
 
template<typename F, typename S>
auto scan(F f, const S& s) {
    return scan1(f) < cons(s);
}
 
 
// Join iterator
template<typename T, typename S, typename I = typename T::iterator, typename J = typename S::iterator>
constexpr auto operator + (const T& v, const S& u) {
    iterator_macro(
        I i; I i_end; J j; bool in_i;,
        i != other.i or j != other.j,
        { if(in_i) {++i; if(not (i != i_end)) { in_i = false; }} else { ++j; } },
        (in_i) ? (*i) : (*j)
    )
    auto bv = std::begin(v);
    auto ev = std::end(v);
    auto bu = std::begin(u);
    auto eu = std::end(u);
    return iterable_wrapper(Iterator{ bv, ev, bu, bv != ev }, Iterator{ ev, ev, eu, false });
}
 
 
// Flatten iterator
constexpr struct {
    using is_composable_ = void;
    template_for_iterable(T)
    auto operator () (const T& v) const {
        auto u = v > filter(FR(_, not is_nil(_)));
        auto b = std::begin(u);
        auto e = std::end(u);
        using J = decltype(b);
        using V = std::decay_t<decltype(*b)>;
        using K = decltype(std::begin(*b));
        struct Iterator {
            J j; J j_end; std::shared_ptr<V> jv_ptr; std::shared_ptr<K> k_ptr; bool is_end;
            Iterator(J j, J j_end, const V& jv, bool is_end) : j(j), j_end(j_end), jv_ptr(new V(jv)), k_ptr(new K(std::begin(*jv_ptr))), is_end(is_end) { }
            Iterator(J j, J j_end, bool is_end) : j(j), j_end(j_end), jv_ptr(nullptr), k_ptr(nullptr), is_end(is_end) { }
            bool operator != (const Iterator& other) const {
                return is_end xor other.is_end;
            }
            void operator ++ () {
                ++*k_ptr;
                if(not(*k_ptr != std::end(*jv_ptr))) {
                    ++j;
                    if(j != j_end) {
                        *jv_ptr = V(*j);
                        *k_ptr = std::begin(*jv_ptr);
                    } else {
                        is_end = true;
                    }
                }
            }
            auto operator * () const {
                return **k_ptr;
            }
        };
        if(u > is_nil) {
            return iterable_wrapper(Iterator(b, e, true), Iterator(b, e, true));
        } else {
            return iterable_wrapper(Iterator(b, e, *b, false), Iterator(e, e, true));
        }
    }
} flatten;
 
 
// Concat-map iterator
template<typename T, typename F, typename = std::enable_if_t<is_iterable_v<T>>>
auto operator >= (const T& v, F f) {
    return v > apply(f) > flatten;
}
 
 
// Zip iterator
template<typename U, size_t i, size_t s>
bool all_different_(const U& x, const U& y) {
    if constexpr(i < s) {
        return std::get<i>(x) != std::get<i>(y) and all_different_<U, i + 1, s>(x, y);
    } else {
        return true;
    }
}
template<typename U, size_t i, size_t s>
void incr_all_(U& u) {
    if constexpr(i < s) {
        ++std::get<i>(u);
        incr_all_<U, i + 1, s>(u);
    }
}
template<typename F, typename U, size_t ...Seq>
decltype(auto) call_f_(F f, const U& u, std::index_sequence<Seq...>) {
    return f(*std::get<Seq>(u)...);
}
template<typename F, typename ...Ts>
constexpr auto zip_with(F f, const Ts& ...vs) {
    iterator_macro(
        F f;
        std::tuple<decltype(std::begin(std::declval<Ts>()))...> its;,
        (all_different_<decltype(its), 0, sizeof...(Ts)>(its, other.its)),
        { (incr_all_<decltype(its), 0, sizeof...(Ts)>(its)); },
        call_f_(f, its, std::index_sequence_for<Ts...>{})
    )
    return iterable_wrapper(Iterator{ f, std::tuple(std::begin(vs)...) }, Iterator{ f, std::tuple(std::end(vs)...) });
}
 
template<typename ...Ts>
constexpr auto zip(const Ts& ...vs) {
    return zip_with([](decltype(*std::begin(std::declval<Ts>())) ...xs) { return std::tuple<decltype(*std::begin(std::declval<Ts>()))...>(xs...); }, vs...);
}
        
 
// Filter iterator
def_iterator_manip_iter(
    filter,
    template<typename F>,
    (F f),
    <F>{f},
    F f;,
    (Iterator{f, std::end(v), std::begin(v)}),
    (Iterator{f, std::end(v), std::end(v)}),
    const I end_it;
    inline void advance() const {
        while(it != end_it and not f(*it)) {
            ++it;
        }
    },
    (advance(), other.advance(), it != other.it),
    { advance(); ++it; },
    (advance(), *it)
)
 
 
// Repeat iterator
def_template_lambda(
template<typename T>,
repeat, (T&& v), {
    struct Iterator {
        const std::decay_t<T> v;
        bool operator != (const Iterator&) const {
            return true;
        }
        void operator ++ () { }
        const auto& operator * () const {
            return v;
        }
    };
    return iterable_wrapper(Iterator{v}, Iterator{v});
})
 
 
// Replicate iterator
constexpr auto replicate(size_t n) {
    return take(n) < repeat;
}
 
 
// Cycle iterator
constexpr auto cycle = flatten < repeat;
 
 
#pragma GCC diagnostic ignored "-Wnarrowing"
// Range iterator
template<typename T1, typename T2, typename T3, typename T = decltype(T1() + T2() + T3())>
constexpr auto range(const T1& b, const T2& e, const T3& step) {
    iterator_macro(
        T x; T e; T step;
        bool is_end() const {
            return (step >= T(0) and x >= e) or (step < T(0) and x <= e);
        },
        is_end() xor other.is_end(),
        { x += step; },
        x
    )
    return iterable_wrapper(Iterator{b, e, step}, Iterator{e, e, step});
}
 
template<typename T1, typename T2>
constexpr auto range(const T1& b, const T2& e) {
    return range(b, e, 1);
}
 
template<typename T>
constexpr auto range(const T& e) {
    return range(T(), e, 1);
}
#pragma GCC diagnostic pop
 
 
// To-infinity iterator
template<typename T>
constexpr auto to_infinity(const T& b = T(), const T& step = 1) {
    iterator_macro(
        T x; T step;,
        true,
        { x += step; },
        x
    )
    return iterable_wrapper(Iterator{b, step}, Iterator{b, step});
}
 
 
// Enumerate iterator
def_iterator_manip(
enumerate, {
    return zip(to_infinity(size_t(0)), v);
})
 
 
// Reversed iterator
def_iterator_manip(
reversed, {
    auto s = v > to_vector;
    std::reverse(s.begin(), s.end());
    return iterc(std::move(s));
})
 
 
// Sorted iterator
def_iterator_manip(sorted_by, template<typename F>, (F f), <F>{f}, F f;, { auto s = v > to_vector; std::sort(std::begin(s), std::end(s), f); return iterc(std::move(s)); })
def_iterator_manip(
sorted, {
    return v > sorted_by(std::less<V>());
})
def_iterator_manip(sorted_on, template<typename F>, (F f), <F>{f}, F f;, { return v > apply(FR(_, std::tuple(_, f(_)))) > sorted_by(FR(x, y, std::get<1>(x) < std::get<1>(y))) > apply(FR(_, std::get<0>(_))); })
 
 
// Nub iterator
def_iterator_manip(
nub, {
    iterator_macro(
        I it_end; I it;,
        it != other.it,
        { decltype(*it) pr; do { pr = *it; ++it; } while(it != it_end and pr == *it); },
        *it
    )
    auto b = std::begin(v);
    auto e = std::end(v);
    return iterable_wrapper(Iterator{e, b}, Iterator{e, e});
})
 
 
// Accum iterator
template<typename F, typename S>
struct accum_vector_by_ {
    using is_composable_ = void;
    size_t n; F f; S s;
    template_for_iterable(T, I, V)
    decltype(auto) operator () (const T& v) const {
        std::vector<std::decay_t<std::invoke_result_t<F, S, decltype(std::get<1>(std::declval<V>()))>>> u(n, s);
        for(auto&& [i, x] : v) {
            std::cout << std::tuple(i, x) << std::endl;
            u[i] = f(u[i], x);
        }
        return u;
    }
};
 
template<typename F, typename S>
constexpr auto accum_vector_by(size_t n, F f, const S& s) {
    return accum_vector_by_<F, S>{ n, f, s };
}
 
template<typename S>
constexpr auto accum_vector(size_t n, const S& s = S()) {
    auto f = FR(x, y, y);
    return accum_vector_by_<decltype(f), S>{ n, f, s };
}
    
template<typename F, typename S>
struct accum_map_by_ {
    using is_composable_ = void;
    F f; S s;
    template_for_iterable(T, I, V)
    decltype(auto) operator () (const T& v) const {
        std::map<std::decay_t<decltype(std::get<0>(std::declval<V>()))>, std::decay_t<std::invoke_result_t<F, S, decltype(std::get<1>(std::declval<V>()))>>> u;
        for(auto&& [i, x] : v) {
            if(u.count(i)) {
                u[i] = f(u[i], x);
            } else {
                u[i] = f(s, x);
            }
        }
        return u;
    }
};
 
template<typename F, typename S>
constexpr auto accum_map_by(F f, const S& s) {
    return accum_map_by_<F, S>{ f, s };
}
 
template<typename S>
constexpr auto accum_map(const S& s = S()) {
    auto f = FR(x, y, y);
    return accum_map_by_<decltype(f), S>{ f, s };
}
 
template<typename F, typename S>
struct accum_unordered_map_by_ {
    using is_composable_ = void;
    F f; S s;
    template_for_iterable(T, I, V)
    decltype(auto) operator () (const T& v) const {
        std::unordered_map<std::decay_t<decltype(std::get<0>(std::declval<V>()))>, std::decay_t<std::invoke_result_t<F, S, decltype(std::get<1>(std::declval<V>()))>>> u;
        for(auto&& [i, x] : v) {
            if(u.count(i)) {
                u[i] = f(u[i], x);
            } else {
                u[i] = f(s, x);
            }
        }
        return u;
    }
};
 
template<typename F, typename S>
constexpr auto accum_unordered_map_by(F f, const S& s) {
    return accum_unordered_map_by_<F, S>{ f, s };
}
 
template<typename S>
constexpr auto accum_unordered_map(const S& s = S()) {
    auto f = FR(x, y, y);
    return accum_unordered_map_by_<decltype(f), S>{ f, s };
}
 
 
// Istream iterator
template<typename T>
constexpr auto istream_iterable(std::istream& in) {
    iterator_macro(
        std::istream& in; mutable T val; bool is_end; mutable bool has_read;,
        is_end xor other.is_end,
        { if(not(in >> val)) { is_end = true; } },
        (has_read) ? (val) : (has_read = true, in >> val, val)
    )
    return iterable_wrapper(Iterator{ in, T{}, false, false }, Iterator{ in, T{}, true, true });
}
 
template<typename T>
constexpr auto input = istream_iterable<T>(std::cin);
 
 
// Ostream iterables
template<typename T>
std::ostream& print_iterable(std::ostream& out, const T& v, const std::string& sep = " ") {
    for(auto it = std::begin(v); it != std::end(v); ) {
        out << *it;
        ++it;
        if(it != std::end(v)) {
            out << sep;
        } else {
            return out;
        }
    }
    return out;
}
template<typename T, typename = typename T::is_iterable_wrapper>
constexpr std::ostream& operator << (std::ostream& out, const T& v) {
    return print_iterable(out, v);
}
 
#define def_iterable_ostream(I)                                     \
template<typename ...Ts>                                                \
std::ostream& operator << (std::ostream& out, const I<Ts...>& v) {      \
    return out << iter(v);                                          \
}
 
def_iterable_ostream(std::vector)
def_iterable_ostream(std::map)
def_iterable_ostream(std::unordered_map)
def_iterable_ostream(std::set)
def_iterable_ostream(std::unordered_set)
template<typename T, typename F>
class sparse_table {
private:
    std::vector<size_t> LOG2;
    F f;
    std::vector<std::vector<T>> st;
    
public:
    explicit sparse_table(F f_ = F()) : f(f_) { }
    template<typename I>
    explicit sparse_table(const I& v, F f_ = F()) : f(f_) {
        build(v);
    }
    template<typename I>
    void build(const I& v) {
        st.emplace_back(v > to_vector);
        LOG2.assign(st[0].size() + 1, 0);
        for(auto i : range(2, LOG2.size())) {
            LOG2[i] = LOG2[i / 2] + 1;
        }
        st.resize(LOG2[st[0].size()] + 1);
        for(auto j : range(1, st.size())) {
            st[j].resize(st[0].size() - (1 << j) + 1);
            for(auto i : range(st[j].size())) {
                st[j][i] = f(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    T range_query(size_t l, size_t r) {
        auto j = LOG2[r - l];
        return f(st[j][l], st[j][r - (1 << j)]);
    }
};
 
template<typename T, typename F, typename I>
auto make_sparse_table(const I& v, F f = F()) {
    return sparse_table<T, F>(v, f);
}
 
 
// Ostream tuples
template<typename U, size_t i, size_t s>
std::ostream& ostream_tuple_helper_(std::ostream& out, const U& u) {
    if constexpr(i == 0) {
        out << "{ ";
    }
    out << std::get<i>(u);
    if constexpr(i + 1 < s) {
        out << ", ";
        return ostream_tuple_helper_<U, i + 1, s>(out, u);
    } else {
        return out << " }";
    }
}
 
template<typename ...Ts>
std::ostream& operator << (std::ostream& out, const std::tuple<Ts...>& u) {
    return ostream_tuple_helper_<decltype(u), 0, sizeof...(Ts)>(out, u);
}
 
template<typename T, typename S>
std::ostream& operator << (std::ostream& out, const std::pair<T, S>& p) {
    return out << std::tuple(p.first, p.second);
}
 
 
using namespace std;
 
using LL = long long;
 
template <typename T>
struct Fenwick {
    int size; // = fen.size() (just to have a shorter name).
    int max_pow2; // = maximum integer such that (1 << max_pow2) <= N.
    // fen[xxx01...1] contains the sum of all the entries from
    // xxx00...0 to xxx01...1 inclusive.
    // i.e. fen[2] contains exactly the value of entry[2], whereas
    // fen[3] contains the sum entry[0] + entry[1] + entry[2] + entry[3].
    vector<T> fen;
 
    // The Fenwick tree is initialized leaving all entries with the value 0.
    Fenwick(int N) :
        size(N),
        max_pow2(log2(N)),
        fen(N, 0) {}
 
    // Initialize the Fenwick tree with the given values as entries.
    Fenwick(const vector<T>& init_vals) :
            Fenwick(init_vals.size()) {
        for (int p = 0; p < size; p++) {
            int q = p | (p+1);
            fen[p] += init_vals[p];
            if (q < size) fen[q] += fen[p];
        }
    }
 
    // Add x to the p-th entry.
    void Add(int p, T x) {
        for (; p < size; p |= (p+1)) fen[p] += x;
    }
 
    // Get the sum on the interval [l, r].
    T GetRange(int l, int r) {
        if (l > 0) return GetRange(0, r) - GetRange(0, l-1);
        T res = 0;
        for (; r >= 0; r = (r&(r+1))-1) res += fen[r];
        return res;
    }
 
    // Get the value of the p-th entry.
    T Get(int p) {
        return GetRange(p, p);
    }
    
    // Get the smallest p >= 0 such that GetRange(0, p) >= x.
    // If such a p does not exist, it returns size.
    // ACHTUNG: Works only if all values are nonnegative.
    int LowerBound(T x) {
        T sum = 0;
        int res = 0;
        for(int i = 1 << max_pow2; i > 0; i >>= 1) {
            if(res + i - 1 < size and sum + fen[res + i - 1] < x) {
                sum += fen[res + i - 1];
                res += i;
            }
        }
        return res;
    }
 
    // Set the p-th entry to x.
    void Set(int p, T x) {
        Add(p, x - Get(p));
    }
 
    // Prints the current state of the Fenwick tree.
    void Debug() {
        cout << "Internal container representation (size = " << size << "):\n";
        for (int i = 0; i < size; i++) cout << fen[i] << " ";
        cout << "\nValues of the entries:\n";
        for (int i = 0; i < size; i++) cout << Get(i) << " ";
        cout << "\n";
        cout.flush();
    }
};
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, W;
    cin >> N >> W;
    Fenwick<LL> F(W);
    for(int n = 0; n < N; ++n) {
        int L;
        cin >> L;
        vector<LL> V(L);
        for(LL& x : V) {
            cin >> x;
        }
        if(2 * L <= W) {
            LL m = 0;
            for(int l = 0; l < L; ++l) {
                m = max(m, V[l]);
                F.Add(l, m);
                F.Add(l + 1, -m);
            }
            m = 0;
            for(int l = 0; l < L; ++l) {
                m = max(m, V[L - l - 1]);
                F.Add(W - l - 1, m);
                F.Add(W - l, -m);
            }
            F.Add(L, m);
            F.Add(W - L, -m);
        } else {
            auto st = make_sparse_table<LL>(V, FV(a, b, max(a, b)));
            for(int i = 0; i < W; ++i) {
                LL v = st.range_query(max(0, i - (W - L)), min(L - 1, i) + 1);
                if(i < W - L or i >= L) {
                    v = max(v, 0LL);
                }
                F.Add(i, v);
                F.Add(i + 1, -v);
            }
        }
    }
    
    for(int i = 0; i < W; ++i) {
        cout << F.GetRange(0, i) << " ";
    }
    cout << "\n";
    
    return 0;
}