#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <bits/stdc++.h>
#include <chrono>
#include <random>
#include<ext/rope>

using __gnu_cxx::rope;
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
using std::bitset;
using std::uniform_int_distribution;
using std::uniform_real_distribution;
using std::stringstream;
using std::istream_iterator;

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(std::istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(std::istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

#define mp make_pair

#endif
#ifndef MODULAR_H
#define MODULAR_H

#include <iostream>

namespace modular
{
template <class T>
inline T Mod(T x, T m)
{
    x %= m;
    if (x < 0)
    {
        x += m;
    }
    return x;
}

inline long long Modmul(long long a, long long b, long long m)
{
    long long k = (long long)((long double)a / m * b + 0.5);
    return Mod(a * b - k * m, m);
}

template <typename T>
T Inverse(T a, T m)
{
    T u = 0, v = 1;
    while (a != 0)
    {
        T t = m / a;
        m -= t * a;
        swap(a, m);
        u -= t * v;
        swap(u, v);
    }
    assert(m == 1);
    return u;
}

template <class T, T M>
class Modular
{
public:
    Modular()
    {
        set(0);
    }
    Modular(const T &val)
    {
        set(val);
    }
    void set(const T &x)
    {
        _v = Mod(x, M);
    }
    Modular(const Modular<T, M> &val)
    {
        _v = val._v;
    }
    Modular<T, M> &operator=(const Modular<T, M> &y){
        _v = y._v;
        return *this;
    }
    const T &operator()() const
    {
        return _v;
    }
    T &operator()()
    {
        return _v;
    }
    Modular<T, M> &operator-=(const Modular<T, M> &y)
    {
        _v = Mod(_v - y._v, M);
        return *this;
    }
    Modular<T, M> &operator+=(const Modular<T, M> &y){
        _v = Mod(_v + y._v, M);
        return *this;
    }

    Modular<T, M> &operator*=(const Modular<T, M> &y)
    {
        _v = Mod<long long>((long long)_v * y._v, M);
        return *this;
    }
    Modular<T, M> &operator/=(const Modular<T, M> &y)
    {
        (*this) *= y.inverse();
        return *this;
    }
    Modular<T, M> pow(T exp) const
    {
        if (exp == 0)
        {
            return 1;
        }
        Modular<T, M> ans = pow(exp >> 1);
        ans *= ans;
        if (exp & 1)
        {
            ans *= *this;
        }
        return ans;
    }
    Modular<T, M> inverse() const
    {
        return Modular::Inverse(_v, M);
    }

private:
    T _v;
};


template <long long M>
class Modular<long long, M>
{
public:
    Modular()
    {
        set(0);
    }
    Modular(const long long &val)
    {
        set(val);
    }
    Modular(const Modular<long long, M> &val)
    {
        _v = val._v;
    }
    Modular<long long, M> &operator=(const Modular<long long, M> &y){
        _v = y._v;
        return *this;
    }
    void set(const long long &x)
    {
        _v = Mod(x, M);
    }
    const long long &operator()() const
    {
        return _v;
    }
    long long &operator()()
    {
        return _v;
    }
    Modular<long long, M> &operator-=(const Modular<long long, M> &y)
    {
        _v = Mod(_v - y._v, M);
        return *this;
    }
    Modular<long long, M> &operator+=(const Modular<long long, M> &y){
        _v = Mod(_v + y._v, M);
        return *this;
    }
    Modular<long long, M> &operator*=(const Modular<long long, M> &y)
    {
        _v = Modmul(_v, y._v, M);
        return *this;
    }
    Modular<long long, M> &operator/=(const Modular<long long, M> &y)
    {
        (*this) *= y.inverse();
        return *this;
    }
    Modular<long long, M> pow(long long exp) const
    {
        if (exp == 0)
        {
            return 1;
        }
        Modular<long long, M> ans = pow(exp >> 1);
        ans *= ans;
        if (exp & 1)
        {
            ans *= *this;
        }
        return ans;
    }
    Modular<long long, M> inverse() const
    {
        return Modular::inverse(_v, M);
    }

private:
    long long _v;
};

template <class T, T M>
Modular<T, M> operator+(const Modular<T, M> &a, const Modular<T, M> &b)
{
    Modular<T, M> ans = a;
    ans += b;
    return ans;
}
template <class T, T M>
Modular<T, M> operator+(const T &a, const Modular<T, M> &b)
{
    Modular<T, M> ans = a;
    ans += b;
    return ans;
}
template <class T, T M>
Modular<T, M> operator+(const Modular<T, M> &a, const T &b)
{
    Modular<T, M> ans = a;
    ans += b;
    return ans;
}
template <class T, T M>
Modular<T, M> operator-(const Modular<T, M> &a, const Modular<T, M> &b)
{
    Modular<T, M> ans = a;
    ans -= b;
    return ans;
}
template <class T, T M>
Modular<T, M> operator-(const T &a, const Modular<T, M> &b)
{
    Modular<T, M> ans = a;
    ans -= b;
    return ans;
}
template <class T, T M>
Modular<T, M> operator-(const Modular<T, M> &a, const T &b)
{
    Modular<T, M> ans = a;
    ans -= b;
    return ans;
}
template <class T, T M>
Modular<T, M> operator*(const Modular<T, M> &a, const Modular<T, M> &b)
{
    Modular<T, M> ans = a;
    ans *= b;
    return ans;
}
template <class T, T M>
Modular<T, M> operator*(const T &a, const Modular<T, M> &b)
{
    Modular<T, M> ans = a;
    ans *= b;
    return ans;
}
template <class T, T M>
Modular<T, M> operator*(const Modular<T, M> &a, const T &b)
{
    Modular<T, M> ans = a;
    ans *= b;
    return ans;
}
template <class T, T M>
Modular<T, M> operator/(const Modular<T, M> &a, const Modular<T, M> &b)
{
    Modular<T, M> ans = a;
    ans /= b;
    return ans;
}
template <class T, T M>
Modular<T, M> operator/(const T &a, const Modular<T, M> &b)
{
    Modular<T, M> ans = a;
    ans /= b;
    return ans;
}
template <class T, T M>
Modular<T, M> operator/(const Modular<T, M> &a, const T &b)
{
    Modular<T, M> ans = a;
    ans /= b;
    return ans;
}
template <class T, T M>
Modular<T, M> operator==(const Modular<T, M> &a, const Modular<T, M> &b)
{
    return a() == b();
}
template <class T, T M>
Modular<T, M> operator==(const Modular<T, M> &a, const T &b)
{
    return a() == Modular<T, M>(b);
}
template <class T, T M>
Modular<T, M> operator==(const T &a, const Modular<T, M> &b)
{
    return Modular<T, M>(a) == b;
}
template <class T, T M>
Modular<T, M> operator!=(const Modular<T, M> &a, const Modular<T, M> &b)
{
    return a() != b();
}
template <class T, T M>
Modular<T, M> operator!=(const Modular<T, M> &a, const T &b)
{
    return a() != Modular<T, M>(b);
}
template <class T, T M>
Modular<T, M> operator!=(const T &a, const Modular<T, M> &b)
{
    return Modular<T, M>(a) != b;
}
template <class T, T M>
std::ostream &operator<<(std::ostream &out, const Modular<T, M> &v)
{
    return out << v();
}
template <class T, T M>
std::istream &operator>>(std::istream &in, const Modular<T, M> &v)
{
    T x;
    in >> x;
    v.set(x);
    return in;
}
} // namespace Modular

#endif
#ifndef BITS_H
#define BITS_H



namespace bits
{
template <class T>
inline bool BitAt(T x, int i)
{
    return (x >> i) & 1;
}
template <class T>
inline T SetBit(T x, int i)
{
    return x |= T(1) << i;
}
template <class T>
inline T RemoveBit(T x, int i)
{
    return x &= ~(T(1) << i);
}
int BitCount(ui i)
{
    i = i - ((i >> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
    i = (i + (i >> 4)) & 0x0f0f0f0f;
    i = i + (i >> 8);
    i = i + (i >> 16);
    return i & 0x3f;
}
int BitCount(ull i)
{
    i = i - ((i >> 1) & 0x5555555555555555L);
    i = (i & 0x3333333333333333L) + ((i >> 2) & 0x3333333333333333L);
    i = (i + (i >> 4)) & 0x0f0f0f0f0f0f0f0fL;
    i = i + (i >> 8);
    i = i + (i >> 16);
    i = i + (i >> 32);
    return (int)i & 0x7f;
}
} // namespace bits

#endif
#ifndef HASH_H
#define HASH_H



namespace hash
{
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
} // namespace hash

#endif

using Mint = modular::Modular<int, (int)1e9 + 7>;
using namespace bits;

vector<ui> allSubgroup;
vector<vector<ui>> subGroupPlusSingle;
vector<vector<ui>> subGroupPlusSet;
unordered_map<ui, int, hash::custom_hash> groupToIndex;

ui expand(int x, vector<int> &vec, int i){
    if(i < 0){
        return ui(1) << x;
    }
    return expand(x, vec, i - 1) | expand(x ^ vec[i], vec, i - 1);
}

void search(vector<int>& vec, int i){
    if(i == 0){
        int mask = expand(0, vec, vec.size() - 1);
        if(groupToIndex.find(mask) == groupToIndex.end()){
            int index = groupToIndex.size();
            groupToIndex[mask] = 1;
        }
        return;
    }
    for(int j = 0; j < 32; j++){
        vec.push_back(j);
        search(vec, i - 1);
        vec.pop_back();
    }
}

int add(ui x, int i)
{
    ui t = SetBit(x, i);
    for (int j = 0; ; j++)
    {
        if ((allSubgroup[j] & t) == t)
        {
            return j;
        }
    }
}

int merge(int a, int b)
{
    for (int i = 0; i < 32; i++)
    {
        if (BitAt(allSubgroup[b], i))
        {
            a = subGroupPlusSingle[a][i];
        }
    }
    return a;
}

void generate()
{
    for(int i = 0; i <= 4; i++){
        vector<int> record;
        search(record, i);
    }
    for(auto &p : groupToIndex){
        allSubgroup.push_back(p.first);
    }
    allSubgroup.push_back(~0);

    error(allSubgroup.size());
    sort(allSubgroup.begin(), allSubgroup.end(), [](int a, int b) { return BitCount((ui)a) < BitCount((ui)b); });

    subGroupPlusSingle.resize(allSubgroup.size(), vector<ui>(32));
    for (int i = 0; i < allSubgroup.size(); i++)
    {
        for (int j = 0; j < 32; j++)
        {
            subGroupPlusSingle[i][j] = add(allSubgroup[i], j);
        }
    }

    subGroupPlusSet.resize(allSubgroup.size(), vector<ui>(allSubgroup.size()));
    for (int i = 0; i < allSubgroup.size(); i++)
    {
        for (int j = 0; j < allSubgroup.size(); j++)
        {
            subGroupPlusSet[i][j] = merge(i, j);
        }
    }
}

struct edge
{
    int to;
    int w;
};

struct node
{
    bool isNear;
    bool visited;
    bool instk;
    ui w;
    int partner;
    ui partnerW;
    ui nearW;
};

vector<vector<edge>> edges;
vector<node> nodes;

void findLoop(ui x, ui &mask, bool &zero)
{
    if ((subGroupPlusSingle[mask][x] == mask) || x == 0)
    {
        zero = true;
    }
    mask = subGroupPlusSingle[mask][x];
}

void detect(int root, int p, ui w, ui &mask, bool &zero)
{
    if (root == 1)
    {
        return;
    }
    if (nodes[root].visited)
    {
        if (nodes[root].instk)
        {
            ui x = w ^ nodes[root].w;
            findLoop(x, mask, zero);
        }
        return;
    }
    nodes[root].visited = true;
    nodes[root].instk = true;
    nodes[root].w = w;
    for (auto &e : edges[root])
    {
        if (e.to == p)
        {
            continue;
        }
        if(e.to == root) {
            findLoop(e.w, mask, zero);
            continue;
        }
        detect(e.to, root, w ^ e.w, mask, zero);
    }
    nodes[root].instk = false;
}

void solve(int testId, istream &in, ostream &out)
{
    generate();
    int n, m;
    in >> n >> m;
    edges.resize(n + 1);
    nodes.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        in >> a >> b >> w;
        edges[a].push_back({b, w});
        edges[b].push_back({a, w});
    }
    for (auto &e : edges[1])
    {
        nodes[e.to].isNear = true;
        nodes[e.to].nearW = e.w;
    }
    for(int i = 1; i <= n; i++){
        if(!nodes[i].isNear){
            continue;
        }
        for(auto &e : edges[i]){
            if(nodes[e.to].isNear && e.to != i){
                nodes[i].partner = e.to;
                nodes[i].partnerW = e.w;
            }
        }
    }

    int k = allSubgroup.size();
    vector<Mint> dp(k);
    vector<Mint> last(k);
    last[0] = 1;
    for(auto &e : edges[1]){
        int i = e.to;
        if(nodes[i].visited){
            continue;
        }
        ui mask = 0;
        bool zero = false;
        detect(i, 1, 0, mask, zero);
        if(zero){
            continue;
        }
        dp = last;
        if(nodes[i].partner == 0){
            //add
            for(int i = 0; i < k; i++){
                if((allSubgroup[i] & allSubgroup[mask]) > 1)
                {
                    continue;
                }
                dp[subGroupPlusSet[i][mask]] += last[i];
            }
        }else{
            //add one
            for(int i = 0; i < k; i++){
                if((allSubgroup[i] & allSubgroup[mask]) > 1)
                {
                    continue;
                }
                dp[subGroupPlusSet[i][mask]] += 2 * last[i];
            }
            //add two
            int circle = nodes[i].nearW ^ nodes[nodes[i].partner].nearW ^ nodes[i].partnerW;
            if(!(subGroupPlusSingle[mask][circle] == mask)){
                mask = subGroupPlusSingle[mask][circle];
                for(int i = 0; i < k; i++){
                   if((allSubgroup[i] & allSubgroup[mask]) > 1)
                   {
                        continue;
                    }
                    dp[subGroupPlusSet[i][mask]] += last[i];
                }
            }
        }
        dp.swap(last);
    }

    Mint ans = 0;
    for(int i = 0; i < k; i++){
        ans += last[i];
    }
    out << ans;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout << std::setiosflags(std::ios::fixed);
    std::cout << std::setprecision(15);
    
    solve(1, std::cin, std::cout);

    return 0;
}