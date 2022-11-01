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


vll as;
int n, m;
vint occ;
int dc;
LL sum;

inline void adv(int &p, int &d, int s){
    int q = p + d;
    if(q < 1 || q > n){
        d = -d;
        q = p + d;
    }
    sum += s * abs(as[q] - as[p]);
    p = q;
}

inline void add(int p, int d){
    if(!occ[p]){ --dc; }
    occ[p] += d;
    if(!occ[p]){ ++dc; }
}

LL solve(){
    scanf("%d", &n);
    as.resize(n + 1);
    for(int i = 1; i <= n; ++i){
        int a;
        scanf("%d", &a);
        as[i] = a;
    }

    scanf("%d", &m);
    occ.resize(n + 1);
    for(int i = 0; i < m; ++i){
        int b;
        scanf("%d", &b);
        add(b, 1);
    }

    int pr = 1, dr = 1;
    add(pr, -1);
    for(int i = 1; i < m; ++i){
        adv(pr, dr, 1);
        add(pr, -1);
    }

    LL ans = -1;
    int pl = 1, dl = 1;
    for(int i = 0; i < 2 * n + 10; ++i){
        add(pl, 1);
        adv(pl, dl, -1);
        adv(pr, dr, 1);
        add(pr, -1);

        if(!dc){
            if(ans != -1 && ans != sum){ return -1; }
            ans = sum;
        }
    }
    return ans;
}

void mainmain(){
    cout << solve() << endl;
}



}
int main() try{
//  ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(4);
    mainmain();
}
catch(...){}