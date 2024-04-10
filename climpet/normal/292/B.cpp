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

int solve(){
    int n, m, x, y;
    scanf("%d%d", &n, &m);
    vint c(n + 1);
    for(int i = 0; i < m; ++i){
        scanf("%d%d", &x, &y);
        ++c[x];
        ++c[y];
    }

    if(n == m){
        for(int i = 1; i <= n; ++i){
            if(c[i] != 2){ return -1; }
        }
        return 1;
    }
    else if(n == m + 1){
        int c1 = 0, c2 = 0, cm = 0;
        for(int i = 1; i <= n; ++i){
            if(c[i] == 1){ ++c1; }
            else if(c[i] == 2){ ++c2; }
            else if(c[i] > 2){ ++cm; }
        }

        if(c1 == 2 && cm == 0){
            return 0;
        }
        if(cm == 1 && c2 == 0){
            return 2;
        }
    }
    
    return -1;
}

int main(){
    const char *type = "unknown";
    switch(solve()){
    case 0:
        type = "bus";
        break;
    case 1:
        type = "ring";
        break;
    case 2:
        type = "star";
        break;
    }
    printf("%s topology\n", type);
}