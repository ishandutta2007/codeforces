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


vint v[2010];

void dfs(int k, int t, vint &w){
    if(k > 2000){
        for(int x : w){
            printf("%d ", x);
        }
        puts("");
        return;
    }

    int sz = w.size();
    for(int x : v[k]){
        w.push_back(x);
    }

    if(t == 1){
        dfs(k + 1, 1, w);
    }
    else if(t == 2 && v[k].size() > 1){
        dfs(k + 1, 1, w);
        swap(w[sz], w[sz + 1]);
        dfs(k + 1, 1, w);
    }
    else if(t == 3 && v[k].size() == 2){
        dfs(k + 1, 2, w);
        swap(w[sz], w[sz + 1]);
        dfs(k + 1, 1, w);
    }
    else if(t == 3 && v[k].size() > 2){
        dfs(k + 1, 1, w);
        swap(w[sz], w[sz + 1]);
        dfs(k + 1, 1, w);
        swap(w[sz], w[sz + 2]);
        dfs(k + 1, 1, w);
    }
    else{
        dfs(k + 1, t, w);
    }

    w.resize(sz);
}


int main(){
    int n, h;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> h;
        v[h].push_back(i);
    }
    
    int a = 1;
    for(int i = 0; i < 2010; ++i){
        int e = max<int>(1, v[i].size());
        a = min<int>(a * e, 10);
    }
    if(a < 3){
        puts("NO");
    }
    else{
        puts("YES");
        vint w;
        dfs(0, 3, w);
    }
}