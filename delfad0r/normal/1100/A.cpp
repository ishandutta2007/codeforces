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

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> II;
typedef pair<int, LL> ILL;
typedef pair<LL, int> LLI;
typedef pair<LL, LL> LLLL;


// Generic iterables

template<typename I, typename = enable_if_t<not is_lvalue_reference<I>::value>>
class iter_type {
    const I b, e;
public:
    typedef I iterator;
    
    iter_type(I b, I e) : b(b), e(e) { }
    I begin() const {
        return b;
    }
    I end() const {
        return e;
    }
};

template<typename I>
auto iter(I b, I e) {
    return iter_type<I>(b, e);
}

template<typename T>
auto iter(T& v) {
    return iter_type<decltype(v.begin())>(v.begin(), v.end());
}

template<typename T>
auto iter(T&& v) {
    return iter_type<decltype(v.begin())>(v.begin(), v.end());
}

template<typename T>
auto iter(const T& v) {
    return iter_type<decltype(v.begin())>(v.begin(), v.end());
}


// Container carrying iterator

template<typename C>
class container_carrying_iterator : public C::iterator {
    shared_ptr<C> p;
public:
    container_carrying_iterator(shared_ptr<C> p, typename C::iterator it) :
        C::iterator(it), p(p) { }
};

template<typename C, typename = enable_if_t<not is_lvalue_reference<C>::value>>
auto iterc(C&& c) {
    shared_ptr<C> p(new C(c));
    return iter(container_carrying_iterator<C>(p, p->begin()), container_carrying_iterator<C>(p, p->end()));
}

template<typename C>
auto iterc(const C& c) {
    shared_ptr<C> p(new C(c));
    return iter(container_carrying_iterator<C>(p, p->begin()), container_carrying_iterator<C>(p, p->end()));
}

template<typename T>
auto iter(initializer_list<T> l) {
    vector<T> v(l);
    return iterc(move(v));
}


// Iterator base

template<typename T>
class iterator_base {
public:
    typedef ptrdiff_t difference_type;
    typedef typename remove_reference<T>::type value_type;
    typedef value_type& reference;
    typedef value_type* pointer;
    typedef input_iterator_tag iterator_category;
};

/*template<typename I, typename T, typename = enable_if_t<is_base_of<iterator_base<T>, I>::value>>
I operator ++ (I& it, int) {
    I copy = it;
    ++it;
    return copy;
}*/

class iterator_manip_base { };

template<typename T, typename H, typename = enable_if_t<is_base_of<iterator_manip_base, H>::value>>
auto operator > (const T& v, const H& helper) {
    return helper(iter(v));
}

template<typename T>
class from_iter_iterator_manip : public iterator_manip_base {
public:
    template<typename I>
    T operator () (const iter_type<I>& it) const {
        return T(it.begin(), it.end());
    }
};

template<typename T>
from_iter_iterator_manip<T> from_iter;

// Take iterator

class take_iterator_manip;

auto take(size_t);

template<typename I>
class take_iterator : public iterator_base<typename I::value_type> {
    friend take_iterator_manip;
    
    size_t cnt;
    I it;
public:
    decltype(auto) operator * () const {
        return *it;
    }
    take_iterator& operator ++ () {
        ++it;
        --cnt;
        return *this;
    }
    bool operator == (const take_iterator& other) const {
        return cnt == other.cnt or it == other.it;
    }
    bool operator != (const take_iterator& other) const {
        return cnt != other.cnt and it != other.it;
    }
protected:
    take_iterator(size_t cnt, I it) :
        cnt(cnt), it(it) { }
};

class take_iterator_manip : public iterator_manip_base {
    friend auto take(size_t);
    
    size_t cnt;
public:
    template<typename I>
    auto operator () (const iter_type<I>& it) const {
        return iter(take_iterator<I>(cnt, it.begin()), take_iterator<I>(0, it.end()));
    }
protected:
    take_iterator_manip(size_t cnt) :
        cnt(cnt) { }
};

auto take(size_t cnt) {
    return take_iterator_manip(cnt);
}


// Take-while iterator

template<typename F>
class take_while_iterator_manip;

template<typename F>
auto take_while(const F&);

template<typename I, typename F>
class take_while_iterator : public iterator_base<typename I::value_type> {
    friend take_while_iterator_manip<F>;
    
