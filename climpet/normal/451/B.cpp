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
    int n;
    scanf("%d", &n);
    vector<pii> a(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    sort(ALL(a));
    int t, u;
    for(t = 0; t < n && a[t].second == t; ++t);
    for(u = n - 1; u >= 0 && a[u].second == u; --u);
    bool ok = true;
    if(u < 0){
        t = u = 0;
    }
    else{
        for(int i = t + 1; i <= u; ++i){
            if(a[i].second != a[i - 1].second - 1){
                ok = false;
            }
        }
    }
    
    if(ok){
        printf("yes\n%d %d\n", t + 1, u + 1);
    }
    else{
        puts("no");
    }
}