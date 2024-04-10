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



int main(){
    int c[8] = {};
    int n, x;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> x;
        ++c[x];
    }

    c[1] -= c[3];
    c[6] -= c[3];
    c[1] -= c[4];
    c[2] -= c[4];
    c[1] -= c[6];
    c[2] -= c[6];
    
    if(c[1] || c[2] || c[5] || c[7] || c[6] < 0){
        puts("-1");
    }
    else{
        for(int i = 0; i < c[3]; ++i){
            puts("1 3 6");
        }
        for(int i = 0; i < c[4]; ++i){
            puts("1 2 4");
        }
        for(int i = 0; i < c[6]; ++i){
            puts("1 2 6");
        }
    }
}