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


int par[50];

int find(int x){
    return x != par[x] ? par[x] = find(par[x]) : x;
}


int main(){
    for(int i = 1; i < 50; ++i){
        par[i] = i;
    }

    int n, m, a, b;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        par[find(a)] = find(b);
    }

    vint v[50];
    for(int i = 1; i <= n; ++i){
        v[find(i)].push_back(i);
    }

    vvint w[4];
    for(int i = 1; i <= n; ++i){
        if(v[i].size() > 3){
            puts("-1");
            return 0;
        }
        w[v[i].size()].push_back(v[i]);
    }

    if(w[2].size() > w[1].size()){
        puts("-1");
        return 0;
    }

    for(int i = 0; i < w[3].size(); ++i){
        printf("%d %d %d\n", w[3][i][0], w[3][i][1], w[3][i][2]);
    }

    for(int i = 0; i < w[2].size(); ++i){
        printf("%d %d %d\n", w[2][i][0], w[2][i][1], w[1].back()[0]);
        w[1].pop_back();
    }

    for(int i = 0; i < w[1].size(); i += 3){
        printf("%d %d %d\n", w[1][i][0], w[1][i+1][0], w[1][i+2][0]);
    }
}