    const F f;
    I it;
    const I it_end;
    void check_end() {
        if(it != it_end and not f(*it)) {
            it = it_end;
        }
    }
public:
    decltype(auto) operator * () const {
        return *it;
    }
    take_while_iterator& operator ++ () {
        ++it;
        check_end();
        return *this;
    }
    take_while_iterator& operator = (const take_while_iterator& other) {
        it = other.it;
        return *this;
    }
    bool operator == (const take_while_iterator& other) const {
        return it == other.it;
    }
    bool operator != (const take_while_iterator& other) const {
        return it != other.it;
    }
protected:
    take_while_iterator(const F& f, I it, I it_end) :
        f(f), it(it), it_end(it_end) {
        check_end();
    }
};

template<typename F>
class take_while_iterator_manip : public iterator_manip_base {
    friend auto take_while<F>(const F&);
    
    const F f;
public:
    template<typename I>
    auto operator () (const iter_type<I>& it) const {
        return iter(take_while_iterator<I, F>(f, it.begin(), it.end()), take_while_iterator<I, F>(f, it.end(), it.end()));
    }
protected:
    take_while_iterator_manip(const F& f) :
        f(f) { }
};

template<typename F>
auto take_while(const F& f) {
    return take_while_iterator_manip<F>(f);
}


//Drop iterator

auto drop(size_t);

class drop_iterator_manip : public iterator_manip_base {
    friend auto drop(size_t);
    
    const size_t cnt;
public:
    template<typename I>
    auto operator () (const iter_type<I>& it) const {
        I b = it.begin(), e = it.end();
        for(size_t i = 0; i < cnt; ++i) {
            if(b == e) {
                break;
            }
            ++b;
        }
        return iter_type<I>(b, e);
    }
protected:
    drop_iterator_manip(size_t cnt) :
        cnt(cnt) { }
};

auto drop(size_t cnt) {
    return drop_iterator_manip(cnt);
}

auto tail = drop(1);


//Drop-while iterator

template<typename F>
auto drop_while(const F&);

template<typename F>
class drop_while_iterator_manip : public iterator_manip_base {
    friend auto drop_while<F>(const F&);
    
    const F f;
public:
    template<typename I>
    auto operator () (const iter_type<I>& it) const {
        I b = it.begin(), e = it.end();
        while(b != e and f(*it)) {
            ++b;
        }
        return iter_type<I>(b, e);
    }
protected:
    drop_while_iterator_manip(const F& f) :
        f(f) { }
};

template<typename F>
auto drop_while(const F& f) {
    return drop_while_iterator_manip<F>(f);
}


//At iterator

auto at(size_t);

class at_iterator_manip : public iterator_manip_base {
    friend auto at(size_t);
    
    const size_t cnt;
public:
    template<typename I>
    decltype(auto) operator () (const iter_type<I>& it) const {
        I b = it.begin();
        for(size_t i = 0; i < cnt; ++i) {
            ++b;
        }
        return *b;
    }
protected:
    at_iterator_manip(size_t cnt) :
        cnt(cnt) { }
};

auto at(size_t cnt) {
    return at_iterator_manip(cnt);
}

auto head = at(0);

// Apply iterator

template<typename F>
class apply_iterator_manip;

template<typename F>
auto apply(const F&);

template<typename I, typename F, typename T = result_of_t<F(typename I::reference)>>
class apply_iterator : public iterator_base<T> {    
    friend apply_iterator_manip<F>;
    
    const F f;
    I it;
public:
    decltype(auto) operator * () const {
        return f(*it);
    }
    apply_iterator& operator ++ () {
        ++it;
        return *this;
    }
    apply_iterator& operator = (const apply_iterator& other) {
        it = other.it;
        return *this;
    }
    bool operator == (const apply_iterator& other) const {
        return it == other.it;
    }
    bool operator != (const apply_iterator& other) const {
        return it != other.it;
    }
protected:
    apply_iterator(const F& f, I it) :
        f(f), it(it) { }
};

template<typename F>
class apply_iterator_manip : public iterator_manip_base {
    friend auto apply<F>(const F&);
    
    const F f;
public:
    template<typename I>
    auto operator () (const iter_type<I>& it) const {
        return iter(apply_iterator<I, F>(f, it.begin()), apply_iterator<I, F>(f, it.end()));
    }
protected:
    apply_iterator_manip(const F& f) :
        f(f) { }
};

template<typename F>
auto apply(const F& f) {
    return apply_iterator_manip<F>(f);
}


// Convert iterator

template<typename T>
class convert_iterator_manip;

template<typename I, typename T>
class convert_iterator : public iterator_base<T> {
    friend convert_iterator_manip<T>;
    
