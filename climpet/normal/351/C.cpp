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
#include <cassert>

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


namespace{
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


template <class Tp, class Func>
class mod_operation_supporter{
    Tp mod;
    Func func;
public:
    explicit mod_operation_supporter(const Tp &m, Func f = Func())
    : mod(m), func(f) {}
    Tp operator() (const Tp &a, const Tp &b) const{
        Tp r = func(a, b) % mod;
        if(r < Tp()){ r += mod; }
        return r;
    }
};

template <class Tp>
mod_operation_supporter<Tp,std::plus<Tp> > mod_plus(const Tp &mod){
    return mod_operation_supporter<Tp,std::plus<Tp> >(mod);
}
template <class Tp>
mod_operation_supporter<Tp,std::minus<Tp> > mod_minus(const Tp &mod){
    return mod_operation_supporter<Tp,std::minus<Tp> >(mod);
}
template <class Tp>
mod_operation_supporter<Tp,std::multiplies<Tp> > mod_mul(const Tp &mod){
    return mod_operation_supporter<Tp,std::multiplies<Tp> >(mod);
}


template <class Tp>
struct matrix : vector<vector<Tp> >{
    static matrix zero(size_t m){
        matrix ret;
        ret.assign(m, vector<Tp>(m, Tp()));
        return ret;
    }
    
    static matrix unit(size_t m){
        matrix ret;
        ret.assign(m, vector<Tp>(m, Tp()));
        for(size_t i = 0; i < m; ++i){
            ret[i][i] = 1;
        }
        return ret;
    }
    
    template <class Fun>
    static matrix generate(size_t m, Fun fun){
        matrix ret;
        ret.assign(m, vector<Tp>());
        for(size_t i = 0; i < m; ++i){
            ret[i].reserve(m);
            for(size_t j = 0; j < m; ++j){
                ret[i].push_back(fun(i, j));
            }
        }
        return ret;
    }

    matrix(){}
    matrix(const vector<vector<Tp> > &w) : vector<vector<Tp> >(w){}
    
    template <class Func>
    matrix &apply(Func func){
        for(size_t i = this->size(); i--; )
        for(size_t j = this->size(); j--; ){
            (*this)[i][j] = func((*this)[i][j]);
        }
        return *this;
    }

    template <class Func>
    matrix &apply(const matrix &a, Func func){
        for(size_t i = this->size(); i--; )
        for(size_t j = this->size(); j--; ){
            (*this)[i][j] = func((*this)[i][j], a[i][j]);
        }
        return *this;
    }

    matrix operator- () const{
        matrix a = *this;
        return a.apply(std::negate<Tp>());
    }
    
    template <class FA, class FM>
    matrix& multiply(const matrix &a, FA funcadd, FM funcmul){
        matrix ret = matrix::zero(this->size());
        for(size_t i = this->size(); i--; )
        for(size_t k = this->size(); k--; )
        for(size_t j = this->size(); j--; ){
            ret[i][j] = funcadd(ret[i][j], funcmul((*this)[i][k], a[k][j]));
        }
        ret.swap(*this);
        return *this;
    }
    
    matrix &operator+= (const matrix &b){
        return this->apply(b, std::plus<Tp>());
    }
    matrix &operator-= (const matrix &b){
        return this->apply(b, std::minus<Tp>());
    }
    matrix &operator*= (const matrix &b){
        return this->multiply(b, std::plus<Tp>(), std::multiplies<Tp>());
    }
};

const LL INF = 1LL << 55;

matrix<LL> def;

void mul(matrix<LL> &x, const matrix<LL> &y){
    int sz = x.size();
    auto z = def;
    for(int i = 0; i < sz; ++i)
    for(int k = 0; k < sz; ++k)
    for(int j = 0; j < sz; ++j){
        z[i][j] = min(z[i][j], x[i][k] + y[k][j]);
    }
    x.swap(z);
}

matrix<LL> powmod(matrix<LL> x, LL y){
    int sz = x.size();
    auto a = def;
    for(int i = 0; i < sz; ++i){
        a[i][i] = 0;
    }
    while(y){
        if(y & 1){ mul(a, x); }
        mul(x, x);
        y >>= 1;
    }
    return a;
}

void mainmain(){
    int n, m;
    cin >> n >> m;
    vint a(n), b(n);
    for(int &x : a){ cin >> x; }
    for(int &x : b){ cin >> x; }

    def = matrix<LL>::generate(2 * n + 1, [](int, int){ return INF; });
    auto tr = def;
    vector<LL> dp1, dp2;
    for(int x = 0; x <= 2 * n; ++x){
        dp1.assign(3 * n + 1, INF);
        dp1[x] = 0;
        for(int i = 0; i < n; ++i){
            dp2.assign(3 * n + 1, INF);
            for(int j = 0; j <= 3 * n; ++j){
                if(j){
                    dp2[j - 1] = min(dp2[j - 1], dp1[j] + b[i]);
                }
                if(j < 3 * n){
                    dp2[j + 1] = min(dp2[j + 1], dp1[j] + a[i]);
                }
            }
            dp1.swap(dp2);
        }
        for(int i = 0; i <= n; ++i){
            tr[x][i] = dp1[i];
        }
    }

    auto res = powmod(tr, m);
    LL ans = res[0][0];
    cout << ans << endl;
}



}
int main() try{
//  ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(4);
    mainmain();
}
catch(...){}