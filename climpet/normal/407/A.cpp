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


int func(int x){
    for(int i = 1; i < x; ++i){
        int y = sqrt(x * x - i * i + 0.5);
        if(i * i + y * y == x * x){
            return i;
        }
    }
    return -1;
}


int main(){
    int a, b;
    cin >> a >> b;
    if(a < b){
        swap(a, b);
    }
    int c = __gcd(a, b);
    int x = func(c);
    if(x > 0){
        int y = sqrt(c * c - x * x + 0.5);
        int t = a / c * x, u = a / c * y;
        printf("YES\n0 0\n%d %d\n%d %d\n",
            t, u, t + b / c * y, u - b / c * x);
    }
    else{
        puts("NO");
    }
    
}