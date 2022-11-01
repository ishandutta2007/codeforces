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


void mul(VV(LL) &a, const VV(LL) &b, LL n){
    int m = a.size();
    VV(LL) c;
    initvv(c, m, m);
    for(int j = 0; j < m; ++j)
    for(int k = 0; k < m; ++k)
    for(int i = 0; i < m; ++i){
        c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % n;
    }
    a.swap(c);
}


void pow(VV(LL) &x, LL y, LL n){
    int m = x.size();
    VV(LL) a;
    initvv(a, m, m);
    for(int i = 0; i < m; ++i){
        a[i][i] = 1;
    }
    while(y){
        if(y & 1){
            mul(a, x, n);
        }
        y >>= 1;
        mul(x, x, n);
    }
    x.swap(a);
}



int main(){
    int ar[6][6] = {
        {2, 1, 1, 0, 1, 2},
        {1, 2, 0, 1, 1, 2},
        {1, 1, 1, 0, 1, 2},
        {1, 1, 0, 1, 1, 2},
        {0, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0, 1},
    };

    LL n, sx, sy, dx, dy, t;
    cin >> n >> sx >> sy >> dx >> dy >> t;
    
    vector<LL> v(6);
    v[0] = sx - 1;
    v[1] = sy - 1;
    v[2] = (dx % n + n) % n;
    v[3] = (dy % n + n) % n;
    v[5] = 1;
    
    VV(LL) a;
    initvv(a, 6, 6);
    for(int i = 0; i < 6; ++i)
    for(int j = 0; j < 6; ++j){
        a[i][j] = ar[i][j];
    }
    
    pow(a, t, n);
    LL ans[6] = {};
    for(int i = 0; i < 6; ++i)
    for(int j = 0; j < 6; ++j){
        ans[i] = (ans[i] + a[i][j] * v[j]) % n;
    }

    cout << ans[0] + 1 << ' ' << ans[1] + 1 << endl;
}