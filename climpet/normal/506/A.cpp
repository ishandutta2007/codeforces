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
    int n, d;
    int cnt[30010] = {};
    cin >> n >> d;
    for(int i = 0; i < n; ++i){
        int p;
        scanf("%d", &p);
        ++cnt[p];
    }
    
    int ans = 0;
    vector<pii> dp[30010];
    dp[d].emplace_back(d, 0);
    for(int i = 0; i <= 30000; ++i){
        sort(RALL(dp[i]));
        dp[i].erase(unique(ALL(dp[i]),
            [](const pii &p, const pii &q){ return p.first == q.first; }
        ), dp[i].end());
        for(auto &p : dp[i]){
            p.second += cnt[i];
            ans = max(ans, p.second);
            for(int j = max(p.first - 1, 1); j <= p.first + 1 && i + j <= 30000; ++j){
                dp[i + j].emplace_back(j, p.second);
            }
        }
        vector<pii>().swap(dp[i]);
    }
    cout << ans << endl;
}



}
int main() try{
    mainmain();
}
catch(...){}