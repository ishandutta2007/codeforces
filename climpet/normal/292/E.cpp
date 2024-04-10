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

const int MAX_N = 131072;

int n, rec[2 * MAX_N - 1];
bool lazy[2 * MAX_N - 1];

void init(int m){
    n = 1;
    while(n < m){ n *= 2; }
    for(int i = 0; i < 2 * n - 1; ++i){
        rec[i] = -1;
    }
}

inline void lazy_update(int k){
    if(lazy[k]){
        lazy[k] = false;
        if(k < n){
            rec[k * 2 + 1] = rec[k * 2 + 2] = rec[k];
            lazy[k * 2 + 1] = lazy[k * 2 + 2] = true;
        }
    }
}

void update(int a, int b, int t, int k = 0, int l = 0, int r = n){
    lazy_update(k);

    if(r <= a || b <= l) return;
    if(a <= l && r <= b){
        rec[k] = t;
        lazy[k] = true;
    }
    else{
        update(a, b, t, k * 2 + 1, l, (l + r) / 2);
        update(a, b, t, k * 2 + 2, (l + r) / 2, r);
    }
}

int query(int a, int k = 0, int l = 0, int r = n){
    while(k < n){
        lazy_update(k);

        int mid = (l + r) / 2;
        if(a < mid){
            k = k * 2 + 1;
            r = mid;
        }
        else{
            k = k * 2 + 2;
            l = mid;
        }
    }
    return rec[k];
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    init(n + 1);

    vint a(MAX_N), b(MAX_N);
    vint t(m), x(m), y(m), k(m);

    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; ++i){
        scanf("%d", &b[i]);
    }

    for(int i = 0; i < m; ++i){
        scanf("%d%d", &t[i], &x[i]);
        if(t[i] == 1){
            scanf("%d%d", &y[i], &k[i]);
        }
    }

    for(int i = 0; i < m; ++i){
        if(t[i] == 1){
            update(y[i], y[i] + k[i], i);
        }
        else{
            int u = query(x[i]);
            int ret = b[x[i]];
            if(u != -1){
                int q = x[i] - y[u];
                ret = a[x[u] + q];
            }
            printf("%d\n", ret);
        }
    }
}