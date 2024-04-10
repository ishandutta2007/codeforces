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


const int tbl[8][4] = {
    {7, -1},
    {6, -1},
    {5, -1},
    {4, 7, -1},
    {3, -1},
    {2, -1},
    {1, 7, -1},
    {0, 3, 6, -1},
};


int n;
char a[7][10010];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

LL solve(){
    vector<LL> dp1(8), dp2(8);
    dp1[7] = 1;
    for(int i = 2; i <= n + 1; ++i){
        int C = 0;
        for(int j = 0; j < 3; ++j){
            if(a[j + 2][i] == '.'){
                C |= 1 << j;
            }
        }

        for(int S = 0; S < 8; ++S){
            if(~S & ~C & 7){ continue; }
            int F = S & C;
            for(int j = 0; tbl[F][j] != -1; ++j){
                LL &u = dp2[tbl[F][j]];
                u = (u + dp1[S]) % MOD;
            }
        }

        dp1.swap(dp2);
        fill(ALL(dp2), 0LL);
    }
    return dp1[7];
}


int main(){
    scanf("%d %s %s %s", &n, a[2] + 2, a[3] + 2, a[4] + 2);
    LL ans = 0;
    int y = 2, x = 0;
    bool fnd = false;
    
    while(1){
        for(x = 2; x <= n + 1 && a[y][x] != 'O'; ++x);
        if(a[y][x] == 'O'){ break; }
        ++y;
    }
    
    int F = 0;
    for(int i = 0; i < 4; ++i){
        char p1 = a[y + dy[i]][x + dx[i]];
        char p2 = a[y + 2 * dy[i]][x + 2 * dx[i]];
        if(p1 == '.' && p2 == '.'){
            F |= 1 << i;
        }
    }

    vector<char*> v;
    for(int S = 1; S < 16; ++S){
        if((S & F) != S){ continue; }
        for(int i = 0; i < 4; ++i){
            if(S >> i & 1){
                for(int j = 1; j <= 2; ++j){
                    v.push_back(&a[y + j * dy[i]][x + j * dx[i]]);
                }
            }
        }
        for(int i = 0; i < v.size(); ++i){
            *v[i] = 'X';
        }
        
        LL t = solve();
        if(bitset<4>(S).count() % 2 == 0){ t = MOD - t; }
        ans = (ans + t) % MOD;
        for(int i = 0; i < v.size(); ++i){
            *v[i] = '.';
        }
        v.clear();
    }
    
    cout << ans << endl;
}