    I it;
public:
    T operator * () const {
        return *it;
    }
    convert_iterator& operator ++ () {
        ++it;
        return *this;
    }
    bool operator == (const convert_iterator& other) const {
        return it == other.it;
    }
    bool operator != (const convert_iterator& other) const {
        return it != other.it;
    }
protected:
    convert_iterator(I it) :
        it(it) { }
};

template<typename T>
class convert_iterator_manip : iterator_manip_base {
public:
    template<typename I>
    auto operator () (const iter_type<I>& it) const {
        return iter(convert_iterator<I, T>(it.begin()), convert_iterator<I, T>(it.end()));
    }
};

template<typename T>
convert_iterator_manip<T> convert;


// Fold iterator

template<typename F, typename S>
auto fold(const F&, const S&);

template<typename F, typename S>
class fold_iterator_manip : public iterator_manip_base {
    friend auto fold<F, S>(const F&, const S&);
    
    const F f;
    const S& s;
public:
    template<typename I>
    decltype(auto) operator () (const iter_type<I>& it) const {
        auto x = s;
        for(const auto& y : it) {
            x = f(x, y);
        }
        return x;
    }
protected:
    fold_iterator_manip(const F& f, const S& s) :
        f(f), s(s) { }
};

template<typename F, typename S>
auto fold(const F& f, const S& s) {
    return fold_iterator_manip<F, S>(f, s);
}


// Join iterator

template<typename I, typename J, typename T = typename I::value_type>
class join_iterator;

template<typename I, typename J>
auto operator + (const iter_type<I>& it1, const iter_type<J>& it2) {
    return iter(join_iterator<I, J>(it1, it2, it1.begin(), it2.begin()), join_iterator<I, J>(it1, it2, it1.end(), it2.end()));
}

template<typename I, typename J, typename T>
class join_iterator : public iterator_base<T> {
    friend auto operator + <>(const iter_type<I>&, const iter_type<J>&);
    
    I i1, i1_end;
    J i2;
    
    static_assert(is_convertible<typename J::value_type, T>::value, "Joining iterators with incompatible value types");
public:
    conditional_t<is_same<decltype(*i1), decltype(*i2)>::value, decltype(*i1), T> operator * () const {
        if(i1 == i1_end) {
            return *i2;
        } else {
            return *i1;
        }
    }
    join_iterator& operator ++ () {
        if(i1 == i1_end) {
            ++i2;
        } else {
            ++i1;
        }
        return *this;
    }
    bool operator == (const join_iterator& other) const {
        return i1 == other.i1 and i2 == other.i2;
    }
    bool operator != (const join_iterator& other) const {
        return (i1 != other.i1) or (i2 != other.i2);
    }
protected:
    join_iterator(const iter_type<I>& it1, const iter_type<J>&, I i1, J i2) :
        i1(i1), i1_end(it1.end()), i2(i2) { }
};


// Concat iterator

class concat_iterator_manip;

template<typename J, typename I = typename J::value_type::iterator>
class concat_iterator : public iterator_base<typename I::value_type> {
    friend concat_iterator_manip;
    
    mutable bool init, is_end;
    mutable J its;
    const J its_end;
    mutable shared_ptr<I> pit, pit_end;
    
    void skip_empty() const {
        while(*pit == *pit_end) {
            ++its;
            if(its == its_end) {
                is_end = true;
                break;
            } else {
                auto tmp = *its;
                *pit = tmp.begin();
                *pit_end = tmp.end();
            }
        }
    }
public:
    decltype(auto) operator * () const {
        if(not init) {
            init = true;
            auto tmp = *its;
            pit = shared_ptr<I>(new I(tmp.begin()));
            pit_end = shared_ptr<I>(new I(tmp.end()));
            skip_empty();
        }
        return **pit;
    }
    concat_iterator& operator ++ () {
        ++*pit;
        skip_empty();
        return *this;
    }
    bool operator == (const concat_iterator& other) const {
        return is_end and other.is_end;
    }
    bool operator != (const concat_iterator& other) const {
        return (not is_end) or (not other.is_end);
    }
protected:
    concat_iterator(J its, J its_end, bool is_end) :
        init(false), is_end(is_end), its(its), its_end(its_end), pit() { }
};

class concat_iterator_manip : public iterator_manip_base {
public:
    template<typename J>
    auto operator () (const iter_type<J>& its) const {
        return iter(concat_iterator<J>(its.begin(), its.end(), false), concat_iterator<J>(its.end(), its.end(), true));
    }
} concat;


// Concat-map iterator

template<typename I, typename F>
auto operator >= (const iter_type<I>& it, const F& f) {
    return it > apply(f) > concat;
}


// Zip iterator

template<typename F, typename ...Is>
class zip_iterator;

