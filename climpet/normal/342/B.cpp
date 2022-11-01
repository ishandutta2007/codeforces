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
    int n, m, s, f;
    scanf("%d%d%d%d", &n, &m, &s, &f);
    vector<int> ts(m), ls(m), rs(m);
    for(int i = 0; i < m; ++i){
        scanf("%d%d%d", &ts[i], &ls[i], &rs[i]);
    }
    
    int d;
    char ch;
    if(s > f){
        d = -1;
        ch = 'L';
    }
    else{
        d = 1;
        ch = 'R';
    }
    
    int p = 0;
    for(int tm = 1; s != f; ++tm){
        bool mv = true;
        if(ts[p] == tm){
            if(ls[p] <= s && s <= rs[p]){
                mv = false;
            }
            else if(ls[p] <= s + d && s + d <= rs[p]){
                mv = false;
            }
            ++p;
        }
        
        if(mv){
            putchar(ch);
            s += d;
        }
        else{
            putchar('X');
        }
    }
    puts("");
}