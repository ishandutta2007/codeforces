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
    int h, q;
    cin >> h >> q;
    vector<LL> ls, rs;
    for(int i = 0; i < q; ++i){
        int y, a;
        LL lt, rt;
        cin >> y >> lt >> rt >> a;
        ++rt;

        lt <<= h - y;
        rt <<= h - y;
        if(a){
            ls.push_back(1LL << (h - 1));
            rs.push_back(lt);
            ls.push_back(rt);
            rs.push_back(1LL << h);
        }
        else{
            ls.push_back(lt);
            rs.push_back(rt);
        }
    }
    
    vector<LL> xs = ls;
    xs.insert(xs.end(), ALL(rs));
    xs.push_back(1LL << (h - 1));
    xs.push_back(1LL << h);
    sort(ALL(xs));
    xs.erase(unique(ALL(xs)), xs.end());
    int sz = xs.size();

    vector<int> imos(sz);
    for(size_t i = 0; i < ls.size(); ++i){
        int lt = lower_bound(ALL(xs), ls[i]) - xs.begin();
        int rt = lower_bound(ALL(xs), rs[i]) - xs.begin();
        ++imos[lt];
        --imos[rt];
    }
    partial_sum(ALL(imos), imos.begin());

    bool amb = false;
    LL ans = -1;
    for(int i = 0; i + 1 < sz; ++i){
        if(imos[i] == 0){
            if(xs[i + 1] - xs[i] > 1 || ans != -1){
                ans = 0;
                amb = true;
            }
            else{
                ans = xs[i];
            }
        }
    }
    
    if(ans == -1){
        cout << "Game cheated!\n";
    }
    else if(amb){
        cout << "Data not sufficient!\n";
    }
    else{
        cout << ans << '\n';
    }
}



}
int main() try{
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(4);
    mainmain();
}
catch(...){}