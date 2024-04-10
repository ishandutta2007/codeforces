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


LL powmod(LL x, LL y){
    LL a = 1;
    while(y){
        if(y & 1){ a = a * x % MOD; }
        y >>= 1;
        x = x * x % MOD;
    }
    return a;
}


int main(){
    int n, x;
    scanf("%d%d", &n, &x);
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }

    LL sum = accumulate(ALL(a), 0LL);
    map<LL,int> mp;
    for(int i = 0; i < n; ++i){
        ++mp[sum - a[i]];
    }

    map<LL,int>::iterator it;
    LL t = 0;
    for(it = mp.begin(); it != mp.end(); ++it){
        if(it->second % x == 0){
            mp[it->first + 1] += it->second / x;
        }
        else{
            t = it->first;
            break;
        }
    }

    LL y = min(sum, t);
    LL ans = powmod(x, y);
    cout << ans << endl;
}