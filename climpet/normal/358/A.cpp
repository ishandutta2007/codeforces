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


bool solve(){
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &v[i]);
    }

    for(int i = 1; i < n; ++i)
    for(int j = 1; j < n; ++j){
        int x1 = min(v[i - 1], v[i]);
        int x2 = min(v[j - 1], v[j]);
        int x3 = v[i - 1] + v[i] - x1;
        int x4 = v[j - 1] + v[j] - x2;
        
        if(x1 < x2 && x2 < x3 && x3 < x4){
            return true;
        }
    }
    return false;
}


int main(){
    puts(solve() ? "yes" : "no");
}