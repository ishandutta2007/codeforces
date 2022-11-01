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


bool check(LL n, LL k, LL x, LL y){
    if(n % 3){ return false; }
    LL p = k - x - 2 * y;
    if(p < 0 || p % 3){ return false; }
    LL c = p / 3;
    LL b = c + y;
    LL a = b + x;
    if(min({a, b, c}) < 0){ return false; }
    if(3 * max({a, b, c}) > n){ return false; }
    return true;
}


int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        LL n, k, d1, d2;
        cin >> n >> k >> d1 >> d2;

        bool ok = false;
        for(int p = -1; p <= 1; p += 2)
        for(int q = -1; q <= 1; q += 2){
            ok |= check(n, k, d1 * p, d2 * q);
        }
        
        puts(ok ? "yes" : "no");
    }
}