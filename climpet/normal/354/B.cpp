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


const int INF = 1010101010;

int n;
char tbl[50][50];
vector<int> chs[50];
VV(int) G[50];
int num[50][50];
vector<int> memo[50];

int dfs(int d, int S){
    int &r = memo[d][S];
    if(r != INF){ return r; }

    int c = G[d].size();
    if(d == 2 * n - 2){
        r = 0;
    }
    else{
        if(d & 1){ r = -INF; }
        int to[26] = {};
        for(int i = 0; i < c; ++i)
        if(S >> i & 1){
            for(int u : G[d][i]){
                to[chs[d + 1][u]] |= 1 << u;
            }
        }
        for(int i = 0; i < 26; ++i){
            if(to[i]){
                int q = dfs(d + 1, to[i]);
                if(d & 1){
                    r = max(r, q);
                }
                else{
                    r = min(r, q);
                }
            }
        }
    }
    
    for(int i = 0; i < c; ++i)
    if(S >> i & 1){
        if(chs[d][i] == 0){
            ++r;
        }
        else if(chs[d][i] == 1){
            --r;
        }
        break;
    }

    return r;
}


void mainmain(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> tbl[i];
    }

    for(int i = 0; i < 2 * n - 1; ++i){
        int c = 0;
        for(int y = 0; y < n; ++y){
            int x = i - y;
            if(x >= 0){
                chs[i].push_back(tbl[y][x] - 'a');
                num[y][x] = c++;
            }
        }
        G[i].resize(c);
        memo[i].assign(1 << c, INF);
    }
    
    for(int y = 0; y < n; ++y)
    for(int x = 0; x < n; ++x){
        int p = num[y][x];
        int d = y + x;
        if(y != n - 1){
            G[d][p].push_back(num[y + 1][x]);
        }
        if(x != n - 1){
            G[d][p].push_back(num[y][x + 1]);
        }
    }

    int res = dfs(0, 1);
    if(res > 0){
        puts("FIRST");
    }
    else if(res < 0){
        puts("SECOND");
    }
    else{
        puts("DRAW");
    }
}



}
int main() try{
//  ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(4);
    mainmain();
}
catch(...){}