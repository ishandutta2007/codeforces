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
    int n, m, k, x, y;
    scanf("%d%d%d", &n, &m, &k);
    vint a(n);
    for(int i = 0; i < n; ++i){
        scanf("%d\n", &a[i]);
    }

    vint ls(m), rs(m), ds(m);
    for(int i = 0; i < m; ++i){
        scanf("%d%d%d", &ls[i], &rs[i], &ds[i]);
    }

    vint imos(m + 1);
    for(int i = 0; i < k; ++i){
        scanf("%d%d", &x, &y);
        ++imos[x - 1];
        --imos[y];
    }
    partial_sum(ALL(imos), imos.begin());

    vLL imos2(n + 1);
    for(int i = 0; i < m; ++i){
        LL t = (LL)imos[i] * ds[i];
        imos2[ls[i] - 1] += t;
        imos2[rs[i]] -= t;
    }

    partial_sum(ALL(imos2), imos2.begin());

    for(int i = 0; i < n; ++i){
        if(i != 0){ putchar(' '); }
        printf("%I64d", a[i] + imos2[i]);
    }
    puts("");
}