template<typename F, typename ...Is>
auto zip(const F& f, const iter_type<Is>&... its) {
    return iter(zip_iterator<F, Is...>(f, its.begin()...), zip_iterator<F, Is...>(f, its.end()...));
}

template<typename F, typename ...Is>
class zip_iterator : public iterator_base<result_of_t<F(typename Is::reference...)>> {
    friend iter_type<zip_iterator<F, Is...>> zip<>(const F&, const iter_type<Is>&...);
    
    const F f;
    tuple<Is...> it;
    
    template<size_t ...Seq>
    decltype(auto) call_f(index_sequence<Seq...>) const {
        return f(*get<Seq>(it)...);
    }
    template<size_t N = 0>
    enable_if_t<N == sizeof...(Is), void> incr_it() { }
    template<size_t N = 0>
    enable_if_t<N < sizeof...(Is), void> incr_it() {
        ++get<N>(it);
        incr_it<N + 1>();
    }
    template<size_t N = 0>
    enable_if_t<N == sizeof...(Is), bool> eq(const zip_iterator&) const {
        return false;
    }
    template<size_t N = 0>
    enable_if_t<N < sizeof...(Is), bool> eq(const zip_iterator& other) const {
        return get<N>(it) == get<N>(other.it) or eq<N + 1>(other);
    }
public:
    decltype(auto) operator * () const {
        return call_f(index_sequence_for<Is...>{});
    }
    zip_iterator& operator ++ () {
        incr_it();
        return *this;
    }
    zip_iterator& operator = (const zip_iterator& other) {
        it = other.it;
        return *this;
    }
    bool operator == (const zip_iterator& other) const {
        return eq(other);
    }
    bool operator != (const zip_iterator& other) const {
        return not eq(other);
    }
protected:
    zip_iterator(const F& f, Is... its) :
        f(f), it(its...) { }
};


// Filter iterator

template<typename F>
class filter_iterator_manip;

template<typename F>
auto filter(const F& f);

template<typename I, typename F, typename T = typename I::value_type>
class filter_iterator : public iterator_base<T> {
    friend filter_iterator_manip<F>;
    
    const F f;
    I it;
    const I it_end;
    
    void skip_false() {
        while(it != it_end and not f(*it)) {
            ++it;
        }
    }
public:
    decltype(auto) operator * () const {
        return *it;
    }
    filter_iterator& operator ++ () {
        ++it;
        skip_false();
        return *this;
    }
    filter_iterator& operator = (const filter_iterator& other) {
        it = other.it;
        return *this;
    }
    bool operator == (const filter_iterator& other) const {
        return it == other.it;
    }
    bool operator != (const filter_iterator& other) const {
        return it != other.it;
    }
protected:
    filter_iterator(const F& f, I it, I it_end):
        f(f), it(it), it_end(it_end) {
        skip_false();
    }
};

template<typename F>
class filter_iterator_manip : public iterator_manip_base {
    friend auto filter<F>(const F&);
    
    const F f;
public:
    template<typename I>
    auto operator () (const iter_type<I>& it) const {
        return iter(filter_iterator<I, F>(f, it.begin(), it.end()), filter_iterator<I, F>(f, it.end(), it.end()));
    }
protected:
    filter_iterator_manip(const F& f) :
        f(f) { }
};

template<typename F>
auto filter(const F& f) {
    return filter_iterator_manip<F>(f);
}


// Repeat iterator

template<typename T>
class repeat_iterator;

template<typename T>
iter_type<repeat_iterator<T>> repeat(const T& v) {
    return iter(repeat_iterator<T>(v), repeat_iterator<T>());
}

template<typename T>
class repeat_iterator : public iterator_base<T> {
    friend iter_type<repeat_iterator<T>> repeat<>(const T&);
    
    const T v;
public:
    const T& operator * () const {
        return v;
    }
    repeat_iterator& operator ++ () {
        return *this;
    }
    bool operator == (const repeat_iterator&) const {
        return false;
    }
    bool operator != (const repeat_iterator&) const {
        return true;
    }
protected:
    repeat_iterator(const T& v = T()) :
        v(v) { }
};


// Replicate iterator

template<typename T>
class replicate_iterator;

template<typename T>
auto replicate(size_t cnt, const T& v) {
    return iter(replicate_iterator<T>(cnt, v), replicate_iterator<T>(0, v));
}

template<typename T>
class replicate_iterator : public iterator_base<T> {
    friend auto replicate<>(size_t, const T&);
    
