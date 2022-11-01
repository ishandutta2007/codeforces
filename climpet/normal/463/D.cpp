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
    int n, k;
    cin >> n >> k;
    VV(int) a;
    initvv(a, k, n);
    for(int i = 0; i < k; ++i)
    for(int j = 0; j < n; ++j){
        cin >> a[i][j];
    }
    
    VV(int) ps;
    initvv(ps, k, n + 1, -1);
    for(int i = 0; i < k; ++i)
    for(int j = 0; j < n; ++j){
        ps[i][a[i][j]] = j;
    }

    vint dp(n);
    for(int i = 0; i < n; ++i){
        int x = a[0][i];
        int v = 1;
        for(int j = 0; j < i; ++j){
            int y = a[0][j];
            bool ok = true;
            for(int h = 0; h < k; ++h){
                if(ps[h][x] <= ps[h][y]){
                    ok = false;
                }
            }
            if(ok){
                v = max(v, dp[j] + 1);
            }
        }
        dp[i] = v;
    }
    
    int ans = *max_element(ALL(dp));
    cout << ans << endl;
}