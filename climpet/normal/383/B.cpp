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



int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> x(m), y(m), xs(1, 1);
    for(int i = 0; i < m; ++i){
        scanf("%d%d", &x[i], &y[i]);
        xs.push_back(x[i]);
        if(x[i] != n){
            xs.push_back(x[i] + 1);
        }
    }
    
    sort(ALL(xs));
    xs.erase(unique(ALL(xs)), xs.end());
    VV(int) bs(xs.size(), vector<int>(1, n + 1));
    for(int i = 0; i < m; ++i){
        bs[lower_bound(ALL(xs), x[i]) - xs.begin()].push_back(y[i]);
    }
    for(size_t i = 0; i < xs.size(); ++i){
        sort(ALL(bs[i]));
    }
    
    vector<pii> rs(1, pii(1, 1)), rs2;
    for(size_t i = 0; i < xs.size(); ++i){
        for(size_t j = 0; j < rs.size(); ++j){
            int p = rs[j].first;
            int t;
            do{
                t = *lower_bound(ALL(bs[i]), p);
                if(p != t){
                    rs2.push_back(pii(p, t - 1));
                }
                p = t + 1;
            } while(t < rs[j].second);
        }

        rs.clear();
        sort(ALL(rs2));
        for(size_t j = 0; j < rs2.size(); ){
            int p = rs2[j].first, q = rs2[j].second;
            for(; j < rs2.size() && rs2[j].first <= q + 1; ++j){
                q = rs2[j].second;
            }
            if(p <= q){
                rs.push_back(pii(p, q));
            }
        }
        rs2.clear();
    }

    printf("%d\n", rs.back().second == n ? n * 2 - 2 : -1);
}