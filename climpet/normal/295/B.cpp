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


#define REP(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define PB push_back
#define ITR ::iterator


#define MOD 1000000009LL
#define EPS 1e-8



int main(){
    int n;
    scanf("%d", &n);
    vint x(n);
    vvint a(n, vint(n));
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j){
        scanf("%d", &a[i][j]);
    }
    for(int i = n - 1; i >= 0; --i){
        scanf("%d", &x[i]);
        --x[i];
    }

    vvint d(n, vint(n));
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j){
        d[i][j] = a[x[i]][x[j]];
    }
    vLL ans(n);
    for(int k = 0; k < n; ++k){
        LL sum = 0;
        
        for(int i = 0; i <= k; ++i)
        for(int j = 0; j <= k; ++j){
            d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
            d[k][j] = min(d[k][j], d[k][i] + d[i][j]);
        }
        
        for(int i = 0; i <= k; ++i)
        for(int j = 0; j <= k; ++j){
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
        
        for(int i = 0; i <= k; ++i)
        for(int j = 0; j <= k; ++j){
            sum += d[i][j];
        }
        ans[n - k - 1] = sum;
    }

    for(int i = 0; i < n; ++i){
        if(i != 0){ cout << ' '; }
        cout << ans[i];
    }
    cout << endl;
}