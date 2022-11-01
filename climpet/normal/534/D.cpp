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


void mainmain(){
    multimap<int,int> mps[3];
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        int a;
        scanf("%d", &a);
        mps[a % 3u].emplace(a, i);
    }
    int s = 0;
    vint ans;
    for(int i = 0; i < n; ++i){
        auto &mp = mps[i % 3u];
        auto it = mp.upper_bound(s);
        if(it == mp.begin()){
            ans.clear();
            break;
        }
        --it;
        s = it->first + 1;
        ans.push_back(it->second);
        mp.erase(it);
    }
    if(ans.empty()){
        puts("Impossible");
    }
    else{
        printf("Possible");
        char spl = '\n';
        for(int x : ans){
            printf("%c%d", spl, x);
            spl = ' ';
        }
        puts("");
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