    size_t cnt;
    const T v;
public:
    const T& operator * () const {
        return v;
    }
    replicate_iterator& operator ++ () {
        --cnt;
        return *this;
    }
    bool operator == (const replicate_iterator& other) const {
        return cnt == other.cnt;
    }
    bool operator != (const replicate_iterator& other) const {
        return cnt != other.cnt;
    }
protected:
    replicate_iterator(size_t cnt, const T& v) :
        cnt(cnt), v(v) { }
};


// Range iterator

template<typename T>
class range_iterator;

template<typename T>
iter_type<range_iterator<T>> range(const T& e) {
    return iter(range_iterator<T>(0, e, 1), range_iterator<T>());
}

template<typename T>
iter_type<range_iterator<T>> range(const T& b, const T& e, const T& step = T(1)) {
    return iter(range_iterator<T>(b, e, step), range_iterator<T>());
}

template<typename T>
iter_type<range_iterator<T>> to_infinity(const T& b = T(0), const T& step = T(1)) {
    return iter(range_iterator<T>(b, numeric_limits<T>::max(), step), range_iterator<T>());
}

template<typename T>
class range_iterator : public iterator_base<T> {
    friend iter_type<range_iterator> range<>(const T&);
    friend iter_type<range_iterator> range<>(const T&, const T&, const T&);
    friend iter_type<range_iterator> to_infinity<>(const T& b, const T&);
    
    T b, e, step;
    bool is_end;
    bool check_end() {
        return (step >= 0 and b >= e) or (step <= 0 and b <= e);
    }
public:
    T operator * () const {
        return b;
    }
    range_iterator& operator ++ () {
        b += step;
        if(check_end()) {
            is_end = true;
        }
        return *this;
    }
    bool operator == (const range_iterator& other) const {
        return is_end and other.is_end;
    }
    bool operator != (const range_iterator& other) const {
        return (not is_end) or (not other.is_end);
    }
protected:
    range_iterator() :
        is_end(true) { }
    range_iterator(const T& b, const T& e, const T& step) :
        b(b), e(e), step(step), is_end(check_end()) { }
};


// Nub iterator

class nub_iterator_manip;

template<typename I, typename T = typename I::value_type>
class nub_iterator : public iterator_base<T> {
    friend nub_iterator_manip;
    
    I it;
    const I it_end;
public:
    decltype(auto) operator * () const {
        return *it;
    }
    nub_iterator& operator ++ () {
        T v = *it;
        ++it;
        while(it != it_end and v == *it) {
            ++it;
        }
        return *this;
    }
    bool operator == (const nub_iterator& other) const {
        return it == other.it;
    }
    bool operator != (const nub_iterator& other) const {
        return it != other.it;
    }
protected:
    nub_iterator(I it, I it_end):
        it(it), it_end(it_end) { }
};

class nub_iterator_manip : iterator_manip_base {
public:
    template<typename I>
    auto operator () (const iter_type<I>& it) const {
        return iter(nub_iterator<I>(it.begin(), it.end()), nub_iterator<I>(it.end(), it.end()));
    }
} nub;


// Sorted iterator

template<typename Cmp>
auto sorted_cmp(const Cmp&);

template<typename Cmp>
class sorted_iterator_manip : public iterator_manip_base {
    friend auto sorted_cmp<Cmp>(const Cmp&);
    
    const Cmp cmp;
public:
    template<typename I, typename T = typename I::value_type, typename CCI = container_carrying_iterator<vector<T>>>
    auto operator () (const iter_type<I>& it) const {
        shared_ptr<vector<T>> p(new vector<T>(it.begin(), it.end()));
        sort(p->begin(), p->end(), cmp);
        return iter_type<CCI>(CCI(p, p->begin()), CCI(p, p->end()));
    }
protected:
    sorted_iterator_manip(const Cmp& cmp) :
        cmp(cmp) { }
};

template<>
class sorted_iterator_manip<void> : public iterator_manip_base {
public:
    template<typename I, typename T = typename I::value_type, typename CCI = container_carrying_iterator<vector<T>>>
    auto operator () (const iter_type<I>& it) const {
        shared_ptr<vector<T>> p(new vector<T>(it.begin(), it.end()));
        sort(p->begin(), p->end());
        return iter_type<CCI>(CCI(p, p->begin()), CCI(p, p->end()));
    }
};

sorted_iterator_manip<void> sorted;

template<typename Cmp>
auto sorted_cmp(const Cmp& cmp) {
    return sorted_iterator_manip<Cmp>(cmp);
}


// I/O for pairs and iterables

template<typename S, typename T>
ostream& operator << (ostream& out, const pair<S, T>& p) {
    return out << "{" << p.first << ", " << p.second << "}";
}

