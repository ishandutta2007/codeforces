//https://codeforces.com/contest/1114/problem/F
#include <iostream>
#include <fstream>
#include <iomanip>
#include <bits/stdc++.h>
#include <chrono>
#include <random>

using std::bitset;
using std::cerr;
using std::deque;
using std::endl;
using std::fill;
using std::ios_base;
using std::istream;
using std::iterator;
using std::make_pair;
using std::map;
using std::max;
using std::min;
using std::numeric_limits;
using std::ostream;
using std::pair;
using std::priority_queue;
using std::set;
using std::sort;
using std::string;
using std::swap;
using std::unordered_map;
using std::vector;

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args)
{
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << ": " << arg1 << " |";
    __f(comma + 1, args...);
}

const int K = 62;
const int PRIME = 1e9 + 7;

namespace dalt
{
};
namespace other
{
};

using namespace dalt;

namespace dalt
{
class EulerSieve
{
private:
    vector<int> _primes;
    vector<bool> _isComp;

public:
    EulerSieve(int limit)
    {
        _primes.reserve(limit + 1);
        _isComp.resize(limit + 1);
        for (int i = 2; i <= limit; i++)
        {
            if (!_isComp[i])
            {
                _primes.push_back(i);
            }
            for (int p : _primes)
            {
                if (p > limit / i)
                {
                    break;
                }
                int pi = p * i;
                _isComp[pi] = true;
                if (i % p == 0)
                {
                    break;
                }
            }
        }
    }

    vector<int> &primes()
    {
        return _primes;
    }

    bool isPrime(int x)
    {
        return x >= 2 && !_isComp[x];
    }
};
} // namespace dalt

namespace dalt
{

#define MOD(a, b) \
    a %= b;       \
    if (a < 0)    \
        a += b;

template <int M>
class Remainder
{
public:
    typedef long long ll;

    Remainder() : _v(0) {}

    Remainder(const int &v) : _v(v){MOD(_v, M)} 
    
    Remainder(ll v)
    {
        MOD(v, M);
        _v = v;
    }

    template <int ANY>
    Remainder(const Remainder<ANY> &x) : _v(x._v) {}

    template <int ANY>
    Remainder<M> &operator=(Remainder<ANY> &x)
    {
        _v = x._v;
        return *this;
    }

    template <int ANY>
    Remainder<M> &operator=(const Remainder<ANY> &x)
    {
        _v = x._v;
        return *this;
    }
    template <int E>
    friend Remainder<E> operator+(const Remainder<E> &a, const Remainder<E> &b);
    template <int E>
    friend Remainder<E> operator-(const Remainder<E> &a, const Remainder<E> &b);
    template <int E>
    friend Remainder<E> operator*(const Remainder<E> &a, const Remainder<E> &b);

    Remainder<M> &operator+=(Remainder<M> &x)
    {
        _v += x._v;
        MOD(_v, M);
        return *this;
    }

    Remainder<M> &operator-=(Remainder<M> &x)
    {
        _v -= x._v;
        MOD(_v, M);
        return *this;
    }

    Remainder<M> &operator+=(const Remainder<M> &x)
    {
        _v += x._v;
        MOD(_v, M);
        return *this;
    }

    Remainder<M> &operator-=(const Remainder<M> &x)
    {
        _v -= x._v;
        MOD(_v, M);
        return *this;
    }

    Remainder<M> &operator*=(Remainder<M> &x)
    {
        ll tmp = (ll)_v * x._v;
        MOD(tmp, M);
        _v = tmp;
        return *this;
    }

    Remainder<M> &operator*=(const Remainder<M> &x)
    {
        ll tmp = (ll)_v * x._v;
        MOD(tmp, M);
        _v = tmp;
        return *this;
    }

    Remainder<M> operator^(int n) const { return pow(_v, n); }

    Remainder<M> operator^(ll n) const { return pow(_v, n); }

    Remainder<M> inverseByFermat() const { return pow(_v, M - 2); }

    Remainder<M> inverseByExtgcd() const { return extgcd(M, _v).second; }

