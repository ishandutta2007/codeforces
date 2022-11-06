//https://codeforces.com/contest/1270/problem/F
#include <iostream>
#include <fstream>
#include <iomanip>
#include <bits/stdc++.h>
#include <chrono>
#include <random>

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

namespace dalt
{
};
namespace other
{
};

using namespace dalt;


namespace dalt{
    template<class T>
    class VersionArray{
    private:
    vector<T> _data;
    vector<int> _version;
    T _def;
    int _now;
    void access(int i){
        if(_version[i] != _now){
            _version[i] = _now;
            _data[i] = _def;
        }
    }
    public:
    VersionArray(int cap, const T &def = 0):_data(cap), _version(cap), _def(def), _now(1){
    }
    void clear(){
        _now++;
    }
    T get(int i) {
        access(i);
        return _data[i];
    }
    void set(int i, const T& val){
        access(i);
        _data[i] = val;
    }
    void modify(int i, const T& val){
        access(i);
        _data[i] += val;
    }
    };
}

/**
     * 1 + 2 + ... + n
     */
ll sumOfIncrementSequence(int n)
{
    return (ll)(1 + n) * n / 2;
}

/**
     * l + (l + 1) + ... + (r - 1) + r
     */
ll sumOfIncrementSequence(int l, int r)
{
    return sumOfIncrementSequence(r) - sumOfIncrementSequence(l - 1);
}

/**
     * sum_{i=0}^y \lfloor i/x \rfloor
     */
ll sumOfImmutableDenominator(int x, int y)
{
    int round = y / x;
    int extra = y - round * x + 1;
    return sumOfIncrementSequence(round - 1) * x + (ll)extra * round;
}

/**
     * sum_{i=b}^y \lfloor i/x \rfloor
     */
ll sumOfImmutableDenominator(int b, int x, int y)
{
    if (b == 0)
    {
        return sumOfImmutableDenominator(x, y);
    }
    return sumOfImmutableDenominator(x, y) - sumOfImmutableDenominator(x, b - 1);
}

vector<int> ps;

int prefixSum(int i)
{
    return i < 0 ? 0 : ps[i];
}

void bruteforce(string &s)
{
    int n = s.length();
    vector<int> cnts(n);
    for (int i = 0; i < n; i++)
    {
        cnts[i] = s[i] - '0';
        if (i > 0)
        {
            cnts[i] += cnts[i - 1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int len = j - i + 1;
            int cnt = cnts[j] - (i > 0 ? cnts[i - 1] : 0);
            if (cnt > 0 && len % cnt == 0)
            {
                cerr << "(" << i << "," << j << ")" << endl;
            }
        }
    }
}

void solve(istream &in, ostream &out)
{
    string s;
    in >> s;
    int n = s.length();
    vector<int> oneIndexes;
    ps.resize(n);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            oneIndexes.push_back(i);
        }
        ps[i] = s[i] - '0';
        if (i > 0)
        {
            ps[i] += ps[i - 1];
        }
    }

    int blockSize = 700;//std::ceil(std::sqrt(n));
    int invBlock = n / blockSize;

    // bruteforce(s);

    ll part1 = 0;
    int m = oneIndexes.size();
    for (int i = 0; i < m; i++)
    {
        for (int j = i; j < m && j - i + 1 < blockSize; j++)
        {
            int a = i == 0 ? oneIndexes[i] : oneIndexes[i] - oneIndexes[i - 1] - 1;
            int b = oneIndexes[j] - oneIndexes[i] + 1;
            int c = j == m - 1 ? n - 1 - oneIndexes[j] : oneIndexes[j + 1] - oneIndexes[j] - 1;
            int x = j - i + 1;
            ll contrib = sumOfImmutableDenominator(b + c, x, a + b + c) - sumOfImmutableDenominator(b - 1, x, a + b - 1);
            part1 += contrib;
        }
    }

    ll part2 = 0;
    int zero = invBlock * m;
    VersionArray<int> va(zero + n + 1);

    for (int i = 1; i <= invBlock; i++)
    {
        va.clear();
        int l = 0;
        int r = 0;
        for (; r < n; r++)
        {
            while (l <= n && prefixSum(r) - prefixSum(l - 1) >= blockSize)
            {
                int p = prefixSum(l - 1);

                int key = (l - 1) - i * p;
                va.modify(key + zero, 1);
                l++;
            }
            int p = prefixSum(r);

            int key = r - i * p;
            part2 += va.get(key + zero);
        }
    }

    out << part1 + part2 << endl;

    cerr << "part1 = " << part1 << endl;
    cerr << "part2 = " << part2 << endl;
    cerr << "blockSize = " << blockSize << endl;
    cerr << "invBlock = " << invBlock << endl;
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