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
#define ITR ::iterator


#define MOD 1000000009LL
#define EPS 1e-8


LL trydiv(LL x, LL y){
    return y ? max(x / y, 0LL) : 0LL;
}


bool solve(){
    LL a, b;
    string s;
    cin >> a >> b >> s;
    if(!a && !b){ return true; }

    LL x = 0, y = 0;
    vector<pll> v(1);
    for(int i = 0; i < s.size(); ++i){
        switch(s[i]){
        case 'U':
            ++y;
            break;
        case 'D':
            --y;
            break;
        case 'L':
            --x;
            break;
        case 'R':
            ++x;
            break;
        }
        v.push_back(pll(x, y));
        if(x == a && y == b){ return true; }
    }
    if(!x && !y){ return false; }

    LL dx = v.back().first, dy = v.back().second;
    for(int i = 0; i < v.size(); ++i){
        x = v[i].first;
        y = v[i].second;
        LL t = max(trydiv(a - x, dx), trydiv(b - y, dy));
        if(dx * t + x == a && dy * t + y == b){
            return true;
        }
    }
    return false;
}

int main(){
    puts(solve() ? "Yes" : "No");
}