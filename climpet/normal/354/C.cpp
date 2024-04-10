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
#include <cassert>

#if __cplusplus >= 201103L
#include <array>
#include <tuple>
#include <initializer_list>
#include <unordered_set>
#include <unordered_map>
#include <forward_list>

#define cauto const auto&
#define ALL(v) begin(v),end(v)
#else
#define ALL(v) (v).begin(),(v).end()
#endif

using namespace std;


namespace{
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
#define RALL(v) (v).rbegin(),(v).rend()


#define MOD 1000000007LL
#define EPS 1e-8


const int M = 1000010;
int pred[M + 1];
bool in[M + 1];


void mainmain(){
    int n, k;
    scanf("%d%d", &n, &k);
    int minval = M;
    for(int i = 0; i < n; ++i){
        int a;
        scanf("%d", &a);
        in[a] = true;
        minval = min(minval, a);
    }
    pred[0] = -1;
    for(int i = 1; i <= M; ++i){
        if(in[i - 1]){
            pred[i] = i - 1;
        }
        else{
            pred[i] = pred[i - 1];
        }
    }
    
    for(int i = minval; i > 0; --i){
        bool ok = true;
        int j, p;
        for(j = 0; j + i < M; j += i){
            p = pred[j + i];
            if(p >= j && p - j > k){
                ok = false;
                break;
            }
        }
        p = pred[M];
        if(p >= j && p - j > k){
            ok = false;
        }
        
        if(ok){
            printf("%d\n", i);
            return;
        }
    }
    
    assert(false);
}



}
int main() try{
//  ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(4);
    mainmain();
}
catch(...){}