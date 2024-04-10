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


const int MAX_N = 262144;

int n, lazy[2][MAX_N * 2 - 1];
int rtbl[MAX_N], qr[MAX_N];
int odd[MAX_N];
vector<int> G[MAX_N];
bool visit[MAX_N];
int cnt;

void init(int n_){
    n = 1;
    while(n < n_){ n *= 2; }
    memset(lazy, 0, sizeof lazy);
}


int getval(int *seg, int y){
    int k = 0, l = 0, r = n;
    while(k < n - 1){
        seg[2 * k + 1] += seg[k];
        seg[2 * k + 2] += seg[k];
        seg[k] = 0;
        
        int m = (l + r) / 2;
        if(y < m){
            k = 2 * k + 1;
            r = m;
        }
        else{
            k = 2 * k + 2;
            l = m;
        }
    }
    
    return seg[k];
}

void query(int *seg, int a, int b, int v, int k = 0, int l = 0, int r = n){
    if(r <= a || b <= l){ return; }
    if(a <= l && r <= b){
        seg[k] += v;
    }
    else{
        query(seg, a, b, v, k * 2 + 1, l, (l + r) / 2);
        query(seg, a, b, v, k * 2 + 2, (l + r) / 2, r);
    }
}


void dfs(int u, bool od){
    if(visit[u]){ return; }
    visit[u] = true;
    odd[u] = od;
    rtbl[u] = cnt++;
    for(size_t i = 0; i < G[u].size(); ++i){
        dfs(G[u][i], !od);
    }
    qr[u] = cnt;
}


int main(){
    int n0, m, u, v, x, val, tp;
    scanf("%d%d", &n0, &m);
    vector<int> as(n0 + 1);
    for(int i = 1; i <= n0; ++i){
        scanf("%d", &as[i]);
    }
    for(int i = 1; i < n0; ++i){
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    init(n0);
    dfs(1, false);
    for(int i = 1; i <= n0; ++i){
        lazy[odd[i]][rtbl[i] + n - 1] = as[i];
    }
    
    for(int i = 0; i < m; ++i){
        scanf("%d%d", &tp, &x);
        if(tp == 1){
            scanf("%d", &val);
            query(lazy[odd[x]], rtbl[x], qr[x], val);
            query(lazy[1 - odd[x]], rtbl[x], qr[x], -val);
        }
        else{
            printf("%d\n", getval(lazy[odd[x]], rtbl[x]));
        }
    }
}