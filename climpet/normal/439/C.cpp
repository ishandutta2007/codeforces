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
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define PB push_back


#define MOD 1000000009LL
#define EPS 1e-8


VV(int) res;

bool solve(){
    vint od;
    int n, k, p, a;
    scanf("%d%d%d", &n, &k, &p);
    res.resize(k);
    int t = 0;
    for(int i = 0; i < n; ++i){
        scanf("%d", &a);
        if(a & 1){
            od.push_back(a);
        }
        else{
            res[t].push_back(a);
            t = (t + 1) % k;
        }
    }

    if(od.size() < k - p || od.size() - (k - p) & 1){
        return false;
    }
    int u = 0;
    for(int i = 0; i < k - p; ++i){
        res[t].push_back(od[u++]);
        t = (t + 1) % k;
    }
    for(; u < od.size(); u += 2){
        res[t].push_back(od[u]);
        res[t].push_back(od[u + 1]);
        t = (t + 1) % k;
    }
    
    for(int i = 0; i < k; ++i){
        if(res[i].empty()){
            return false;
        }
    }
    return true;
}


int main(){
    if(solve()){
        puts("YES");
        for(cauto v : res){
            printf("%d", (int)v.size());
            for(int x : v){
                printf(" %d", x);
            }
            puts("");
        }
    }
    else{
        puts("NO");
    }
}