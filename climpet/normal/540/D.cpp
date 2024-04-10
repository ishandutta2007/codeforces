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


double dp[101][101][101];


void mainmain(){
    int r, s, p;
    cin >> r >> s >> p;
    dp[r][s][p] = 1.0;

    double ar = 0, as = 0, ap = 0;

    for(int i = r; i >= 0; --i)
    for(int j = s; j >= 0; --j)
    for(int k = p; k >= 0; --k){
        int c = i * j + j * k + k * i;
        if(c){
            double t = 1.0 / c;
            if(i){
                dp[i - 1][j][k] += dp[i][j][k] * (k * i) * t;
            }
            if(j){
                dp[i][j - 1][k] += dp[i][j][k] * (i * j) * t;
            }
            if(k){
                dp[i][j][k - 1] += dp[i][j][k] * (j * k) * t;
            }
        }
        
        if(i && !j && !k){
            ar += dp[i][j][k];
        }
        if(!i && j && !k){
            as += dp[i][j][k];
        }
        if(!i && !j && k){
            ap += dp[i][j][k];
        }
    }
    printf("%.15f %.15f %.15f\n", ar, as, ap);
}



}
int main() try{
//  ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(4);
    mainmain();
}
catch(...){}