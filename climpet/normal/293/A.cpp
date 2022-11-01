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
    int n;
    string s, t;
    cin >> n >> s >> t;

    int a = 0, b = 0, c = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '1' && t[i] == '0'){
            ++a;
        }
        else if(s[i] == '0' && t[i] == '1'){
            ++b;
        }
        else if(s[i] == '1' && t[i] == '1'){
            ++c;
        }
    }

    int x = 0, y = 0;
    int p = 1;
    while(a || b || c){
        if(p){
            if(c){
                ++x;
                --c;
            }
            else if(a){
                ++x;
                --a;
            }
            else{
                --b;
            }
        }
        else{
            if(c){
                ++y;
                --c;
            }
            else if(b){
                ++y;
                --b;
            }
            else{
                --a;
            }
        }
        
        p = !p;
    }

    const char *ans = "Draw";
    if(x > y){
        ans = "First";
    }
    else if(x < y){
        ans = "Second";
    }
    puts(ans);
}