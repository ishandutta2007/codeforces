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
    const LL LIM = 1000000000;

    int n, m;
    cin >> n >> m;

    vint ts(m), ls(m), rs(m);
    vector<LL> ds(m);
    for(int i = 0; i < m; ++i){
        cin >> ts[i] >> ls[i] >> rs[i] >> ds[i];
        --ls[i];
    }

    vector<LL> cand(n, 1LL << 50);
    for(int i = m - 1; i >= 0; --i){
        if(ts[i] == 1){
            for(int j = ls[i]; j < rs[i]; ++j){
                cand[j] -= ds[i];
            }
        }
        else{
            for(int j = ls[i]; j < rs[i]; ++j){
                cand[j] = min(cand[j], ds[i]);
            }
        }
    }
    for(LL &x : cand){
        if(x > LIM){ x = LIM; }
        else if(x < -LIM){ x = -LIM; }
    }

    vector<LL> as = cand;
    bool ok = true;
    for(int i = 0; i < m; ++i){
        if(ts[i] == 1){
            for(int j = ls[i]; j < rs[i]; ++j){
                as[j] += ds[i];
            }
        }
        else{
            if(*max_element(as.begin() + ls[i], as.begin() + rs[i]) != ds[i]){
                ok = false;
                break;
            }
        }
    }

    if(ok){
        cout << "YES";
        char spl = '\n';
        for(LL x : cand){
            cout << spl << x;
            spl = ' ';
        }
        cout << '\n';
    }
    else{
        cout << "NO\n";
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