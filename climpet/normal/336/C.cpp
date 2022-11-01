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


vector<int> check(const vector<int> &a, int x){
    vector<int> b;
    int z = INT_MAX;
    for(int i = 0; i < a.size(); ++i){
        if(a[i] & x){
            b.push_back(a[i]);
            z &= a[i];
        }
    }
    if(z % x){ b.clear(); }
    return b;
}


int main(){
    int n;
    scanf("%d", &n);
    vector<int> a(n);

    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }

    vector<int> b;
    for(int x = 1 << 30; x > 0; x >>= 1){
        b = check(a, x);
        if(!b.empty()){ break; }
    }
    if(b.empty()){ b = a; }

    int c = '\n';
    printf("%d", b.size());
    for(int i = 0; i < b.size(); ++i){
        printf("%c%d", c, b[i]);
        c = ' ';
    }
    puts("");
}