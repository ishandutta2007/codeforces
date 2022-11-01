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

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
    v.assign(a, vector<T>(b, t));
}


#define REP(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define PB push_back
#define ITR ::iterator


#define MOD 1000000007
#define EPS 1e-8

int cmb[1002][1002];
int pow2[1002];

int main(){
    for(int i = 0; i <= 1000; ++i){
        cmb[i][0] = 1;
        for(int j = 1; j <= i; ++j){
            cmb[i][j] = (cmb[i-1][j-1] + cmb[i-1][j]) % MOD;
        }
    }
    pow2[0] = 1;
    for(int i = 1; i <= 1000; ++i){
        pow2[i] = pow2[i-1] * 2 % MOD;
    }

    int n, m;
    cin >> n >> m;
    vint a(m);
    for(int i = 0; i < m; ++i){
        cin >> a[i];
    }
    sort(ALL(a));

    vint v;
    LL ans = 1;
    if(a[0] != 1){
        v.push_back(a[0] - 1);
    }
    for(int i = 1; i < a.size(); ++i){
        int t = a[i] - a[i-1] - 1;
        if(t){
            v.push_back(t);
            ans = ans * pow2[t - 1] % MOD;
        }
    }
    if(a.back() != n){
        v.push_back(n - a.back());
    }

    int s = n - m;
    for(int i = 0; i < v.size(); ++i){
        ans = ans * cmb[s][v[i]] % MOD;
        s -= v[i];
    }
    
    cout << ans << endl;
}