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

#if __cplusplus >= 201103L
#include <array>
#include <tuple>
#include <initializer_list>
#include <unordered_set>
#include <unordered_map>
#include <forward_list>
#endif

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
    cin >> n;
    vector<tuple<int,int,int>> vs(n + 1);
    for(int i = 0; i < n; ++i){
        cin >> get<0>(vs[i]) >> get<1>(vs[i]);
        get<2>(vs[i]) = i + 1;
    }
    get<0>(vs[n]) = 1010101010;
    sort(ALL(vs));
    cin >> m;
    vector<pii> rs(m);
    for(int i = 0; i < m; ++i){
        cin >> rs[i].first;
        rs[i].second = i + 1;
    }
    sort(ALL(rs));

    int k = 0;
    int sum = 0;
    priority_queue<pii> pq;
    vector<pii> ans;
    for(int i = 0; i < m; ++i){
        while(get<0>(vs[k]) <= rs[i].first){
            pq.emplace(get<1>(vs[k]), get<2>(vs[k]));
            ++k;
        }
        if(!pq.empty()){
            sum += pq.top().first;
            ans.emplace_back(pq.top().second, rs[i].second);
            pq.pop();
        }
    }
    
    cout << ans.size() << ' ' << sum << '\n';
    for(const auto &p : ans){
        cout << p.first << ' ' << p.second << '\n';
    }
}