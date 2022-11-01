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


void mainmain(){
    const LL QUESTION = 1020000000;
    const int INF = 1010101010;

    int n, k;
    scanf("%d%d", &n, &k);
    vint as(n, QUESTION);
    for(int i = 0; i < n; ++i){
        if(scanf("%d", &as[i]) != 1){ scanf("%*s"); }
    }
    for(int z = 0; z < k; ++z){
        vint v(1, -INF);
        for(int j = z; j < n; j += k){ v.push_back(as[j]); }
        v.push_back(INF);
        for(int l = 0; l + 1 < (int)v.size(); ){
            int r;
            for(r = l + 1; v[r] == QUESTION; ++r);
            int d = r - l - 1;
            if(v[r] - v[l] <= d){
                puts("Incorrect sequence");
                return;
            }
            
            int t = -((d - 1) >> 1);
            int u = t + d - 1;
            if(u >= v[r]){
                u = v[r] - 1;
                t = u - d + 1;
            }
            else if(t <= v[l]){
                t = v[l] + 1;
                u = t + d - 1;
            }
            for(int i = 0; i < d; ++i){
                v[l + 1 + i] = t + i;
            }
            
            l = r;
        }
        
        for(int i = 1; i + 1 < (int)v.size(); ++i){
            as[(i - 1) * k + z] = v[i];
        }
    }
    for(int i = 0; i < n; ++i){
        printf("%d%c", as[i], i + 1 == n ? '\n' : ' ');
    }
}



}
int main() try{
//  ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(4);
    mainmain();
}
catch(...){}