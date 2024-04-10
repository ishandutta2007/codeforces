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


#define REP(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define PB push_back
#define ITR ::iterator


#define MOD 1000000009LL
#define EPS 1e-8

bool use[10];
vector<string> ans;
char buf[32];

int toint(const string &s, int f, int t){
    return atoi(s.substr(f, t - f).c_str());
}

void check(string s){
    bool e[10] = {};
    for(int i = 0; i < s.size(); ++i){
        e[s[i] - '0'] = true;
    }
    for(int i = 0; i < 10; ++i){
        if(!e[i] && use[i]){ return; }
    }

    for(int i = 0; i < s.size(); ++i){
        for(int j = i + 1; j < s.size(); ++j){
            int a = toint(s, i, j);
            if(a > 255) continue;
            for(int k = j + 1; k < s.size(); ++k){
                int b = toint(s, j, k);
                if(b > 255) continue;
                for(int l = k + 1; l < s.size(); ++l){
                    int c = toint(s, k, l);
                    int d = toint(s, l, s.size());
                    if(c > 255 || d > 255) continue;
                    
                    sprintf(buf, "%d%d%d%d", a, b, c, d);
                    if(s != buf) continue;
                    
                    sprintf(buf, "%d.%d.%d.%d", a, b, c, d);
                    ans.push_back(buf);
                }
            }
        }
    }
}

void func(const string &s){
    string r(s.rbegin(), s.rend());
    check(s + r);
    
    if(s.size() < 6){
        for(int i = 0; i < 10; ++i){
            if(use[i]){
                check(s + char('0' + i) + r);
            }
        }
    }
}

void dfs(string &s){
    if(s.size() > 1){
        func(s);
    }
    if(s.size() > 5){
        return;
    }
    
    for(int i = 0; i < 10; ++i){
        if(use[i]){
            s.push_back('0' + i);
            dfs(s);
            s.resize(s.size() - 1);
        }
    }
}

int main(){
    int n, a;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a;
        use[a] = true;
    }

    if(n < 10){
        string s;
        dfs(s);
    }

    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); ++i){
        puts(ans[i].c_str());
    }
}