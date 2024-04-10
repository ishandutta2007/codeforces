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


struct matrix{
    LL v[16];
    matrix(LL x = LLONG_MAX / 4){
        for(int i = 0; i < 16; ++i){
            v[i] = x;
        }
    }
    LL operator() (int r, int c) const{
        return v[r * 4 + c];
    }
    LL &operator() (int r, int c){
        return v[r * 4 + c];
    }
    LL min() const{
        return *min_element(v, v + 16);
    }
};

matrix mul(const matrix &a, const matrix &b){
    matrix c;
    for(int i = 0; i < 4; ++i)
    for(int k = 0; k < 4; ++k)
    for(int j = 0; j < 4; ++j){
        LL &r = c(i, j);
        r = min(r, a(i, k) + b(k, j));
    }
    return c;
}


int main(){
    LL n;
    string t;
    cin >> n >> t;
    int m = t.size();

    matrix mat0;
    vector<char> ap;
    for(int k = min(m, 11); k > 1; --k){
        const int mask = (1 << (2 * k)) - 1;
        ap.assign(1 << (2 * k), (char)0);
        int w = 0;
        for(int i = 0; i < k - 1; ++i){
            w = w << 2 | t[i] - 'A';
        }
        for(int i = k - 1; i < m; ++i){
            w = (w << 2 | t[i] - 'A') & mask;
            ap[w] = 1;
        }
        
        for(int S = 0; S <= mask; ++S)
        if(!ap[S]){
            mat0(S >> (2 * k - 2), S & 3) = k - 1;
        }
    }
    
    matrix pows[64];
    pows[0] = mat0;
    for(int i = 1; i < 64; ++i){
        pows[i] = mul(pows[i - 1], pows[i - 1]);
    }

    LL ans = 0;
    int b;
    for(b = 0; pows[b].min() < n; ++b);
    matrix a(0);
    for(; b >= 0; --b){
        matrix tmp = mul(a, pows[b]);
        if(tmp.min() < n){
            ans |= 1LL << b;
            a = tmp;
        }
    }
    
    ++ans;
    cout << ans << endl;
}