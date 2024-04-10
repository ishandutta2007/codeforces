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


vint at, df, c;

int ans;

void calc(){
    for(int i = 0; i < c.size(); ++i){
        int s = 0;
        bool ok = true;
        
        int k = (i < at.size() ? at.size() - i - 1 : 0);
        for(int j = 0; j <= i; ++j, ++k){
            if(k >= at.size()){
                if(df.empty()){
                    s += c[j];
                }
                else{
                    ok = false;
                }
            }
            else{
                if(at[k] > c[j]){
                    ok = false;
                }
                else{
                    s += c[j] - at[k];
                }
            }
        }
        if(!ok){ break; }
        ans = max(ans, s);
    }
}

int main(){
    int n, m, x;
    cin >> n >> m;
    string str;
    c.resize(m);
    for(int i = 0; i < n; ++i){
        cin >> str >> x;
        if(str[0] == 'A'){
            at.push_back(x);
        }
        else{
            df.push_back(x);
        }
    }
    c.resize(m);
    for(int i = 0; i < m; ++i){
        cin >> c[i];
    }
    
    sort(RALL(at));
    sort(RALL(df));
    sort(RALL(c));

    calc();
    
    bool ok = true;
    for(int i = 0; i < df.size(); ++i){
        int j;
        for(j = c.size() - 1; j >= 0 && df[i] >= c[j]; --j);
        if(j < 0){
            ok = false;
            break;
        }
        c.erase(c.begin() + j);
    }
    
    if(ok){
        df.clear();
        calc();
    }
    
    printf("%d\n", ans);
}