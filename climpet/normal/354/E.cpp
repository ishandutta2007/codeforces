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
#include <cassert>

#if __cplusplus >= 201103L
#include <array>
#include <tuple>
#include <initializer_list>
#include <unordered_set>
#include <unordered_map>
#include <forward_list>

#define cauto const auto&
#define ALL(v) begin(v),end(v)
#else
#define ALL(v) (v).begin(),(v).end()
#endif

using namespace std;


namespace{
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
#define RALL(v) (v).rbegin(),(v).rend()


#define MOD 1000000007LL
#define EPS 1e-8


int dp[24][10];

void solve(string s){
    memset(dp, 0, sizeof dp);
    int m = s.size();
    dp[m][0] = -1;
    for(int i = m - 1; i >= 0; --i){
        char d = s[i] - '0';
        for(int c0 = 0; c0 <= 6; ++c0)
        for(int c4 = 0; c0 + c4 <= 6; ++c4){
            int c7 = 6 - c0 - c4;
            int sum = 4 * c4 + 7 * c7;
            int p;
            for(p = 0; (p + sum) % 10 != d; ++p);
            if(dp[i + 1][p] == 0){ continue; }
            dp[i][(p + sum) / 10] = c0 | c4 << 3 | c7 << 6 | p << 9;
        }
    }
    
    if(dp[0][0] == 0){
        puts("-1");
    }
    else{
        string res[6];
        int u = 0;
        for(int k = 0; k < m; ++k){
            int c0 = dp[k][u] & 7;
            int c4 = dp[k][u] >> 3 & 7;
            int c7 = dp[k][u] >> 6 & 7;
            int x = 0;
            for(int i = 0; i < c0; ++i){
                res[x++] += '0';
            }
            for(int i = 0; i < c4; ++i){
                res[x++] += '4';
            }
            for(int i = 0; i < c7; ++i){
                res[x++] += '7';
            }
            u = dp[k][u] >> 9;
        }
        for(int i = 0; i < 6; ++i){
            const char *q = res[i].c_str();
            while(q[1] && q[0] == '0'){ ++q; }
            printf("%s%c", q, i == 5 ? '\n' : ' ');
        }
    }
    
}

void mainmain(){
    int t;
    scanf("%d", &t);
    char buf[32] = "";
    for(int i = 0; i < t; ++i){
        scanf("%s", buf);
        solve(buf);
    }
}



}
int main() try{
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(4);
    mainmain();
}
catch(...){}