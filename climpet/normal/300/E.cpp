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


int c[10000010];
bool isnp[10000010];

LL tbl[64];
LL pw[64];


inline LL func(LL x, LL b){
    tbl[0] = pw[0] = 1;
    int i;
    for(i = 1; ; ++i){
        pw[i] = pw[i-1] * b;
        tbl[i] = tbl[i-1] * b + 1;
        
        if(tbl[i] > x){ break; }
    }

    LL s = 0, t = 0, u = LLONG_MAX;
    for( ; i >= 0; --i){
        u = min(u, t + (x - s + tbl[i] - 1) / tbl[i] * pw[i]);
        LL p = (x - s) / tbl[i];
        t += pw[i] * p;
        s += p * tbl[i];
    }

    return u * b;
}


int main(){
    int k, a, m = 0;
    scanf("%d", &k);
    for(int i = 0; i < k; ++i){
        scanf("%d", &a);
        ++a;
        m = max(m, a);
        --c[a];
    }

    c[0] = k;
    partial_sum(c, c + m, c);

    LL n = 1;
    for(LL i = 2; i < m; ++i){
        if(isnp[i]){ continue; }

        if(i < 4000){
            for(LL j = i * i; j < m; j += i){
                isnp[j] = true;
            }
        }

        LL s = 0;
        for(LL j = i; j < m; j += i){
            s += c[j];
        }

        for(LL t = (LL)i * i; t < m; t *= i){
            for(LL j = t; j < m; j += t){
                s += c[j];
            }
        }

        LL r = func(s, i);
        n = max(n, r);
    }
    
    cout << n << endl;
}