    Remainder<M> operator/(const Remainder<M> &x) const { return (*this) * x.inverseByExtgcd(); }

    Remainder<M> &operator/=(Remainder<M> &x)
    {
        ll tmp = (ll)_v * extgcd(M, _v).second;
        MOD(tmp, M);
        _v = tmp;
        return *this;
    }

    Remainder<M> &operator/=(const Remainder<M> &x)
    {
        ll tmp = (ll)_v * extgcd(M, _v).second;
        MOD(tmp, M);
        _v = tmp;
        return *this;
    }

    int value() const { return _v; }

    template <int E>
    friend bool operator==(const Remainder<E> &a, const Remainder<E> &b);

    template <int E>
    friend bool operator!=(const Remainder<E> &a, const Remainder<E> &b);

private:
    int _v;

    template <typename L>
    static int pow(int x, L n)
    {
        if (n == 0)
        {
            return 1 % M;
        }
        ll ans = pow(x, n >> 1);
        ans = ans * ans % M;
        if (n & 1)
        {
            ans = ans * x % M;
        }
        return ans;
    }

    static pair<ll, ll> extgcd(ll a, ll b)
    {
        if (a >= b)
        {
            return extgcd0(a, b);
        }
        pair<ll, ll> xy = extgcd0(b, a);
        swap(xy.first, xy.second);
        return xy;
    }

    static pair<ll, ll> extgcd0(ll a, ll b)
    {
        if (b == 0)
        {
            return {1, 0};
        }
        pair<ll, ll> xy = extgcd0(b, a % b);
        return {xy.second, xy.first - xy.second * (a / b)};
    }
};

template <int M>
inline Remainder<M> operator+(const Remainder<M> &a, const Remainder<M> &b)
{
    return a._v + b._v;
}
template <int M>
inline Remainder<M> operator-(const Remainder<M> &a, const Remainder<M> &b)
{
    return a._v - b._v;
}
template <int M>
inline Remainder<M> operator*(const Remainder<M> &a, const Remainder<M> &b)
{
    return (ll)a._v * b._v;
}
template <int M>
inline bool operator==(const Remainder<M> &a, const Remainder<M> &b)
{
    return a._v == b._v;
}
template <int M>
inline bool operator!=(const Remainder<M> &a, const Remainder<M> &b)
{
    return a._v != b._v;
}

template <int M>
inline ostream &operator<<(ostream &os, const Remainder<M> &x)
{
    return os << x.value();
}

template <int M>
inline istream &operator>>(istream &is, Remainder<M> &x)
{
    ll val;
    is >> val;
    x = val;
    return is;
}

#undef MOD
} // namespace dalt

typedef Remainder<PRIME> rmd;

namespace dalt
{
class segment
{
public:
    segment(int l, int r) : _dirty(1), _val(1)
    {
        int m = (l + r) >> 1;
        if (l < r)
        {
            _l = new segment(l, m);
            _r = new segment(m + 1, r);
            _size = _l->_size + _r->_size;
        }
        else
        {
            _size = 1;
        }
    }

#define NO_INTERSECTION ql > r || qr < l
#define COVER ql <= l &&qr >= r
#define RANGE (min(qr, r) - max(l, ql) + 1)

    void update(int ql, int qr, int l, int r, const rmd &x)
    {
        if (NO_INTERSECTION)
        {
            return;
        }
        if (COVER)
        {
            modify(x);
            return;
        }
        pushDown();
        int m = (l + r) >> 1;
        _l->update( ql, qr, l, m, x);
        _r->update( ql, qr, m + 1, r, x);
        pushUp();
    }

    rmd query(int ql, int qr, int l, int r)
    {
        if (NO_INTERSECTION)
        {
            return 1;
        }
        if (COVER)
        {
            return _val;
        }
        pushDown();
        int m = (l + r) >> 1;
        return _l->query(ql, qr, l, m) *
               _r->query(ql, qr, m + 1, r);
    }

#undef NO_INTERSECTION
#undef COVER

private:
    segment *_l, *_r;
    rmd _val;
    rmd _dirty;
    rmd _size;

