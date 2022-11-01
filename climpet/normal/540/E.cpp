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



template <class Tp>
struct fenwick_tree{
    typedef unsigned size_type;
    std::vector<Tp> bit;

    fenwick_tree(){}
    explicit fenwick_tree(size_type n){
        init(n);
    }
    void init(size_type n){
        bit.assign(n + 1, Tp());
    }
    Tp sum(size_type i) const{
        Tp s = 0;
        while(i){
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    void add(size_type i, Tp x){
        size_type sz = bit.size();
        while(i < sz){
            bit[i] += x;
            i += i & -i;
        }
    }
    void clear(){
        bit.clear();
    }
    void swap(fenwick_tree &f){
        bit.swap(f.bit);
    }
};


void mainmain(){
    int n;
    scanf("%d", &n);
    vint ps(1, 1), as(n), bs(n);
    for(int i = 0; i < n; ++i){
        scanf("%d%d", &as[i], &bs[i]);
        if(as[i] > 1){ ps.push_back(as[i] - 1); }
        if(bs[i] > 1){ ps.push_back(bs[i] - 1); }
        ps.push_back(as[i]);
        ps.push_back(bs[i]);
        ps.push_back(as[i] + 1);
        ps.push_back(bs[i] + 1);
    }
    sort(ALL(ps));
    ps.erase(unique(ALL(ps)), ps.end());

    vint pe(ps.size());
    iota(ALL(pe), 1);
    for(int i = 0; i < n; ++i){
        int ia = lower_bound(ALL(ps), as[i]) - ps.begin();
        int ib = lower_bound(ALL(ps), bs[i]) - ps.begin();
        swap(pe[ia], pe[ib]);
    }

    fenwick_tree<LL> fw(ps.size() + 10);
    LL ans = 0;
    for(int i = ps.size() - 2; i >= 0; --i){
        LL c = ps[i + 1] - ps[i];
        ans += fw.sum(pe[i]) * c;
        fw.add(pe[i], c);
    }
    cout << ans << endl;
}



}
int main() try{
//  ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(4);
    mainmain();
}
catch(...){}