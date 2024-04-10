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


int dist(pii p, pii q){
    return abs(p.first - q.first) + abs(p.second - q.second);
}

int main(){
    int n, d;
    cin >> n >> d;
    vint a(n);
    for(int i = 1; i < n - 1; ++i){
        cin >> a[i];
    }
    vector<pii> p(n);
    for(int i = 0; i < n; ++i){
        cin >> p[i].first >> p[i].second;
    }

    vvint G(n, vint(n));
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
    if(i != j){
        G[i][j] = dist(p[i], p[j]) * d - a[i];
    }

    vint m(n, INT_MAX);
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    m[0] = 0;
    pq.push(pii());
    while(!pq.empty()){
        pii p = pq.top();
        pq.pop();
        if(m[p.second] != p.first){ continue; }
        for(int i = 0; i < n; ++i){
            int c = p.first + G[p.second][i];
            if(m[i] > c){
                m[i] = c;
                pq.push(pii(c, i));
            }
        }
    }
    printf("%d\n", m.back());
}