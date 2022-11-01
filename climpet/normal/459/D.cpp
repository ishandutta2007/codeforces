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


#define MAX_N 1000010
LL bit[MAX_N + 1];
int m;
int sum(int i){
    LL s = 0;
    while(i > 0){
        s += bit[i];
        i -= i & -i;
    }
    return s;
}
void add(int i, LL x){
    while(i <= m){
        bit[i] += x;
        i += i & -i;
    }
}


int main(){
    int n;
    scanf("%d", &n);
    vint v(n);
    vint ts(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &v[i]);
        ts[i] = v[i];
    }
    sort(ALL(ts));
    ts.erase(unique(ALL(ts)), ts.end());
    vint w(n);
    
    vint cnt(ts.size());
    m = n + 5;
    for(int i = 0; i < n; ++i){
        v[i] = lower_bound(ALL(ts), v[i]) - ts.begin();
        w[i] = ++cnt[v[i]];
        add(w[i], 1);
    }

    LL ans = 0;
    for(int i = 0; i < n; ++i){
        add(cnt[v[i]] - w[i] + 1, -1);
        ans += sum(w[i] - 1);
    }

    cout << ans << endl;
}