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


LL tbl[100010];


int main(){
    for(int i = 1; i <= 100000; ++i){
        tbl[i] = tbl[i - 1] + i * 2 - 1;
    }

    int m;
    double R;
    cin >> m >> R;
    double sum = 0.0;
    double s = sqrt(2.0);
    for(int i = 0; i < m; ++i){
        double d = 2.0;
        if(i > 0){
            d += 2.0 + s;
        }
        if(i < m - 1){
            d += 2.0 + s;
        }
        if(i > 1){
            d += (i - 1) * (1.0 + 2.0 * s) + tbl[i - 1];
        }
        if(i < m - 2){
            d += (m - 2 - i) * (1.0 + 2.0 * s) + tbl[m - 2 - i];
        }
        sum += d;
    }
    printf("%.9f\n", sum * R / m / m);
}