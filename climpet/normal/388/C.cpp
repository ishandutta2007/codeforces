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
    int n;
    scanf("%d", &n);
    VV(int) cs(n);
    int sum = 0;
    for(int i = 0; i < n; ++i){
        int s;
        scanf("%d", &s);
        cs[i].resize(s);
        for(int j = 0; j < s; ++j){
            scanf("%d", &cs[i][j]);
            sum += cs[i][j];
        }
    }

    int a = 0;
    vector<int> v;
    for(int i = 0; i < n; ++i){
        int s = cs[i].size();
        a += accumulate(cs[i].begin(), cs[i].begin() + s / 2, 0);
        if(s & 1){
            v.push_back(cs[i][s / 2]);
        }
    }
    sort(ALL(v));
    for(int i = (int)v.size() - 1; i >= 0; i -= 2){
        a += v[i];
    }
    printf("%d %d\n", a, sum - a);
}