    void modify(const rmd &x)
    {
        _dirty *= x;
        _val *= x ^ _size.value();
    }

    void pushDown()
    {
        if (_dirty.value() != 1)
        {
            _l->modify( _dirty);
            _r->modify( _dirty);
            _dirty = 1;
        }
    }

    void pushUp()
    {
        _val = (_l->_val * _r->_val);
    }
};

} // namespace dalt

namespace dalt
{
class segment_bit
{
public:
    segment_bit(int l, int r) : _mask(0), _dirty(0)
    {
        int m = (l + r) >> 1;
        if (l < r)
        {
            _l = new segment_bit(l, m);
            _r = new segment_bit(m + 1, r);
        }
        else
        {
        }
    }

#define NO_INTERSECTION ql > r || qr < l
#define COVER ql <= l &&qr >= r
#define RANGE (min(qr, r) - max(l, ql) + 1)

    void update(int ql, int qr, int l, int r, const ll &x)
    {
        if (NO_INTERSECTION)
        {
            return;
        }
        if (COVER)
        {
            modify(x);
            return;
        }
        pushDown();
        int m = (l + r) >> 1;
        _l->update( ql, qr, l, m, x);
        _r->update( ql, qr, m + 1, r, x);
        pushUp();
    }

    ll query(int ql, int qr, int l, int r)
    {
        if (NO_INTERSECTION)
        {
            return 0;
        }
        if (COVER)
        {
            return _mask;
        }
        pushDown();
        int m = (l + r) >> 1;
        return _l->query(ql, qr, l, m) |
               _r->query(ql, qr, m + 1, r);
    }

#undef NO_INTERSECTION
#undef COVER

private:
    segment_bit *_l, *_r;
    ll _mask;
    ll _dirty;

    void modify(const ll &x)
    {
        _mask |= x;
        _dirty |= x;
    }

    void pushDown()
    {
        if (_dirty)
        {
            _l->modify( _dirty);
            _r->modify( _dirty);
            _dirty = 0;
        }
    }

    void pushUp()
    {
        _mask = (_l->_mask | _r->_mask);
    }
};

} // namespace dalt

int n, q;
vector<int> primes;
vector<int> invPrimes;
segment *segtree;
segment_bit *bits;

void mul(int l, int r, int x)
{
    ll mask = 0;
    for (int i = 0; i < K; i++)
    {
        int p = primes[i];
        int factor = 0;
        int y = x;
        while (y % p == 0)
        {
            y /= p;
            factor++;
        }
        if(factor)
        {
            mask |= ll(1) << i;
        }
    }

    segtree->update(l, r, 1, n, x);
    bits->update(l, r, 1, n, mask);
}

int answer(int l, int r)
{
    rmd euler = segtree->query(l, r, 1, n);
    ll mask = bits->query(l, r, 1, n);

    for(int i = 0; i < K; i++){
        if((mask >> i) & 1){
            euler *= rmd(1) - rmd(invPrimes[i]);
        }
    }

    return euler.value();
}

void solve(istream &in, ostream &out)
{
    EulerSieve sieve(300);
    primes = sieve.primes();
    invPrimes.reserve(primes.size());
    for(int p : primes){
        invPrimes.push_back(rmd(p).inverseByFermat().value());
    }

    in >> n >> q;
    segtree = new segment(1, n);
    bits = new segment_bit(1, n);

    for (int i = 1; i <= n; i++)
    {
        int x;
        in >> x;
        mul(i, i, x);
    }

    for (int i = 0; i < q; i++)
    {
        string cmd;
        int l, r;
        in >> cmd >> l >> r;
        if (cmd == "MULTIPLY")
        {
            int x;
            in >> x;
            mul(l, r, x);
        }
        else
        {
            int ans = answer(l, r);
            out << ans << endl;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout << std::setiosflags(std::ios::fixed);
    std::cout << std::setprecision(15);

    solve(std::cin, std::cout);

    return 0;
}