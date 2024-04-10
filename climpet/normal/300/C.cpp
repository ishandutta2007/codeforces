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


#define MOD 1000000007LL
#define EPS 1e-8

int a, b, n;
bool good[10000010];
LL fact[1000010], inv[1000010];
char buf[16];

inline int powmod(LL x, LL y){
    LL a = 1;
    while(y){
        if(y & 1) a = a * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return a;
}

void dfs(int i){
    if(i){
        good[atoi(buf)] = true;
    }

    if(i < 7){
        buf[i] = a + '0';
        dfs(i + 1);
        buf[i] = b + '0';
        dfs(i + 1);
        buf[i] = 0;
    }
}

int main(){
    fact[0] = inv[0] = 1;
    for(int i = 1; i <= 1000000; ++i){
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = powmod(fact[i], MOD - 2);
    }

    cin >> a >> b >> n;
    dfs(0);

    int ans = 0;
    for(int i = 0; i <= n; ++i){
        if(good[i * a + (n - i) * b]){
            ans = (ans + fact[n] * inv[n-i] % MOD * inv[i]) % MOD;
        }
    }

    cout << ans << endl;
}