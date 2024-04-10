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
using namespace std;


typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
    v.assign(a, vector<T>(b, t));
}


#define REP(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define PB push_back
#define ITR ::iterator


#define MOD 1000000009LL
#define EPS 1e-8

typedef complex<double> P;

int main(){
    double pi = acos(-1.0);
    int m, n;
    cin >> n >> m;
    
    vector<P> v(2 * m);
    double r = 1e8 - 3.0;
    double t = 2.0 * pi / m;
    double d = 1e-6;
    for(int i = 0; i < m; ++i){
        v[i] = polar(r, t * i);
        v[i+m] = polar(r - 1e6, t * i + d);
    }
    v.resize(n);
    
    if(m == 3 && n >= 5){
        puts("-1");
    }
    else{
        for(int i = 0; i < n; ++i){
            printf("%d %d\n", (int)real(v[i]), (int)imag(v[i]));
        }
    }
}