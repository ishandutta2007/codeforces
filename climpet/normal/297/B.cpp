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



int main(){
    int n, m, k, x;
    scanf("%d%d%d", &n, &m, &k);

    map<int,int> a, b;
    map<int,int>::iterator it, it2;
    for(int i = 0; i < n; ++i){
        scanf("%d", &x);
        ++a[x];
    }
    for(int i = 0; i < m; ++i){
        scanf("%d", &x);
        ++b[x];
    }

    for(it = a.begin(); it != a.end(); ++it){
        it2 = b.find(it->first);
        if(it2 != b.end()){
            x = min(it->second, it2->second);
            it->second -= x;
            it2->second -= x;
        }
    }
    
    for(it = a.begin(); it != a.end(); ){
        it2 = it;
        ++it;
        if(it2->second == 0){ a.erase(it2); }
    }

    for(it = b.begin(); it != b.end(); ){
        it2 = it;
        ++it;
        if(it2->second == 0){ b.erase(it2); }
    }

    vector<int> c, d;
    for(it = a.begin(); it != a.end(); ++it){
        for(int i = 0; i < it->second; ++i){
            c.push_back(it->first);
        }
    }
    for(it = b.begin(); it != b.end(); ++it){
        for(int i = 0; i < it->second; ++i){
            d.push_back(it->first);
        }
    }

    while(!c.empty() && !d.empty()){

        if(c.back() >= d.back()){ break; }
        c.pop_back();
        d.pop_back();
    }
    
    puts(c.empty() ? "NO" : "YES");
}