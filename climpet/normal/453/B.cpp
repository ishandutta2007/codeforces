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



int main(){
    const int m = 59;

    const vector<int> prs =
        {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector<int> use(m);
    for(int i = 2; i < m; ++i){
        for(size_t j = 0; j < prs.size(); ++j){
            if(i % prs[j] == 0){
                use[i] |= 1 << j;
            }
        }
    }

    VV(pii) dp;
    initvv(dp, 1 << prs.size(), n + 1, pii(1010101010, -1));
    dp.back()[n] = pii();
    for(int k = n - 1; k >= 0; --k){
        for(int S = dp.size(); S--; )
        for(int x = 1; x < m; ++x){
            if(~S & use[x]){ continue; }
            int T = S & ~use[x];
            int c = dp[S][k + 1].first + abs(x - a[k]);
            dp[T][k] = min(dp[T][k], pii(c, x));
        }
    }
    
    int t = 0;
    for(int S = dp.size(); S--; ){
        if(dp[t][0].first > dp[S][0].first){
            t = S;
        }
    }
    for(int i = 0; i < n; ++i){
        int x = dp[t][i].second;
        printf("%d%c", x, i + 1 == n ? '\n' : ' ');
        t |= use[x];
    }
}