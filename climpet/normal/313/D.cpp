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


int tbl[304][304];
LL dp[304][304];


int main(){
    fill(*tbl, *tbl + sizeof tbl / sizeof **tbl, INT_MAX);
    fill(*dp, *dp + sizeof dp / sizeof **dp, LLONG_MAX / 2);
    int n, m, k, l, r, c;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; ++i){
        scanf("%d%d%d", &l, &r, &c);
        tbl[l - 1][r] = min(tbl[l - 1][r], c);
    }
    for(r = 1; r <= n; ++r){
        for(int i = 1; i < r; ++i){
            tbl[i][r] = min(tbl[i][r], tbl[i - 1][r]);
        }
    }

    dp[0][0] = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j <= n; ++j){
            if(tbl[i][j] == INT_MAX){ continue; }
            for(int h = 0; h <= k; ++h){
                int d = min(j - i + h, k);
                dp[d][j] = min(dp[d][j], dp[h][i] + tbl[i][j]);
            }
        }
        for(int h = 0; h <= k; ++h){
            dp[h][i + 1] = min(dp[h][i + 1], dp[h][i]);
        }
    }

    LL ans = dp[k][n];
    if(ans == LLONG_MAX / 2){ ans = -1; }
    cout << ans << endl;
}