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

#define cauto const auto&
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
    ios::sync_with_stdio(false);

    int n, a;
    cin >> n;
    vector<int> xs(n + 1), ys(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> a;
        xs[i] = xs[i - 1] + a;
        ys[i] = ys[i - 1] + (i & 1 ? -a : a);
    }

    int ymin = *min_element(ALL(ys));
    int ymax = *max_element(ALL(ys));
    
    vector<string> ans(ymax - ymin + 1, string(xs[n], ' '));
    for(int i = 0; i < n; ++i){
        int d = xs[i + 1] - xs[i];
        if(ys[i + 1] > ys[i]){
            for(int j = 0; j < d; ++j){
                ans[ys[i] - ymin + j][xs[i] + j] = '\\';
            }
        }
        else{
            for(int j = 0; j < d; ++j){
                ans[ys[i] - ymin - j - 1][xs[i] + j] = '/';
            }
        }
    }
    
    for(cauto s : ans){
        cout << s << '\n';
    }
}