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


#define MOD 1000000007LL
#define EPS 1e-8


LL tbl[300010];


LL inv(LL x){
    LL y = MOD - 2;
    LL a = 1;
    while(y){
        if(y & 1){ a = a * x % MOD; }
        x = x * x % MOD;
        y >>= 1;
    }
    return a;
}

LL fact(LL n){
    LL a = 1;
    while(n > 1){
        a = a * n % MOD;
        --n;
    }
    return a;
}

LL comb(LL n, LL k){
    if(k < 0 || k > n){ return 0; }
    return tbl[n] * inv(tbl[k] * tbl[n - k] % MOD) % MOD;
}


map<pll,LL> memo;

LL func(int i, int j){
    if(i < 0 || j < 0){ return 0; }

    if(i == 0){
        if(j == 2){ return 1; }
        if(j < 2){ return 0; }
    }
    else if(i == 1){
        if(j == 0){ return 1; }
        if(j == 1){ return 2; }
    }
    
    if(memo.count(pll(i, j))){
        return memo[pll(i, j)];
    }

    LL t = (func(i - 2, j) + func(i - 1, j - 1) + func(i, j - 1)) % MOD;
    memo.insert(make_pair(pll(i, j), t));
    return t;
}

int solve(LL n, LL m, LL g){
    if(g){
        if(m == 1 && n == 0){ return 1; }
        if(!n){ return 0; }
        --n;
    }

    if(n == 0){
        if(m < 2){ return 0; }
        return 1;
    }
    if(m < 3){ return func(n, m); }

    LL ans = 0;
    for(LL k = 0; k <= n; ++k){
        LL t = comb(k + m, m) % MOD;
        if(n - k & 1){ t = (MOD - t) % MOD; }
        ans = (ans + t) % MOD;
    }
    
    return ans;
}



int main(){
    tbl[0] = 1;
    for(int i = 1; i <= 300000; ++i){
        tbl[i] = tbl[i - 1] * i % MOD;
    }

    LL n, m, g;
    cin >> n >> m >> g;
    cout << solve(n, m, g) << endl;
}