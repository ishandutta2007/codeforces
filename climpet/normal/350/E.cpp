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


void solve(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    if(n == k){ throw 0; }

    vector<int> a(k);
    vector<int> mk(n + 1);
    REP(i, k){
        scanf("%d", &a[i]);
        mk[a[i]] = 1;
    }

    int mfst;
    for(mfst = 1; mk[mfst]; ++mfst);

    vector<pii> res;
    for(int i = 1; i <= n; ++i){
        if(i != mfst){
            res.push_back(pii(i, mfst));
        }
    }
    for(int i = 1; i <= n; ++i)
    for(int j = 1; j < i; ++j){
        if(i == mfst || j == mfst){ continue; }
        if(i == a[0] || j == a[0]){
            int v = i ^ j ^ a[0];
            if(mk[v]){ continue; }
        }
        res.push_back(pii(i, j));
    }
    
    if(res.size() < m){
        throw "";
    }
    for(int i = 0; i < m; ++i){
        printf("%d %d\n", res[i].first, res[i].second);
    }
}


int main() try{
    solve();
}
catch(...){
    puts("-1");
}