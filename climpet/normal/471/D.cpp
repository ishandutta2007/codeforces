#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>

#if __cplusplus >= 201103L
#include <array>
#include <tuple>
#include <initializer_list>
#include <unordered_set>
#include <unordered_map>
#include <forward_list>

#define cauto const auto&
#define ALL(v) begin(v),end(v)
#else
#define ALL(v) (v).begin(),(v).end()
#endif

using namespace std;


typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
    v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
    stringstream ss;
    ss << f;
    ss >> t;
}


#define REP(i,n) for(int i=0;i<int(n);++i)
#define RALL(v) (v).rbegin(),(v).rend()


#define MOD 1000000007LL
#define EPS 1e-8



struct rhash{
    typedef unsigned long long ull;

    enum{ num_val = 4 };

    static const ull modval;
    static const ull bases[num_val];
    static vector<unsigned> pows[num_val];

    ull val[num_val];

    static void prepare(unsigned max_size){
        for(int i = 0; i < num_val; ++i){
            vector<unsigned> &v = pows[i];
            v.resize(max_size + 1);
            v[0] = 1;
            for(unsigned j = 1; j <= max_size; ++j){
                v[j] = v[j - 1] * bases[i] % modval;
            }
        }
    }

    rhash(){
        if(pows[0].empty()){
            fprintf(stderr, "rhash: need PREPARE\n");
            exit(EXIT_FAILURE);
        }
        for(int i = 0; i < num_val; ++i){
            val[i] = 0;
        }
    }
    rhash mul(unsigned shf, int y) const{
        rhash ret;
        for(int i = 0; i < num_val; ++i){
            ret.val[i] = (val[i] * (ull)pows[i][shf] + modval + y) % modval;
        }
        return ret;
    }
    rhash operator<< (unsigned shf) const{
        return mul(shf, 0);
    }
    rhash operator+ (int y) const{
        return mul(0, y);
    }
    rhash &operator<<= (unsigned shf){
        return *this = *this << shf;
    }
    rhash &operator+= (int y){
        return *this += y;
    }
    rhash operator+ (const rhash &other) const{
        rhash ret;
        for(int i = 0; i < num_val; ++i){
            ull t = val[i] + other.val[i];
            if(t >= modval){ t -= modval; }
            ret.val[i] = t;
        }
        return ret;
    }
    rhash operator- (const rhash &other) const{
        rhash ret;
        for(int i = 0; i < num_val; ++i){
            ret.val[i] = (modval + val[i] - other.val[i]) % modval;
        }
        return ret;
    }
    rhash &operator+= (const rhash &other){
        return *this += other;
    }
    rhash &operator-= (const rhash &other){
        return *this -= other;
    }
    bool operator== (const rhash &other) const{
        return std::equal(val, val + num_val, other.val);
    }
    bool operator!= (const rhash &other) const{
        return !(*this == other);
    }
    bool operator< (const rhash &other) const{
        return std::lexicographical_compare(
            val, val + num_val, other.val, other.val + num_val
        ) < 0;
    }
};
vector<unsigned> rhash::pows[];
const rhash::ull rhash::modval = 2576980451ull;
const rhash::ull rhash::bases[] = {
    1123581321, 1135214521, 1145141919, 1192296044,
};
ostream &operator<< (ostream &os, const rhash &r){
    char c = '(';
    for(int i = 0; i < rhash::num_val; ++i){
        os << c << r.val[i];
        c = ',';
    }
    os << ')';
    return os;
}


vint input(int n){
    vint v(n - 1);
    int a, b;
    scanf("%d", &a);
    for(int i = 0; i < n - 1; ++i){
        scanf("%d", &b);
        v[i] = b - a;
        a = b;
    }
    return v;
}

int main(){
    rhash::prepare(200010);

    int n, w;
    scanf("%d%d", &n, &w);
    vint a = input(n);
    vint b = input(w);
    rhash y;
    for(int i = 0; i < w - 1; ++i){
        y = y.mul(1, b[i]);
    }

    vector<rhash> xs(n);
    int res = 0;
    for(int i = 1; i < n; ++i){
        xs[i] = xs[i - 1].mul(1, a[i - 1]);
    }
    for(int i = w - 1; i < n; ++i){
        if((xs[i] - (xs[i - w + 1] << (w - 1))) == y){
            ++res;
        }
    }
    printf("%d\n", res);
}