template<typename S, typename T>
istream& operator >> (istream& in, pair<S, T>& p) {
    return in >> p.first >> p.second;
}

template<typename I>
ostream& operator << (ostream& out, const iter_type<I>& x) {
    out << "[";
    for(auto it = x.begin(); it != x.end();) {
        out << *it;
        if(++it != x.end()) {
            out << ", ";
        }
    }
    return out << "]";
}

template<typename I>
istream& operator >> (istream& in, const iter_type<I>& x) {
    for(I it = x.begin(); it != x.end(); ++it) {
        in >> *it;
    }
    return in;
}

template<typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
    return out << iter(v);
}

template<typename T>
istream& operator >> (istream& in, vector<T>& v) {
    return in >> iter(v);
}

template<typename T>
ostream& operator << (ostream& out, const set<T>& v) {
    return out << iter(v);
}

template<typename S, typename T>
ostream& operator << (ostream& out, const map<S, T>& v) {
    return out << iter(v);
}

template<typename T>
ostream& operator << (ostream& out, const unordered_set<T>& v) {
    return out << iter(v);
}

template<typename S, typename T>
ostream& operator << (ostream& out, const unordered_map<S, T>& v) {
    return out << iter(v);
}


// Fenwick tree

template<typename T, typename Op = plus<T>>
class fenwick_tree {
    const int N, max_pow2;
    vector<T> ft;
    const Op op;
public:
    explicit fenwick_tree(int N, const T& val = T(), const Op& op = Op()) :
        N(N), max_pow2(log2(N)), ft(N, val), op(op) { }
    template<typename I>
    fenwick_tree(const iter_type<I>& it, const Op& op = Op()) :
        fenwick_tree(it.size(), T(), op) {
        int p = 0, q;
        for(auto x : it) {
            q = p | (p + 1);
            ft[p] = op(ft[p], x);
            if(q < N) {
                ft[q] = op(ft[q], ft[p]);
            }
            ++p;
        }
    }
    void update(int p, const T& v) {
        for(; p < N; p |= p + 1) {
            ft[p] = op(ft[p], v);
        }
    }
    T get_prefix(int r) {   // [0, r)
        --r;
        T ans = T();
        for(; r >= 0; r = (r & (r + 1)) - 1) {
            ans = op(ans, ft[r]);
        }
        return ans;
    }
    T get_range(int l, int r) { // [l, r)
        return get_prefix(r) - get_prefix(l);
    }
    T get(int p) {
        return get_range(p, p + 1);
    }
    int lower_bound(const T& x) {   // min{p : get_prefix(p) >= x}, assuming get_prefix(p) is an increasing function of p
        T total = T();
        int ans = 0;
        for(int i = 1 << max_pow2; i > 0; i >>= 1) {
            if(ans + i - 1 < int(N) and op(total, ft[ans + i - 1]) <= x) {
                total = op(total, ft[ans + i - 1]);
                ans += i;
            }
        }
        return ans;
    }
};


// Range tree

template<typename Idx>
struct interval_t {
    Idx l, r;
    interval_t(const Idx l, const Idx r) :
        l(l), r(r) { }
    Idx size() const {
        return r - l;
    }
};

template<typename Idx>
bool disjoint_interval(const interval_t<Idx>& a, const interval_t<Idx>& b) {
    return a.r <= b.l or b.r <= a.l;
}

template<typename Idx>
bool contained_interval(const interval_t<Idx>& a, const interval_t<Idx>& b) {
    return b.l <= a.l and a.r <= b.r;
}

template<typename Idx>
void left(interval_t<Idx>& a) {
    a.r = 2 * a.l - a.r;
    swap(a.l, a.r);
}

template<typename Idx>
void right(interval_t<Idx>& a) {
    a.l = 2 * a.r - a.l;
    swap(a.l, a.r);
}

template<typename Idx>
void left_half(interval_t<Idx>& a) {
    a.r = (a.r + a.l) / 2;
}

template<typename Idx>
void right_half(interval_t<Idx>& a) {
    a.l = (a.r + a.l) / 2;
}

template<typename Idx>
void left_double(interval_t<Idx>& a) {
    a.l = 2 * a.l - a.r;
}

template<typename Idx>
void right_double(interval_t<Idx>& a) {
    a.r = 2 * a.r - a.l;
}

