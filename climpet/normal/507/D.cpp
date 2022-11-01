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


LL func(int n, int k, LL m){
    vll p10(n + 1);
    p10[0] = 1;
    for(int i = 1; i <= n; ++i){
        p10[i] = p10[i - 1] * 10 % m;
    }

    vector<LL> dp1(k), dp2(k);
    LL ret = 0;
    int w = 1;
    for(int i = n - 1; i >= 0; --i){
        for(int d = 0; d < 10; ++d){
            if(d){ dp2[d * w % k] += 1; }
            for(int j = 0; j < k; ++j){
                LL &r = dp2[(d * w + j) % k];
                r = (r + dp1[j]) % m;
            }
        }
        ret = (ret + p10[i] * dp2[0]) % m;
        dp2[0] = 0;
        dp1.swap(dp2);
        fill(ALL(dp2), 0LL);
        
        w = w * 10 % k;
    }
    return ret;
}

void mainmain(){
    int n, m, k;
    cin >> n >> k >> m;
    LL ans = (func(n, k, m) - func(n - 1, k, m) + m) % m;
    cout << ans << endl;
}



}
int main() try{
    mainmain();
}
catch(...){}