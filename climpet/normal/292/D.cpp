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

void init(vint &v, int n){
    v.resize(n + 1);
    for(int i = 1; i <= n; ++i){
        v[i] = i;
    }
}

int find(vint &v, int x){
    return v[x] != x ? v[x] = find(v, v[x]) : x;
}

void unite(vint &v, int x, int y){
    x = find(v, x);
    y = find(v, y);
    if(x == y){ return; }
    if(rand() >> 9 & 1){ swap(x, y); }
    v[x] = y;
}

int main(){
    srand(time(0));

    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> x(m + 1), y(m + 1);
    for(int i = 1; i <= m; ++i){
        scanf("%d%d", &x[i], &y[i]);
    }

    vvint uf(m + 1);
    init(uf[0], n);
    for(int i = 1; i <= m; ++i){
        uf[i] = uf[i - 1];
        unite(uf[i], x[i], y[i]);
    }
    
    vvint ufr(m + 2);
    init(ufr[m + 1], n);
    for(int i = m; i > 0; --i){
        ufr[i] = ufr[i + 1];
        unite(ufr[i], x[i], y[i]);
    }

    int k, l, r;
    scanf("%d", &k);
    vint ufu;
    for(int i = 0; i < k; ++i){
        scanf("%d%d", &l, &r);
        ++r;
        ufu = uf[l - 1];
        for(int j = 1; j <= n; ++j){
            unite(ufu, j, ufr[r][j]);
        }
        
        int c = 0;
        for(int j = 1; j <= n; ++j){
            if(ufu[j] == j){ ++c; }
        }
        printf("%d\n", c);
    }
}