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



int main(){
    int n, x;
    scanf("%d", &n);
    bool c[101] = {};
    for(int i = 0; i < n; ++i){
        scanf("%d", &x);
        c[x] = true;
    }

    vint ans;

    int t = -1;
    for(int i = 1; i <= 9; ++i){
        if(c[i]){ t = i; }
    }
    if(t != -1){ ans.push_back(t); }
    
    t = -1;
    for(int i = 10; i <= 90; i += 10){
        if(c[i]){ t = i; }
    }
    if(t != -1){ ans.push_back(t); }

    t = -1;
    if(ans.empty()){
        for(int i = 1; i < 100; ++i){
            if(c[i]){ t = i; }
        }
        if(t != -1){ ans.push_back(t); }
    }
    
    if(c[0]){ ans.push_back(0); }
    if(c[100]){ ans.push_back(100); }
    
    char ch = '\n';
    printf("%d", ans.size());
    for(int i = 0; i < ans.size(); ++i){
        printf("%c%d", ch, ans[i]);
        ch = ' ';
    }
    puts("");
}