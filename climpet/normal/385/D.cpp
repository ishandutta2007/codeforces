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
    double rat = acos(-1.0) / 180.0;

    int n;
    double fr, to;
    scanf("%d%lf%lf", &n, &fr, &to);
    vector<double> xs(n), ys(n), as(n);
    for(int i = 0; i < n; ++i){
        scanf("%lf%lf%lf", &xs[i], &ys[i], &as[i]);
        as[i] *= rat;
    }

    int last = 1 << n;
    vector<double> dp(last, fr);

    for(int S = 0; S < last; ++S){
        for(int i = 0; i < n; ++i){
            if(S >> i & 1){ continue; }
            double t = min(atan2(-ys[i], dp[S] - xs[i]) + as[i], -1e-10);
            double q = xs[i] - ys[i] / tan(t);

            int T = S | 1 << i;
            dp[T] = max(dp[T], q);
        }
    }
    
    printf("%.9f\n", min(dp.back(), to) - fr);
}