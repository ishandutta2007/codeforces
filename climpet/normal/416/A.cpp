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


bool check(const vint &gs, const vint &ls, int x){
    for(int y : gs){
        if(y >= x){ return false; }
    }
    for(int y : ls){
        if(y <= x){ return false; }
    }
    return true;
}


int main(){
    int n, x;
    cin >> n;
    string s;
    char c;
    vector<int> gs, ls;
    for(int i = 0; i < n; ++i){
        cin >> s >> x >> c;
        if(c == 'N'){
            if(s.size() == 2){
                s.resize(1);
            }
            else{
                s += '=';
            }
            s[0] ^= '<' ^ '>';
        }

        if(s == "<"){
            ls.push_back(x);
        }
        else if(s == "<="){
            ls.push_back(x + 1);
        }
        else if(s == ">"){
            gs.push_back(x);
        }
        else{
            gs.push_back(x - 1);
        }
    }

    for(int y : gs){
        if(check(gs, ls, y + 1)){
            printf("%d\n", y + 1);
            return 0;
        }
    }
    for(int y : ls){
        if(check(gs, ls, y - 1)){
            printf("%d\n", y - 1);
            return 0;
        }
    }
    puts("Impossible");
}