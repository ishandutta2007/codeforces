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

void add(LL &x, LL y){
    x = (x + y) % MOD;
}


void mainmain(){
    int r, g;
    cin >> r >> g;
    
    vector<LL> dp1(r + 1), dp2(r + 1);
    dp1[r] = 1;
    int s = 0;
    for(int h = 1; ; ++h){
        bool ok = false;
        for(int i = 0; i <= r; ++i){
            int j = r + g - i - s;
            
            if(i >= h && dp1[i]){
                add(dp2[i - h], dp1[i]);
                ok = true;
            }
            if(j >= h && dp1[i]){
                add(dp2[i], dp1[i]);
                ok = true;
            }
        }
        if(!ok){ break; }
        
        dp1.swap(dp2);
        fill(ALL(dp2), 0LL);
        s += h;
    }
    
    LL res = accumulate(ALL(dp1), 0LL) % MOD;
    cout << res << endl;
}



}
int main() try{
    mainmain();
}
catch(...){}