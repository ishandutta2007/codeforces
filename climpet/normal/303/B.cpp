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
#define ITR ::iterator


#define MOD 1000000009LL
#define EPS 1e-8


LL gcd(LL x, LL y){
    while(y){
        LL r = x % y;
        x = y;
        y = r;
    }
    return x;
}


int main(){
    LL n, m, a, b, x, y;
    cin >> n >> m >> x >> y >> a >> b;
    LL g = gcd(a, b);
    a /= g;
    b /= g;
    LL k = min(n / a, m / b);
    a *= k;
    b *= k;

    LL x1 = max(min(x - (a + 1) / 2, n - a), 0LL);
    LL y1 = max(min(y - (b + 1) / 2, m - b), 0LL);
    cout << x1 << ' ' << y1 << ' ' << x1 + a << ' ' << y1 + b << '\n';
}