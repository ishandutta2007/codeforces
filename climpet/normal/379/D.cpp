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


struct state{
    int bg, en;
    LL acs;

    state(int b, int e, LL a): bg(b), en(e), acs(a) {}
};


bool check1(LL n, const state &s){
    if(n == 1){
        return s.bg == s.en && !s.acs;
    }

    LL m;
    if(s.bg == 'A'){
        if(n == 2 && s.en == 'C'){
            return s.acs == 1;
        }

        if(n & 1){
            m = n / 2;
        }
        else{
            m = n / 2 - (s.en != 'C');
        }
    }
    else{
        if(n & 1){
            m = n / 2 - (s.en != 'C');
        }
        else{
            m = n / 2 - 1;
        }
    }
    return s.acs <= m;
}


bool check2(int k, LL x, state s1, state s2){
    for(int i = 2; i < k; ++i){
        state s3(s1.bg, s2.en, s1.acs + s2.acs);
        if(s1.en == 'A' && s2.bg == 'C'){
            ++s3.acs;
        }
        s1 = s2;
        s2 = s3;
    }
    
    return s2.acs == x;
}


string makeptn(int n, const state &s){
    string ret(n, 'Z');
    ret[0] = s.bg;
    *ret.rbegin() = s.en;

    int t = s.acs;
    if(s.bg == 'A'){
        for(int i = 0; i < t; ++i){
            ret[2 * i] = 'A';
            ret[2 * i + 1] = 'C';
        }
    }
    else{
        for(int i = 0; i < t; ++i){
            ret[2 * i + 1] = 'A';
            ret[2 * i + 2] = 'C';
        }
    }
    return ret;
}


void solve(){
    LL k, x, n, m;
    cin >> k >> x >> n >> m;

    for(int i = n / 2; i >= 0; --i)
    for(int j = m / 2; j >= 0; --j)
    for(char c1 = 'A'; c1 <= 'C'; ++c1)
    for(char c2 = 'A'; c2 <= 'C'; ++c2)
    for(char c3 = 'A'; c3 <= 'C'; ++c3)
    for(char c4 = 'A'; c4 <= 'C'; ++c4){
        state s1(c1, c2, i), s2(c3, c4, j);
        if(check1(n, s1) && check1(m, s2) && check2(k, x, s1, s2)){
            cout << makeptn(n, s1) << '\n' << makeptn(m, s2) << endl;
            throw 0;
        }
    }
    
    cout << "Happy new year!\n";
}


int main(){
    try{
        solve();
    }
    catch(...){
    }
}