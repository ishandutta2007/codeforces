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
    const char * tbl[7] = {"9681", "8196", "9861", "8691", "6891", "9816", "8961"};

    int cnt[10] = {};
    string s;
    cin >> s;
    for(size_t i = 0; i < s.size(); ++i){
        ++cnt[s[i] - '0'];
    }

    int d = 0;
    for(int i = 9; i > 0; --i){
        for(int j = (i == 1 || i == 6 || i == 8 || i == 9); j < cnt[i]; ++j){
            cout << char(i + '0');
            d = (d * 10 + i) % 7;
        }
    }

    d = d * 10000 % 7;

    cout << tbl[d] << string(cnt[0], '0') << endl;
}