template<typename Idx, typename T>
class contiguous_binary_tree {
    const Idx size;
    vector<T> tree;
public:
    class iterator {
        contiguous_binary_tree<Idx, T>* my_tree;
        Idx i;
        interval_t<Idx> interval;
    public:
        explicit iterator(contiguous_binary_tree<Idx, T>* t) :
            my_tree(t), i(1), interval(0, t->size) { }
        iterator(contiguous_binary_tree<Idx, T>* t, Idx leaf_index) :
            my_tree(t), i(t->size + leaf_index), interval(leaf_index, leaf_index + 1) { }
        void go_up() {
            if(i & 1) {
                left_double(interval);
            } else {
                right_double(interval);
            }
            i /= 2;
        }
        void go_left() {
            left_half(interval);
            i *= 2;
        }
        void go_right() {
            right_half(interval);
            i = i * 2 + 1;
        }
        iterator father_node() const {
            iterator other = *this;
            other.go_up();
            return other;
        }
        iterator left_child() const {
            iterator other = *this;
            other.go_left();
            return other;
        }
        iterator right_child() const {
            iterator other = *this;
            other.go_right();
            return other;
        }
        void modify() {
            
        }
        iterator& operator ++ () {
            ++i;
            if(i & (i - 1)) {
                left(interval);
            } else {
                interval = interval_t<Idx>(0, interval.size() / 2);
            }
            return *this;
        }
        iterator operator ++ (int) {
            iterator other = *this;
            operator ++ ();
            return other;
        }
        iterator& operator -- () {
            --i;
            if(i & (i + 1)) {
                right(interval);
            } else {
                interval = interval_t<Idx>(my_tree->size - interval.size() / 2, my_tree->size);
            }
            return *this;
        }
        iterator operator -- (int) {
            iterator other = *this;
            operator -- ();
            return other;
        }
        T& operator * () {
            return my_tree->tree[i];
        }
        T* operator -> () {
            return &(my_tree->tree[i]);
        }
        bool is_root() const {
            return i == 1;
        }
        bool is_leaf() const {
            return i >= my_tree->size;
        }
        Idx get_index() const {
            return i;
        }
        Idx get_leaf_index() const {
            return i - my_tree->size;
        }
        Idx left_index() const {
            return interval.l;
        }
        Idx right_index() const {
            return interval.r;
        }
        interval_t<Idx> get_interval() const {
            return interval;
        }
        bool is_end() const {
            return interval.size() == 0;
        }
    };
    
    explicit contiguous_binary_tree(Idx size) :
        size(size), tree(size * 2) { }
    iterator get_root() {
        return iterator(this);
    }
    iterator get_leaf(Idx i) {
        return iterator(this, i);
    }
};

template<
    typename Idx,
    typename T,
    template<typename, typename> class BinaryTree,
    typename Merge,
    typename Operation>
class range_tree {
    class vertex {
        bool pending_operation;
        Operation op;
    public:
        T val;
        
        vertex() :
            pending_operation(false) { }
        bool no_op() const {
            return not pending_operation;
        }
        const Operation& get_operation() const {
            return op;
        }
        void new_operation(const Operation& new_op, Idx size) {
            if(no_op()) {
                pending_operation = true;
                op = new_op;
            } else {
                op.append(new_op);
            }
            new_op.apply(val, size);
        }
        void delete_operation() {
            pending_operation = false;
        }
    };
    typedef typename BinaryTree<Idx, vertex>:: iterator iterator;
    
    static Idx get_pow2_size(Idx sz) {
        Idx ans = 1;
        while(ans < sz) {
            ans *= 2;
        }
        return ans;
    }
    
    const Merge merge;
    mutable BinaryTree<Idx, vertex> tree;
    
    void propagate_operation(iterator it) const {
        if(it->no_op()) {
            return;
        }
        Idx l = it.left_index(), r = it.right_index();
        Idx m = (l + r) / 2, half_size = (r - l) / 2;
        it.left_child()->new_operation(it->get_operation().restrict(l, m, l, r), half_size);
        it.right_child()->new_operation(it->get_operation().restrict(m, r, l, r), half_size);
        it->delete_operation();
    }
    iterator _apply_range_operation(iterator it, const interval_t<Idx>& interval, const Operation& op) {
        if(disjoint_interval(it.get_interval(), interval)) {
            return it;
        }
        it.modify();
        if(contained_interval(it.get_interval(), interval)) {
            auto restr = op.restrict(it.left_index(), it.right_index(), interval.l, interval.r);
            it->new_operation(restr, it.get_interval().size());
            return it;
        }
        propagate_operation(it);
        _apply_range_operation(it.left_child(), interval, op);
        _apply_range_operation(it.right_child(), interval, op);
        it->val = merge(it.left_child()->val, it.right_child()->val);
        return it;
    }
    T _get_range(iterator it, const interval_t<Idx>& interval) const {
        if(contained_interval(it.get_interval(), interval)) {
            return it->val;
        }
        propagate_operation(it);
        if(disjoint_interval(it.left_child().get_interval(), interval)) {
            return _get_range(it.right_child(), interval);
        }
        if(disjoint_interval(it.right_child().get_interval(), interval)) {
            return _get_range(it.left_child(), interval);
        }
        return merge(_get_range(it.left_child(), interval), _get_range(it.right_child(), interval));
    }
public:
    range_tree(Idx size, const Merge& merge) :
        merge(merge), tree(get_pow2_size(size)) { }
    template<typename I>
    range_tree(Idx size, iter_type<I> initial_values, const Merge& merge) :
        range_tree(size, merge) {
        auto it = tree.get_leaf(0);
        auto j = (initial_values + repeat(Operation::get_identity())).begin();
        for(; not it.is_end(); ++it) {
            it->val = *j++;
        }
        it = tree.get_leaf(0);
        while(not it.is_root()) {
            --it;
            it->val = merge(it.left_child()->val, it.right_child()->val);
        }
    }
    T get_range(Idx l, Idx r) const {
        return get_range(l, r, tree.get_root());
    }
    T get_range(Idx l, Idx r, iterator root) const {
        interval_t<Idx> interval(l, r);
        if(l > r or disjoint_interval(root.get_interval(), interval)) {
            return Operation::get_identity();
        }
        return _get_range(root, interval);
    }
    T get_value(Idx i) const {
        return get_value(i, tree.get_root());
    }
    T get_value(Idx i, iterator root) const {
        return _get_range(root, interval_t<Idx>(i, i + 1));
    }
    iterator apply_range_operation(Idx l, Idx r, const Operation& op) {
        return apply_range_operation(l, r, op, tree.get_root());
    }
    iterator apply_range_operation(Idx l, Idx r, const Operation& op, iterator root) {
        return _apply_range_operation(root, interval_t<Idx>(l, r), op);
    }
    iterator apply_operation(Idx i, const Operation& op) {
        return apply_operation(i, op, tree.get_root());
    }
    iterator apply_operation(Idx i, const Operation& op, iterator root) {
        return _apply_range_operation(root, interval_t<Idx>(i, i + 1), op);
    }
};

template<
    typename T,
    template<typename, typename> class BinaryTree,
    typename Operation,
    typename Idx,
    typename Merge>
auto make_range_tree(Idx size, const Merge& merge) {
    return range_tree<Idx, T, BinaryTree, Merge, Operation>(size, merge);
}

template<
    typename T,
    template<typename, typename> class BinaryTree,
    typename Operation,
    typename Idx,
    typename Merge,
    typename I>
auto make_range_tree(Idx size, iter_type<I> initial_values, const Merge& merge) {
    return range_tree<Idx, T, BinaryTree, Merge, Operation>(size, initial_values, merge);
}

template<
    typename T,
    template<typename, typename> class BinaryTree,
    typename Operation,
    typename Idx,
    typename Merge>
auto make_range_tree(Idx size, const T& initial_value, const Merge& merge) {
    return range_tree<Idx, T, BinaryTree, Merge, Operation>(size, repeat(initial_value), merge);
}

template<typename T, typename Idx>
class operation_base {
    static T get_identity();
    operation_base restrict(Idx new_l, Idx new_r, Idx old_l, Idx old_r) const;
    void append(const operation_base& other);
    void apply(T& v, Idx sz) const;
};


// Random utility functions (be specific, don't abuse this section)

template<typename T>
void remove_duplicates(vector<T>& v) {  // v should be sorted
    v.erase(unique(v.begin(), v.end()), v.end());
}



//////////////////////
// HAPPY CODING  :) //
//////////////////////

template<typename T>
struct my_op {
    static T get_identity() {
        return 0;
    }
    T v = 0;
    my_op<T> restrict(int, int, int, int) const {
        return *this;
    }
    void append(const my_op& other) {
        v += other.v;
    }
    void apply(T& x, int sz) const {
        x += v * sz;
    }
};

int main() {
    // remove in interactive problems
    #ifdef DEBUG
    freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //
    
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    cin >> v;
    int s = v > fold(plus<int>(), 0);
    cout << (
        range(k)
        > apply([=](int b) {
            return abs(s - 
                (range(b, n, k)
                > apply([=](int i) { return v[i]; })
                > fold(plus<int>(), 0)));
            })
        > fold([](int x, int y) { return max(x, y); }, 0))
    << "\n";
    
    
    return 0;
}